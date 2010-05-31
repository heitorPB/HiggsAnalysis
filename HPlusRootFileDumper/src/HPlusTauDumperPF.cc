#include "HiggsAnalysis/HPlusRootFileDumper/interface/HPlusTauDumperPF.h"

//#include "DataFormats/TauReco/interface/PFTauDecayMode.h"
//#include "DataFormats/TauReco/interface/PFTauDecayModeAssociation.h"
#include "DataFormats/TauReco/interface/PFTauTagInfo.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminator.h"

#include "RecoTauTag/TauTagTools/interface/TauTagTools.h"

#include "DataFormats/TauReco/interface/PFTauTagInfoFwd.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/Math/interface/Vector.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/Math/interface/deltaR.h"

namespace HPlusAnalysis {

HPlusTauDumperPF::HPlusTauDumperPF(edm::EDProducer& producer, edm::ParameterSet& aTauCollectionParameterSet,
                                   Counter* counter)
: HPlusTauDumperBase(producer, aTauCollectionParameterSet, counter) {
  std::string alias;
  // PF BDT output from Electron PreID
  producer.produces<std::vector<float> >(alias = "PFElectronPreIDOutput").setBranchAlias(alias);
  // Decision from Electron PreID
  producer.produces<std::vector<float> >(alias = "PFElectronPreIDDecision").setBranchAlias(alias);
  producer.produces<std::vector<float> >(alias = "PFNeutralHadronET").setBranchAlias(alias);
  producer.produces<std::vector<float> >(alias = "PFGammaET").setBranchAlias(alias);
  producer.produces<std::vector<float> >(alias = "PFElectronET").setBranchAlias(alias);

  // Common tau variable aliases are created in the base class constructor
  // Discriminator aliases are created in the base class constructor
}

HPlusTauDumperPF::~HPlusTauDumperPF() {

}

/*void HPlusTauDumperPF::setupSpecificRootTreeBranches() {
  fRootTree->Branch("fPFElectronPreIDOutput", &fPFElectronPreIDOutput);
  fRootTree->Branch("fPFElectronPreIDDecision", &fPFElectronPreIDDecision);
  fRootTree->Branch("fPFNeutralHadronET", &fPFNeutralHadronET);
  fRootTree->Branch("fPFGammaET", &fPFGammaET);
  fRootTree->Branch("fPFElectronET", &fPFElectronET);
}

void HPlusTauDumperPF::initializeSpecificBranchData() {
  fPFElectronPreIDOutput = -1;
  fPFElectronPreIDDecision = -1;
  fPFNeutralHadronET = -1;
  fPFGammaET = -1;
  fPFElectronET = -1;
}
*/
void HPlusTauDumperPF::setData(edm::Event& iEvent) {
  // Create pointers to data
  
  // Jet direction
  std::auto_ptr<std::vector<math::XYZVector> > myDataJetE(new std::vector<math::XYZVector>);
  // Leading track properties
  std::auto_ptr<std::vector<math::XYZVector> > myDataLdgChargedHadronP(new std::vector<math::XYZVector>);
  std::auto_ptr<std::vector<float> > myDataLdgChargedHadronJetDR(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataLdgChargedHadronHits(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataLdgChargedHadronNormalizedChi(new std::vector<float>);
  std::auto_ptr<std::vector<math::XYZVector> > myDataLdgChargedHadronIP(new std::vector<math::XYZVector>);
  std::auto_ptr<std::vector<float> > myDataLdgChargedHadronIPTSignificance(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataRtau(new std::vector<float>);
  // Charge related
  std::auto_ptr<std::vector<int> > myDataChargeSum(new std::vector<int>);
  // Charged track isolation related
  std::auto_ptr<std::vector<int> > myDataTrIsoSignalTrackCount(new std::vector<int>);
  std::auto_ptr<std::vector<float> > myDataTrIsoLowestSignalTrackPt(new std::vector<float>);
  std::auto_ptr<std::vector<int> > myDataTrIsoIsolationTrackCount(new std::vector<int>);
  std::auto_ptr<std::vector<float> > myDataTrIsoHighestIsolationTrackPt(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataTrIsoSignalMinTrackPt(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataTrIsoIsolationMinTrackPt(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataTrIsoIsolationMaxDz(new std::vector<float>);
  // Jet energy details
  std::auto_ptr<std::vector<float> > myDataEMFraction(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataMaxHCALOverLdgP(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataECALIsolationET(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataMaxHCALClusterET(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataChargedHadronET(new std::vector<float>);
  // Flight path related
  std::auto_ptr<std::vector<math::XYZVector> > myDataFlightPathLength(new std::vector<math::XYZVector>);
  std::auto_ptr<std::vector<float> > myDataFlightPathTransverseSignificance(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataFlightPathSignificance(new std::vector<float>);
  // Invariant mass related
  std::auto_ptr<std::vector<float> > myDataInvariantMassFromTracksOnly(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataInvariantMassFull(new std::vector<float>);
  // PF specific
  std::auto_ptr<std::vector<float> > myDataPFElectronPreIDOutput(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataPFElectronPreIDDecision(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataPFNeutralHadronET(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataPFGammaET(new std::vector<float>);
  std::auto_ptr<std::vector<float> > myDataPFElectronET(new std::vector<float>);
  // other
  std::auto_ptr<math::XYZVector> myDataPV(new math::XYZVector);
  math::XYZVector myPV(-1., -1., -1.);
  *myDataPV = myPV;
  
  // Get tau jets
  edm::Handle<reco::PFTauCollection> myTauJets;
  if (!iEvent.getByLabel(fTauCollection, myTauJets)) {
    throw cms::Exception("HPlus") << "tau collection not found" << std::endl;
  }
  size_t myTauJetCount = myTauJets->size();
  
  // Get discriminators
  size_t myDiscriminatorCount = fTauDiscriminators.size();
  std::vector<edm::Handle<reco::PFTauDiscriminator> > myDiscriminatorHandles;
  myDiscriminatorHandles.reserve(myDiscriminatorCount);
  for (size_t i = 0; i < myDiscriminatorCount; ++i) {
    edm::Handle<reco::PFTauDiscriminator> myEmptyHandle;
    myDiscriminatorHandles.push_back(myEmptyHandle);
    if (!iEvent.getByLabel(fTauDiscriminators[i], myDiscriminatorHandles[i])) {
      throw cms::Exception("HPlus") << "Discriminator " << fTauDiscriminators[i].label() << " not found in dataset!" << std::endl;
    }
  }
  std::vector<reco::PFTauRef> mySelectedPFTauRefs;
  // Loop over the tau jets
  for (size_t i = 0; i < myTauJetCount; ++i) {
    reco::PFTauRef myTauJetRef(myTauJets, i);
    
    const PFCandidateRef& myLdgChargedHadronCandidateRef = myTauJetRef->leadPFChargedHadrCand();
    if (myLdgChargedHadronCandidateRef.isNull()) continue;
    // FIXME: add a counter here
    
    const reco::TrackRef myLdgChargedHadronTrackRef = myLdgChargedHadronCandidateRef->trackRef();
    if (myLdgChargedHadronTrackRef.isNull()) continue;
    // FIXME: add a counter here
    
    // NOTE: No more continue-calls after this line!!!
    // Otherwise the data will be corrupt, since the data vector sizes will be different
    
    mySelectedPFTauRefs.push_back(myTauJetRef);
    
    // Set tau jet related variables
    math::XYZVector myJetVector = myTauJetRef->momentum();
    myDataJetE->push_back(myJetVector);
    // Leading charged hadron related
    math::XYZVector myLdgChargedHadronMomentum = myLdgChargedHadronTrackRef->momentum();
    myDataLdgChargedHadronP->push_back(myLdgChargedHadronMomentum);
    myDataLdgChargedHadronJetDR->push_back(deltaR(myJetVector, myLdgChargedHadronMomentum));
    myDataLdgChargedHadronHits->push_back(myLdgChargedHadronTrackRef->numberOfValidHits());
    myDataLdgChargedHadronNormalizedChi->push_back(myLdgChargedHadronTrackRef->normalizedChi2());
    // FIXME: add IP information
    myDataLdgChargedHadronIP->push_back(math::XYZVector(-1.,-1.,-1.));
    myDataLdgChargedHadronIPTSignificance->push_back(-1.);
    if (myJetVector.Mag2()) {
      myDataRtau->push_back(sqrt(myLdgChargedHadronMomentum.Mag2() / myJetVector.Mag2()));
    }
    
    // Track quality cuts have already been applied to all the PF tracks
    
    // Charged track isolation
    const PFCandidateRefVector& mySignalPFCandidates = myTauJetRef->signalPFCands(); // Leading track is included here 
    const PFCandidateRefVector& myIsolationPFCandidates = myTauJetRef->isolationPFCands(); // Leading track is included here
    RefVector<PFCandidateCollection>::const_iterator iTrack;
    // Count the number of signal tracks in the signal cone above a certain pt threshold
    int mySignalTrackCount = 0;
    int myChargeSum = 0;
    double myMinPt = 9999.;
    math::XYZVector myPtSum(0,0,0);
    for (iTrack = mySignalPFCandidates.begin(); iTrack != mySignalPFCandidates.end(); ++iTrack) {
      const reco::TrackRef myTrack = (*iTrack)->trackRef();
      if (myTrack.isNonnull()) {
        if ((*iTrack)->particleId() == reco::PFCandidate::h) { // Look at charged hadrons only
          double myTrackPt = myTrack->pt();
          if (myTrackPt > 1) {
            ++mySignalTrackCount;
            myChargeSum += myTrack->charge();
            myPtSum += myTrack->momentum();
            if (myTrackPt < myMinPt)
              myMinPt = myTrackPt;
          }
        }
      }
    }
    myDataChargeSum->push_back(myChargeSum);
    myDataTrIsoSignalTrackCount->push_back(mySignalTrackCount);
    myDataTrIsoLowestSignalTrackPt->push_back(myMinPt);
    double myHighestIsolationTrackPt = 0;
    int myIsolationTrackCount = 0;
    myMinPt = 9999.;
    for (iTrack = myIsolationPFCandidates.begin(); iTrack != myIsolationPFCandidates.end(); ++iTrack) {
      const reco::TrackRef myTrack = (*iTrack)->trackRef();
      if (myTrack.isNonnull()) {
        if ((*iTrack)->particleId() == reco::PFCandidate::h) { // Look at charged hadrons only
          double myTrackPt = myTrack->pt();
          if (myTrackPt > myHighestIsolationTrackPt) {
            myHighestIsolationTrackPt = myTrackPt;
            ++myIsolationTrackCount;
          }
          if (myTrackPt < myMinPt)
            myMinPt = myTrackPt;
        }
      }
    }
    myDataTrIsoIsolationTrackCount->push_back(myIsolationTrackCount);
    myDataTrIsoHighestIsolationTrackPt->push_back(myHighestIsolationTrackPt);
    myDataTrIsoIsolationMinTrackPt->push_back(myMinPt);
    myDataTrIsoIsolationMaxDz->push_back(-1.); // FIXME
    
    // Calorimetry related
    myDataEMFraction->push_back(myTauJetRef->emFraction());
    myDataMaxHCALOverLdgP->push_back(myTauJetRef->hcalMaxOverPLead());
    myDataECALIsolationET->push_back(myTauJetRef->isolationPFGammaCandsEtSum()); // nan if ldg track does not exist
    myDataMaxHCALClusterET->push_back(myTauJetRef->maximumHCALPFClusterEt());
    myDataChargedHadronET->push_back(sqrt(myPtSum.Perp2()));
    
    // Flight path - FIXME: move this code to the base class
    myDataFlightPathLength->push_back(math::XYZVector(-1.,-1.,-1.));
    myDataFlightPathTransverseSignificance->push_back(-1.);
    myDataFlightPathSignificance->push_back(-1.);
    
    // Invariant mass FIXME: move this code to the base class (if possible)
    myDataInvariantMassFromTracksOnly->push_back(-1.);
    myDataInvariantMassFull->push_back(-1.);

    // PF specific
    myDataPFElectronPreIDOutput->push_back(myTauJetRef->electronPreIDOutput());
    myDataPFElectronPreIDDecision->push_back(myTauJetRef->electronPreIDDecision());
    // Loop over all candidate tracks to calculate neutral hadron, gamma, and PF electron ET 
    
    myDataPFNeutralHadronET->push_back(-1.); // FIXME
    myDataPFGammaET->push_back(-1.); // FIXME
    myDataPFElectronET->push_back(-1.); // FIXME
  }
  
  // Put event data
  
  // Jet direction
  iEvent.put(myDataJetE, "jetE");
  // Leading track properties
  iEvent.put(myDataLdgChargedHadronP, "ldgChargedHadronP");
  iEvent.put(myDataLdgChargedHadronJetDR, "ldgChargedHadronJetDR");
  iEvent.put(myDataLdgChargedHadronHits, "ldgChargedHadronHits");
  iEvent.put(myDataLdgChargedHadronNormalizedChi, "ldgChargedHadronNormalizedChi");
  iEvent.put(myDataLdgChargedHadronIP, "ldgChargedHadronIP");
  iEvent.put(myDataLdgChargedHadronIPTSignificance, "ldgChargedHadronIPTSignificance");
  iEvent.put(myDataRtau, "Rtau");
  // Charge related
  iEvent.put(myDataChargeSum, "chargeSum");
  // Charged track isolation related
  iEvent.put(myDataTrIsoSignalTrackCount, "trIsoSignalTrackCount");
  iEvent.put(myDataTrIsoSignalMinTrackPt, "trIsoSignalMinTrackPt");
  iEvent.put(myDataTrIsoIsolationTrackCount, "trIsoIsolationTrackCount");
  iEvent.put(myDataTrIsoHighestIsolationTrackPt, "trIsoHighestIsolationTrackPt");
  iEvent.put(myDataTrIsoIsolationMinTrackPt, "trIsoIsolationMinTrackPt");
  iEvent.put(myDataTrIsoIsolationMaxDz, "trIsoIsolationMaxDz");
  // Jet energy details
  iEvent.put(myDataEMFraction, "EMFraction");
  iEvent.put(myDataMaxHCALOverLdgP, "maxHCALOverLdgP");
  iEvent.put(myDataECALIsolationET, "ECALIsolationET");
  iEvent.put(myDataMaxHCALClusterET, "maxHCALClusterET");
  iEvent.put(myDataChargedHadronET, "chargedHadronET");
  // Flight path related
  iEvent.put(myDataFlightPathLength, "flightPathLength");
  iEvent.put(myDataFlightPathTransverseSignificance, "flightPathTransverseSignificance");
  iEvent.put(myDataFlightPathSignificance, "flightPathSignificance");
  // Invariant mass related
  iEvent.put(myDataInvariantMassFromTracksOnly, "invariantMassFromTracksOnly");
  iEvent.put(myDataInvariantMassFull, "invariantMassFull");
  // PF specific
  iEvent.put(myDataPFElectronPreIDOutput, "PFElectronPreIDOutput");
  iEvent.put(myDataPFElectronPreIDDecision, "PFElectronPreIDDecision");
  iEvent.put(myDataPFNeutralHadronET, "PFNeutralHadronET");
  iEvent.put(myDataPFGammaET, "PFGammaET");
  iEvent.put(myDataPFElectronET, "PFElectronET");
  // Discriminators
  for (size_t j = 0; j < myDiscriminatorCount; ++j) {
    std::auto_ptr<std::vector<float> > myDiscriminatorValues(new std::vector<float>);
    for (std::vector<reco::PFTauRef>::const_iterator it = mySelectedPFTauRefs.begin(); it != mySelectedPFTauRefs.end(); ++it) {
      myDiscriminatorValues->push_back((*myDiscriminatorHandles[j])[*it]);
    }
    iEvent.put(myDiscriminatorValues, fTauDiscriminators[j].label());
  }
  // Other
  iEvent.put(myDataPV, "primaryVertex");
  
  myDiscriminatorHandles.clear();
}

}