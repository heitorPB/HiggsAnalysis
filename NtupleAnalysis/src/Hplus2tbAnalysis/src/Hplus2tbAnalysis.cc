// -*- c++ -*-
#include "Framework/interface/BaseSelector.h"
#include "Framework/interface/makeTH.h"

#include "EventSelection/interface/CommonPlots.h"
#include "EventSelection/interface/EventSelections.h"

#include "DataFormat/interface/Event.h"

#include "TDirectory.h"

#include "Math/VectorUtil.h"

class Hplus2tbAnalysis: public BaseSelector {
public:
	explicit Hplus2tbAnalysis(const ParameterSet& config, const TH1* skimCounters);
	virtual ~Hplus2tbAnalysis() {}

	/// Books histograms
	virtual void book(TDirectory *dir) override;
	/// Sets up branches for reading the TTree
	virtual void setupBranches(BranchManager& branchManager) override;
	/// Called for each event
	virtual void process(Long64_t entry) override;

private:
	// Input parameters

	/// Common plots
	CommonPlots fCommonPlots;
	// Event selection classes and event counters (in same order like they are applied)
	Count cAllEvents;
	Count cTrigger;
	METFilterSelection fMETFilterSelection;
	Count cVertexSelection;
	TauSelection fTauSelection;
	//Count cFakeTauSFCounter;
	//Count cTauTriggerSFCounter;
	Count cMetTriggerSFCounter;
	ElectronSelection fElectronSelection;
	MuonSelection fMuonSelection;
	JetSelection fJetSelection;
	BJetSelection fBJetSelection;
	Count cBTaggingSFCounter;
	METSelection fMETSelection;
	Count cSelected;

	// Non-common histograms
	// Associated quarks histos
	// Top quark histos
	WrappedTH1 *hAssociatedTPt;
	WrappedTH1 *hAssociatedTEta;
	WrappedTH1 *hAssociatedTPhi;
	// B quark histos
	WrappedTH1 *hAssociatedBPt;
	WrappedTH1 *hAssociatedBEta;
	WrappedTH1 *hAssociatedBPhi;

	// H+ decay to quarks histos
	// Top
	WrappedTH1 *hHplusToTPt;
	WrappedTH1 *hHplusToTEta;
	WrappedTH1 *hHplusToTPhi;
	// B
	WrappedTH1 *hHplusToBPt;
	WrappedTH1 *hHplusToBEta;
	WrappedTH1 *hHplusToBPhi;

	// Generator level MET of the Event
	WrappedTH1 *hGenMetEt;
	WrappedTH1 *hGenMetPhi;

	// H+
	WrappedTH1 *hHplusPt;
	WrappedTH1 *hHplusEta;
	WrappedTH1 *hHplusPhi;

	// HT - scalar sum of quarks t and b Pt
	WrappedTH1 *hGenHt;

	// number of jets
	WrappedTH1 *hNGenJets;

	// reco objects
	// MET
	WrappedTH1 *hMetEt;
	WrappedTH1 *hMetPhi;

	// HT
	WrappedTH1 *hHt;

	// number of jets
	WrappedTH1 *hNJets;
	WrappedTH1 *hNBJets;

	// leading jet pt
	WrappedTH1 *hLeadingJetPt;
	WrappedTH1 *hLeadingBJetPt;

	// jets eta
	WrappedTH1 *hJetEta;
	WrappedTH1 *hBJetEta;
};

#include "Framework/interface/SelectorFactory.h"
REGISTER_SELECTOR(Hplus2tbAnalysis);

