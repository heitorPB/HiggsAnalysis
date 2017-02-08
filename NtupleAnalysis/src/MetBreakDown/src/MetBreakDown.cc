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

  CommonPlots fCommonPlots;

  // Event selection classes
  ElectronSelection fElectronSelection;
  MuonSelection fMuonSelection;

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


  // MHT histos
  WrappedTH1 *h_genMHT;
  WrappedTH1 *h_recoMHT;

  WrappedTH1 *h_genMHT_0leptonFromW;
  WrappedTH1 *h_genMHT_1_more_leptonFromW;
  WrappedTH1 *h_genMHT_0leptonsFromB;
  WrappedTH1 *h_genMHT_1_more_leptonsFromB;

  WrappedTH1 *h_genMHT_leptons_0FromB_0FromW;
  WrappedTH1 *h_genMHT_leptons_0FromB_1_more_FromW;
  WrappedTH1 *h_genMHT_leptons_1_more_FromB_0FromW;
  WrappedTH1 *h_genMHT_leptons_1_more_FromB_1_more_FromW;

  WrappedTH1 *h_genMHT_1_more_leptons;

  WrappedTH1 *h_recoMHT_0leptonFromW;
  WrappedTH1 *h_recoMHT_1_more_leptonFromW;
  WrappedTH1 *h_recoMHT_0leptonsFromB;
  WrappedTH1 *h_recoMHT_1_more_leptonsFromB;

  WrappedTH1 *h_recoMHT_leptons_0FromB_0FromW;
  WrappedTH1 *h_recoMHT_leptons_0FromB_1_more_FromW;
  WrappedTH1 *h_recoMHT_leptons_1_more_FromB_0FromW;
  WrappedTH1 *h_recoMHT_leptons_1_more_FromB_1_more_FromW;

  WrappedTH1 *h_recoMHT_1_more_leptons;




  // GenJets
  WrappedTH1 *h_GenJet_N_NoPreselections;
  WrappedTH1 *h_GenJet_N_AfterLeptonVeto;
  WrappedTH1 *h_GenJet_N_AfterLeptonVetoNJetsCut;
  WrappedTH1 *h_GenJet_N_AfterPreselections;
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
    cSubPassedHtCut(fEventCounter.addSubCounter("Preselections","HT Cut")),
    fCommonPlots(config.getParameter<ParameterSet>("CommonPlots"), CommonPlots::kSignalAnalysis, fHistoWrapper),
    fElectronSelection(config.getParameter<ParameterSet>("ElectronSelection"),
                       fEventCounter, fHistoWrapper, &fCommonPlots, "Veto"),
    fMuonSelection(config.getParameter<ParameterSet>("MuonSelection"),
                       fEventCounter, fHistoWrapper, &fCommonPlots, "Veto")
{ }

