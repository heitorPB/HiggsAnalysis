// -*- c++ -*-
#include "Framework/interface/BaseSelector.h"
#include "Framework/interface/makeTH.h"

// User
#include "Auxiliary/interface/Table.h"
#include "Auxiliary/interface/Tools.h"
#include "Tools/interface/MCTools.h"
#include "Tools/interface/DirectionalCut.h"
#include "EventSelection/interface/CommonPlots.h"
#include "EventSelection/interface/EventSelections.h"

// ROOT
#include "TDirectory.h"
#include "Math/VectorUtil.h"

struct PtComparator
{
  bool operator() (const math::XYZTLorentzVector p1, const math::XYZTLorentzVector p2) const { return ( p1.pt() > p2.pt() ); }
};


class MetBreakDown: public BaseSelector {
public:
  explicit MetBreakDown(const ParameterSet& config, const TH1* skimCounters);
  virtual ~MetBreakDown() {}

  /// Books histograms
  virtual void book(TDirectory *dir) override;
  /// Sets up branches for reading the TTree
  virtual void setupBranches(BranchManager& branchManager) override;
  /// Called for each event
  virtual void process(Long64_t entry) override;

private:
  // Input parameters
  const double cfg_Verbose;
  const ParameterSet PSet_JetSelection;
  const double cfg_JetPtCut;
  const double cfg_JetEtaCut;
  const DirectionalCut<int> cfg_JetNumberCut;
  const ParameterSet PSet_ElectronSelection;
  const double cfg_ElectronPtCut;
  const double cfg_ElectronEtaCut;
  const DirectionalCut<int> cfg_ElectronNumberCut;
  const ParameterSet PSet_MuonSelection;
  const double cfg_MuonPtCut;
  const double cfg_MuonEtaCut;
  const DirectionalCut<int> cfg_MuonNumberCut;
  const ParameterSet PSet_HtSelection;
  const DirectionalCut<float> cfg_HtCut;
  const HistogramSettings cfg_PtBinSetting;
  const HistogramSettings cfg_EtaBinSetting;
  const HistogramSettings cfg_PhiBinSetting;
  const HistogramSettings cfg_MassBinSetting;
  const HistogramSettings cfg_DeltaEtaBinSetting;
  const HistogramSettings cfg_DeltaPhiBinSetting;
  const HistogramSettings cfg_DeltaRBinSetting;

  Tools auxTools;

  // Counters
  Count cAllEvents;
  Count cSubNoPreselections;
  Count cSubPassedLeptonVeto;
  Count cSubPassedJetsCut;
  Count cSubPassedHtCut;

  // Event Variables
  WrappedTH1 *h_genMET_Et;
  WrappedTH1 *h_genMET_Phi;
  WrappedTH1 *h_genHT_GenJets;

  // MET discriminators
  // lepton from W. Not checking for lepton from b
  WrappedTH1 *h_genMET_0leptonFromW_Et;
  WrappedTH1 *h_genMET_0leptonFromW_Phi;
  WrappedTH1 *h_genMET_1leptonFromW_Et;
  WrappedTH1 *h_genMET_1leptonFromW_Phi;
  WrappedTH1 *h_genMET_1_more_leptonFromW_Et;
  WrappedTH1 *h_genMET_1_more_leptonFromW_Phi;
  WrappedTH1 *h_genMET_2leptonFromW_Et;
  WrappedTH1 *h_genMET_2leptonFromW_Phi;
  WrappedTH1 *h_genMET_2_more_leptonFromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_2_more_leptonFromW_Phi; // two or more leptonic decays
  // semi-leptonic b decays
  WrappedTH1 *h_genMET_0leptonsFromB_Et;
  WrappedTH1 *h_genMET_0leptonsFromB_Phi;
  WrappedTH1 *h_genMET_1leptonsFromB_Et;
  WrappedTH1 *h_genMET_1leptonsFromB_Phi;
  WrappedTH1 *h_genMET_1_more_leptonsFromB_Et;
  WrappedTH1 *h_genMET_1_more_leptonsFromB_Phi;
  WrappedTH1 *h_genMET_2leptonsFromB_Et;
  WrappedTH1 *h_genMET_2leptonsFromB_Phi;
  WrappedTH1 *h_genMET_2_more_leptonsFromB_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_2_more_leptonsFromB_Phi; // two or more leptonic decays
  WrappedTH1 *h_genMET_3leptonsFromB_Et;
  WrappedTH1 *h_genMET_3leptonsFromB_Phi;
  WrappedTH1 *h_genMET_4leptonsFromB_Et;
  WrappedTH1 *h_genMET_4leptonsFromB_Phi;
  // combination of b and W
  WrappedTH1 *h_genMET_leptons_0FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_0FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_0FromB_1FromW_Et;
  WrappedTH1 *h_genMET_leptons_0FromB_1FromW_Phi;
  WrappedTH1 *h_genMET_leptons_0FromB_1_more_FromW_Et;
  WrappedTH1 *h_genMET_leptons_0FromB_1_more_FromW_Phi;
  WrappedTH1 *h_genMET_leptons_0FromB_2FromW_Et;
  WrappedTH1 *h_genMET_leptons_0FromB_2FromW_Phi;
  WrappedTH1 *h_genMET_leptons_0FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_0FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_genMET_leptons_1FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_1FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_1_more_FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_1_more_FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_1FromB_1FromW_Et;
  WrappedTH1 *h_genMET_leptons_1FromB_1FromW_Phi;
  WrappedTH1 *h_genMET_leptons_1_more_FromB_1_more_FromW_Et;
  WrappedTH1 *h_genMET_leptons_1_more_FromB_1_more_FromW_Phi;
  WrappedTH1 *h_genMET_leptons_1FromB_2FromW_Et;
  WrappedTH1 *h_genMET_leptons_1FromB_2FromW_Phi;
  WrappedTH1 *h_genMET_leptons_1FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_1FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_genMET_leptons_2FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_2FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_2FromB_1FromW_Et;
  WrappedTH1 *h_genMET_leptons_2FromB_1FromW_Phi;
  WrappedTH1 *h_genMET_leptons_2FromB_2FromW_Et;
  WrappedTH1 *h_genMET_leptons_2FromB_2FromW_Phi;
  WrappedTH1 *h_genMET_leptons_2_more_FromB_0FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_2_more_FromB_0FromW_Phi; // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_2_more_FromB_1FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_2_more_FromB_1FromW_Phi; // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_2_more_FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_genMET_leptons_2_more_FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_genMET_leptons_3FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_3FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_3FromB_1FromW_Et;
  WrappedTH1 *h_genMET_leptons_3FromB_1FromW_Phi;
  WrappedTH1 *h_genMET_leptons_3FromB_2FromW_Et;
  WrappedTH1 *h_genMET_leptons_3FromB_2FromW_Phi;

  WrappedTH1 *h_genMET_leptons_4FromB_0FromW_Et;
  WrappedTH1 *h_genMET_leptons_4FromB_0FromW_Phi;
  WrappedTH1 *h_genMET_leptons_4FromB_1FromW_Et;
  WrappedTH1 *h_genMET_leptons_4FromB_1FromW_Phi;
  WrappedTH1 *h_genMET_leptons_4FromB_2FromW_Et;
  WrappedTH1 *h_genMET_leptons_4FromB_2FromW_Phi;

  // leptons, does not matter who is the mother
  WrappedTH1 *h_genMET_1leptons_Et;
  WrappedTH1 *h_genMET_1leptons_Phi;
  WrappedTH1 *h_genMET_1_more_leptons_Et;
  WrappedTH1 *h_genMET_1_more_leptons_Phi;
  WrappedTH1 *h_genMET_2_more_leptons_Et;
  WrappedTH1 *h_genMET_2_more_leptons_Phi;

  // GenParticles: number of b quarks vs B Hadrons
  WrappedTH2 *h_genP_n_b_B;


  // RECO histos
  WrappedTH1 *h_recoMET_Et;
  WrappedTH1 *h_recoMET_Phi;

  // MET discriminators
  // lepton from W. Not checking for lepton from b
  WrappedTH1 *h_recoMET_0leptonFromW_Et;
  WrappedTH1 *h_recoMET_0leptonFromW_Phi;
  WrappedTH1 *h_recoMET_1leptonFromW_Et;
  WrappedTH1 *h_recoMET_1leptonFromW_Phi;
  WrappedTH1 *h_recoMET_1_more_leptonFromW_Et;
  WrappedTH1 *h_recoMET_1_more_leptonFromW_Phi;
  WrappedTH1 *h_recoMET_2leptonFromW_Et;
  WrappedTH1 *h_recoMET_2leptonFromW_Phi;
  WrappedTH1 *h_recoMET_2_more_leptonFromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_2_more_leptonFromW_Phi; // two or more leptonic decays
  // semi-leptonic b decays
  WrappedTH1 *h_recoMET_0leptonsFromB_Et;
  WrappedTH1 *h_recoMET_0leptonsFromB_Phi;
  WrappedTH1 *h_recoMET_1leptonsFromB_Et;
  WrappedTH1 *h_recoMET_1leptonsFromB_Phi;
  WrappedTH1 *h_recoMET_1_more_leptonsFromB_Et;
  WrappedTH1 *h_recoMET_1_more_leptonsFromB_Phi;
  WrappedTH1 *h_recoMET_2leptonsFromB_Et;
  WrappedTH1 *h_recoMET_2leptonsFromB_Phi;
  WrappedTH1 *h_recoMET_2_more_leptonsFromB_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_2_more_leptonsFromB_Phi; // two or more leptonic decays
  WrappedTH1 *h_recoMET_3leptonsFromB_Et;
  WrappedTH1 *h_recoMET_3leptonsFromB_Phi;
  WrappedTH1 *h_recoMET_4leptonsFromB_Et;
  WrappedTH1 *h_recoMET_4leptonsFromB_Phi;
  // combination of b and W
  WrappedTH1 *h_recoMET_leptons_0FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_0FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_0FromB_1FromW_Et;
  WrappedTH1 *h_recoMET_leptons_0FromB_1FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_0FromB_1_more_FromW_Et;
  WrappedTH1 *h_recoMET_leptons_0FromB_1_more_FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_0FromB_2FromW_Et;
  WrappedTH1 *h_recoMET_leptons_0FromB_2FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_0FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_0FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_recoMET_leptons_1FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_1FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_1_more_FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_1_more_FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_1FromB_1FromW_Et;
  WrappedTH1 *h_recoMET_leptons_1FromB_1FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_1_more_FromB_1_more_FromW_Et;
  WrappedTH1 *h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_1FromB_2FromW_Et;
  WrappedTH1 *h_recoMET_leptons_1FromB_2FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_1FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_1FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_recoMET_leptons_2FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_2FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_2FromB_1FromW_Et;
  WrappedTH1 *h_recoMET_leptons_2FromB_1FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_2FromB_2FromW_Et;
  WrappedTH1 *h_recoMET_leptons_2FromB_2FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_0FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_0FromW_Phi; // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_1FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_1FromW_Phi; // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_2_more_FromW_Et;  // two or more leptonic decays
  WrappedTH1 *h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi; // two or more leptonic decays

