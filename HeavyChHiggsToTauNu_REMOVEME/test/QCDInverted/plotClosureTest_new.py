#!/usr/bin/env python

import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.PyConfig.IgnoreCommandLineOptions = True
import math
import sys
import os
import array
from optparse import OptionParser

import HiggsAnalysis.HeavyChHiggsToTauNu.tools.dataset as dataset
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.histograms as histograms
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.histogramsExtras as histogramsExtras
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.tdrstyle as tdrstyle
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.styles as styles
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.plots as plots
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.systematics as systematics
from HiggsAnalysis.HeavyChHiggsToTauNu.tools.analysisModuleSelector import *
from HiggsAnalysis.HeavyChHiggsToTauNu.qcdCommon.dataDrivenQCDCount import *
from HiggsAnalysis.HeavyChHiggsToTauNu.tools.ShellStyles import *
import HiggsAnalysis.HeavyChHiggsToTauNu.qcdInverted.qcdInvertedResult as qcdInvertedResult

def doSinglePlot(hbase, hinv, myDir, histoName, luminosity):
    def rebin(h, name):
        myBinning = []
        if name.startswith("MT"):
            myBinning = systematics.getBinningForPlot("shapeTransverseMass")
        elif name.startswith("INVMASS"):
            myBinning = systematics.getBinningForPlot("shapeInvariantMass")
        else:
            raise Exception("Unknown binning information")
        maxBin = h.GetXaxis().GetBinUpEdge(h.GetNbinsX())
        if maxBin < myBinning[-1]:
            print WarningLabel()+"Adjust rebinning last bin from %.0f to %.0f because that is the up edge of last bin in the historam" % (myBinning[-1], maxBin)
            myBinning[-1] = 500
        myArray = array.array("d",myBinning)
        # Rebin and move under/overflow bins to visible bins
        h = h.Rebin(len(myBinning)-1,"",myArray)
        histogramsExtras.makeFlowBinsVisible(h)
        return h

    #hbase.SetFillColor(ROOT.kGray)
    hbase.SetLineColor(ROOT.kGray)
    hbase.SetFillColor(hbase.GetLineColor())
    hinv.SetLineColor(ROOT.kBlue)
    # Rebin
    hbase = rebin(hbase, histoName)
    hinv = rebin(hinv, histoName)
    # Normalize
    print "baseline: %.1f events, inverted %.1f events"%(hbase.Integral(), hinv.Integral())
    toUnitArea = True
    if toUnitArea:
        hbase.Scale(1.0 / hbase.Integral())
        hinv.Scale(1.0 / hinv.Integral())
    # Plot
    baseHisto = histograms.Histo(hbase, "Isolated", drawStyle="HIST", legendStyle="F")
    invHisto = histograms.Histo(hinv, "Anti-isolated", drawStyle="HIST E", legendStyle="l")
    plot = plots.ComparisonPlot(invHisto, baseHisto)
    plot.setLuminosity(luminosity)
    plot.histoMgr.forEachHisto(lambda h: h.getRootHisto().SetLineWidth(3))
    if toUnitArea:
        plot.appendPlotObject(histograms.PlotText(0.5, 0.6, "Normalized to unit area", size=20))
    myPlotName = "%s/QCDInv_ClosureTest_%s"%(myDir, histoName)
    myParams = {}
    if toUnitArea:
        myParams["ylabel"] = "A.u.    "
    else:
        myParams["ylabel"] = "< Events / GeV >"
    myParams["xlabel"] = "m_{T} (GeV)"
    myParams["log"] = False
    myParams["opts2"] = {"ymin": 0.0, "ymax":2.0}
    myParams["opts"] = {"ymin": 0.0}
    myParams["ratio"] = True
    myParams["ratioType"] = "errorScale"
    myParams["ratioYlabel"] = "Anti-isol./Isol."
    myParams["ratioCreateLegend"] = True
    myParams["ratioMoveLegend"] = {"dx": -0.05, "dy": -0.4, "dh": -0.1}
    myParams["cmsTextPosition"] = "right"
    myParams["addLuminosityText"] = True
    myParams["divideByBinWidth"] = True
    plots._legendLabels["BackgroundStatError"] = "Isol. stat. unc."
    plots.drawPlot(plot, myPlotName, **myParams)

