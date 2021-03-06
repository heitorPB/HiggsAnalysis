#!/usr/bin/env python
'''

Usage:
./plotTemplate.py -m <pseudo_mcrab_directory>

'''

#================================================================================================
# Imports
#================================================================================================
import os
import sys
from optparse import OptionParser
import getpass
import socket

import HiggsAnalysis.NtupleAnalysis.tools.dataset as dataset
import HiggsAnalysis.NtupleAnalysis.tools.tdrstyle as tdrstyle
import HiggsAnalysis.NtupleAnalysis.tools.styles as styles
import HiggsAnalysis.NtupleAnalysis.tools.plots as plots
import HiggsAnalysis.NtupleAnalysis.tools.histograms as histograms
import HiggsAnalysis.NtupleAnalysis.tools.aux as aux
from plotAux import *

import ROOT

#================================================================================================
# Variable Definition
#================================================================================================
kwargs = {
    "analysis"       : "MetBreakDown",
    "savePath"       : "plots/2d/",
    "refDataset"     : "ChargedHiggs_HplusTB_HplusToTB_M_200", #, TT, QCD
    "rmDataset"      : ["ChargedHiggs_HplusTB_HplusToTB_M_500", "TT", "TTTT", "QCD", "QCD-b"], #["QCD"],
    "saveFormats"    : [".png", ".pdf"],
    "normalizeTo"    : "One", #One", "XSection", "Luminosity"
    "zMin"           : 1e-5,
    "zMax"           : 5e-2,
    "rebinX"         : 1,
    "rebinY"         : 1,
    "createRatio"    : False,
    "logX"           : False,
    "logY"           : False,
    "logZ"           : True,
    "gridX"          : True,
    "gridY"          : True,
    "drawStyle"      : "COLZ", #"CONT4" "COLZ" "COL"
    "legStyle"       : "F",     # "LP", "F"
    "verbose"        : False,
    "cutValue"       : None,
    "cutBox"         : False,
    "cutLine"        : False,
    "cutLessthan"    : False,
    "cutFillColour"  : ROOT.kAzure-4,
}


hNames = [
    "genP_n_b_B",
    "bJets_met",
    "bJets_mht",
]



