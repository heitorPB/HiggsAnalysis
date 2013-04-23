#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/Math/interface/LorentzVector.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeEventBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeFunctionBranch.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventItem.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeTauBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeJetBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeVertexBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeTriggerBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeGenBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeGenParticleBranches.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TreeGenTauBranches.h"

#include "TTree.h"

#include <limits>

class HPlusTauNtupleAnalyzer: public edm::EDAnalyzer {
public:
  HPlusTauNtupleAnalyzer(const edm::ParameterSet& iConfig);

  ~HPlusTauNtupleAnalyzer();

private:
  void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  void reset();

  typedef math::XYZTLorentzVector XYZTLorentzVector;

  TTree *fTree;

  typedef HPlus::EventItem<XYZTLorentzVector> MetItem;
  typedef HPlus::EventItem<double> DoubleItem;

  edm::InputTag fGenParticleTauSrc;
  edm::InputTag fSelectedPrimaryVertexSrc;
  edm::InputTag fGoodPrimaryVertexSrc;

  HPlus::TreeEventBranches fEventBranches;
  HPlus::TreeGenBranches fGenBranches;
  HPlus::TreeVertexBranches fSelectedVertexBranches;
  HPlus::TreeVertexBranches fGoodVertexBranches;
  HPlus::TreeTriggerBranches fTriggerBranches;
  HPlus::TreeTauBranches fTauBranches;
  HPlus::TreeJetBranches fJetBranches;

  HPlus::TreeGenTauBranches fGenTaus;

  std::vector<MetItem> fMets;
  std::vector<DoubleItem> fDoubles;

  int fNSelectedPrimaryVertices;
  int fNGoodPrimaryVertices;
};

HPlusTauNtupleAnalyzer::HPlusTauNtupleAnalyzer(const edm::ParameterSet& iConfig):
  fGenParticleTauSrc(iConfig.getParameter<edm::InputTag>("genParticleTauSrc")),
  fGenBranches(iConfig),
  fSelectedVertexBranches(iConfig, "selectedPrimaryVertex", "selectedPrimaryVertexSrc"),
  fGoodVertexBranches(iConfig, "goodPrimaryVertex", "goodPrimaryVertexSrc"),
  fTriggerBranches(iConfig),
  fTauBranches(iConfig),
  fJetBranches(iConfig, false),
  fGenTaus("gentaus")
{

  edm::ParameterSet pset = iConfig.getParameter<edm::ParameterSet>("mets");
  std::vector<std::string> names = pset.getParameterNames();
  for(size_t i=0; i<names.size(); ++i) {
    fMets.push_back(MetItem(names[i], pset.getParameter<edm::InputTag>(names[i])));
  }

  pset = iConfig.getParameter<edm::ParameterSet>("doubles");
  names = pset.getParameterNames();
  for(size_t i=0; i<names.size(); ++i) {
    fDoubles.push_back(DoubleItem(names[i], pset.getParameter<edm::InputTag>(names[i])));
  }

  edm::Service<TFileService> fs;
  fTree = fs->make<TTree>("tree", "Tree");

  fEventBranches.book(fTree);
  fGenBranches.book(fTree);
  fSelectedVertexBranches.book(fTree);
  fGoodVertexBranches.book(fTree);
  fTriggerBranches.book(fTree);
  fTauBranches.book(fTree);
  fJetBranches.book(fTree);

  fGenTaus.book(fTree);

  for(size_t i=0; i<fMets.size(); ++i) {
    fTree->Branch(fMets[i].name.c_str(), &(fMets[i].value));
  }
  for(size_t i=0; i<fDoubles.size(); ++i) {
    fTree->Branch(fDoubles[i].name.c_str(), &(fDoubles[i].value));
  }
}

HPlusTauNtupleAnalyzer::~HPlusTauNtupleAnalyzer() {}

void HPlusTauNtupleAnalyzer::reset() {
  double nan = std::numeric_limits<double>::quiet_NaN();
 
  fEventBranches.reset();
  fGenBranches.reset();
  fSelectedVertexBranches.reset();
  fGoodVertexBranches.reset();
  fTriggerBranches.reset();
  fTauBranches.reset();
  fJetBranches.reset();

  fGenTaus.reset();

  for(size_t i=0; i<fMets.size(); ++i) {
    fMets[i].value.SetXYZT(nan, nan, nan, nan);
  }
  for(size_t i=0; i<fDoubles.size(); ++i) {
    fDoubles[i].value = nan;
  }

  fNSelectedPrimaryVertices = -1;
  fNGoodPrimaryVertices = -1;
}

void HPlusTauNtupleAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  fEventBranches.setValues(iEvent);
  fSelectedVertexBranches.setValues(iEvent);
  fGoodVertexBranches.setValues(iEvent);
  fTriggerBranches.setValues(iEvent);

  edm::Handle<edm::View<reco::GenParticle> > hgenparticlestau;
  if(!iEvent.isRealData())
    iEvent.getByLabel(fGenParticleTauSrc, hgenparticlestau);

  // Taus
  if(iEvent.isRealData()) {
    fTauBranches.setValues(iEvent);
  }
  else {
    fGenBranches.setValues(iEvent);
    fTauBranches.setValues(iEvent, *hgenparticlestau);

    for(edm::View<reco::GenParticle>::const_iterator iGen = hgenparticlestau->begin(); iGen != hgenparticlestau->end(); ++iGen) {
      if(std::abs(iGen->pdgId()) == 15) {
        fGenTaus.addValue(&(*iGen));
      }
    }
  }

  fJetBranches.setValues(iEvent);

  for(size_t i=0; i<fMets.size(); ++i) {
    edm::Handle<edm::View<reco::MET> > hmet;
    iEvent.getByLabel(fMets[i].src, hmet);
    fMets[i].value = hmet->at(0).p4();
  }
  for(size_t i=0; i<fDoubles.size(); ++i) {
    edm::Handle<double> hnum;
    iEvent.getByLabel(fDoubles[i].src, hnum);
    fDoubles[i].value = *hnum;
  }

  fTree->Fill();
  reset();
}

DEFINE_FWK_MODULE(HPlusTauNtupleAnalyzer);