Hplus2tbAnalysis::Hplus2tbAnalysis(const ParameterSet& config, const TH1* skimCounters)
: BaseSelector(config, skimCounters),
	fCommonPlots(config.getParameter<ParameterSet>("CommonPlots"), CommonPlots::kHplus2tbAnalysis, fHistoWrapper),
	cAllEvents(fEventCounter.addCounter("All events")),
	cTrigger(fEventCounter.addCounter("Passed trigger")),
	fMETFilterSelection(config.getParameter<ParameterSet>("METFilter"),
	                    fEventCounter, fHistoWrapper, &fCommonPlots, ""),
	cVertexSelection(fEventCounter.addCounter("Primary vertex selection")),
	fTauSelection(config.getParameter<ParameterSet>("TauSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, ""),
	//cFakeTauSFCounter(fEventCounter.addCounter("Fake tau SF")),
	//cTauTriggerSFCounter(fEventCounter.addCounter("Tau trigger SF")),
	cMetTriggerSFCounter(fEventCounter.addCounter("Met trigger SF")),
	fElectronSelection(config.getParameter<ParameterSet>("ElectronSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, "Veto"),
	fMuonSelection(config.getParameter<ParameterSet>("MuonSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, "Veto"),
	fJetSelection(config.getParameter<ParameterSet>("JetSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, ""),
	fBJetSelection(config.getParameter<ParameterSet>("BJetSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, ""),
	cBTaggingSFCounter(fEventCounter.addCounter("b tag SF")),
	fMETSelection(config.getParameter<ParameterSet>("METSelection"),
	              fEventCounter, fHistoWrapper, &fCommonPlots, ""),
	cSelected(fEventCounter.addCounter("Selected events"))
{ }

void Hplus2tbAnalysis::book(TDirectory *dir) {
	// Book common plots histograms
	fCommonPlots.book(dir, isData());
	// Book histograms in event selection classes
	fMETFilterSelection.bookHistograms(dir);
	fTauSelection.bookHistograms(dir);
	fElectronSelection.bookHistograms(dir);
	fMuonSelection.bookHistograms(dir);
	fJetSelection.bookHistograms(dir);
	fBJetSelection.bookHistograms(dir);
	fMETSelection.bookHistograms(dir);
	// Book non-common histograms
	//hExample =  fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "example pT", "example pT", 40, 0, 400);
	hAssociatedTPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedTPt",  "Associated t pT",  100,  0, 1000);
	hAssociatedTEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedTEta", "Associated t eta", 50,  -3, 3);
	hAssociatedTPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedTPhi", "Associated t phi", 100, -3.1416, 3.1416);

	hAssociatedBPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedBPt",  "Associated b pT",  100, 0, 1000);
	hAssociatedBEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedBEta", "Associated b eta", 50, -3, 3);
	hAssociatedBPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "associatedBPhi", "Associated b phi", 100, -3.1416, 3.1416);

	hHplusToTPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToTPt",  "H+ to t pT",  100, 0, 1000);
	hHplusToTEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToTEta", "H+ to t eta", 50, -2.5, 2.5);
	hHplusToTPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToTPhi", "H+ to t phi", 100, -3.1416, 3.1416);

	hHplusToBPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToBPt",  "H+ to b pT",  100, 0, 1000);
	hHplusToBEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToBEta", "H+ to b eta", 50, -2.5, 2.5);
	hHplusToBPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusToBPhi", "H+ to b phi", 100, -3.1416, 3.1416);

	hGenMetEt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "genMetEt",  "Gen MET",     100, 0, 1000);
	hGenMetPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "genMetPhi", "Gen MET phi", 100, -3.1416, 3.1416);

	hHplusPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusPt",  "Hplus pT",  100, 0, 1000);
	hHplusEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusEta", "Hplus eta", 50, -2.5, 2.5);
	hHplusPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "HplusPhi", "Hplus phi", 100, -3.1416, 3.1416);

	hGenHt = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "genHt",  "Gen Ht", 140, 200, 2000);

	hNGenJets = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "nGenJets",  "nGenJets", 40, 0, 40);


	hMetEt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MetEt",  "MET",     150, 0, 1500);
	hMetPhi = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "MetPhi", "MET phi", 100, -3.1416, 3.1416);

	hHt = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "Ht",  "Ht", 300, 0, 3000);

	hNJets  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "nJets",  "nJets",  40, 0, 40);
	hNBJets = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "nBJets", "nBJets", 10, 0, 10);

	hLeadingJetPt  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "LeadingJetPt",  "Leading Jet pT",   150, 0, 1500);
	hLeadingBJetPt = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "LeadingBJetPt", "Leading B Jet pT", 150, 0, 1500);

	hJetEta  = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "JetsEta",  "Jets Eta",   50, -5.5, 5.5);
	hBJetEta = fHistoWrapper.makeTH<TH1F>(HistoLevel::kInformative, dir, "BJetsEta", "B Jets Eta", 50, -5.5, 5.5);
}