  WrappedTH1 *h_recoMET_leptons_3FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_3FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_3FromB_1FromW_Et;
  WrappedTH1 *h_recoMET_leptons_3FromB_1FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_3FromB_2FromW_Et;
  WrappedTH1 *h_recoMET_leptons_3FromB_2FromW_Phi;

  WrappedTH1 *h_recoMET_leptons_4FromB_0FromW_Et;
  WrappedTH1 *h_recoMET_leptons_4FromB_0FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_4FromB_1FromW_Et;
  WrappedTH1 *h_recoMET_leptons_4FromB_1FromW_Phi;
  WrappedTH1 *h_recoMET_leptons_4FromB_2FromW_Et;
  WrappedTH1 *h_recoMET_leptons_4FromB_2FromW_Phi;

  // leptons, does not matter who is the mother
  WrappedTH1 *h_recoMET_1leptons_Et;
  WrappedTH1 *h_recoMET_1leptons_Phi;
  WrappedTH1 *h_recoMET_1_more_leptons_Et;
  WrappedTH1 *h_recoMET_1_more_leptons_Phi;
  WrappedTH1 *h_recoMET_2_more_leptons_Et;
  WrappedTH1 *h_recoMET_2_more_leptons_Phi;



























  // TODO remove all histos below this line
  // GenParticles: BQuarks
  WrappedTH1 *h_BQuarks_N;
  WrappedTH1 *h_BQuark1_Pt;
  WrappedTH1 *h_BQuark2_Pt;
  WrappedTH1 *h_BQuark3_Pt;
  WrappedTH1 *h_BQuark4_Pt;
  //
  WrappedTH1 *h_BQuark1_Eta;
  WrappedTH1 *h_BQuark2_Eta;
  WrappedTH1 *h_BQuark3_Eta;
  WrappedTH1 *h_BQuark4_Eta;

  // GenParticles: BQuarks pair closest together
  WrappedTH1 *h_BQuarkPair_dRMin_pT;
  WrappedTH1 *h_BQuarkPair_dRMin_dEta;
  WrappedTH1 *h_BQuarkPair_dRMin_dPhi;
  WrappedTH1 *h_BQuarkPair_dRMin_dR;
  WrappedTH1 *h_BQuarkPair_dRMin_Mass;
  WrappedTH2 *h_BQuarkPair_dRMin_Eta1_Vs_Eta2;
  WrappedTH2 *h_BQuarkPair_dRMin_Phi1_Vs_Phi2;
  WrappedTH2 *h_BQuarkPair_dRMin_Pt1_Vs_Pt2;
  WrappedTH2 *h_BQuarkPair_dRMin_dEta_Vs_dPhi;
  WrappedTH1 *h_BQuarkPair_dRMin_jet1_dR;
  WrappedTH1 *h_BQuarkPair_dRMin_jet1_dEta;
  WrappedTH1 *h_BQuarkPair_dRMin_jet1_dPhi;
  WrappedTH1 *h_BQuarkPair_dRMin_jet2_dR;
  WrappedTH1 *h_BQuarkPair_dRMin_jet2_dEta;
  WrappedTH1 *h_BQuarkPair_dRMin_jet2_dPhi;

  // GenParticles: bqq trijet system (H+)
  WrappedTH1 *h_tbWPlus_bqq_Pt;
  WrappedTH1 *h_tbWPlus_bqq_Rap;
  WrappedTH1 *h_tbWPlus_bqq_Mass;
  WrappedTH1 *h_tbWPlus_bqq_dRMax_dR;
  WrappedTH1 *h_tbWPlus_bqq_dRMax_dRap;
  WrappedTH1 *h_tbWPlus_bqq_dRMax_dPhi;
  WrappedTH2 *h_tbWPlus_bqq_dRMax_dRap_Vs_dPhi;

  // GenParticles: bqq trijet system (associated top)
  WrappedTH1 *h_tbWMinus_bqq_Pt;
  WrappedTH1 *h_tbWMinus_bqq_Rap;
  WrappedTH1 *h_tbWMinus_bqq_Mass;
  WrappedTH1 *h_tbWMinus_bqq_dRMax_dR;
  WrappedTH1 *h_tbWMinus_bqq_dRMax_dRap;
  WrappedTH1 *h_tbWMinus_bqq_dRMax_dPhi;
  WrappedTH2 *h_tbWMinus_bqq_dRMax_dRap_Vs_dPhi;

  // GenJets
  WrappedTH1 *h_GenJet_N_NoPreselections;
  WrappedTH1 *h_GenJet_N_AfterLeptonVeto;
  WrappedTH1 *h_GenJet_N_AfterLeptonVetoNJetsCut;
  WrappedTH1 *h_GenJet_N_AfterPreselections;

  WrappedTH1 *h_GenJet1_Pt;
  WrappedTH1 *h_GenJet2_Pt;
  WrappedTH1 *h_GenJet3_Pt;
  WrappedTH1 *h_GenJet4_Pt;
  WrappedTH1 *h_GenJet5_Pt;
  WrappedTH1 *h_GenJet6_Pt;
  //
  WrappedTH1 *h_GenJet1_Eta;
  WrappedTH1 *h_GenJet2_Eta;
  WrappedTH1 *h_GenJet3_Eta;
  WrappedTH1 *h_GenJet4_Eta;
  WrappedTH1 *h_GenJet5_Eta;
  WrappedTH1 *h_GenJet6_Eta;


  // GenJets: Dijet with largest mass
  WrappedTH1 *h_MaxDiJetMass_Pt;
  WrappedTH1 *h_MaxDiJetMass_Eta;
  WrappedTH1 *h_MaxDiJetMass_Rap;
  WrappedTH1 *h_MaxDiJetMass_Mass;
  WrappedTH1 *h_MaxDiJetMass_dR;
  WrappedTH1 *h_MaxDiJetMass_dRrap;
  WrappedTH1 *h_MaxDiJetMass_dEta;
  WrappedTH1 *h_MaxDiJetMass_dPhi;
  WrappedTH1 *h_MaxDiJetMass_dRap;
  WrappedTH2 *h_MaxDiJetMass_dEta_Vs_dPhi;
  WrappedTH2 *h_MaxDiJetMass_dRap_Vs_dPhi;

  // Correlations
  WrappedTH2 *h_BQuark1_BQuark2_dEta_Vs_dPhi;
  WrappedTH2 *h_BQuark1_BQuark3_dEta_Vs_dPhi;
  WrappedTH2 *h_BQuark1_BQuark4_dEta_Vs_dPhi;
  WrappedTH2 *h_BQuark2_BQuark3_dEta_Vs_dPhi;
  WrappedTH2 *h_BQuark2_BQuark4_dEta_Vs_dPhi;
  WrappedTH2 *h_BQuark3_BQuark4_dEta_Vs_dPhi;

  WrappedTH2 *h_Jet1Jet2_dEta_Vs_Jet3Jet4_dEta;
  WrappedTH2 *h_Jet1Jet2_dPhi_Vs_Jet3Jet4_dPhi;
  WrappedTH2 *h_Jet1Jet2_dEta_Vs_Jet1Jet2_Mass;
  WrappedTH2 *h_Jet3Jet4_dEta_Vs_Jet3Jet4_Mass;

};

#include "Framework/interface/SelectorFactory.h"
REGISTER_SELECTOR(MetBreakDown);

MetBreakDown::MetBreakDown(const ParameterSet& config, const TH1* skimCounters)
  : BaseSelector(config, skimCounters),
    cfg_Verbose(config.getParameter<bool>("verbose")),
    PSet_JetSelection(config.getParameter<ParameterSet>("JetSelection")),
    cfg_JetPtCut(config.getParameter<float>("JetSelection.jetPtCut")),
    cfg_JetEtaCut(config.getParameter<float>("JetSelection.jetEtaCut")),
    cfg_JetNumberCut(config, "JetSelection.jetNCut"),
    PSet_ElectronSelection(config.getParameter<ParameterSet>("ElectronSelection")),
    cfg_ElectronPtCut(config.getParameter<float>("ElectronSelection.electronPtCut")),
    cfg_ElectronEtaCut(config.getParameter<float>("ElectronSelection.electronEtaCut")),
    cfg_ElectronNumberCut(config, "ElectronSelection.electronNCut"),
    PSet_MuonSelection(config.getParameter<ParameterSet>("MuonSelection")),
    cfg_MuonPtCut(config.getParameter<float>("MuonSelection.muonPtCut")),
    cfg_MuonEtaCut(config.getParameter<float>("MuonSelection.muonEtaCut")),
    cfg_MuonNumberCut(config, "MuonSelection.muonNCut"),
    PSet_HtSelection(config.getParameter<ParameterSet>("HtSelection")),
    cfg_HtCut(config, "HtSelection.HtCut"),
    cfg_PtBinSetting(config.getParameter<ParameterSet>("CommonPlots.ptBins")),
    cfg_EtaBinSetting(config.getParameter<ParameterSet>("CommonPlots.etaBins")),
    cfg_PhiBinSetting(config.getParameter<ParameterSet>("CommonPlots.phiBins")),
    cfg_MassBinSetting(config.getParameter<ParameterSet>("CommonPlots.invmassBins")),
    cfg_DeltaEtaBinSetting(config.getParameter<ParameterSet>("CommonPlots.deltaEtaBins")),
    cfg_DeltaPhiBinSetting(config.getParameter<ParameterSet>("CommonPlots.deltaPhiBins")),
    cfg_DeltaRBinSetting(config.getParameter<ParameterSet>("CommonPlots.deltaRBins")),
    cAllEvents(fEventCounter.addCounter("All events")),
    cSubNoPreselections(fEventCounter.addSubCounter("Preselections", "All Events")),
    cSubPassedLeptonVeto(fEventCounter.addSubCounter("Preselections", "Lepton Veto")),
    cSubPassedJetsCut(fEventCounter.addSubCounter("Preselections", "Jets Cut")),
    cSubPassedHtCut(fEventCounter.addSubCounter("Preselections","HT Cut"))
{ }

