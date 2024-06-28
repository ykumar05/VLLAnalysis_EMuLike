#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

void anaCond( TString ifname , TString ofname, TString data, TString year, TString lep, TString era, TString MC, TString flag)
{
  gROOT->Time();  
  const char *hstfilename;
  TChain *chain = new TChain("Events");
  AnaScript m_selec;
  TString input = ifname;
  bool manual = input.EndsWith(".root");
  bool single=false;
  if(!manual) {
    input += "/*.root";
  }
  chain->Add(input);	
  hstfilename = ofname;  
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetVerbose(1);

  //Checking whether it is MC or Data
  if(data=="0")
    m_selec.SetData(0); //0 - not running over data, 1 - running over data
  if(data=="1")
    m_selec.SetData(1); //0 - not running over data, 1 - running over data

  //Setting the year
  if(year=="2016")
    m_selec.SetYear(2016);
  if(year=="2017")
    m_selec.SetYear(2017);
  if(year=="2018")
    m_selec.SetYear(2018);

  //Setting the era
  m_selec.SetEra(era);

  //Setting whether it is SingleMuon or Single Electron
  if(lep=="el")
    m_selec.SetLep(0);
  if(lep=="mu")
    m_selec.SetLep(1);

  //cout<<"Set the options"<<endl;
  if(data=="0"){
    int _sample = -1;
    TString _flag = ""; 
    
    //SampleNumbering: Simulation
    // DY: 1-9; QCD: 10-20; ZZ : 20-29; WZ : 30-39; WW : 40-49; SingleTop: 50-59; TTBar: 60-69; HTBinnedWJets: 70-79; VLL: 80-89
    
    //DYJetsToLL
    if(MC=="DYJetsToLL_M10to50"){
      _sample = 1;
      _flag= "DY";
    }
    if(MC=="DYJetsToLL_M50"){
      _sample = 2;
      _flag = "DY";
    }
    
    //QCD_MuEnriched
    if(MC=="QCD_MuEnriched_20to30"){
      _sample = 10;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_30to50"){
      _sample = 11;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_50to80"){
      _sample = 12;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_80to120"){
      _sample = 13;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_120to170"){
      _sample = 14;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_170to300"){
      _sample = 15;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_300to470"){
      _sample = 16;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_470to600"){
      _sample = 17;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_600to800"){
      _sample = 18;
      _flag = "qcd";
    }
    if(MC=="QCD_MuEnriched_800to1200"){
      _sample = 19;
      _flag = "qcd";
    }

    //ZZ
    if(MC=="ZZ_ZZTo2Q2L"){
      _sample = 20;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo2Q2Nu"){
      _sample = 21;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo4L"){
      _sample = 22;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo2L2Nu"){
      _sample = 23;
      _flag = "zz";
    }
    
    //WZ
    if(MC=="WZ_WZTo2Q2L"){
      _sample = 30;
      _flag = "wz";
    }
    if(MC=="WZ_WZTo3LNu"){
      _sample = 31;
      _flag = "wz";
    }
    if(MC=="WZ_WZTo1L1Nu2Q"){
      _sample = 32;
      _flag = "wz";
    }
    
    //WW
    if(MC=="WW_WWTo1L1Nu2Q"){
      _sample = 40;
      _flag = "ww";
    }
    if(MC=="WW_WWto2L2Nu"){
      _sample = 41;
      _flag = "ww";
    }
    if(MC=="WW_WWto4Q"){
      _sample = 42;
      _flag = "ww";
    }
    
    //Single Top
    if(MC=="SingleTop_t-channel_Top_InclusiveDecays"){
      _sample = 50;
      _flag = "st";
    }
    if(MC=="SingleTop_t-channel_AntiTop_InclusiveDecays"){
      _sample = 51;
      _flag = "st";
    }
    if(MC=="SingleTop_s-channel_LeptonDecays"){
      _sample = 52;
      _flag = "st";
    }
    if(MC=="SingleTop_tW_AntiTop_InclusiceDecays"){
      _sample = 53;
      _flag = "st";
    }
    if(MC=="SingleTop_tW_Top_InclusiveDecays"){
      _sample = 54;
      _flag = "st";
    }
    
    //TTbar
    if(MC=="TTBar_TTToSemiLeptonic"){
      _sample = 60;
      _flag = "ttbar";
    }
    if(MC=="TTBar_TTTo2L2Nu"){
      _sample = 61;
      _flag = "ttbar";
    }
    
    //HTbinned WJets
    if(MC=="HTbinnedWJets_Inclusive"){
      _sample = 70;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_70to100"){
      _sample = 71;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_100to200"){
      _sample = 72;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_200to400"){
      _sample = 73;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_400to600"){
      _sample = 74;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_600to800"){
      _sample = 75;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_800to1200"){
      _sample = 76;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_1200to2500"){
      _sample = 77;
      _flag = "wjets";
    }
    if(MC=="HTbinnedWJets_2500toInf"){
      _sample = 78;
      _flag = "wjets";
    }

    //SampleNumbering: Signal
    //VLLD_E-Like
    if(MC=="VLLD_ele_M100")
      _flag = "doublet";
    if(MC=="VLLD_ele_M200")
      _flag = "doublet";
    if(MC=="VLLD_ele_M300")
      _flag = "doublet";
    if(MC=="VLLD_ele_M400")
      _flag = "doublet";
    if(MC=="VLLD_ele_M600")
      _flag = "doublet";
    if(MC=="VLLD_ele_M800")
      _flag = "doublet";
    if(MC=="VLLD_ele_M1000")
      _flag = "doublet";
    if(MC=="VLLD_ele_M1200")
      _flag = "doublet";
    if(MC=="VLLD_ele_M1400")
      _flag = "doublet";
    if(MC=="VLLD_ele_M1600")
      _flag = "doublet";
    if(MC=="VLLD_ele_M1800")
      _flag = "doublet";
    if(MC=="VLLD_ele_M2000")
      _flag = "doublet";
    if(MC=="VLLD_ele_M2200")
      _flag = "doublet";

    //VLLD_Mu-Like
    if(MC=="VLLD_mu_M100")
      _flag = "doublet";
    if(MC=="VLLD_mu_M200")
      _flag = "doublet";
    if(MC=="VLLD_mu_M300")
      _flag = "doublet";
    if(MC=="VLLD_mu_M400")
      _flag = "doublet";
    if(MC=="VLLD_mu_M600")
      _flag = "doublet";
    if(MC=="VLLD_mu_M800")
      _flag = "doublet";
    if(MC=="VLLD_mu_M1200")
      _flag = "doublet";
    if(MC=="VLLD_mu_M1400")
      _flag = "doublet";
    if(MC=="VLLD_mu_M1600")
      _flag = "doublet";
    if(MC=="VLLD_mu_M1800")
      _flag = "doublet";
    if(MC=="VLLD_mu_M2000")
      _flag = "doublet";
    if(MC=="VLLD_mu_M2200")
      _flag = "doublet";

    //VLLS_E-Like
    if(MC=="VLLS_ele_M100")
      _flag = "singlet";
    if(MC=="VLLS_ele_M125")
      _flag = "singlet";
    if(MC=="VLLS_ele_M150")
      _flag = "singlet";
    if(MC=="VLLS_ele_M200")
      _flag = "singlet";
    if(MC=="VLLS_ele_M250")
      _flag = "singlet";
    if(MC=="VLLS_ele_M300")
      _flag = "singlet";
    if(MC=="VLLS_ele_M350")
      _flag = "singlet";
    if(MC=="VLLS_ele_M400")
      _flag = "singlet";
    if(MC=="VLLS_ele_M450")
      _flag = "singlet";
    if(MC=="VLLS_ele_M500")
      _flag = "singlet";
    if(MC=="VLLS_ele_M750")
      _flag = "singlet";
    if(MC=="VLLS_ele_M1000")
      _flag = "singlet";

    //VLLS_Mu-Like
    if(MC=="VLLS_mu_M100")
      _flag = "singlet";
    if(MC=="VLLS_mu_M125")
      _flag = "singlet";
    if(MC=="VLLS_mu_M150")
      _flag = "singlet";
    if(MC=="VLLS_mu_M200")
      _flag = "singlet";
    if(MC=="VLLS_mu_M250")
      _flag = "singlet";
    if(MC=="VLLS_mu_M300")
      _flag = "singlet";
    if(MC=="VLLS_mu_M400")
      _flag = "singlet";
    if(MC=="VLLS_mu_M450")
      _flag = "singlet";
    if(MC=="VLLS_mu_M500")
      _flag = "singlet";
    if(MC=="VLLS_mu_M750")
      _flag = "singlet";
    if(MC=="VLLS_mu_M1000")
      _flag = "singlet";
    
    m_selec.SetSample(_sample);
    m_selec.SetFlag(_flag);
    
  }
  
  if(data == "1"){
    int _sample = -1;
    TString _flag = ""; 
    
    //SampleNumbering: Data
    if(year == "2018"){
      //SingleMuon
      if(MC=="SingleMuon_SingleMuon_A"){
	_sample = 1000;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_B"){
	_sample = 1001;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_C"){
	_sample = 1002;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_D"){
	_sample = 1003;
	_flag = "singlemuon";
      }
    
      //EGamma
      if(MC=="EGamma_EGamma_A"){
	_sample = 1100;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_B"){
	_sample = 1101;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_C"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_D"){
	_sample = 1103;
	_flag = "egamma";
      }
    }   

    if(year == "2017"){
      //SingleMuon
      if(MC=="SingleMuon_SingleMuon_B"){
	_sample = 1000;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_C"){
	_sample = 1001;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_D"){
	_sample = 1002;
	_flag = "singlemuon";
	}
      if(MC=="SingleMuon_SingleMuon_E"){
	_sample = 1003;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_F"){
	_sample = 1004;
	_flag = "singlemuon";
      }
      
      //SingleElectron
      if(MC=="SingleElectron_SingleElectron_B"){
	_sample = 1100;
	_flag = "egamma";
      }
      if(MC=="SingleElectron_SingleElectron_C"){
	_sample = 1101;
	_flag = "egamma";
      }
      if(MC=="SingleElectron_SingleElectron_D"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="SingleElectron_SingleElectron_E"){
	_sample = 1103;
	_flag = "egamma";
      }
      if(MC=="SingleElectron_SingleElectron_F"){
	_sample = 1104;
	_flag = "egamma";
      }
    }
    m_selec.SetSample(_sample);
    m_selec.SetFlag(_flag);
  }

  chain->Process(&m_selec);
  gROOT->Time();
}
