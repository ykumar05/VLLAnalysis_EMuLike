#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
void runana(TString ifname="input_file" , TString ofname="outputfile" , TString data="data", TString year="year", TString lep="lep", TString era="era", TString MC="mc", TString flag="flag")
{
TString anastring =".x /home/work/ykumar1/Work/VLLAnalysis_e-muLike/AnalyzerCode/anaCond.C(\""+ifname+"\",\""+ofname+"\",\""+data+"\",\""+year+"\",\""+lep+"\",\""+era+"\",\""+MC+"\",\""+flag+"\")";
gSystem->Load("/home/work/ykumar1/Work/VLLAnalysis_e-muLike/AnalyzerCode/AnaScript_C.so");
gROOT->ProcessLine(anastring);
}