def doClosureTestPlots(opts, dsetMgr, moduleInfoString, myDir, luminosity, normFactors):
    # Set here the names of the histograms you want to access
    histoNameList = ["MTInvertedTauIdFinalReversedBtag",
                     "MTInvertedTauIdFinalReversedBacktoBackDeltaPhi",
                    ]
    for histoName in histoNameList:
        print histoName
        myBaselineShape = DataDrivenQCDShape(dsetMgr, "Data", "EWK", "baseline/"+histoName.replace("Inverted","Baseline"), luminosity)
        myInvertedShape = DataDrivenQCDShape(dsetMgr, "Data", "EWK", "Inverted/"+histoName, luminosity)
        myInvertedResults = qcdInvertedResult.QCDInvertedShape(myInvertedShape, moduleInfoString, normFactors, optionPrintPurityByBins=False, optionDoNQCDByBinHistograms=True)
        # Do comparison plots bin-by-bin
        myInvertedHistos = myInvertedResults.getNQCDHistograms()
        for i in range(0, len(myInvertedHistos)):
            doSinglePlot(myBaselineShape.getDataDrivenQCDHistoForSplittedBin(i), myInvertedHistos[i], myDir, histoName+"_bin%d"%i, luminosity)
        # Do comparison plot for bins summed up
        doSinglePlot(myBaselineShape.getIntegratedDataDrivenQCDHisto(), myInvertedResults.getResultShape(), myDir, histoName, luminosity)
    print HighlightStyle()+"doClosureTestPlots is ready"+NormalStyle()

def doEventYieldTable(opts, dsetMgr, moduleInfoString, myDir, luminosity, normFactors):
    def _calculateCellWidths(widths, row):
        myResult = widths
        # Initialise widths if necessary
        if len(row) == 0:
          return myResult
        for i in range(len(widths),len(row)):
            myResult.append(0)
        # Loop over row cells
        for i in range(0,len(row)):
            if len(row[i]) > myResult[i]:
                myResult[i] = len(row[i])
        return myResult

    def _printRow(widths, row):
        myResult = ""
        for i in range(0,len(row)):
            if i != 0:
                myResult += " "
            myResult += row[i].ljust(widths[i])
        print myResult

    histoName = "shapeTransverseMass"
    print "Event yield table for shape: %s"%histoName
    # Obtain shape
    myShape = DataDrivenQCDShape(dsetMgr, "Data", "EWK", histoName, luminosity)
    myHeader = []
    myDataList = []
    myMCEWKList = []
    myNormList = []
    myResultList = []
    for i in range(0,len(myShape._dataList)):
        # Get histograms
        hData = myShape._dataList[i]
        hMCEWK = myShape._ewkList[i]
        # Get event count and stat. uncert.
        myDataStatUncert = ROOT.Double(0.0)
        myMCEWKStatUncert = ROOT.Double(0.0)
        myDataCount = hData.IntegralAndError(0, hData.GetNbinsX()+2, myDataStatUncert)
        myMCEWKCount = hMCEWK.IntegralAndError(0, hMCEWK.GetNbinsX()+2, myMCEWKStatUncert)
        # Store result
        myHeader.append(myShape.getPhaseSpaceBinFileFriendlyTitle(i))
        myDataList.append("%.1f +- %.1f"%(myDataCount, myDataStatUncert))
        myMCEWKList.append("%.1f +- %.1f"%(myMCEWKCount, myMCEWKStatUncert))
        myNormFactor = normFactors[myShape.getPhaseSpaceBinFileFriendlyTitle(i)]
        myNormList.append("%.3f"%myNormFactor)
        myTotalCount = myDataCount - myMCEWKCount
        myTotalStatUncert = math.sqrt(myDataStatUncert**2 + myMCEWKStatUncert**2)
        myTotalCount *= myNormFactor
        myTotalStatUncert *= myNormFactor
        myResultList.append("%.1f +- %.1f"%(myTotalCount, myTotalStatUncert))
    # Format table
    myWidths = []
    myWidths = _calculateCellWidths(myWidths, myHeader)
    myWidths = _calculateCellWidths(myWidths, myDataList)
    myWidths = _calculateCellWidths(myWidths, myMCEWKList)
    myWidths = _calculateCellWidths(myWidths, myNormList)
    myWidths = _calculateCellWidths(myWidths, myResultList)
    # Print result
    _printRow(myWidths, myHeader)
    _printRow(myWidths, myDataList)
    _printRow(myWidths, myMCEWKList)
    _printRow(myWidths, myNormList)
    _printRow(myWidths, myResultList)

