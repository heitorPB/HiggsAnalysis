// -*- c++ -*-
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/CommonPlots.h"

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventCounter.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/HistoWrapper.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TransverseMass.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/DeltaPhi.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include <sstream>

namespace HPlus {
  CommonPlotsFilledAtEveryStep::CommonPlotsFilledAtEveryStep(HistoWrapper& histoWrapper, std::string label, bool enterSelectionFlowPlot, std::string selectionFlowPlotLabel) :
    fDataObjectsCached(false),
    fEnterSelectionFlowPlot(enterSelectionFlowPlot),
    fSelectionFlowPlotLabel(selectionFlowPlotLabel) {
    // Create directory for histogram
    edm::Service<TFileService> fs;
    std::stringstream myStream;
    myStream << "CommonPlots_" << label;
    TFileDirectory myDir = fs->mkdir(myStream.str().c_str());
    // Create histograms
    hNVertices = histoWrapper.makeTH<TH1F>(HistoWrapper::kVital, myDir, "nVertices", "Number of vertices;N_{vertices};N_{events}", 60, 0, 60);
  }

  CommonPlotsFilledAtEveryStep::~CommonPlotsFilledAtEveryStep() {}

  void CommonPlotsFilledAtEveryStep::fill() {
     // Safety check
     if (!fDataObjectsCached)
       throw cms::Exception("Assert") << "CommonPlotsFilledAtEveryStep: data objects have not been cached! (did you forget to call CommonPlotsFilledAtEveryStep::cacheDataObjects from CommonPlots::initialize?)";
    hNVertices->Fill(fNVertices);
    if (!fVertexData->passedEvent()) return; // Plots do not make sense if no PV has been found
    
  }

  void CommonPlotsFilledAtEveryStep::cacheDataObjects(int nVertices,
                                                      const VertexSelection::Data* vertexData,
                                                      const TauSelection::Data* tauData,
                                                      const GlobalElectronVeto::Data* electronData) {
    fNVertices = nVertices;
    fVertexData = vertexData;
    fTauData = tauData;
    fElectronData = electronData;
    fDataObjectsCached = true;
  }

  // ====================================================================================================

  CommonPlots::CommonPlots(const edm::ParameterSet& iConfig, EventCounter& eventCounter, HistoWrapper& histoWrapper) :
    bDataObjectsCached(false),
    fEventCounter(eventCounter),
    fHistoWrapper(histoWrapper) {
    // Create histograms
    
  }

  CommonPlots::~CommonPlots() {
    for (std::vector<CommonPlotsFilledAtEveryStep*>::iterator it = hEveryStepHistograms.begin(); it < hEveryStepHistograms.end(); ++it)
      delete (*it);
    hEveryStepHistograms.clear();
  }

  void CommonPlots::initialize(const edm::Event& iEvent,
                               const edm::EventSetup& iSetup,
                               int nVertices,
                               VertexSelection& vertexSelection,
                               TauSelection& tauSelection,
                               GlobalElectronVeto& eVeto) {
    // Obtain data objects only, if they have not yet been cached
    if (bDataObjectsCached) return;
    bDataObjectsCached = true;

    // Obtain data objects
    fVertexData = vertexSelection.silentAnalyze(iEvent, iSetup);
    if (!fVertexData.passedEvent()) return; // Plots do not make sense if no PV has been found
    fTauData = tauSelection.silentAnalyze(iEvent, iSetup, fVertexData.getSelectedVertex()->z());
    fElectronData = eVeto.silentAnalyze(iEvent, iSetup);

    // Pass pointer to cached data objects to CommonPlotsFilledAtEveryStep
    if (!hEveryStepHistograms.size())
      throw cms::Exception("Assert") << "CommonPlots::initialize() was called before creating CommonPlots::createCommonPlotsFilledAtEveryStep()!" << endl<<  "  make first all CommonPlots::createCommonPlotsFilledAtEveryStep() and then call CommonPlots::initialize()";
    for (std::vector<CommonPlotsFilledAtEveryStep*>::iterator it = hEveryStepHistograms.begin(); it != hEveryStepHistograms.end(); ++it) {
      (*it)->cacheDataObjects(fNVertices,
                              &fVertexData,
                              &fTauData,
                              &fElectronData);
    }
  }

  CommonPlotsFilledAtEveryStep* CommonPlots::createCommonPlotsFilledAtEveryStep(std::string label, bool enterSelectionFlowPlot, std::string selectionFlowPlotLabel) {
    // Create and return object, but sneakily save the pointer for later use
    CommonPlotsFilledAtEveryStep* myObject = new CommonPlotsFilledAtEveryStep(fHistoWrapper, label, enterSelectionFlowPlot, selectionFlowPlotLabel);
    hEveryStepHistograms.push_back(myObject);
    return myObject;
  }

  void CommonPlots::fillControlPlots(const TriggerSelection::Data& data) {
    
  }

  void CommonPlots::fillControlPlots(const VertexSelection::Data& data) {
    
  }

  void CommonPlots::fillControlPlots(const TauSelection::Data& data) {
    
  }

  void CommonPlots::fillControlPlots(const GlobalElectronVeto::Data& data) {
    
  }


}