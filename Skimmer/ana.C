#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
/*
  This is a driver script.
  It decides which code to run over which sample, the names
  of output files and so on.
*/


void ana(int sample=0){
  const char *hstfilename, *sumfilename, *skimfilename;
  //Declare a chain for input files.
  TChain *chain = new TChain("Events"); //"Events"
  //Declare an instance of our code class
  
  skimmer m_selec;
  
  if(sample==0){
    //Add one file to chain. This is the input file.
    chain->Add("/home/work/alaha1/public/RunII_ULSamples/2018/ZZ/ZZTo4L/VLL_ZZTo4L_27.root");
    //Set Names of outputfiles
    hstfilename = "hst_ZZTo4L.root";
    sumfilename = "sum_ZZTo4L.txt";
    skimfilename = "skim2018_ZZTo4L.root";
    m_selec.SetData(0);
    m_selec.SetYear(2018);
  }
  
  if(sample==1){
    //Add one file to chain. This is the input file.
    chain->Add("/home/work/alaha1/public/RunII_ULSamples/2018/UL2018Data/EGamma/EGamma_B/*EGamma*20.root");
    //Set Names of outputfiles
    hstfilename = "hst2018_SingleEle.root";
    sumfilename = "sum2018_SingleEle.txt";
    skimfilename = "skim2018_SingleEle.root";
    m_selec.SetData(1);
    m_selec.SetYear(2018);
  }

  if(sample==2){
    //Add one file to chain. This is the input file.
    chain->Add("/home/work/alaha1/public/RunII_ULSamples/2018/DYJetsToLL/M50/VLL_DYJetsToLL_M50_139.root");
    //Set Names of outputfiles
    hstfilename = "hst_DYSkimmed.root";
    sumfilename = "sum_DYSkimmed.txt";
    skimfilename = "skim2018_DY139.root";
    m_selec.SetData(0);
    m_selec.SetYear(2018);
  }

  std::cout<<"Output file :"<<skimfilename<<std::endl;
  // Set some more options.. set the output file names.
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetSkimFileName(skimfilename);
  m_selec.SetVerbose(10);//set verbosity level for output.
  // Call the process function which runs the code.
  chain->Process(&m_selec);

}