def createOutputdirectory(myDir):
    if os.path.exists(myDir):
        # Remove very old files
        for filename in os.listdir("%s/."%myDir):
            if filename[0:4] == "old_":
                os.remove("%s/%s"%(myDir,filename))
        # Rename remaining files
        for filename in os.listdir("%s/."%myDir):
            os.rename("%s/%s"%(myDir,filename), "%s/old_%s"%(myDir,filename))
    else:
        # Create directory since it does not exist
        os.mkdir(myDir)

if __name__ == "__main__":
    # Obtain normalization factors
    myNormalizationFactorSource = "QCDInvertedNormalizationFactors.py"
    myNormFactors = None
    myNormFactorsSafetyCheck = None
    if os.path.exists(myNormalizationFactorSource):
        myNormFactorsImport = getattr(__import__(myNormalizationFactorSource.replace(".py","")), "QCDInvertedNormalization")
        myNormFactorsSafetyCheck = getattr(__import__(myNormalizationFactorSource.replace(".py","")), "QCDInvertedNormalizationSafetyCheck")
        #QCDInvertedNormalizationSafetyCheck(era)
        myNormFactors = myNormFactorsImport.copy()
    else:
        raise Exception(ErrorLabel()+"Normalisation factors ('%s.py') not found!\nRun script InvertedTauID_Normalization.py to generate the normalization factors."%myNormalizationFactorSource)

    myModuleSelector = AnalysisModuleSelector() # Object for selecting data eras, search modes, and optimization modes

    parser = OptionParser(usage="Usage: %prog [options]",add_help_option=True,conflict_handler="resolve")
    myModuleSelector.addParserOptions(parser)
    parser.add_option("--mdir", dest="multicrabDir", action="store", help="Multicrab directory")
    # Add here parser options, if necessary, following line is an example
    #parser.add_option("--showcard", dest="showDatacard", action="store_true", default=False, help="Print datacards also to screen")

    # Parse options
    (opts, args) = parser.parse_args()

    # Obtain multicrab directory
    myMulticrabDir = "."
    if opts.multicrabDir != None:
        myMulticrabDir = opts.multicrabDir

    # Obtain dsetMgrCreator and register it to module selector
    dsetMgrCreator = dataset.readFromMulticrabCfg(directory=myMulticrabDir)
    myModuleSelector.setPrimarySource("analysis", dsetMgrCreator)
    # Select modules
    myModuleSelector.doSelect(opts)

    # Apply TDR style
    style = tdrstyle.TDRStyle()
    histograms.createLegend.moveDefaults(dx=-0.1, dy=-0.12, dh=-0.2)
    histograms.uncertaintyMode.set(histograms.Uncertainty.StatOnly)

    myDisplayStatus = True
    # Loop over era/searchMode/optimizationMode options
    for era in myModuleSelector.getSelectedEras():
        for searchMode in myModuleSelector.getSelectedSearchModes():
            for optimizationMode in myModuleSelector.getSelectedOptimizationModes():
                # Construct info string of module
                myModuleInfoString = "%s_%s_%s"%(era, searchMode, optimizationMode)
                print HighlightStyle()+"Module:",myModuleInfoString,NormalStyle()
                # Obtain dataset manager
                dsetMgr = dsetMgrCreator.createDatasetManager(dataEra=era,searchMode=searchMode,optimizationMode=optimizationMode)
                # Do the usual normalisation
                dsetMgr.updateNAllEventsToPUWeighted()
                dsetMgr.loadLuminosities()
                plots.mergeRenameReorderForDataMC(dsetMgr)
                dsetMgr.merge("EWK", [
                              "TTJets",
                              "WJets",
                              "DYJetsToLL",
                              "SingleTop",
                              "Diboson"
                              ])
                # Make a directory for output
                myDir = "QCDInv_ClosureTest_%s"%myModuleInfoString
                createOutputdirectory(myDir)
                # Obtain luminosity
                myLuminosity = dsetMgr.getDataset("Data").getLuminosity()
                # Print info so that user can check that merge went correct
                if myDisplayStatus:
                    dsetMgr.printDatasetTree()
                    print "Luminosity = %f 1/fb"%(myLuminosity / 1000.0)
                    print
                    myDisplayStatus = False
                # Run plots
                doClosureTestPlots(opts, dsetMgr, myModuleInfoString, myDir, myLuminosity, myNormFactors)
                doEventYieldTable(opts, dsetMgr, myModuleInfoString, myDir, myLuminosity, myNormFactors)
                #doPurityPlots(opts, dsetMgr, myModuleInfoString, myDir, myLuminosity)
                #doQCDfactorisedResultPlots(opts, dsetMgr, myModuleInfoString, myDir, myLuminosity)