void MetBreakDown::book(TDirectory *dir) {

  Table cuts("Variable | Jets | Electron | Muon | HT", "Text"); //LaTeX or Text
  cuts.AddRowColumn(0, "Pt (GeV/c)");
  cuts.AddRowColumn(1, "Eta");
  cuts.AddRowColumn(2, "Cut Direction");
  cuts.AddRowColumn(3, "Cut Value");
  //
  cuts.AddRowColumn(0, auxTools.ToString(cfg_JetPtCut) );
  cuts.AddRowColumn(0, auxTools.ToString(cfg_ElectronPtCut) );
  cuts.AddRowColumn(0, auxTools.ToString(cfg_MuonPtCut) );
  cuts.AddRowColumn(0, "-");
  //
  cuts.AddRowColumn(1, auxTools.ToString(cfg_JetEtaCut) );
  cuts.AddRowColumn(1, auxTools.ToString(cfg_ElectronEtaCut) );
  cuts.AddRowColumn(1, auxTools.ToString(cfg_MuonEtaCut) );
  cuts.AddRowColumn(1, "-");
  //
  cuts.AddRowColumn(2, PSet_JetSelection.getParameter<string>("jetNCutDirection") );
  cuts.AddRowColumn(2, PSet_ElectronSelection.getParameter<string>("electronNCutDirection") );
  cuts.AddRowColumn(2, PSet_MuonSelection.getParameter<string>("muonNCutDirection") );
  cuts.AddRowColumn(2, PSet_HtSelection.getParameter<string>("HtCutDirection") );
  //
  cuts.AddRowColumn(3, auxTools.ToString(PSet_JetSelection.getParameter<int>("jetNCutValue")) );
  cuts.AddRowColumn(3, auxTools.ToString(PSet_ElectronSelection.getParameter<int>("electronNCutValue")) );
  cuts.AddRowColumn(3, auxTools.ToString(PSet_MuonSelection.getParameter<int>("muonNCutValue")) );
  cuts.AddRowColumn(3, PSet_HtSelection.getParameter<string>("HtCutValue") );
  //
  std::cout << "\n" << std::endl;
  cuts.Print();


  // Fixed binning
  const int nBinsMet   = 30;
  const double minMet  = 0;
  const double maxMet  = 300;

  const int nBinsPt   = cfg_PtBinSetting.bins();
  const double minPt  = cfg_PtBinSetting.min();
  const double maxPt  = cfg_PtBinSetting.max();

  const int nBinsEta  = cfg_EtaBinSetting.bins();
  const double minEta = cfg_EtaBinSetting.min();
  const double maxEta = cfg_EtaBinSetting.max();

  const int nBinsRap  = cfg_EtaBinSetting.bins();
  const double minRap = cfg_EtaBinSetting.min();
  const double maxRap = cfg_EtaBinSetting.max();

  const int nBinsPhi  = cfg_PhiBinSetting.bins();
  const double minPhi = cfg_PhiBinSetting.min();
  const double maxPhi = cfg_PhiBinSetting.max();

  const int nBinsM  = cfg_MassBinSetting.bins();
  const double minM = cfg_MassBinSetting.min();
  const double maxM = cfg_MassBinSetting.max();

  const int nBinsdEta  = cfg_DeltaEtaBinSetting.bins();
  const double mindEta = cfg_DeltaEtaBinSetting.min();
  const double maxdEta = cfg_DeltaEtaBinSetting.max();

  const int nBinsdRap  = cfg_DeltaEtaBinSetting.bins();
  const double mindRap = cfg_DeltaEtaBinSetting.min();
  const double maxdRap = cfg_DeltaEtaBinSetting.max();

  const int nBinsdPhi  = cfg_DeltaPhiBinSetting.bins();
  const double mindPhi = cfg_DeltaPhiBinSetting.min();
  const double maxdPhi = cfg_DeltaPhiBinSetting.max();

  const int nBinsdR  = cfg_DeltaRBinSetting.bins();
  const double mindR = cfg_DeltaRBinSetting.min();
  const double maxdR = cfg_DeltaRBinSetting.max();


  // Event Variables
  h_genMET_Et         =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_Et"          , ";Gen E_{T}^{miss} (GeV)",              nBinsMet, minMet, maxMet);
  h_genMET_Phi        =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_Phi"         , ";Gen E_{T}^{miss} #phi (rads)" , nBinsPhi, minPhi, maxPhi);
  h_genHT_GenJets     =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genHT_GenJets"      , ";GenJ H_{T} (GeV)"             ,  75,  0.0, +1500.0);

  // MET analysis
  h_genMET_0leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_0leptonFromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_0leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_0leptonFromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_1leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptonFromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptonFromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_1_more_leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptonFromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1_more_leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptonFromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_2leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2leptonFromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_2leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2leptonFromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_2_more_leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptonFromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_2_more_leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptonFromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_0leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_0leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_0leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_0leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_1leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_1_more_leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1_more_leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_2leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_2leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_3leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_3leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_3leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_3leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_4leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_4leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_4leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_4leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_2_more_leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptonFromB_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_2_more_leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptonFromB_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_0FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_0FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_0FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_0FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_0FromB_1_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_1_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_0FromB_1_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_1_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_0FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_2FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_0FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_2FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_0FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_2_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_0FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_0FromB_2_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_1FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_1_more_FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1_more_FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1_more_FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1_more_FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_1FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_1_more_FromB_1_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1F_more_romB_1_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1_more_FromB_1_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1F_more_romB_1_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_1FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_2FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_2FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_1FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_2_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1FromB_2_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_2FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_2FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_2FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_2FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2FromB_2FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_2_more_FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2_more_FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_2_more_FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2_more_FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_2_more_FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_2_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_2_more_FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_2_more_FromB_2_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_3FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_3FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_3FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_3FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_3FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_2FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_3FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_3FromB_2FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_leptons_4FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_0FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_4FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_0FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_4FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_1FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_4FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_1FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_leptons_4FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_2FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_4FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_4FromB_2FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_genMET_1leptons_Et        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptons_Et",        ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1leptons_Phi       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1leptons_Phi",       ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_1_more_leptons_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptons_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_1_more_leptons_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_1_more_leptons_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_genMET_2_more_leptons_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptons_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_2_more_leptons_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_2_more_leptons_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  // GenParticles: number of b quarks vs B Hadrons
  h_genP_n_b_B = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "genP_n_b_B", ";#N b;#N B", 8, 0, 8, 8, 0, 8);


  // reco analysis
  h_recoMET_Et         =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_Et"          , ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_Phi        =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_Phi"         , ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_0leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_0leptonFromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_0leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_0leptonFromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_1leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1leptonFromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1leptonFromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_1_more_leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1_more_leptonFromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1_more_leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1_more_leptonFromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_2leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_2leptonFromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_2leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_2leptonFromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_2_more_leptonFromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptonFromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_2_more_leptonFromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptonFromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_0leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_0leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_0leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_0leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_1leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_1_more_leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1_more_leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1_more_leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_1_more_leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_2leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_2leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_2leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_2leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_3leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_3leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_3leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_3leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_4leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_4leptonFromB_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_4leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_4leptonFromB_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_2_more_leptonsFromB_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptonFromB_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_2_more_leptonsFromB_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptonFromB_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_0FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_0FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_0FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_0FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_0FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_1FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_0FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_1FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_0FromB_1_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_1_more_FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_0FromB_1_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_1_more_FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_0FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_2FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_0FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_0FromB_2FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_0FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_0FromB_2_more_FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_0FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_0FromB_2_more_FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_1FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_0FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_0FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_1_more_FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1_more_FromB_0FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1_more_FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1_more_FromB_0FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_1FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_1FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_1FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_1_more_FromB_1_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1_more_FromB_1_more_FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1_more_FromB_1_more_FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_1FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_2FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_1FromB_2FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_1FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_1FromB_2_more_FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_1FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_1FromB_2_more_FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_2FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_0FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_0FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_2FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_1FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_1FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_2FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_2FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2FromB_2FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_2_more_FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_2_more_FromB_0FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2_more_FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_2_more_FromB_0FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_2_more_FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_2_more_FromB_1FromW_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2_more_FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital,       dir, "recoMET_leptons_2_more_FromB_1FromW_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_2_more_FromB_2_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2_more_FromB_2_more_FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_2_more_FromB_2_more_FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_3FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_0FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_3FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_0FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_3FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_1FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_3FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_1FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_3FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_2FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_3FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_3FromB_2FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_leptons_4FromB_0FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_0FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_4FromB_0FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_0FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_4FromB_1FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_1FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_4FromB_1FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_1FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_leptons_4FromB_2FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_2FromW_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_leptons_4FromB_2FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_leptons_4FromB_2FromW_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

  h_recoMET_1leptons_Et        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_1leptons_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1leptons_Phi       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_1leptons_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_1_more_leptons_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_1_more_leptons_Et",        ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_1_more_leptons_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_1_more_leptons_Phi",       ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
  h_recoMET_2_more_leptons_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptons_Et",  ";Reco E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_recoMET_2_more_leptons_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMET_2_more_leptons_Phi", ";Reco E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);

















  // GenParticles: B-quarks
  h_BQuarks_N   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarks_N" , ";N (b-quarks)" , 10, -0.5, +9.5);
  h_BQuark1_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark1_Pt", ";p_{T} (GeV/c)" , nBinsPt, minPt, maxPt);
  h_BQuark2_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark2_Pt", ";p_{T} (GeV/c)" , nBinsPt, minPt, maxPt);
  h_BQuark3_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark3_Pt", ";p_{T} (GeV/c)" , nBinsPt, minPt, maxPt);
  h_BQuark4_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark4_Pt", ";p_{T} (GeV/c)" , nBinsPt, minPt, maxPt);

  h_BQuark1_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark1_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_BQuark2_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark2_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_BQuark3_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark3_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_BQuark4_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuark4_Eta", ";#eta", nBinsEta, minEta, maxEta);

  // GenParticles: BQuarks pair closest together
  h_BQuarkPair_dRMin_pT        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_pT"       , ";p_{T} (GeV/c)"     ,  nBinsPt  , minPt  , maxPt  );
  h_BQuarkPair_dRMin_dEta      = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_dEta"     , ";#Delta#eta"        ,  nBinsdEta, mindEta, maxdEta);
  h_BQuarkPair_dRMin_dPhi      = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_dPhi"     , ";#Delta#phi (rads)" ,  nBinsdPhi, mindPhi, maxdPhi);
  h_BQuarkPair_dRMin_dR        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_dR"       , ";#DeltaR"           ,  nBinsdR  , mindR  , maxdR  );
  h_BQuarkPair_dRMin_Mass      = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_Mass"     , ";M (GeV/c^{2})"     ,  nBinsM   , minM   , maxM   );
  h_BQuarkPair_dRMin_jet1_dEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet1_dEta", ";#Delta#eta"        ,  nBinsdEta, mindEta, maxdEta);
  h_BQuarkPair_dRMin_jet1_dPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet1_dPhi", ";#Delta#phi (rads)" ,  nBinsdPhi, mindPhi, maxdPhi);
  h_BQuarkPair_dRMin_jet1_dR   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet1_dR"  , ";#DeltaR"           ,  nBinsdR  , mindR  , maxdR  );
  h_BQuarkPair_dRMin_jet2_dEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet2_dEta", ";#Delta#eta"        ,  nBinsdEta, mindEta, maxdEta);
  h_BQuarkPair_dRMin_jet2_dPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet2_dPhi", ";#Delta#phi (rads)" ,  nBinsdPhi, mindPhi, maxdPhi);
  h_BQuarkPair_dRMin_jet2_dR   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_jet2_dR"  , ";#DeltaR"           ,  nBinsdR  , mindR  , maxdR  );
  //
  h_BQuarkPair_dRMin_Eta1_Vs_Eta2 = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_Eta1_Vs_Eta2", ";#eta;#eta", nBinsEta, minEta, maxEta, nBinsEta, minEta, maxEta);
  h_BQuarkPair_dRMin_Phi1_Vs_Phi2 = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_Phi1_Vs_Phi2", ";#phi;#phi", nBinsPhi, minPhi, maxPhi, nBinsPhi, minPhi, maxPhi);
  h_BQuarkPair_dRMin_Pt1_Vs_Pt2   = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_Pt1_Vs_Pt2"  , ";p_{T} (GeV/c); p_{T} (GeV/c)", nBinsPt, minPt, maxPt, nBinsPt, minPt, maxPt);
  h_BQuarkPair_dRMin_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuarkPair_dRMin_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);

  // GenParticles: bqq trijet system (W+)
  h_tbWPlus_bqq_Pt         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_Pt"   , ";p_{T} (GeV/c)"    ,  nBinsPt, minPt, maxPt);
  h_tbWPlus_bqq_Rap        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_Rap"  , ";#omega"           ,  nBinsRap, minRap, maxRap);
  h_tbWPlus_bqq_Mass       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_Mass" , ";M (GeV/c^{2})"    ,  nBinsM, minM, maxM);
  h_tbWPlus_bqq_dRMax_dPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_dRMax_dPhi" , ";#Delta#phi (rads)",  nBinsdPhi, mindPhi, maxdPhi);
  h_tbWPlus_bqq_dRMax_dRap = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_dRMax_dRap" , ";#Delta#omega"     ,  nBinsdRap, mindRap, maxdRap);
  h_tbWPlus_bqq_dRMax_dR   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWPlus_bqq_dRMax_dR"   , ";#DeltaR"          ,  nBinsdR, mindR, maxdR);
  //
  h_tbWPlus_bqq_dRMax_dRap_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "tbWPlus_bqq_dRMax_dRap_Vs_dPhi", ";#Delta#omega;#Delta#phi (rads)", nBinsdRap, mindRap, maxdRap, nBinsdPhi, mindPhi, maxdPhi);

  // GenParticles: bqq trijet system (W-)
  h_tbWMinus_bqq_Pt         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_Pt"   , ";p_{T} (GeV/c^{2})",  nBinsPt, minPt, maxPt);
  h_tbWMinus_bqq_Rap        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_Rap"  , ";#omega"           ,  nBinsRap, minRap, maxRap);
  h_tbWMinus_bqq_Mass       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_Mass" , ";M (GeV/c^{2})"    ,  nBinsM, minM, maxM);
  //
  h_tbWMinus_bqq_dRMax_dPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_dRMax_dPhi", ";#Delta#phi (rads)",  nBinsdPhi, mindPhi, maxdPhi);
  h_tbWMinus_bqq_dRMax_dRap = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_dRMax_dRap", ";#Delta#omega"     ,  nBinsdRap, mindRap, maxdRap);
  h_tbWMinus_bqq_dRMax_dR   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "tbWMinus_bqq_dRMax_dR"  , ";#DeltaR"          ,  nBinsdR, mindR, maxdR);
  h_tbWMinus_bqq_dRMax_dRap_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "tbWMinus_bqq_dRMax_dRap_Vs_dPhi", ";#Delta#omega;#Delta#phi (rads)", nBinsdRap, mindRap, maxdRap, nBinsdPhi, mindPhi, maxdPhi);

  // Leading Jets
  h_Jet1Jet2_dEta_Vs_Jet3Jet4_dEta = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "Jet1Jet2_dEta_Vs_Jet3Jet4_dEta", ";#Delta#eta(j_{1},j_{2});#Delta#eta(j_{3},j_{4})", nBinsdEta, mindEta, maxdEta, nBinsdEta, mindEta, maxdEta);

  h_Jet1Jet2_dPhi_Vs_Jet3Jet4_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "Jet1Jet2_dPhi_Vs_Jet3Jet4_dPhi", ";#Delta#phi(j_{1},j_{2}) (rads);#Delta#phi(j_{3},j_{4}) (rads)", nBinsdPhi, mindPhi, maxdPhi, nBinsdPhi, mindPhi, maxdPhi);

  h_Jet1Jet2_dEta_Vs_Jet1Jet2_Mass = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "Jet1Jet2_dEta_Vs_Jet1Jet2_Mass", ";#Delta#eta(j_{1},j_{2});M(j_{1},j_{2}) (GeV/c^{2})", nBinsdEta, mindEta, maxdEta, nBinsM, minM, maxM);

  h_Jet3Jet4_dEta_Vs_Jet3Jet4_Mass = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "Jet3Jet4_dEta_Vs_Jet3Jet4_Mass", ";#Delta#eta(j_{3},j_{4});M(j_{4},j_{4}) (GeV/c^{2})", nBinsdEta, mindEta, maxdEta, nBinsM, minM, maxM);

  // GenJets
  h_GenJet_N_NoPreselections         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_NoPreselections"        , ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterLeptonVeto         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterLeptonVeto"        , ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterLeptonVetoNJetsCut = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterLeptonVetoNJetsCut", ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterPreselections      = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterPreselections"     , ";N (selected jets)" , 16, -0.5, +15.5);
  //
  h_GenJet1_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet1_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  h_GenJet2_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet2_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  h_GenJet3_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet3_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  h_GenJet4_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet4_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  h_GenJet5_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet5_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  h_GenJet6_Pt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet6_Pt", ";p_{T} (GeV/c)", nBinsPt, minPt, maxPt);
  //
  h_GenJet1_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet1_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_GenJet2_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet2_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_GenJet3_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet3_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_GenJet4_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet4_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_GenJet5_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet5_Eta", ";#eta", nBinsEta, minEta, maxEta);
  h_GenJet6_Eta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet6_Eta", ";#eta", nBinsEta, minEta, maxEta);

  // GenJets: Dijet with largest mass
  h_MaxDiJetMass_Pt    = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_Pt"   , ";p_{T} (GeV/c)"    , nBinsPt, minPt, maxPt);
  h_MaxDiJetMass_Eta   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_Eta"  , ";#eta"             , nBinsEta, minEta, maxEta);
  h_MaxDiJetMass_Rap   = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_Rap"  , ";#omega"           , nBinsRap, minRap, maxRap);
  h_MaxDiJetMass_Mass  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_Mass" , ";M (GeV/c^{2})"    , 50,  0.0, +1000.0);
  h_MaxDiJetMass_dEta  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dEta" , ";#Delta#eta"       , nBinsdEta, mindEta, maxdEta);
  h_MaxDiJetMass_dRap  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dRap" , ";#Delta#omega"     , nBinsdRap, mindRap, maxdRap);
  h_MaxDiJetMass_dPhi  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dPhi" , ";#Delta#phi"       , nBinsdPhi, mindPhi, maxdPhi);
  h_MaxDiJetMass_dR    = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dR"   , ";#DeltaR"          , nBinsdR, mindR, maxdR);
  h_MaxDiJetMass_dRrap = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dRrap", ";#DeltaR_{#omega}" , nBinsdR, mindR, maxdR);
  h_MaxDiJetMass_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)"  , nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_MaxDiJetMass_dRap_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kInformative, dir, "MaxDiJetMass_dRap_Vs_dPhi", ";#Delta#omega;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);

  // Correlations
  h_BQuark1_BQuark2_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark1_BQuark2_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_BQuark1_BQuark3_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark1_BQuark3_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_BQuark1_BQuark4_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark1_BQuark4_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_BQuark2_BQuark3_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark2_BQuark3_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_BQuark2_BQuark4_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark2_BQuark4_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);
  h_BQuark3_BQuark4_dEta_Vs_dPhi = fHistoWrapper.makeTH<TH2F>(HistoLevel::kVital, dir, "BQuark3_BQuark4_dEta_Vs_dPhi", ";#Delta#eta;#Delta#phi (rads)", nBinsdEta, mindEta, maxdEta, nBinsdPhi, mindPhi, maxdPhi);

  return;
}