#================================================================================================
# Main
#================================================================================================
def main():

    style = tdrstyle.TDRStyle()
    #style.setWide(True)
    style.setPaletteMy()
    ROOT.gStyle.SetNumberContours(20)
    # tdrstyle.setDeepSeaPalette()
    # tdrstyle.setRainBowPalette()
    # tdrstyle.setDarkBodyRadiatorPalette()
    # tdrstyle.setGreyScalePalette()
    # tdrstyle.setTwoColorHuePalette()
 
    
    # Set ROOT batch mode boolean
    ROOT.gROOT.SetBatch(parseOpts.batchMode)
    
    # Get all datasets from the mcrab dir
    #datasetsMgr  = GetDatasetsFromDir(parseOpts.mcrab, kwargs.get("analysis"))
    datasetsMgr  = GetDatasetsFromDir(parseOpts.mcrab, parseOpts, **kwargs)

    # Determine Integrated Luminosity (If Data datasets present)
    intLumi = GetLumi(datasetsMgr)
    
    # Update to PU
    datasetsMgr.updateNAllEventsToPUWeighted()

    # Remove datasets
    #datasetsMgr.remove(kwargs.get("rmDataset"))
    datasetsMgr.remove(filter(lambda name: not kwargs.get("refDataset") in name, datasetsMgr.getAllDatasetNames()))

    # Set custom XSections
    # d.getDataset("TT_ext3").setCrossSection(831.76)
    
    # Default merging & ordering: "Data", "QCD", "SingleTop", "Diboson"
    plots.mergeRenameReorderForDataMC(datasetsMgr) #WARNING: Merged MC histograms must be normalized to something!

    # Remove datasets (for merged names)
    # datasetsMgr.remove(kwargs.get("rmDataset"))
                  
    # For-loop: All Histogram names
    for hName in hNames:
        savePath, saveName = GetSavePathAndName(hName, **kwargs)                

        # Get Histos for Plotter
        refHisto, otherHistos = GetHistosForPlotter(datasetsMgr, hName, **kwargs)

        # Create a plot
        p = plots.PlotBase([refHisto], kwargs.get("saveFormats"))
        
        # Remove negative contributions
        #RemoveNegativeBins(datasetsMgr, hName, p)

        # Customize
        # p.histoMgr.setHistoDrawStyleAll("COL") #"CONT4" "COLZ" "COL"
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().RebinX(kwargs.get("rebinX")))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().RebinY(kwargs.get("rebinY")))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().GetXaxis().SetRangeUser(1.0, 5.0))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().GetYaxis().SetRangeUser(1.0, 5.0))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().GetZaxis().SetRangeUser(0.0, 0.015))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().SetMinimum(kwargs.get("zMin")))
        # p.histoMgr.forEachHisto(lambda h: h.getRootHisto().SetMaximum(kwargs.get("zMax")))
        
        # Create a frame
        opts = {"ymin": 0.0, "ymaxfactor": 1.0}
        p.createFrame(saveName, opts=opts)


        # Customise frame
        p.getFrame().GetXaxis().SetTitle( getTitleX(refHisto, **kwargs) )
        p.getFrame().GetYaxis().SetTitle( getTitleY(refHisto, **kwargs) )
        # p.getFrame().GetZaxis().SetTitle( getTitleZ(refHisto, **kwargs) ) #does not work
        
        # SetLog
        SetLogAndGrid(p, **kwargs)

        # Add cut line/box
        _kwargs = { "lessThan": kwargs.get("cutLessThan")}
        p.addCutBoxAndLine(cutValue=kwargs.get("cutValue"), fillColor=kwargs.get("cutFillColour"), box=kwargs.get("cutBox"), line=kwargs.get("cutLine"), **_kwargs)
        
        # Customise Legend
        moveLegend = {"dx": -0.1, "dy": +0.0, "dh": -0.1}
        p.setLegend(histograms.moveLegend(histograms.createLegend(), **moveLegend))
        p.removeLegend()

        # Add MC Uncertainty (Invalid method for a 2-d histogram)
        #p.addMCUncertainty()
        
        #  Draw plots
        p.draw()

        # Customise text
        histograms.addStandardTexts(lumi=intLumi)
        #histograms.addText(0.16, 0.95, plots._legendLabels[kwargs.get("refDataset")], 22)
        histograms.addText(0.20, 0.88, plots._legendLabels[kwargs.get("refDataset")], 17)
        
        # Save canvas under custom dir
	if not os.path.exists(savePath):
		os.mkdir(savePath)
        SaveAs(p, savePath, saveName, kwargs.get("saveFormats"))

    return

#================================================================================================
# Main
#================================================================================================
if __name__ == "__main__":
    parser = OptionParser(usage="Usage: %prog [options]" , add_help_option=False,conflict_handler="resolve")
    parser.add_option("-m", "--mcrab"    , dest="mcrab"    , action="store", help="Path to the multicrab directory for input")
    parser.add_option("-b", "--batchMode", dest="batchMode", action="store_false", default=True, help="Enables batch mode (canvas creation does NOT generates a window)")
    parser.add_option("-v", "--verbose"  , dest="verbose"  , action="store_true", default=False, help="Enables verbose mode (for debugging purposes)")
    parser.add_option("-i", "--includeTasks", dest="includeTasks" , default="", type="string", help="Only perform action for this dataset(s) [default: '']")
    parser.add_option("-e", "--excludeTasks", dest="excludeTasks" , default="", type="string", help="Exclude this dataset(s) from action [default: '']")

    (parseOpts, parseArgs) = parser.parse_args()

    # Require at least two arguments (script-name, path to multicrab)
    if parseOpts.mcrab == None:
        Print("Not enough arguments passed to script execution. Printing docstring & EXIT.")
        print __doc__
        sys.exit(0)
    else:
        pass

    # Program execution
    main()

    if not parseOpts.batchMode:
        raw_input("=== plotTemplate.py: Press any key to quit ROOT ...")
