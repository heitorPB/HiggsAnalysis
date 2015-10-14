import FWCore.ParameterSet.Config as cms
import HiggsAnalysis.MiniAOD2TTree.tools.git as git #HiggsAnalysis.HeavyChHiggsToTauNu.tools.git as git
from HiggsAnalysis.HeavyChHiggsToTauNu.HChOptions import getOptionsDataVersion

process = cms.Process("TTreeDump")

#dataVersion = "74Xmc"
dataVersion = "74Xdata"

options, dataVersion = getOptionsDataVersion(dataVersion)
print dataVersion

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("FWCore/MessageService/MessageLogger_cfi")
process.MessageLogger.categories.append("TriggerBitCounter")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000 # print the event number for every 100th event
process.MessageLogger.cerr.TriggerBitCounter = cms.untracked.PSet(limit = cms.untracked.int32(10)) # print max 100 warnings

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#       '/store/mc/RunIISpring15DR74/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/AsymptFlat10to50bx25Raw_MCRUN2_74_V9-v1/10000/1AEFBE02-4C02-E511-B796-0025905A60BE.root',
#       '/store/data/Run2015C/SingleMuon/MINIAOD/PromptReco-v1/000/254/231/00000/3EA254BD-EA45-E511-B1DA-02163E0141FF.root'
	'/store/data/Run2015C/SingleMuon/MINIAOD/PromptReco-v1/000/254/906/00000/2A365D2E-D74B-E511-9D09-02163E012539.root'
#	'/store/data/Run2015C/SingleMuon/MINIAOD/PromptReco-v1/000/254/879/00000/DA13C76D-9B4B-E511-822A-02163E013790.root'
    )
)

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, str(dataVersion.getGlobalTag()), '')
print "GlobalTag="+dataVersion.getGlobalTag()

# Set up electron ID (VID framework)
# https://twiki.cern.ch/twiki/bin/view/CMS/MultivariateElectronIdentificationRun2
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
switchOnVIDElectronIdProducer(process, DataFormat.MiniAOD)
# define which IDs we want to produce and add them to the VID producer
for idmod in ['RecoEgamma.ElectronIdentification.Identification.mvaElectronID_PHYS14_PU20bx25_nonTrig_V1_cff']:
    setupAllVIDIdsInModule(process, idmod, setupVIDElectronSelection)

# Set up HBHE noise filter
# https://twiki.cern.ch/twiki/bin/viewauth/CMS/MissingETOptionalFiltersRun2
print "Setting up HBHE noise filter"   
process.load('CommonTools.RecoAlgos.HBHENoiseFilterResultProducer_cfi')
process.HBHENoiseFilterResultProducer.minZeros = cms.int32(99999)
process.HBHENoiseFilterResultProducer.IgnoreTS4TS5ifJetInLowBVRegion=cms.bool(False)
process.HBHENoiseFilterResultProducer.defaultDecision = cms.string("HBHENoiseFilterResultRun2Loose")
# Do not apply EDfilters for HBHE noise, the discriminators for them are saved into the ttree

TrgResultsSource = "TriggerResults::PAT"
if dataVersion.isData():
    TrgResultsSource = "TriggerResults::RECO"
print "Trigger source has been set to:",TrgResultsSource

process.load("HiggsAnalysis/MiniAOD2TTree/Tau_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Electron_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Muon_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Jet_cfi")    
process.load("HiggsAnalysis/MiniAOD2TTree/MET_cfi")    

process.dump = cms.EDFilter('MiniAOD2TTreeFilter',
    OutputFileName = cms.string("miniaod2tree.root"),
    CodeVersion = cms.string(git.getCommitId()),
    DataVersion = cms.string(str(dataVersion.version)),
    CMEnergy = cms.int32(13),
    Skim = cms.PSet(
	Counters = cms.VInputTag(
	    "skimCounterAll",
            "skimCounterPassed"
        ),
    ),
    EventInfo = cms.PSet(
	PileupSummaryInfoSrc = cms.InputTag("addPileupInfo"),
	OfflinePrimaryVertexSrc = cms.InputTag("offlineSlimmedPrimaryVertices"),
    ),
    Trigger = cms.PSet(
	TriggerResults = cms.InputTag("TriggerResults::HLT"),
	TriggerBits = cms.vstring(
	    "HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v",
	    "HLT_IsoMu16_eta2p1_CaloMET30_v",
            "HLT_IsoMu16_eta2p1_MET30_JetIdCleaned_LooseIsoPFTau50_Trk30_eta2p1_v",
            "HLT_IsoMu16_eta2p1_MET30_JetIdCleaned_v",
            "HLT_IsoMu17_eta2p1_v",
            "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v",
            "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v",
            "HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v",
            "HLT_IsoMu20_eta2p1_v",
            "HLT_IsoMu24_eta2p1_v",
            "HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v"
        ),
	L1Extra = cms.InputTag("l1extraParticles:MET"),
	TriggerObjects = cms.InputTag("selectedPatTrigger"),
	TriggerMatch = cms.untracked.vstring(
	    "LooseIsoPFTau50_Trk30_eta2p1",
	    "LooseIsoPFTau20",
            "MediumIsoPFTau40_Trk1_eta2p1_Reg",
	    "IsoMu16_eta2p1",
            "IsoMu17_eta2p1",
            "IsoMu20_eta2p1"
	),
	filter = cms.untracked.bool(False)
    ),
    METNoiseFilter = cms.PSet(
        triggerResults = cms.InputTag(TrgResultsSource),
        printTriggerResultsList = cms.untracked.bool(False),
        filtersFromTriggerResults = cms.vstring(
            "Flag_CSCTightHaloFilter",
            "Flag_goodVertices",
            "Flag_eeBadScFilter",
        ),
        hbheNoiseTokenRun2LooseSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHENoiseFilterResultRun2Loose'),
        hbheNoiseTokenRun2TightSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHENoiseFilterResultRun2Tight'),
        hbheIsoNoiseTokenSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHEIsoNoiseFilterResult'),
    ),
    Taus      = process.Taus,
#    Electrons = process.Electrons,
    Muons     = process.Muons,
    Jets      = process.Jets,
    METs      = process.METs,
    GenWeights = cms.VPSet(
        cms.PSet(
            branchname = cms.untracked.string("GenWeights"),
            src = cms.InputTag("generator"),
            filter = cms.untracked.bool(False)
        )
    ),
)

process.load("HiggsAnalysis.MiniAOD2TTree.TauLegSkim_cfi")

process.skimCounterAll        = cms.EDProducer("HplusEventCountProducer")
process.skimCounterMETFilters = cms.EDProducer("HplusEventCountProducer")
process.skimCounterPassed     = cms.EDProducer("HplusEventCountProducer")

# module execution
process.runEDFilter = cms.Path(process.skimCounterAll*
                               process.skim*
                               process.skimCounterPassed*
                               process.HBHENoiseFilterResultProducer* #Produces HBHE booleans
                               process.egmGsfElectronIDSequence*
                               process.dump)

#process.output = cms.OutputModule("PoolOutputModule",
#    outputCommands = cms.untracked.vstring(
#        "keep *",
#    ),
#    fileName = cms.untracked.string("CMSSW.root")
#)
#process.out_step = cms.EndPath(process.output)