void MetBreakDown::book(TDirectory *dir) {
  fCommonPlots.book(dir, isData());
 
  fElectronSelection.bookHistograms(dir);
  fMuonSelection.bookHistograms(dir);

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

  //const int nBinsPt   = cfg_PtBinSetting.bins();
  //const double minPt  = cfg_PtBinSetting.min();
  //const double maxPt  = cfg_PtBinSetting.max();

  const int nBinsPhi  = cfg_PhiBinSetting.bins();
  const double minPhi = cfg_PhiBinSetting.min();
  const double maxPhi = cfg_PhiBinSetting.max();


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
  h_genMET_leptons_1_more_FromB_1_more_FromW_Et  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1_more_FromB_1_more_FromW_Et",  ";Gen E_{T}^{miss} (GeV)",       nBinsMet, minMet, maxMet);
  h_genMET_leptons_1_more_FromB_1_more_FromW_Phi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMET_leptons_1_more_FromB_1_more_FromW_Phi", ";Gen E_{T}^{miss} #phi (rads)", nBinsPhi, minPhi, maxPhi);
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


  // MHT
  h_genMHT  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir,  "genMHT",  ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT", ";Reco MH_{T} (GeV)", nBinsMet, minMet, maxMet);


  h_genMHT_0leptonFromW        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_0leptonFromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_1_more_leptonFromW  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_1_more_leptonFromW", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_0leptonsFromB       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_0leptonFromB",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_1_more_leptonsFromB = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_1_more_leptonFromB", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);

  h_genMHT_leptons_0FromB_0FromW             = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_leptons_0FromB_0FromW",             ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_leptons_0FromB_1_more_FromW       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_leptons_0FromB_1_more_FromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_leptons_1_more_FromB_0FromW       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_leptons_1_more_FromB_0FromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_genMHT_leptons_1_more_FromB_1_more_FromW = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_leptons_1_more_FromB_1_more_FromW", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);

  h_genMHT_1_more_leptons = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "genMHT_1_more_leptons", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);


  h_recoMHT_0leptonFromW        = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_0leptonFromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_1_more_leptonFromW  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_1_more_leptonFromW", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_0leptonsFromB       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_0leptonFromB",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_1_more_leptonsFromB = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_1_more_leptonFromB", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);

  h_recoMHT_leptons_0FromB_0FromW             = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_leptons_0FromB_0FromW",             ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_leptons_0FromB_1_more_FromW       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_leptons_0FromB_1_more_FromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_leptons_1_more_FromB_0FromW       = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_leptons_1_more_FromB_0FromW",       ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);
  h_recoMHT_leptons_1_more_FromB_1_more_FromW = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_leptons_1_more_FromB_1_more_FromW", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);

  h_recoMHT_1_more_leptons = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "recoMHT_1_more_leptons", ";Gen MH_{T} (GeV)", nBinsMet, minMet, maxMet);












  // GenJets
  h_GenJet_N_NoPreselections         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_NoPreselections"        , ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterLeptonVeto         = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterLeptonVeto"        , ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterLeptonVetoNJetsCut = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterLeptonVetoNJetsCut", ";N (selected jets)" , 16, -0.5, +15.5);
  h_GenJet_N_AfterPreselections      = fHistoWrapper.makeTH<TH1F>(HistoLevel::kVital, dir, "GenJet_N_AfterPreselections"     , ";N (selected jets)" , 16, -0.5, +15.5);

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
/*
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

  }*/
  const ElectronSelection::Data eData = fElectronSelection.analyze(fEvent);
  if (eData.hasIdentifiedElectrons())
    return;
  const MuonSelection::Data muData = fMuonSelection.analyze(fEvent);
  if (muData.hasIdentifiedMuons())
    return;


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

  // MHT = | sum p4 |_t
  std::vector<float>  genJets_px;
  std::vector<float>  genJets_py;
  std::vector<float> recoJets_px;
  std::vector<float> recoJets_py;

  for(auto j: fEvent.genjets()) {
    genJets_px.push_back(j.p4().x());
    genJets_py.push_back(j.p4().y());
  }
  for(auto j: fEvent.jets()) {
    recoJets_px.push_back(j.p4().x());
    recoJets_py.push_back(j.p4().y());
  }

  float  genJets_px_sum = std::accumulate(genJets_px.begin(), genJets_px.end(), 0.0);
  float  genJets_py_sum = std::accumulate(genJets_py.begin(), genJets_py.end(), 0.0);
  float recoJets_px_sum = std::accumulate(recoJets_px.begin(), recoJets_px.end(), 0.0);
  float recoJets_py_sum = std::accumulate(recoJets_py.begin(), recoJets_py.end(), 0.0);

  float  genMHT = std::sqrt(std::pow(genJets_px_sum, 2) + std::pow(genJets_py_sum, 2));
  float recoMHT = std::sqrt(std::pow(recoJets_px_sum, 2) + std::pow(recoJets_py_sum, 2));

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

	  h_genMHT_0leptonFromW->Fill(genMHT);
	  h_recoMHT_0leptonFromW->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonFromW->Fill(genMHT);
	  h_recoMHT_1_more_leptonFromW->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonFromW->Fill(genMHT);
	  h_recoMHT_1_more_leptonFromW->Fill(recoMHT);
	  break;
  }

  // Lepton from B
  switch (lepton_from_B) {
  case 0:
	  h_genMET_0leptonsFromB_Et->Fill(fEvent.genMET().et());
	  h_genMET_0leptonsFromB_Phi->Fill(fEvent.genMET().Phi());
	  h_recoMET_0leptonsFromB_Et->Fill(fEvent.met().et());
	  h_recoMET_0leptonsFromB_Phi->Fill(fEvent.met().Phi());

	  h_genMHT_0leptonsFromB->Fill(genMHT);
	  h_recoMHT_0leptonsFromB->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonsFromB->Fill(genMHT);
	  h_recoMHT_1_more_leptonsFromB->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonsFromB->Fill(genMHT);
	  h_recoMHT_1_more_leptonsFromB->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonsFromB->Fill(genMHT);
	  h_recoMHT_1_more_leptonsFromB->Fill(recoMHT);
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

	  h_genMHT_1_more_leptonsFromB->Fill(genMHT);
	  h_recoMHT_1_more_leptonsFromB->Fill(recoMHT);
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

		h_genMHT_leptons_0FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_0FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_0FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_0FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_0FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_0FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_0FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_0FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

		h_genMHT_leptons_1_more_FromB_1_more_FromW->Fill(genMHT);
		h_recoMHT_leptons_1_more_FromB_1_more_FromW->Fill(recoMHT);
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

	h_genMHT_1_more_leptons->Fill(genMHT);
	h_recoMHT_1_more_leptons->Fill(recoMHT);
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

	h_genMHT_1_more_leptons->Fill(genMHT);
	h_recoMHT_1_more_leptons->Fill(recoMHT);
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

  h_genMHT->Fill(genMHT);
  h_recoMHT->Fill(recoMHT);

  return;
}