void MetBreakDown::setupBranches(BranchManager& branchManager) {
  fEvent.setupBranches(branchManager);
}


void MetBreakDown::process(Long64_t entry) {

  if ( !fEvent.isMC() ) return;

  // Increment Counter(s)
  cAllEvents.increment();

  MCTools mcTools(fEvent);

  ///////////////////////////////////////////////////////////////////////////
  // GenJets Calculations
  ///////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== GenJets" << std::endl;
  std::vector<math::XYZTLorentzVector> selJets_p4;
  int nSelJets   = 0;
  double genJ_HT = 0.0;

  // For-loop: GenJets
  for(GenJet j: fEvent.genjets()) {

    math::XYZTLorentzVector genJ_p4;
    genJ_p4 = j.p4();
    double genJ_pt     = j.pt();
    double genJ_eta    = j.eta();

    // Apply selection cuts
    if (genJ_pt < cfg_JetPtCut) continue;
    if (std::abs(genJ_eta) > cfg_JetEtaCut) continue;

    // Do calculations
    nSelJets++;
    selJets_p4.push_back( genJ_p4 );
    genJ_HT += genJ_pt;
  }


  ///////////////////////////////////////////////////////////////////////////
  // Lepton Veto & Primary Vertex
  ///////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== Lepton Veto & Primary Vertex" << std::endl;
  int nElectrons = 0;
  int nMuons     = 0;
  bool foundPV   = false;
  ROOT::Math::XYZPoint pv;

  // For-loop: All genParticles
  for (auto& p: fEvent.genparticles().getGenParticles()) {

    // Find the PV. Only consider particles that are part of the hard process
    if (!foundPV)
      {
	if ( p.isHardProcess() )
	  {
	    // pv.SetXYZ( p.vtxX(), p.vtxY(), p.vtxZ() );
	    pv.SetXYZ(0, 0, 0);
	    foundPV = true;
	  }
      }

    // Find leptons for vetoing
    if (!p.isLastCopy()) continue;
    if( !mcTools.IsLepton(p.pdgId()) ) continue;

    // mcTools.PrintGenParticle(p);
    // mcTools.PrintGenDaughters(p);

    if ( std::abs(p.pdgId()) == 11)
      {
	if ( (p.pt() >= cfg_ElectronPtCut) && ( std::abs(p.eta()) <= cfg_ElectronEtaCut) ) nElectrons++;
      }
    else if ( std::abs(p.pdgId()) == 13)
      {
	if ( (p.pt() >= cfg_MuonPtCut) && ( std::abs(p.eta()) <= cfg_MuonEtaCut) ) nMuons++;
      }
    else continue;

  }

  ///////////////////////////////////////////////////////////////////////////
  // Preselection Cuts (python/parameters/hplus2tbAnalysis.py)
  ///////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== Preselection Cuts" << std::endl;
  cSubNoPreselections.increment();
  h_GenJet_N_NoPreselections->Fill(nSelJets);

  // Lepton Veto
  if ( !cfg_ElectronNumberCut.passedCut(nElectrons) ) return;
  if ( !cfg_MuonNumberCut.passedCut(nMuons) ) return;
  cSubPassedLeptonVeto.increment();
  h_GenJet_N_AfterLeptonVeto->Fill(nSelJets);

  // Jet Selection
  if ( !cfg_JetNumberCut.passedCut(nSelJets) ) return;
  cSubPassedJetsCut.increment();
  h_GenJet_N_AfterLeptonVetoNJetsCut->Fill(nSelJets);

  // HT Selection
  if ( !cfg_HtCut.passedCut(genJ_HT) ) return;
  cSubPassedHtCut.increment();
  h_GenJet_N_AfterPreselections->Fill(nSelJets);


  ///////////////////////////////////////////////////////////////////////////
  // GenParticles
  ///////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== GenParticles" << std::endl;
  std::vector<math::XYZTLorentzVector> bQuarks_p4;
  math::XYZTLorentzVector tbWPlus_BQuark_p4;
  math::XYZTLorentzVector tbWPlus_Wqq_Quark_p4;
  math::XYZTLorentzVector tbWPlus_Wqq_AntiQuark_p4;
  math::XYZTLorentzVector tbWMinus_BQuark_p4;
  math::XYZTLorentzVector tbWMinus_Wqq_Quark_p4;
  math::XYZTLorentzVector tbWMinus_Wqq_AntiQuark_p4;

  // counters
  short lepton_from_Wplus = 0;
  short lepton_from_Wminus = 0;
  short lepton_from_B = 0;
  short bQuarks =  0;
  short BHadrons = 0;

  // Define the table
  Table table("Evt | Index | PdgId | Status | Charge | Pt | Eta | Phi | E | Vertex (mm) | Lxy (mm) | d0 (mm) | Mothers | Daughters |", "Text"); //LaTeX or Text
  int row = 0;
  // For-loop: GenParticles
  for (auto& p: fEvent.genparticles().getGenParticles()) {

    // Create the genParticles
    // genParticle p = fEvent.genparticles().getGenParticles()[genP_index];
    genParticle m;
    genParticle d;

    // mcTools.PrintGenParticle(p);
    // mcTools.PrintGenDaughters(p);

    // Particle properties
    short genP_index   = p.index();
    int genP_pdgId     = p.pdgId();
    int genP_status    = p.status();
    double genP_pt     = p.pt();
    double genP_eta    = p.eta();
    double genP_phi    = p.phi();
    double genP_energy = p.e();
    int genP_charge    = p.charge();
    //ROOT::Math::XYZPoint genP_vtx(p.vtxX()*10, p.vtxY()*10, p.vtxZ()*10); //in mm
    math::XYZTLorentzVector genP_p4;
    genP_p4 = p.p4();

    // Get vectors for mom/daus
    std::vector<short> genP_mothers   = p.mothers();
    std::vector<short> genP_daughters = p.daughters();

    // Assign mother/daughers for Lxy & d0 calculation
    if (genP_mothers.size() > 0  ) m = fEvent.genparticles().getGenParticles()[genP_mothers.at(0)];
    if (genP_daughters.size() > 0) d = fEvent.genparticles().getGenParticles()[genP_daughters.at(0)];
    // double genP_Lxy = mcTools.GetLxy(p, m, d, pv);
    // double genP_d0  = mcTools.GetD0( p, m, d, pv);

    // Filtering
    if (!p.isLastCopy()) continue;
    // if ( !mcTools.IsQuark(genP_pdgId) ) continue;
    // if (!p.isPrompt()) continue;
    // if (!p.isPromptDecayed()) continue;
    // if (!p.isPromptFinalState()) continue;
    // if (!p.isDecayedLeptonHadron()) continue;
    // if (!p.isTauDecayProduct()) continue;
    // if (!p.isPromptTauDecayProduct()) continue;
    // if (!p.isDirectTauDecayProduct()) continue;
    // if (!p.isDirectPromptTauDecayProduct()) continue;
    // if (!p.isDirectPromptTauDecayProductFinalState()) continue;
    // if (!p.isDirectHadronDecayProduct()) continue;
    // if (!p.isDirectHardProcessTauDecayProductFinalState()) continue;
    //// if (!p.isHardProcess()) continue;
    // if (!p.fromHardProcess()) continue;
    // if (!p.fromHardProcessDecayed()) continue;
    // if (!p.fromHardProcessFinalState()) continue;
    // if (!p.isHardProcessTauDecayProduct()) continue;
    // if (!p.isDirectHardProcessTauDecayProduct()) continue;
    // if (!p.fromHardProcessBeforeFSR()) continue;
    // if (!p.isFirstCopy()) continue;
    // if (!p.isLastCopyBeforeFSR()) continue;


    // Add table rows
    if (cfg_Verbose)
      {
	table.AddRowColumn(row, auxTools.ToString(entry)           );
	table.AddRowColumn(row, auxTools.ToString(genP_index)      );
	table.AddRowColumn(row, auxTools.ToString(genP_pdgId)      );
	table.AddRowColumn(row, auxTools.ToString(genP_status)     );
	table.AddRowColumn(row, auxTools.ToString(genP_charge)     );
	table.AddRowColumn(row, auxTools.ToString(genP_pt , 3)     );
	table.AddRowColumn(row, auxTools.ToString(genP_eta, 4)     );
	table.AddRowColumn(row, auxTools.ToString(genP_phi, 3)     );
	table.AddRowColumn(row, auxTools.ToString(genP_energy, 3)  );
	//table.AddRowColumn(row, "(" + auxTools.ToString(genP_vtx.x(), 3) + ", " + auxTools.ToString(genP_vtx.y(), 3)  + ", " + auxTools.ToString(genP_vtx.z(), 3) + ")" );
        table.AddRowColumn(row, "N/A");
	//table.AddRowColumn(row, auxTools.ToString(genP_Lxy, 3)     );
	//table.AddRowColumn(row, auxTools.ToString(genP_d0,  3)     );
        table.AddRowColumn(row, "N/A");
        table.AddRowColumn(row, "N/A");
	if (genP_mothers.size() < 6)
	  {
	    table.AddRowColumn(row, auxTools.ConvertIntVectorToString(genP_mothers) );
	  }
	else table.AddRowColumn(row, ".. Too many .." );
	if (genP_daughters.size() < 6)
	  {
	    table.AddRowColumn(row, auxTools.ConvertIntVectorToString(genP_daughters) );
	  }
	else table.AddRowColumn(row, ".. Too many .." );
	row++;
      }

    // b-quarks
    if(std::abs(genP_pdgId) == 5)
      {
	bQuarks++;
	bQuarks_p4.push_back( genP_p4 );
	if ( mcTools.HasMother(p, +6) ) tbWPlus_BQuark_p4  = genP_p4;
	if ( mcTools.HasMother(p, -6) ) tbWMinus_BQuark_p4 = genP_p4;
      }// b-quarks


    // Quarks
    if (mcTools.IsQuark(genP_pdgId)) {
      // Quarrk from W-
      if (mcTools.HasMother(p, -24) ) //W-
      {
  	if (genP_pdgId > 0) tbWPlus_Wqq_Quark_p4 = genP_p4;
  	else tbWPlus_Wqq_AntiQuark_p4 = genP_p4;
      }

      // Quark from W+
      if (mcTools.HasMother(p, +24) ) //W+
      {
  	//std::cout << auxTools.ConvertIntVectorToString(genP_mothers) << std::endl;
  	if (genP_pdgId > 0) tbWMinus_Wqq_Quark_p4 = genP_p4;
  	else tbWMinus_Wqq_AntiQuark_p4 = genP_p4;
      }
    }

    // t-quarks
    if (std::abs(genP_pdgId) == 6) {
	auto d0 = genP_daughters[0];
	auto d1 = genP_daughters[1];

	int d0_pdgId = fEvent.genparticles().getGenParticles()[d0].pdgId();
	int d1_pdgId = fEvent.genparticles().getGenParticles()[d1].pdgId();

	// t quark produces a W and a b-quark
	if ((std::abs(d0_pdgId) == 24 && (std::abs(d1_pdgId) == 5)) || (std::abs(d1_pdgId) == 24 && (std::abs(d0_pdgId) == 5))) {
		int W;
		if (std::abs(d0_pdgId) == 24)
			W = d0;
		else
			W = d1;

		auto W_daughters = fEvent.genparticles().getGenParticles()[W].daughters();
//TODO		mcTools.PrintGenParticle(fEvent.genparticles().getGenParticles()[W]);
	}
    }

    // Charged Leptons: e, mu, tau
    if (mcTools.IsChargedLepton(genP_pdgId)) {
        // from W+
        if (mcTools.HasMother(p, +24)) {
		lepton_from_Wplus++;
        // from W-
	} else if (mcTools.HasMother(p, -24)) {
		lepton_from_Wminus++;
	// if lepton from a Hadron
	} else if (p.isDirectHadronDecayProduct()) {
		// if hadron from a b
		//if (mcTools.HasMother(p, 5) || mcTools.HasMother(p, -5))
                	//mcTools.PrintGenParticle(p);
        }
    }

    // all long lived particles
    if (p.isPromptDecayed()) {
	// B-hadron
	// FIXME something is not right here. There are more leptonic B decays than b quarks
	if (((std::abs(genP_pdgId) >= 500) && (std::abs(genP_pdgId)  < 600)) || ((std::abs(genP_pdgId) >= 5000) && (std::abs(genP_pdgId)  < 6000)) || ((std::abs(genP_pdgId) >= 50000) && (std::abs(genP_pdgId)  < 60000))) {
		// check if B-hadron is from b quark from the diagram
		// TODO from the diagram?
		if (!p.isHardProcess()) {
			if (mcTools.HasMother(p, 5) || mcTools.HasMother(p, -5)) {
				BHadrons++;
				//mcTools.PrintGenParticle(p);
				// check if lepton as daughter
				bool found_lepton = false;
				for (auto k: genP_daughters) {
					auto _d = fEvent.genparticles().getGenParticles()[k];

					if (mcTools.IsChargedLepton(_d.pdgId())) {
						found_lepton = true;
					}
				}
				if (found_lepton) {
					lepton_from_B++;
				}
			}
		}
	}
    }

  }//for-loop: genParticles


  // MET analysis
  short lepton_from_W = lepton_from_Wplus + lepton_from_Wminus;
  //std::cout << lepton_from_W << " leptons from W\t";
  //std::cout << lepton_from_B << " leptons from b\n";

  // evetns with lepton from a W
  switch (lepton_from_W) {
  case 0:
	  h_genMET_0leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_0leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_0leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_0leptonFromW_Phi->Fill(fEvent.met().Phi());
	  break;
  case 1:
	  h_genMET_1leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_1leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_1leptonFromW_Phi->Fill(fEvent.met().Phi());

	  h_genMET_1_more_leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonFromW_Phi->Fill(fEvent.met().Phi());
	  break;
  case 2:
	  h_genMET_2leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_2leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_2leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_2leptonFromW_Phi->Fill(fEvent.met().Phi());
  default:
	  h_genMET_1_more_leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonFromW_Phi->Fill(fEvent.met().Phi());

	  h_genMET_2_more_leptonFromW_Et->Fill(fEvent.genMET().et());
	  h_genMET_2_more_leptonFromW_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_2_more_leptonFromW_Et->Fill(fEvent.met().et());
	  h_recoMET_2_more_leptonFromW_Phi->Fill(fEvent.met().Phi());
	  break;
  }

  // Lepton from B
  switch (lepton_from_B) {
  case 0:
	  h_genMET_0leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_0leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_0leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_0leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  break;
  case 1:
	  h_genMET_1leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_1leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_1leptonsFromB_Phi->Fill(fEvent.met().Phi());

	  h_genMET_1_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  break;
  case 2:
	  h_genMET_2leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_2leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_genMET_2_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_2_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_2leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_2leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  h_recoMET_2_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_2_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());

	  h_genMET_1_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  break;
  case 3:
	  h_genMET_3leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_3leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_genMET_2_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_2_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_3leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_3leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  h_recoMET_2_more_leptonsFromB_Et->Fill(fEvent.met().et());

	  h_genMET_1_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  h_recoMET_2_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  break;
  case 4:
	  h_genMET_4leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_4leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_4leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_4leptonsFromB_Phi->Fill(fEvent.met().Phi());
  default:
	  h_genMET_1_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_1_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_1_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_1_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());

	  h_genMET_2_more_leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_2_more_leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_2_more_leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_2_more_leptonsFromB_Phi->Fill(fEvent.met().Phi());
	  break;
  }

  // each combination of lepton from b and lepton from W
  switch (lepton_from_B) {
  case 0:
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_0FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_0FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_1FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_0FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
		h_genMET_leptons_0FromB_2FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_2FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_2FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_2FromW_Phi->Fill(fEvent.met().Phi());
	default:
		h_genMET_leptons_0FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_0FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_0FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_0FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_0FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  case 1:
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_1FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1FromB_0FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_1FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1FromB_1FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
		h_genMET_leptons_1FromB_2FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1FromB_2FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1FromB_2FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1FromB_2FromW_Phi->Fill(fEvent.met().Phi());
	default:
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  case 2:
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_2FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_2FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());

		h_recoMET_leptons_2FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
		// TODO check this logic here. Sems weird.
		h_genMET_leptons_2FromB_2FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2FromB_2FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2FromB_2FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2FromB_2FromW_Phi->Fill(fEvent.met().Phi());
	default:
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  case 3:
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_3FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_3FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_3FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_3FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_3FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_3FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_3FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_3FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
		h_genMET_leptons_3FromB_2FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_3FromB_2FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_3FromB_2FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_3FromB_2FromW_Phi->Fill(fEvent.met().Phi());
	default:
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  case 4:
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_4FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_4FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_4FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_4FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_4FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_4FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_genMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_4FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_4FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_recoMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
		h_genMET_leptons_4FromB_2FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_4FromB_2FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_4FromB_2FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_4FromB_2FromW_Phi->Fill(fEvent.met().Phi());
	default:
		h_genMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  default: // 5 or more from B
	switch (lepton_from_W) {
	case 0:
		h_genMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());

		h_genMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_0FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_0FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 1:
		h_genMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_1FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_1FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	case 2:
	default:
		h_genMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_2_more_FromB_2_more_FromW_Phi->Fill(fEvent.met().Phi());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.genMET().et());
		h_genMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.genMET().Phi());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Et->Fill(fEvent.met().et());
		h_recoMET_leptons_1_more_FromB_1_more_FromW_Phi->Fill(fEvent.met().Phi());
		break;
	}
	break;
  }

  // only leptons
  switch (lepton_from_B + lepton_from_W) {
  case 0: // histogram 0FromB_0FromW
	break;
  case 1:
	h_genMET_1leptons_Et->Fill(fEvent.genMET().et());
	h_genMET_1leptons_Phi->Fill(fEvent.genMET().phi());
	h_recoMET_1leptons_Et->Fill(fEvent.met().et());
	h_recoMET_1leptons_Phi->Fill(fEvent.met().phi());

	h_genMET_1_more_leptons_Et->Fill(fEvent.genMET().et());
	h_genMET_1_more_leptons_Phi->Fill(fEvent.genMET().phi());
	h_recoMET_1_more_leptons_Et->Fill(fEvent.met().et());
	h_recoMET_1_more_leptons_Phi->Fill(fEvent.met().phi());
	break;
  case 2:
  default:
	h_genMET_1_more_leptons_Et->Fill(fEvent.genMET().et());
	h_genMET_1_more_leptons_Phi->Fill(fEvent.genMET().phi());
	h_recoMET_1_more_leptons_Et->Fill(fEvent.met().et());
	h_recoMET_1_more_leptons_Phi->Fill(fEvent.met().phi());

	h_genMET_2_more_leptons_Et->Fill(fEvent.genMET().et());
	h_genMET_2_more_leptons_Phi->Fill(fEvent.genMET().phi());
	h_recoMET_2_more_leptons_Et->Fill(fEvent.met().et());
	h_recoMET_2_more_leptons_Phi->Fill(fEvent.met().phi());
	break;
  }

  h_genP_n_b_B->Fill(bQuarks, BHadrons);

  if (cfg_Verbose) table.Print();


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // Basic Variables
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  h_genMET_Et  ->Fill(fEvent.genMET().et());
  h_genMET_Phi ->Fill(fEvent.genMET().Phi());
  h_genHT_GenJets->Fill(genJ_HT);

  h_recoMET_Et  ->Fill(fEvent.met().et());
  h_recoMET_Phi ->Fill(fEvent.met().Phi());

  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // GenJets
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== GenJets" << std::endl;
  std::vector<math::XYZTLorentzVector> v_dijet_p4;
  std::vector<double> v_dijet_masses;
  std::vector<double> v_dijet_dR;
  std::vector<double> v_dijet_dRrap;
  std::vector<double> v_dijet_dEta;
  std::vector<double> v_dijet_dPhi;
  std::vector<double> v_dijet_dRap;

  double maxDijetMass_mass;
  math::XYZTLorentzVector maxDijetMass_p4;
  int maxDijetMass_pos;
  double maxDijetMass_dR;
  double maxDijetMass_dRrap;
  double maxDijetMass_dEta;
  double maxDijetMass_dPhi;
  double maxDijetMass_dRap;
  double maxDijetMass_rapidity;

  int iJet = 0;
  // For-loop: All selected jets
  for (size_t i=0; i < selJets_p4.size(); i++)
    {
      iJet++;
      double genJ_Pt  = selJets_p4.at(i).pt();
      double genJ_Eta = selJets_p4.at(i).eta();
      // double genJ_Rap = mcTools.GetRapidity(selJets_p4.at(i));

      if (iJet==1)
	{
	  h_GenJet1_Pt -> Fill( genJ_Pt  );
	  h_GenJet1_Eta-> Fill( genJ_Eta );
	}
      else if (iJet==2)
	{
	  h_GenJet2_Pt -> Fill( genJ_Pt  );
	  h_GenJet2_Eta-> Fill( genJ_Eta );
	}
      else if (iJet==3)
	{
	  h_GenJet3_Pt -> Fill( genJ_Pt  );
	  h_GenJet3_Eta-> Fill( genJ_Eta );
	}
      else if (iJet==4)
	{
	  h_GenJet4_Pt -> Fill( genJ_Pt  );
	  h_GenJet4_Eta-> Fill( genJ_Eta );
	}
      else if (iJet==5)
	{
	  h_GenJet5_Pt -> Fill( genJ_Pt  );
	  h_GenJet5_Eta-> Fill( genJ_Eta );
	}
      else if (iJet==6)
	{
	  h_GenJet6_Pt -> Fill( genJ_Pt  );
	  h_GenJet6_Eta-> Fill( genJ_Eta );
	}
      else{}

       // For-loop: All selected jets (nested)
       for (size_t j=i+1; j < selJets_p4.size(); j++)
       	{
       	  math::XYZTLorentzVector p4_i = selJets_p4.at(i);
       	  math::XYZTLorentzVector p4_j = selJets_p4.at(j);
       	  math::XYZTLorentzVector p4   = p4_i + p4_j;
       	  double rap_i = mcTools.GetRapidity(p4_i);
       	  double rap_j = mcTools.GetRapidity(p4_j);
       	  double dR    = ROOT::Math::VectorUtil::DeltaR(p4_i, p4_j);
       	  double dRap  = std::fabs(rap_i - rap_j);
       	  double dEta  = std::fabs(p4_i.eta() - p4_j.eta());
       	  double dPhi  = std::fabs(ROOT::Math::VectorUtil::DeltaPhi(p4_i, p4_j));

       	  v_dijet_p4.push_back( p4 );
       	  v_dijet_masses.push_back( p4.mass() );
       	  v_dijet_dR.push_back( dR );
       	  v_dijet_dRrap.push_back( sqrt( pow(dRap, 2) + pow(dPhi, 2) ) );
       	  v_dijet_dEta.push_back( dEta );
       	  v_dijet_dRap.push_back( dRap );
       	  v_dijet_dPhi.push_back( dPhi );

       	}
    }


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // MaxDiJet System (DiJet combination with largest mass)
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== MaxDiJet System" << std::endl;
  if (v_dijet_masses.size() > 0)
    {
      maxDijetMass_pos      = std::max_element(v_dijet_masses.begin(), v_dijet_masses.end()) - v_dijet_masses.begin();
      maxDijetMass_mass     = v_dijet_masses.at(maxDijetMass_pos);
      maxDijetMass_p4       = v_dijet_p4.at(maxDijetMass_pos);
      maxDijetMass_dR       = v_dijet_dR.at(maxDijetMass_pos);
      maxDijetMass_dRrap    = v_dijet_dRrap.at(maxDijetMass_pos);
      maxDijetMass_dEta     = v_dijet_dEta.at(maxDijetMass_pos);
      maxDijetMass_dPhi     = v_dijet_dPhi.at(maxDijetMass_pos);
      maxDijetMass_dRap     = v_dijet_dRap.at(maxDijetMass_pos);
      maxDijetMass_rapidity = mcTools.GetRapidity(maxDijetMass_p4);
    }

  // Fill histos
  h_MaxDiJetMass_Mass ->Fill( maxDijetMass_mass     );
  h_MaxDiJetMass_Pt   ->Fill( maxDijetMass_p4.pt()  );
  h_MaxDiJetMass_Eta  ->Fill( maxDijetMass_p4.eta() );
  h_MaxDiJetMass_Rap  ->Fill( maxDijetMass_rapidity );
  h_MaxDiJetMass_dR   ->Fill( maxDijetMass_dR       );
  h_MaxDiJetMass_dRrap->Fill( maxDijetMass_dRrap    );
  h_MaxDiJetMass_dEta ->Fill( maxDijetMass_dEta     );
  h_MaxDiJetMass_dPhi ->Fill( maxDijetMass_dPhi     );
  h_MaxDiJetMass_dRap ->Fill( maxDijetMass_dRap     );
  h_MaxDiJetMass_dEta_Vs_dPhi->Fill( maxDijetMass_dEta, maxDijetMass_dPhi );
  h_MaxDiJetMass_dRap_Vs_dPhi->Fill( maxDijetMass_dRap, maxDijetMass_dPhi );


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // GenJets Correlations
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== GenJets Correlations" << std::endl;

  // Fill Histos
  if (selJets_p4.size() >= 2)
    {
      double jet1_Eta = selJets_p4.at(0).eta();
      double jet1_Phi = selJets_p4.at(0).phi();
      double jet2_Eta = selJets_p4.at(1).eta();
      double jet2_Phi = selJets_p4.at(1).phi();
      h_Jet1Jet2_dEta_Vs_Jet1Jet2_Mass ->Fill(std::fabs(jet1_Eta - jet2_Eta), (selJets_p4.at(0) + selJets_p4.at(1)).mass() );

      if (selJets_p4.size() >= 4)
	{
	  double jet3_Eta = selJets_p4.at(2).eta();
	  double jet3_Phi = selJets_p4.at(2).phi();
	  double jet4_Eta = selJets_p4.at(3).eta();
	  double jet4_Phi = selJets_p4.at(3).phi();
	  h_Jet1Jet2_dEta_Vs_Jet3Jet4_dEta ->Fill(std::fabs(jet1_Eta - jet2_Eta), std::fabs(jet3_Eta - jet4_Eta));
	  h_Jet1Jet2_dPhi_Vs_Jet3Jet4_dPhi ->Fill(std::fabs(jet1_Phi - jet2_Phi), std::fabs(jet3_Phi - jet4_Phi));
	  h_Jet3Jet4_dEta_Vs_Jet3Jet4_Mass ->Fill(std::fabs(jet3_Eta - jet4_Eta), (selJets_p4.at(2) + selJets_p4.at(3)).mass() );
	}
    }

  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // TriJet System (W+)
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== TriJet System (W+)" << std::endl;
  math::XYZTLorentzVector tbWPlus_bqq_p4 = tbWPlus_BQuark_p4 + tbWPlus_Wqq_Quark_p4 + tbWPlus_Wqq_AntiQuark_p4;

  // Find max separation
  std::vector<math::XYZTLorentzVector> bqq_p4;
  bqq_p4.push_back(tbWPlus_BQuark_p4);
  bqq_p4.push_back(tbWPlus_Wqq_Quark_p4);
  bqq_p4.push_back(tbWPlus_Wqq_AntiQuark_p4);
  double deltaRMax = -1.0;
  int deltaRMax_i  = -1;
  int deltaRMax_j  = -1;
  // For-loop: All p4 of bqq system
  for (size_t i = 0; i < bqq_p4.size(); i++)
    {
      for (size_t j = i+1; j < bqq_p4.size(); j++)
	{
	  double deltaR = ROOT::Math::VectorUtil::DeltaR(bqq_p4.at(i), bqq_p4.at(j));
	  if (deltaR > deltaRMax)
	    {
	      deltaRMax   = deltaR;
	      deltaRMax_i = i;
	      deltaRMax_j = j;
	    }
	}
    } // For-loop: All p4 of bqq system

  // double bqq_dEta = std::fabs(bqq_p4.at(deltaRMax_i).eta() - bqq_p4.at(deltaRMax_j).eta());
  double bqq_dRap = -1.0;
  double bqq_dPhi = -1.0;

  if (deltaRMax_i >= 0 && deltaRMax_j >= 0)
    {
      bqq_dRap = std::fabs(mcTools.GetRapidity(bqq_p4.at(deltaRMax_i) ) - mcTools.GetRapidity(bqq_p4.at(deltaRMax_j) ) );
      bqq_dPhi = std::fabs(ROOT::Math::VectorUtil::DeltaPhi(bqq_p4.at(deltaRMax_i), bqq_p4.at(deltaRMax_j)));
    }

  // Fill Histos
  h_tbWPlus_bqq_Pt->Fill( tbWPlus_bqq_p4.pt());
  h_tbWPlus_bqq_Rap->Fill( mcTools.GetRapidity(tbWPlus_bqq_p4) );
  h_tbWPlus_bqq_Mass->Fill( tbWPlus_bqq_p4.mass() );
  h_tbWPlus_bqq_dRMax_dR->Fill( deltaRMax );
  h_tbWPlus_bqq_dRMax_dRap->Fill( bqq_dRap );
  h_tbWPlus_bqq_dRMax_dPhi->Fill( bqq_dPhi );
  h_tbWPlus_bqq_dRMax_dRap_Vs_dPhi->Fill( bqq_dRap, bqq_dPhi );


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // TriJet System (W-)
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== TriJet System (W-)" << std::endl;
  math::XYZTLorentzVector tbWMinus_bqq_p4 = tbWMinus_Wqq_Quark_p4 + tbWMinus_Wqq_AntiQuark_p4 + tbWMinus_BQuark_p4;

  // Fix max separation (again)
  bqq_p4.clear();
  bqq_p4.push_back(tbWMinus_BQuark_p4);
  bqq_p4.push_back(tbWMinus_Wqq_Quark_p4);
  bqq_p4.push_back(tbWMinus_Wqq_AntiQuark_p4);
  deltaRMax    = -1.0;
  deltaRMax_i  = -1;
  deltaRMax_j  = -1;

  // For-loop: All p4 of bqq system
  for (size_t i = 0; i < bqq_p4.size(); i++)
    {
      for (size_t j = i+1; j < bqq_p4.size(); j++)
	{
	  double deltaR = ROOT::Math::VectorUtil::DeltaR(bqq_p4.at(i), bqq_p4.at(j));
	  if (deltaR > deltaRMax)
	    {
	      deltaRMax   = deltaR;
	      deltaRMax_i = i;
	      deltaRMax_j = j;
	    }
	}
    } // For-loop: All p4 of bqq system

  bqq_dRap = std::fabs(mcTools.GetRapidity(bqq_p4.at(deltaRMax_i) ) - mcTools.GetRapidity(bqq_p4.at(deltaRMax_j) ) );
  bqq_dPhi = std::fabs(ROOT::Math::VectorUtil::DeltaPhi(bqq_p4.at(deltaRMax_i), bqq_p4.at(deltaRMax_j)));

  // Fill Histos
  h_tbWMinus_bqq_Pt->Fill( tbWMinus_bqq_p4.pt() );
  h_tbWMinus_bqq_Rap->Fill( mcTools.GetRapidity(tbWMinus_bqq_p4) );
  h_tbWMinus_bqq_Mass->Fill( tbWMinus_bqq_p4.mass() );
  h_tbWMinus_bqq_dRMax_dR->Fill( deltaRMax );
  h_tbWMinus_bqq_dRMax_dRap->Fill( bqq_dRap );
  h_tbWMinus_bqq_dRMax_dPhi->Fill( bqq_dPhi );
  h_tbWMinus_bqq_dRMax_dRap_Vs_dPhi ->Fill( bqq_dRap, bqq_dPhi );


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // B-quarks (pT sorted)
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== BQuarks" << std::endl;
  std::sort( bQuarks_p4.begin(), bQuarks_p4.end(), PtComparator() );

  // Fill histos
  h_BQuarks_N->Fill(bQuarks_p4.size());

  if (bQuarks_p4.size() >= 2)
    {
      double dEta_1_2 = std::fabs(bQuarks_p4.at(0).eta() - bQuarks_p4.at(1).eta());
      double dPhi_1_2 = std::fabs(bQuarks_p4.at(0).phi() - bQuarks_p4.at(1).phi());

      h_BQuark1_BQuark2_dEta_Vs_dPhi->Fill( dEta_1_2 , dPhi_1_2 );
    }

  if (bQuarks_p4.size() >= 3)
    {
      double dEta_1_3 = std::fabs(bQuarks_p4.at(0).eta() - bQuarks_p4.at(2).eta());
      double dPhi_1_3 = std::fabs(bQuarks_p4.at(0).phi() - bQuarks_p4.at(2).phi());
      double dEta_2_3 = std::fabs(bQuarks_p4.at(1).eta() - bQuarks_p4.at(2).eta());
      double dPhi_2_3 = std::fabs(bQuarks_p4.at(1).phi() - bQuarks_p4.at(2).phi());

      h_BQuark1_BQuark3_dEta_Vs_dPhi->Fill( dEta_1_3 , dPhi_1_3 );
      h_BQuark2_BQuark3_dEta_Vs_dPhi->Fill( dEta_2_3 , dPhi_2_3 );
    }

  if (bQuarks_p4.size() >= 4)
    {
      double dEta_1_4 = std::fabs(bQuarks_p4.at(0).eta() - bQuarks_p4.at(3).eta());
      double dPhi_1_4 = std::fabs(bQuarks_p4.at(0).phi() - bQuarks_p4.at(3).phi());
      double dEta_2_4 = std::fabs(bQuarks_p4.at(1).eta() - bQuarks_p4.at(3).eta());
      double dPhi_2_4 = std::fabs(bQuarks_p4.at(1).phi() - bQuarks_p4.at(3).phi());
      double dEta_3_4 = std::fabs(bQuarks_p4.at(2).eta() - bQuarks_p4.at(3).eta());
      double dPhi_3_4 = std::fabs(bQuarks_p4.at(2).phi() - bQuarks_p4.at(3).phi());

      h_BQuark1_BQuark4_dEta_Vs_dPhi->Fill( dEta_1_4 , dPhi_1_4 );
      h_BQuark2_BQuark4_dEta_Vs_dPhi->Fill( dEta_2_4 , dPhi_2_4 );
      h_BQuark3_BQuark4_dEta_Vs_dPhi->Fill( dEta_3_4 , dPhi_3_4 );
    }

  double deltaRMin = 999999.9;
  int deltaRMin_i  = -1;
  int deltaRMin_j  = -1;
  // For-loop: All b-quarks
  for (size_t i = 0; i < bQuarks_p4.size(); i++)
    {

      if (i==0)
	{
	  h_BQuark1_Pt ->Fill( bQuarks_p4.at(i).pt()  );
	  h_BQuark1_Eta->Fill( bQuarks_p4.at(i).eta() );
	}
      else if (i==1)
	{
	  h_BQuark2_Pt ->Fill( bQuarks_p4.at(i).pt()  );
	  h_BQuark2_Eta->Fill( bQuarks_p4.at(i).eta() );
	}
      else if (i==2)
	{
	  h_BQuark3_Pt ->Fill( bQuarks_p4.at(i).pt()  );
	  h_BQuark3_Eta->Fill( bQuarks_p4.at(i).eta() );
	}
      else if (i==3)
	{
	  h_BQuark4_Pt ->Fill( bQuarks_p4.at(i).pt()  );
	  h_BQuark4_Eta->Fill( bQuarks_p4.at(i).eta() );
	}
      else{}


      // For-Loop (Nested): All b-quarks
      for (size_t j = i+1; j < bQuarks_p4.size(); j++)
	{

	  double deltaR = ROOT::Math::VectorUtil::DeltaR(bQuarks_p4.at(i), bQuarks_p4.at(j));

	  if (deltaR < deltaRMin)
	    {
	      deltaRMin = deltaR;
	      deltaRMin_i = i;
	      deltaRMin_j = j;
	    }
	}
    } // For-loop: All b-quarks


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  // BquarkPair - Ldg Jets Correlations
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if(0) std::cout << "=== BQuarkPair" << std::endl;
  if (deltaRMin_i>= 0  && deltaRMin_j >= 0)
    {
      math::XYZTLorentzVector bQuarkPair_dRMin_p4 = bQuarks_p4.at(deltaRMin_i) + bQuarks_p4.at(deltaRMin_j);
      double bQuarkPair_dEta = std::fabs(bQuarks_p4.at(deltaRMin_i).eta() - bQuarks_p4.at(deltaRMin_j).eta());
      double bQuarkPair_dPhi = std::fabs(ROOT::Math::VectorUtil::DeltaPhi(bQuarks_p4.at(deltaRMin_i), bQuarks_p4.at(deltaRMin_j)));

      // Fill Histos
      h_BQuarkPair_dRMin_pT   ->Fill( bQuarkPair_dRMin_p4.pt() );
      h_BQuarkPair_dRMin_dEta ->Fill( bQuarkPair_dEta );
      h_BQuarkPair_dRMin_dPhi ->Fill( bQuarkPair_dPhi );
      h_BQuarkPair_dRMin_dR   ->Fill( deltaRMin );
      h_BQuarkPair_dRMin_Mass ->Fill( bQuarkPair_dRMin_p4.mass() );
      h_BQuarkPair_dRMin_Eta1_Vs_Eta2->Fill( bQuarks_p4.at(deltaRMin_i).eta(), bQuarks_p4.at(deltaRMin_j).eta());
      h_BQuarkPair_dRMin_Phi1_Vs_Phi2->Fill( bQuarks_p4.at(deltaRMin_i).phi(), bQuarks_p4.at(deltaRMin_j).phi());
      h_BQuarkPair_dRMin_Pt1_Vs_Pt2  ->Fill(bQuarks_p4.at(deltaRMin_i).pt(), bQuarks_p4.at(deltaRMin_j).pt());
      h_BQuarkPair_dRMin_dEta_Vs_dPhi->Fill( bQuarkPair_dEta, bQuarkPair_dPhi);

      // Fill histos
      if (selJets_p4.size() > 0)
	{
	  h_BQuarkPair_dRMin_jet1_dEta ->Fill( std::fabs(bQuarkPair_dRMin_p4.eta() - selJets_p4.at(0).eta()) );
	  h_BQuarkPair_dRMin_jet1_dPhi ->Fill( std::fabs(ROOT::Math::VectorUtil::DeltaPhi(bQuarkPair_dRMin_p4, selJets_p4.at(0) ) ) );
	  h_BQuarkPair_dRMin_jet1_dR   ->Fill( ROOT::Math::VectorUtil::DeltaR(bQuarkPair_dRMin_p4, selJets_p4.at(0) ) );
	}

      if (selJets_p4.size() > 1)
	{
	  h_BQuarkPair_dRMin_jet2_dEta ->Fill( std::fabs(bQuarkPair_dRMin_p4.eta() - selJets_p4.at(1).eta()) );
	  h_BQuarkPair_dRMin_jet2_dPhi ->Fill( std::fabs(ROOT::Math::VectorUtil::DeltaPhi(bQuarkPair_dRMin_p4, selJets_p4.at(1) ) ) );
	  h_BQuarkPair_dRMin_jet2_dR   ->Fill( ROOT::Math::VectorUtil::DeltaR(bQuarkPair_dRMin_p4, selJets_p4.at(1) ) );
	}
    }

  return;
}