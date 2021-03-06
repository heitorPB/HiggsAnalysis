## \package multicrabDatasetsCollisionData11May10
#
# Dataset definitions for partial Run2011 (160431-163869) May10 ReReco (with CMSSW 42X)
#
# \see multicrab

import multicrabDatasetsCommon as common

## Dataset definitions
datasets = {
    # Single tau + MET
    "Tau_160431-161176_May10": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_IsoPFTau35_Trk20_MET45_v1",
        "runs": (160431, 161176), #
        "data": {
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-May10ReReco_v1_AOD_160431_pattuple_v18-344241722cb53b6dc9e6433dfd125850/USER",
                "luminosity": 6.625000,
                "number_of_jobs": 1
            },
            "pattuple_v18_2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_160431_pattuple_v18_2-322d7a6c0312354f16bad76dbf6f2f25/USER",
                "number_of_jobs": 1
            },
            "pattuple_v18_3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_160431_pattuple_v18_3-172ee752d8cdcf2479297bbcbbc450d7/USER",
                "number_of_jobs": 2,
                "args": {"doTauHLTMatchingInAnalysis": "1"},
            },
        }
    },
    "Tau_161217-163261_May10": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_IsoPFTau35_Trk20_MET45_v2",
        "runs": (161217, 163261),
        "data": {
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-May10ReReco_v1_AOD_161217_pattuple_v18-69a11d04d01ec96141c740547251864b/USER",
                "luminosity": 40.762000,
                "number_of_jobs": 1
            },
            "pattuple_v18_2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_161217_pattuple_v18_2-bc9738b682323bfade84362bc601e919/USER",
                "number_of_jobs": 1
            },
            "pattuple_v18_3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_161217_pattuple_v18_3-682e73b78660242aaa9ad84acfbb905d/USER",
                "number_of_jobs": 2,
                "args": {"doTauHLTMatchingInAnalysis": "1"},
            },
        },
    },
    "Tau_163270-163869_May10": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_IsoPFTau35_Trk20_MET45_v4",
        "runs": (163270, 163869),
        "data": {
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-May10ReReco_v1_AOD_163270_pattuple_v18-62e2e156bbf332fdc6c67ab8a6d7a4f0/USER",
                "luminosity": 167.786000,
                "number_of_jobs": 2
            },
            "pattuple_v18_2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_163270_pattuple_v18_2-299981d469467ce228236455770c7bc0/USER",
                "number_of_jobs": 2
            },
            "pattuple_v18_3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_163270_pattuple_v18_3-38e5d5a54e09db68c85b134fff29b7ae/USER",
                "number_of_jobs": 4,
                "args": {"doTauHLTMatchingInAnalysis": "1"},
            },
        }
    },
    "Tau_160431-163869_May10": {
        "dataVersion": "42Xdata",
        "args": {"triggerThrow": 0}, # needed for OR of triggers in separate run ranges
        "triggerOR": [
            "HLT_IsoPFTau35_Trk20_MET45_v1", # 160431-161176
            "HLT_IsoPFTau35_Trk20_MET45_v2", # 161217-163261
            "HLT_IsoPFTau35_Trk20_MET45_v4", # 163270-163869
        ],
        "runs": (160431, 163869),
        "data": {
            "AOD": {
                "datasetpath": "/Tau/Run2011A-May10ReReco-v1/AOD",
                "number_of_jobs": 350, # Adjusted for PATtuple file size
                "lumiMask": "DCSONLY11"
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tau/local-Run2011A_May10ReReco_v1_AOD_160431_pattuple_v19-95bdfb89e63988c1ffa2ad610b62da8e/USER",
                "luminosity": 216.149000,
                "number_of_jobs": 6
            },
        }
    },

    # Single Mu
    "SingleMu_160431-163261_May10": {
        "dataVersion": "42Xdata",
        "args": {"doTauHLTMatching": 0},
        "triggerOR": [
            "HLT_Mu20_v1", "HLT_IsoMu12_v1", # not prescaled
            "HLT_Mu15_v2", # prescaled
            ],
        "runs": (160431, 163261),
        "data": {
            "AOD": {
                "datasetpath": "/SingleMu/Run2011A-May10ReReco-v1/AOD",
                "number_of_jobs": 1000, # Adjusted for PATtuple file size (~430 in reality)
                "lumiMask": "DCSONLY11"
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/SingleMu/local-Run2011A_May10ReReco_v1_AOD_160431_pattuple_v19b-c0ae6cd4b6a7f4894060bf4c50b6b08b/USER",
                "luminosity": 47.008000,
                "number_of_jobs": 15
            },
        }
    }, 
   "SingleMu_163270-163869_May10": {
        "dataVersion": "42Xdata",
        "args": {"doTauHLTMatching": 0},
        "triggerOR": [
            "HLT_Mu24_v2", "HLT_IsoMu17_v6", # not prescaled
            "HLT_Mu15_v3", "HLT_Mu20_v2", "HLT_IsoMu15_v6", # prescaled
            ],
        "runs": (163270, 163869),
        "data": {
            "AOD": {
                "datasetpath": "/SingleMu/Run2011A-May10ReReco-v1/AOD",
                "number_of_jobs": 1000, # Adjusted for PATtuple file size (~390 in reality)
                "lumiMask": "DCSONLY11"
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/SingleMu/local-Run2011A_May10ReReco_v1_AOD_163270_pattuple_v19b-4be8b2cd98e864fb2d0886a3cbadb57d/USER",
                "luminosity": 164.500000,
                "number_of_jobs": 20
            },
        },
    },


    # Single Mu for tau embedding skims
    "SingleMu_Mu_160431-163261_May10": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_Mu20_v1",
        "runs": (160431, 163261),
        "data": {
            "AOD": {
                "datasetpath": "/SingleMu/Run2011A-May10ReReco-v1/AOD",
                "number_of_jobs": 120, # Adjusted for skim file size
                "lumiMask": "May10ReReco"
            },
        }
    }, 
    "SingleMu_Mu_161119-161119_May10_Wed": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_Mu20_v1",
        "runs": (161119, 161119),
        "data": {
        }
    },
   "SingleMu_Mu_163270-163869_May10": {
        "dataVersion": "42Xdata",
        "trigger": "HLT_Mu24_v2",
        "runs": (163270, 163869),
        "data": {
            "AOD": {
                "datasetpath": "/SingleMu/Run2011A-May10ReReco-v1/AOD",
                "number_of_jobs": 140, # Adjusted for skim file size
                "lumiMask": "May10ReReco"
            },
        },
    },
}
