#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/HistoWrapper.h"

namespace HPlus {

  HistoWrapper::HistoWrapper(EventWeight& eventWeight, std::string level):
    fEventWeight(eventWeight),
    fIsEnabled(true)
  { 
    // Find level from string
    if (level == "Systematics") {
      fAmbientLevel = kSystematics;
    } else if (level == "Vital") {
      fAmbientLevel = kVital;
    } else if (level == "Informative") {
      fAmbientLevel = kInformative;
    } else if (level == "Debug") {
      fAmbientLevel = kInformative;
    } else {
      throw cms::Exception("Configuration") << "HistoWrapper: Error in ambient histogram level! Valid options are: 'Systematics', 'Vital', 'Informative', 'Debug' (you specified: '" << level << "'";
    }
  }
  HistoWrapper::~HistoWrapper() {
    // Do not destroy histogram objects (they are owned by the root file)
    for (std::vector<WrappedTH1*>::iterator it = fAllTH1Histos.begin(); it != fAllTH1Histos.end(); ++it)
      delete *it;
    for (std::vector<WrappedTH2*>::iterator it = fAllTH2Histos.begin(); it != fAllTH2Histos.end(); ++it)
      delete *it;
    for (std::vector<WrappedTH3*>::iterator it = fAllTH3Histos.begin(); it != fAllTH3Histos.end(); ++it)
      delete *it;
  }

  bool HistoWrapper::checkIfDirExists(TDirectory* d, std::string name) const {
    for (int i = 0; i < d->GetNkeys(); ++i) {
      std::string s = d->GetListOfKeys()->At(i)->GetTitle();
      if (s == name)
        return true;
    }
    return false;
  }

  WrappedTH1::WrappedTH1(HistoWrapper& histoWrapper, TH1* histo, HistoWrapper::HistoLevel level)
  : fHistoWrapper(histoWrapper),
  h(histo),
  fLevel(level) { }

  WrappedTH1::~WrappedTH1() { }

  WrappedTH2::WrappedTH2(HistoWrapper& histoWrapper, TH2* histo, HistoWrapper::HistoLevel level)
  : fHistoWrapper(histoWrapper),
  h(histo),
  fLevel(level) { }

  WrappedTH2::~WrappedTH2() { }

  WrappedTH3::WrappedTH3(HistoWrapper& histoWrapper, TH3* histo, HistoWrapper::HistoLevel level)
  : fHistoWrapper(histoWrapper),
  h(histo),
  fLevel(level) { }

  WrappedTH3::~WrappedTH3() { }

}
