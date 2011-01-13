import multicrabDatasetsCommon as common

datasets = {
    # Signal
    "TTToHplusBWB_M90": {
        "dataVersion": "38Xrelval", # The trigger process was HLT, hence 38Xrelval is suitable here
        "crossSection": 16.442915,
        "data": {
            "RECO": {
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20, # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-78d4b6b79bb86567b5da3e176aad4eb3/USER",
                "number_of_jobs": 1
            },
            "pattuple_v7_test2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v7_test2-cdb56ea6d6415310da94b31a48308b73/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M100": {
        "dataVersion": "38Xrelval",
        "crossSection": 14.057857,
        "data": {
            "RECO": {
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20, # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-78d4b6b79bb86567b5da3e176aad4eb3/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M120": {
        "dataVersion": "38Xrelval",
        "crossSection": 8.984715,
        "data": {
            "RECO": {
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20, # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-78d4b6b79bb86567b5da3e176aad4eb3/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M140": {
        "dataVersion": "38Xrelval",
        "crossSection": 4.223402,
        "data": {
            "RECO": {
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20,
            },
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-78d4b6b79bb86567b5da3e176aad4eb3/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M160": {
        "dataVersion": "38Xrelval",
        "crossSection": 0.811493,
        "data": {
            "RECO": {
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20, # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-78d4b6b79bb86567b5da3e176aad4eb3/USER",
                "number_of_jobs": 1
            },
            "pattuple_v7_test2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v7_test2-cdb56ea6d6415310da94b31a48308b73/USER",
                "number_of_jobs": 1
            },
        }
    },

    # QCD Fall10
    "QCD_Pt30to50_Fall10": {
        "dataVersion": "38X",
        "crossSection": 5.312e+07,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_30to50_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt_30to50_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
            "pattuple_v3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_30to50_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_AODSIM-pattuple_v3-77a027b4f9e83a8f0edf7612e8721105/USER",
                "number_of_jobs": 10
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_30to50_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-38ae4fe7f537aab1b1e19a9c13e79d63/USER",
                "number_of_jobs": 10
            }
        },
    },
    "QCD_Pt50to80_Fall10": {
        "dataVersion": "38X",
        "crossSection": 6.359e+06,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_50to80_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt_50to80_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
            "pattuple_v3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_50to80_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_AODSIM-pattuple_v3-77a027b4f9e83a8f0edf7612e8721105/USER",
                "number_of_jobs": 10
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_50to80_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-38ae4fe7f537aab1b1e19a9c13e79d63/USER",
                "number_of_jobs": 10
            },
        },
    },
    "QCD_Pt80to120_Fall10": {
        "dataVersion": "38X",
        "crossSection": 7.843e+05,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_80to120_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt_80to120_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
            "pattuple_v3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_80to120_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_AODSIM-pattuple_v3-77a027b4f9e83a8f0edf7612e8721105/USER",
                "number_of_jobs": 10
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_80to120_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1-38ae4fe7f537aab1b1e19a9c13e79d63/USER",
                "number_of_jobs": 10
            }
        },
    },
    "QCD_Pt120to170_Fall10": {
        "dataVersion": "38X",
        "crossSection": 1.151e+05,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_120to170_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt_120to170_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
            "pattuple_v3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_120to170_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_AODSIM-pattuple_v3-77a027b4f9e83a8f0edf7612e8721105/USER",
                "number_of_jobs": 10
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_120to170_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-38ae4fe7f537aab1b1e19a9c13e79d63/USER",
                "number_of_jobs": 10
            }
        },
    },
    "QCD_Pt170to300_Fall10": {
        "dataVersion": "38X",
        "crossSection": 2.426e+04,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_170to300_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt_170to300_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
            "pattuple_v3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_170to300_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_AODSIM-pattuple_v3-77a027b4f9e83a8f0edf7612e8721105/USER",
                "number_of_jobs": 10
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt_170to300_TuneZ2_7TeV_pythia6/local-Fall10_START38_V12_v1_GEN-SIM-RECO_pattuple_v6_1b-38ae4fe7f537aab1b1e19a9c13e79d63/USER",
                "number_of_jobs": 10
            }
        },
    },
    "QCD_Pt300to470_Fall10": {
        "dataVersion": "38X",
        "crossSection": 1.168e+03,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt_170to300_TuneZ2_7TeV_pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
        },
    },


    # Electroweak (Fall10)
    "TT": {
        "dataVersion": "38Xrelval",
        "crossSection": 165,
        "data": {
            "RECO": {
                "datasetpath": "/TT_TuneZ2_7TeV-pythia6-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 100 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TT_TuneZ2_7TeV-pythia6-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 100,
            }
        },
    },
    "TTJets": {
        "dataVersion": "38Xrelval",
        "crossSection": 165,
        "data": {
            "RECO": {
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/Fall10-START38_V12-v2/GEN-SIM-RECO",
                "number_of_jobs": 100 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/Fall10-START38_V12-v2/AODSIM",
                "number_of_jobs": 100,
            },
            "pattuple_v6": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/local-Fall10_START38_V12_v2_GEN-SIM-RECO_pattuple_v6_1-07f034ca14f38db495c4c9937f852e0b/USER",
                "number_of_jobs": 5
            }
        },
    },
    "WJets_Fall10": {
        "dataVersion": "38Xrelval",
        "crossSection": 24640,
        "data": {
            "RECO": {
                "datasetpath": "/WJetsToLNu_TuneZ2_7TeV-madgraph-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 1000,
                "use_server": 1,
            },
            "AOD": {
                "datasetpath": "/WJetsToLNu_TuneZ2_7TeV-madgraph-tauola/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 1000,
                "use_server": 1,
            },
        },
    },


    # Backgrounds for electroweak background measurement (Fall10)
    "QCD_Pt20_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 296600000.*0.0002855,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-20_MuEnrichedPt-15_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 200, # Adjusted for PAT on the fly
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-20_MuEnrichedPt-15_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 200,
            }
        },
    },
    "QCD_Pt20to30_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 236300000*0.00518,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-20to30_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-20to30_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
        },
    },
    "QCD_Pt30to50_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 53070000*0.01090,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-30to50_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-30to50_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
        },
    },
    "QCD_Pt50to80_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 6351000*0.02274,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-50to80_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 150 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-50to80_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 150,
            },
        },
    },
    "QCD_Pt80to120_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 785100*0.03700,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-80to120_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 100 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-80to120_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 100,
            },
        },
    },
    "QCD_Pt120to150_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 92950*0.04777,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-120to150_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 40 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-120to150_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 40,
            },
        },
    },
    "QCD_Pt150_MuEnriched": {
        "dataVersion": "38X",
        "crossSection": 47580*0.05964,
        "data": {
            "RECO": {
                "datasetpath": "/QCD_Pt-150_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 20 # Adjusted for PATtuple file size
            },
            "AOD": {
                "datasetpath": "/QCD_Pt-150_MuPt5Enriched_TuneZ2_7TeV-pythia6/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 20,
            },
        },
    },
    "DYJetsToLL": { # Z+jets
        "dataVersion": "38Xrelval",
        "crossSection": 2321,
        "data": {
            "RECO": {
                "datasetpath": "/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/Fall10-START38_V12-v2/GEN-SIM-RECO",
                "number_of_jobs": 15, # Adjusted for PAT on the fly
            },
            "AOD": {
                "datasetpath": "/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/Fall10-START38_V12-v2/AODSIM",
                "number_of_jobs": 15,
            }
        },
    },
    "TToBLNu_s-channel": {
        "dataVersion": "38Xrelval",
        "crossSection": 0.99,
        "data": {
            "RECO": {
                "datasetpath": "/TToBLNu_TuneZ2_s-channel_7TeV-madgraph/Fall10-START38_V12-v1/GEN-SIM-RECO",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            },
            "AOD": {
                "datasetpath": "/TToBLNu_TuneZ2_s-channel_7TeV-madgraph/Fall10-START38_V12-v1/AODSIM",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            }
        },
    },
    "TToBLNu_t-channel": {
        "dataVersion": "38Xrelval",
        "crossSection": 63./3.,
        "data": {
            "RECO": {
                "datasetpath": "/TToBLNu_TuneZ2_t-channel_7TeV-madgraph/Fall10-START38_V12-v2/GEN-SIM-RECO",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            },
            "AOD": {
                "datasetpath": "/TToBLNu_TuneZ2_t-channel_7TeV-madgraph/Fall10-START38_V12-v2/AODSIM",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            }
        },
    },
    "TToBLNu_tW-channel": {
        "dataVersion": "38Xrelval",
        "crossSection": 10.56,
        "data": {
            "RECO": {
                "datasetpath": "/TToBLNu_TuneZ2_tW-channel_7TeV-madgraph/Fall10-START38_V12-v2/GEN-SIM-RECO",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            },
            "AOD": {
                "datasetpath": "/TToBLNu_TuneZ2_tW-channel_7TeV-madgraph/Fall10-START38_V12-v2/AODSIM",
                "number_of_jobs": 10, # Adjusted for PAT on the fly
            },
        },
    },
}
