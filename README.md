# VLLAnalysis_EMuLike

The repo consists of the following things:
1. Analysis Codes
2. Setup Function Codes
3. Control Region Definitions
4. Scale Factor Scripts
5. Condor Setup

The Condor Setup used for the skimmer section is in Python. The only argument it takes is the jobname. You need to edit other things accordingly in the setup.
The Condor Setup used in general for the analysis is in C++. You need to provide job name and code directory both for it to submit the jobs successfully.
python3 submitCondorJobs.py --jobname __ --codedir___