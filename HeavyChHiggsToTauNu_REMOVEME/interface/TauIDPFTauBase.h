// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_TauIDPFTauBase_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_TauIDPFTauBase_h

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TauIDBase.h"

namespace HPlus {
  class TauIDPFTauBase : public TauIDBase {
  public:

    /**
     * Base class for PF tau ID operations.
     * Actual tau ID specific classes are inherited from this class.
     */
    TauIDPFTauBase(const edm::ParameterSet& iConfig, EventCounter& eventCounter, HistoWrapper& histoWrapper, const std::string& baseLabel, TFileDirectory& myDir);
    virtual ~TauIDPFTauBase();

    /// Returns true, if the tau candidate conditions are fulfilled (jet et, eta, ldg pt, e/mu veto) 
    bool passLeadingTrackCuts(const edm::Ptr<pat::Tau> tau);
    bool passNProngsCut(const edm::Ptr<pat::Tau> tau);
    size_t getNProngs(const edm::Ptr<pat::Tau> tau) const;
    bool passRTauCut(const edm::Ptr<pat::Tau> tau);
    double getRtauValue(const edm::Ptr<pat::Tau> tau) const;
    
  protected:
    // Tau ID selections concerning isolation (track, ECAL) are implemented in the specific tau ID classes

  private:
    WrappedTH1* hRtauOneProngZeroPiZero;
    WrappedTH1* hRtauOneProngOnePiZero;
    WrappedTH1* hRtauOneProngTwoPiZero;
    WrappedTH1* hRtauOneProngOther;
    WrappedTH1* hRtauThreeProngZeroPiZero;
    WrappedTH1* hRtauThreeProngOnePiZero;
    WrappedTH1* hRtauThreeProngOther;
  };
}

#endif
