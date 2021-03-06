#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TH1F.h"
#include "TNamed.h"

#include<limits>
#include<string>

class HPlusConfigInfoAnalyzer: public edm::EDAnalyzer {
 public:

  /// Default EDAnalyzer constructor
  explicit HPlusConfigInfoAnalyzer(const edm::ParameterSet&);
  /// Default EDAnalyzer destructor
  ~HPlusConfigInfoAnalyzer();

 private:
  /// Default EDAnalyzer method - called at the beginning of the job
  virtual void beginJob();
  /// Default EDAnalyzer method - called for each event
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);

  /// Default EDAnalyzer method - called at the end of the job
  virtual void endJob();

private:
  std::string dataVersion;
  std::string codeVersion;
  std::string era;
  std::string topPtReweightScheme;
  unsigned energy;
  double crossSection;
  const bool isPileupReweighted;
  bool isData;
  bool hasCrossSection;
  bool hasIsData;
};

HPlusConfigInfoAnalyzer::HPlusConfigInfoAnalyzer(const edm::ParameterSet& pset): 
  dataVersion(pset.getUntrackedParameter<std::string>("dataVersion", "")),
  codeVersion(pset.getUntrackedParameter<std::string>("codeVersion", "")),
  era(pset.getUntrackedParameter<std::string>("era", "")),
  topPtReweightScheme(pset.getUntrackedParameter<std::string>("topPtReweightScheme", "")),
  energy(pset.getUntrackedParameter<unsigned>("energy", 0)),
  crossSection(std::numeric_limits<double>::quiet_NaN()),
  isPileupReweighted(pset.getUntrackedParameter<bool>("isPileupReweighted", false)),
  isData(false),
  hasCrossSection(false), hasIsData(false)
{
  if(pset.exists("crossSection")) {
    crossSection = pset.getUntrackedParameter<double>("crossSection");
    hasCrossSection = true;
  }
  if(pset.exists("isData")) {
    isData = pset.getUntrackedParameter<bool>("isData");
    hasIsData = true;
  }
}

HPlusConfigInfoAnalyzer::~HPlusConfigInfoAnalyzer() {}

void HPlusConfigInfoAnalyzer::beginJob() {
}

void HPlusConfigInfoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
}

void HPlusConfigInfoAnalyzer::endJob() {
  edm::Service<TFileService> fs;

  int nbins = 3+hasCrossSection+hasIsData;
  TH1F *info = fs->make<TH1F>("configinfo", "configinfo", nbins, 0, nbins);

  int bin = 1;
  info->GetXaxis()->SetBinLabel(bin, "control");
  info->AddBinContent(bin, 1);
  ++bin;

  info->GetXaxis()->SetBinLabel(bin, "energy");
  info->AddBinContent(bin, energy);
  ++bin;

  if(hasCrossSection) {
    info->GetXaxis()->SetBinLabel(bin, "crossSection");
    info->AddBinContent(bin, crossSection);
    ++bin;
  }
  if(hasIsData) {
    info->GetXaxis()->SetBinLabel(bin, "isData");
    info->AddBinContent(bin, isData);
    ++bin;
  }
  info->GetXaxis()->SetBinLabel(bin, "isPileupReweighted");
  info->AddBinContent(bin, isPileupReweighted);
  ++bin;

  fs->make<TNamed>("dataVersion", dataVersion.c_str());
  fs->make<TNamed>("codeVersion", codeVersion.c_str());
  if(era.length() > 0)
    fs->make<TNamed>("era", era.c_str());
  if(topPtReweightScheme.length() > 0)
    fs->make<TNamed>("topPtReweightScheme", topPtReweightScheme.c_str());
}

//define this as a plug-in
DEFINE_FWK_MODULE(HPlusConfigInfoAnalyzer);
