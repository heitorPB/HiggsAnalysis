#!/usr/bin/env python
import sys

dataEras = ["2015"]
#dataEras = ["2015B","2015C"]
searchModes = ["80to1000"]

if len(sys.argv) < 2:
    print "Usage: ./QCDMeasurementAnalysis.py <path-to-multicrab-directory> <1pr> <2pr> <3pr>"
    sys.exit(0)

from HiggsAnalysis.NtupleAnalysis.main import Process, PSet, Analyzer
from HiggsAnalysis.NtupleAnalysis.parameters.signalAnalysisParameters import obtainAnalysisSuffix
process = Process("QCDMeasurement"+obtainAnalysisSuffix(sys.argv))
process.addDatasetsFromMulticrab(sys.argv[1])

# Add config
from HiggsAnalysis.NtupleAnalysis.parameters.signalAnalysisParameters import allSelections,applyAnalysisCommandLineOptions
# Enable genuine tau histograms for common plots (needed for calculating N_QCD)
allSelections.CommonPlots.enableGenuineTauHistograms = True
# Set splitting of phase space (first bin is below first edge value and last bin is above last edge value)
allSelections.CommonPlots.histogramSplitting = [
    PSet(label="tauPt", binLowEdges=[60.0, 80.0, 100.0], useAbsoluteValues=False),
  ]
#===== Selection customisations
#allSelections.TauSelection.rtau = 0.0
#allSelections.BJetSelection.numberOfBJetsCutValue = 0
#allSelections.BJetSelection.numberOfBJetsCutDirection = "=="
#===== End of selection customisations

applyAnalysisCommandLineOptions(sys.argv, allSelections)

# Build analysis modules
from HiggsAnalysis.NtupleAnalysis.AnalysisBuilder import AnalysisBuilder
builder = AnalysisBuilder("QCDMeasurement", 
                          dataEras,
                          searchModes,
                          #### Options ####
                          usePUreweighting=True,
                          doSystematicVariations=False,
                          )
#builder.addVariation()
builder.build(process, allSelections)

# Pick events
#process.addOptions(EventSaver = PSet(enabled = True,pickEvents = True))

# Run the analysis
if "proof" in sys.argv:
    #raise Exception("Proof messes up the event weights, do not use for the moment!")
    process.run(proof=True)
else:
    process.run()

# Run the analysis with PROOF
# By default it uses all cores, but you can give proofWorkers=<N> as a parameter

