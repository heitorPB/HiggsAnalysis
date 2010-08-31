#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/HPlusMultiHistoAnalyzer.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/HPlusExpressionEfficiencyHisto.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/Candidate/interface/Candidate.h"

typedef HPlusMultiHistoAnalyzer<reco::CandidateView, HPlusExpressionEfficiencyHistoPerObject> HPlusCandViewMultiEfficiencyPerObjectAnalyzer;

DEFINE_FWK_MODULE( HPlusCandViewMultiEfficiencyPerObjectAnalyzer );
