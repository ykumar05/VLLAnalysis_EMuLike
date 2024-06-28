import sys
import os,argparse
import setup.condorsetup.condorjobsetup as cset
import json


##--------------------------------------------------------------------------------------------------#
#                                     USER DEFINED                                                  #
##--------------------------------------------------------------------------------------------------#
#jsonfilename ="inputs/sample2018_2LSkimmed.json"
jsonfilename ="inputs/sample2018_sig_bkg.json"

#bkgbundle =["QCD_MuEnriched","HTbinnedWJets","DYJetsToLL","SingleTop","TTBar","WW","WZ","ZZ","SingleMuon"]

#2018(3L/4L)
#bkgbundle =["Higgs", "DYJetsToLL","SingleTop","TTBar","WZ","ZZ","TTZ","TTW","EGamma","SingleMuon","ZZZ", "WWZ", "WZZ", "ZGamma", "VLLD_ele", "VLLD_mu", "VLLS_ele", "VLLS_mu"]
#bkgbundle =["Higgs", "DYJetsToLL","SingleTop","TTBar","WZ","ZZ","TTZ","TTW","EGamma","SingleMuon","ZZZ", "WWZ", "WZZ", "ZGamma", "VLLD_ele", "VLLD_mu", "VLLS_ele", "VLLS_mu"]
#bkgbundle =["ZZ", "SingleMuon"]

#2018(2LOS)
#bkgbundle =["Higgs", "DYJetsToLL","SingleTop","TTBar","WZ","ZZ","TTZ","TTW","EGamma","SingleMuon","ZZZ", "WWZ", "WZZ", "ZGamma", "WW", "HTbinnedWJets"]
#bkgbundle =["Higgs", "DYJetsToLL","SingleTop","TTBar","WZ","ZZ","TTZ","TTW","SingleMuon", "EGamma", "ZZZ", "WWZ", "WZZ", "ZGamma", "WW", "HTbinnedWJets"]
bkgbundle =["DYJetsToLL", "WZ", "ZZ", "TTBar"]

##--------------------------------------------------------------------------------------------------#
#                                  DON'T TOUCH BELOW                                                #
##--------------------------------------------------------------------------------------------------#
parser=argparse.ArgumentParser()
parser.add_argument('--jobname',type=str,required=True,help='AnalysisName: Such as VLL2018_Mar1_v0')
parser.add_argument('--codedir',type=str,required=True,help='Give path to your VLLAna.C directory')
parser.add_argument('--dryrun',type=bool,required=False,help='Check If everything is correct before submitting')
parser.add_argument('--test',type=bool,required=False,help='Check one job')

args=parser.parse_args()
DRYRUN= args.dryrun

########################
newjob = cset.CondorJob()     
newjob.dataset='mu'             #inputs json (if data 0, doesn't matter)el,mu 
newjob.era ='Z'                #NOT IMPORTANT NOW
newjob.codedir = args.codedir  #Code Directory # user defined
newjob.currentdir = os.getcwd()
newjob.anaConddir = os.getcwd()
newjob.setup()

runanaString = os.path.join(os.path.abspath(newjob.codedir),"runana.C")
### Copy anaCond.C and runana.C to codedirectory
os.system("cp -f runana.C "+newjob.codedir)
os.system("cp -f "+newjob.anaConddir+"/"+"anaCond.C "+newjob.codedir)


### Print Out the inputs
def printInfo():
    print("\n***********************************************************************************************")
    print("*       Jobname is    : ",newjob.jobname)
    print("*       Code dir      : ",newjob.codedir+"AnaScript.C")
    print("*       Sample dir    : ",newjob.sampleinputdir)
    print("*       DATA          : ",newjob.data)
    print("*       YEAR          : ",newjob.year)
    print("*       DATASET       : ",newjob.dataset)
    print("*       Sample Group  : ",samplegroup)
    print("*       Sample Tag    : ",newjob.sampletag)
    print("*       Flag          : ",newjob.flag)
    print("*************************************************************************************************")
    return processLine+"\n"

with open(jsonfilename,'r') as infile:
    bkglist = json.load(infile)
    
#print(bkglist)    
## Run over samples
samplesummary=[]
for background in bkgbundle:
    #print(item.lower())
    for samplegroup,groupvalue in bkglist.items():
        #print(samplegroup)
        if(samplegroup.lower() == background.lower()):
            samplesummary.append(samplegroup)
            for samplename,samplevalue in groupvalue.items():
                #print(ikey+jkey+"sample")
                #print(jbkg)
            
                newjob.jobname= args.jobname+"_"+samplename+"_sample"
                newjob.sampleinputdir= samplevalue["samplepath"]
                newjob.sampletag= samplename
                newjob.data =str(samplevalue["data"])
                newjob.year =str(samplevalue["year"])
                newjob.flag =str(samplevalue["flag"])
        
                processLine = './createJobsToCondor.sh'+' '+runanaString+' '+newjob.jobname+' '+newjob.sampleinputdir+' '+str(newjob.data)+' '+str(newjob.year)+' '+newjob.dataset+' '+newjob.era+' '+newjob.sampletag+' '+newjob.flag 
                if(DRYRUN==True):
                    print(printInfo())
                    #print("\n"+processLine+"\n")
                    if(args.test==True):
                        break
                else:
                    os.system(processLine)
                    if(args.test==True):
                        break
    #else:
    # print("\n For the following samples you didn't request a condor job...\n")
for item in samplesummary:
    print("\nYou submit jobs for.....:|"+item)
print(" \n")

### COPY submission files to CondorJobs directory
### Keep you submission directory clean
if(DRYRUN==None):
    os.system("mv -f submitJobsCondor* CondorJobsLog/")
    print("\n *****SubmitJobsCondor*.sh files are moved to CondorJobs directory******\n")
