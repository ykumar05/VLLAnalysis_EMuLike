#!/bin/bash
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
export COIN_FULL_INDIRECT_RENDERING=1
echo $VO_CMS_SW_DIR
source $VO_CMS_SW_DIR/cmsset_default.sh
cd /home/work/ykumar1/CMSSW_10_3_1/src
eval `scramv1 runtime -sh` 
root -q -b -l /home/work/ykumar1/Work/VLLAnalysis_e-muLike/AnalyzerCode/runana.C\(\"$1\",\"$2\",\"$3\",\"$4\",\"$5\",\"$6\",\"$7\",\"$8\"\)