void Hplus2tbAnalysis::setupBranches(BranchManager& branchManager) {
	fEvent.setupBranches(branchManager);
}

void Hplus2tbAnalysis::process(Long64_t entry) {

//====== Initialize
	fCommonPlots.initialize();
	fCommonPlots.setFactorisationBinForEvent(std::vector<float> {});

	cAllEvents.increment();

//====== Apply trigger
//	if (!(fEvent.passTriggerDecision()))
//		return;
	cTrigger.increment();
	int nVertices = fEvent.vertexInfo().value();
	fCommonPlots.setNvertices(nVertices);
	fCommonPlots.fillControlPlotsAfterTrigger(fEvent);

//====== MET filters to remove events with spurious sources of fake MET
	const METFilterSelection::Data metFilterData = fMETFilterSelection.analyze(fEvent);
	//if (!metFilterData.passedSelection())
	//	return;

//====== GenParticle analysis
	for (auto& p: fEvent.genparticles().getGenParticles()) {
		int genP_pdgId = p.pdgId();
		auto mother_index = p.mother();
		int mother_pdgId = -66642137;

		if (mother_index >= 0) {
			const Particle<ParticleCollection<double>> m = fEvent.genparticles().getGenParticles()[mother_index];
			mother_pdgId = m.pdgId();
		}

		// top quark
		if(std::abs(genP_pdgId) == 6){
			// if mother is H+
			if (std::abs(mother_pdgId) == 37) {
				hHplusToTPt->Fill(p.pt());
				hHplusToTEta->Fill(p.eta());
				hHplusToTPhi->Fill(p.phi());
			} else {
				hAssociatedTPt->Fill(p.pt());
				hAssociatedTEta->Fill(p.eta());
				hAssociatedTPhi->Fill(p.phi());
			}
		// b quark
		} else if (std::abs(genP_pdgId) == 5) {
			if (std::abs(mother_pdgId) == 37) {
				hHplusToBPt->Fill(p.pt());
				hHplusToBEta->Fill(p.eta());
				hHplusToBPhi->Fill(p.phi());
			} else {
				hAssociatedBPt->Fill(p.pt());
				hAssociatedBEta->Fill(p.eta());
				hAssociatedBPhi->Fill(p.phi());
			}
		// H+
		} else if (std::abs(genP_pdgId) == 37) {
			hHplusPt->Fill(p.pt());
			hHplusEta->Fill(p.eta());
			hHplusPhi->Fill(p.phi());
		}
	}

	double genHT = 0;
	int nGenJets = 0;
	for (const auto& j: fEvent.genjets()) {
		genHT += j.pt();
		nGenJets++;
	}
	hGenHt->Fill(genHT);
	hNGenJets->Fill(nGenJets);

	// Event Gen MET
	hGenMetEt->Fill(fEvent.genMET().et());
	hGenMetPhi->Fill(fEvent.genMET().phi());

//====== Check that primary vertex exists
	if (nVertices < 1)
		return;
	cVertexSelection.increment();
	fCommonPlots.fillControlPlotsAtVertexSelection(fEvent);

//====== Tau selection
	//const TauSelection::Data tauData = fTauSelection.analyze(fEvent);
	const TauSelection::Data tauData = fTauSelection.silentAnalyze(fEvent);
	if (tauData.hasIdentifiedTaus())
		return;

//====== Fake tau SF
	//if (fEvent.isMC()) {
	//	fEventWeight.multiplyWeight(tauData.getTauMisIDSF());
	//	cFakeTauSFCounter.increment();
	//}

//====== Tau trigger SF
	//if (fEvent.isMC()) {
	//	fEventWeight.multiplyWeight(tauData.getTauTriggerSF());
	//	cTauTriggerSFCounter.increment();
	//}

//====== MET trigger SF
	//const METSelection::Data silentMETData = fMETSelection.silentAnalyze(fEvent, nVertices);
	//if (fEvent.isMC()) {
	//	fEventWeight.multiplyWeight(silentMETData.getMETTriggerSF());
	//}
	//cMetTriggerSFCounter.increment();
	//fCommonPlots.fillControlPlotsAfterMETTriggerScaleFactor(fEvent);
	//std::cout << tauData.getSelectedTau().pt() << ":" << tauData.getTauMisIDSF() << ", " << tauData.getTauTriggerSF() << ", met=" << silentMETData.getMET().R() << ", SF=" << silentMETData.getMETTriggerSF() << std::endl;

//====== Electron veto
	const ElectronSelection::Data eData = fElectronSelection.analyze(fEvent);
	if (eData.hasIdentifiedElectrons())
		return;

//====== Muon veto
	const MuonSelection::Data muData = fMuonSelection.analyze(fEvent);
	if (muData.hasIdentifiedMuons())
		return;

//====== Jet selection
	//const JetSelection::Data jetData = fJetSelection.analyze(fEvent, tauData.getSelectedTau());
	const JetSelection::Data jetData = fJetSelection.analyzeWithoutTau(fEvent);
	if (!jetData.passedSelection())
		return;

//====== Point of standard selections
	//fCommonPlots.fillControlPlotsAfterTopologicalSelections(fEvent);

//====== b-jet selection
	const BJetSelection::Data bjetData = fBJetSelection.analyze(fEvent, jetData);
	if (!bjetData.passedSelection())
		return;

//====== b tag SF
	//if (fEvent.isMC()) {
	//	fEventWeight.multiplyWeight(bjetData.getBTaggingScaleFactorEventWeight());
	//}
	//cBTaggingSFCounter.increment();

//====== MET selection
	//const METSelection::Data METData = fMETSelection.analyze(fEvent, nVertices);
	//if (!METData.passedSelection())
	//	return;

//====== All cuts passed
	cSelected.increment();
	// TODO Fill final plots
	//fCommonPlots.fillControlPlotsAfterAllSelections(fEvent);

//====== Experimental selection code
	// if necessary

	// RECO

	// Jets
	double recoHT = 0;
	int nJets = 0;
	double maxPt = 0;
	for (const auto& j: fEvent.jets()) {
		double jet_pt = j.pt();
		recoHT += jet_pt;

		nJets++;

		if (jet_pt > maxPt)
			maxPt = jet_pt;
	}

	// HT selection
	if (recoHT < 300)
		return;

	for (const auto& j: fEvent.jets())
		hJetEta->Fill(j.eta());

	hHt->Fill(recoHT);
	hNJets->Fill(nJets);
	hLeadingJetPt->Fill(maxPt);

	// MET
	hMetEt->Fill(fEvent.met().et());
	hMetPhi->Fill(fEvent.met().phi());

	// B jets
	hNBJets->Fill(bjetData.getNumberOfSelectedBJets());
	maxPt = 0;
	for (const auto& bjet: bjetData.getSelectedBJets()) {
		if (bjet.pt() > maxPt)
			maxPt = bjet.pt();

		hBJetEta->Fill(bjet.eta());
	}
	hLeadingBJetPt->Fill(maxPt);

	//====== Finalize
	fEventSaver.save();
}
