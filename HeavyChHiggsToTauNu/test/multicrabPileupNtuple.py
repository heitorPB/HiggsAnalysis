#!/usr/bin/env python

from HiggsAnalysis.HeavyChHiggsToTauNu.tools.multicrab import *


multicrab = Multicrab("crab_analysis.cfg", "pileupNtuple_cfg.py")

datasets = [
        # MC Signal (WH)
        "TTToHplusBWB_M80_Fall11",
        "TTToHplusBWB_M90_Fall11",
        "TTToHplusBWB_M100_Fall11",
        "TTToHplusBWB_M120_Fall11",
        "TTToHplusBWB_M140_Fall11",
        "TTToHplusBWB_M150_Fall11",
        "TTToHplusBWB_M155_Fall11",
        "TTToHplusBWB_M160_Fall11",

        # MC Signal (HH)
        "TTToHplusBHminusB_M80_Fall11",
        "TTToHplusBHminusB_M90_Fall11",
        "TTToHplusBHminusB_M100_Fall11",
        "TTToHplusBHminusB_M120_Fall11",
        "TTToHplusBHminusB_M140_Fall11",
        "TTToHplusBHminusB_M150_Fall11",
        "TTToHplusBHminusB_M155_Fall11",
        "TTToHplusBHminusB_M160_Fall11",

	# MC Signal (heavy H+ from process pp->tbH+)
        "HplusTB_M180_Fall11",
        "HplusTB_M190_Fall11",
        "HplusTB_M200_Fall11",
        "HplusTB_M220_Fall11",
        "HplusTB_M250_Fall11",
        "HplusTB_M300_Fall11",

        # MC Background
        "QCD_Pt30to50_TuneZ2_Fall11",
        "QCD_Pt50to80_TuneZ2_Fall11",
        "QCD_Pt80to120_TuneZ2_Fall11",
        "QCD_Pt120to170_TuneZ2_Fall11",
        "QCD_Pt170to300_TuneZ2_Fall11",
        "QCD_Pt300to470_TuneZ2_Fall11",
       "QCD_Pt20_MuEnriched_TuneZ2_Fall11",
        "TTJets_TuneZ2_Fall11",
        "WJets_TuneZ2_Fall11",
        "W2Jets_TuneZ2_Fall11",
        "W3Jets_TuneZ2_Fall11",
        "W4Jets_TuneZ2_Fall11",
        "DYJetsToLL_M50_TuneZ2_Fall11",
        "T_t-channel_TuneZ2_Fall11",
        "Tbar_t-channel_TuneZ2_Fall11",
        "T_tW-channel_TuneZ2_Fall11",
        "Tbar_tW-channel_TuneZ2_Fall11",
        "T_s-channel_TuneZ2_Fall11",
        "Tbar_s-channel_TuneZ2_Fall11",
        "WW_TuneZ2_Fall11",
        "WZ_TuneZ2_Fall11",
        "ZZ_TuneZ2_Fall11",
        ]

# Add the datasest to the multicrab system
multicrab.extendDatasets("pileupNtuple_44X", datasets)

# Generate configuration only?
configOnly=True
#configOnly=False
# Genenerate configuration and create the crab tasks
multicrab.createTasks(prefix="multicrab_pileupNtuple", configOnly=configOnly)
