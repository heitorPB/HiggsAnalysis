import FWCore.ParameterSet.Config as cms

# WARNING: the trigger path is modified in qcdMeasurementByIsolationVeto_cfg.py depending on the data version
trigger = cms.untracked.PSet(
    src = cms.untracked.InputTag("patTriggerEvent"),
    triggers = cms.untracked.vstring("HLT_SingleLooseIsoTau20",
                                     "HLT_SingleIsoTau20_Trk5",
                                     "HLT_SingleIsoTau30_Trk5",
                                     "HLT_SingleIsoTau20_Trk15_MET20",
                                     "HLT_SingleIsoTau20_Trk15_MET25_v3",
                                     "HLT_SingleIsoTau20_Trk15_MET25_v4"
                                     ),
    hltMetCut = cms.untracked.double(20.0),
    )

TriggerMETEmulation = cms.untracked.PSet(
    src = cms.untracked.InputTag("patMETs"), # calo MET
    metEmulationCut = cms.untracked.double(30.0)
    )

#import HiggsAnalysis.HeavyChHiggsToTauNu.HChTauIDFactorization_cfi as factorizationParams

### Define tau selection
import HiggsAnalysis.HeavyChHiggsToTauNu.HChTauIDFactorization_cfi as factorizationParams
seFactorizedTauID = cms.untracked.bool(False)
#
tauSelectionBase = cms.untracked.PSet(
    src = cms.untracked.InputTag("myTauCollection"),
    selection = cms.untracked.string(""),
    ptCut = cms.untracked.double(30),
    etaCut = cms.untracked.double(2.4),
    leadingTrackPtCut = cms.untracked.double(20), #To fully disable this remove requirement to ldgTrkExist from TauSelectionByIsolationVeto.cc
    rtauCut = cms.untracked.double(0.8),
    invMassCut = cms.untracked.double(999.),
    nprongs = cms.untracked.uint32(1),
    factorization = factorizationParams.tauIDFactorizationParameters
    )
### Reco CaloTau
tauSelectionCaloTauCutBased = tauSelectionBase.clone()
tauSelectionCaloTauCutBased.src = cms.untracked.InputTag("selectedPatTausCaloRecoTauTauTriggerMatched")
tauSelectionCaloTauCutBased.selection = cms.untracked.string("CaloTauCutBased")
### PF Shrinking Cone
tauSelectionShrinkingConeCutBased = tauSelectionBase.clone()
tauSelectionShrinkingConeCutBased.src = cms.untracked.InputTag("selectedPatTausShrinkingConePFTauTauTriggerMatched")
tauSelectionShrinkingConeCutBased.selection = cms.untracked.string("ShrinkingConePFTauCutBased")
### TaNC
tauSelectionShrinkingConeTaNCBased = tauSelectionBase.clone()
tauSelectionShrinkingConeTaNCBased.src = cms.untracked.InputTag("selectedPatTausShrinkingConePFTauTauTriggerMatched")
tauSelectionShrinkingConeTaNCBased.selection = cms.untracked.string("ShrinkingConePFTauTaNCBased")
### HPS
tauSelectionHPSTauBased = tauSelectionBase.clone()
tauSelectionHPSTauBased.src = cms.untracked.InputTag("selectedPatTausHpsPFTauTauTriggerMatched")
tauSelectionHPSTauBased.selection = cms.untracked.string("HPSTauBased")
### Select tau-collection to be used
#tauSelection = tauSelectionCaloTauCutBased
#tauSelection = tauSelectionShrinkingConeCutBased
#tauSelection = tauSelectionShrinkingConeTaNCBased
tauSelection = tauSelectionHPSTauBased
print "tauSelection.src :", tauSelection.src

### Define jet selection
jetSelection = cms.untracked.PSet(
    #src = cms.untracked.InputTag("selectedPatJets"),       # Calo jets
    #src = cms.untracked.InputTag("selectedPatJetsAK5JPT"), # JPT jets 
    src = cms.untracked.InputTag("selectedPatJetsAK5PF"),  # PF jets
    src_met = cms.untracked.InputTag("patMETsPF"), # pf MET
    cleanTauDR = cms.untracked.double(0.5),
    ptCut = cms.untracked.double(30),
    etaCut = cms.untracked.double(2.4),
    minNumber = cms.untracked.uint32(3),
    METCut = cms.untracked.double(70.0) # Only used for deltaPhi histogram plotting
)
print "jetSelection.src :", jetSelection.src

### Definre the rest of the event selection: MET, B-tagging, Global e/mu vetoes, fakeMET veto, 
MET = cms.untracked.PSet(
    # src = cms.untracked.InputTag("patMETs"), # calo MET
    src = cms.untracked.InputTag("patMETsPF"), # PF MET
    # src = cms.untracked.InputTag("patMETsTC"), # tc MET
    METCut = cms.untracked.double(70.0),
    # Direction of MET cut; options are: lowerLimit (i.e. > ) and upperLimit (i.e. < )
    METCutDirection = cms.untracked.string("lowerLimit")
)
print "MET.src :", MET.src

bTagging = cms.untracked.PSet(
    discriminator = cms.untracked.string("trackCountingHighEffBJetTags"),
    discriminatorCut = cms.untracked.double(2.0),
    ptCut = cms.untracked.double(30),
    etaCut = cms.untracked.double(2.4),
    minNumber = cms.untracked.uint32(1)
)
print "bTagging.discriminator :", bTagging.discriminator

GlobalElectronVeto = cms.untracked.PSet(
    ElectronCollectionName = cms.untracked.InputTag("selectedPatElectrons"),
    ElectronSelection = cms.untracked.string("simpleEleId95relIso"),
    ElectronPtCut = cms.untracked.double(20.0),
    ElectronEtaCut = cms.untracked.double(2.5)
)
print "GlobalElectronVeto.ElectronSelection :", GlobalElectronVeto.ElectronSelection

GlobalMuonVeto = cms.untracked.PSet(
    MuonCollectionName = cms.untracked.InputTag("selectedPatMuons"),
    MuonSelection = cms.untracked.string("GlobalMuonPromptTight"),
    MuonPtCut = cms.untracked.double(20.0),
    MuonEtaCut = cms.untracked.double(2.5)
)
print "GlobalMuonVeto.MuonSelection :", GlobalMuonVeto.MuonSelection

fakeMETVeto = cms.untracked.PSet(
  src = MET.src,
  minDeltaPhi = cms.untracked.double(10.0)
)
print "fakeMETVeto.src :", fakeMETVeto.src

#transverseMassCut = cms.untracked.double(-10)