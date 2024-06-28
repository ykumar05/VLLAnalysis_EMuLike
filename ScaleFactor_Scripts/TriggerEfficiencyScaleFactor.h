//.........................................................//
//                                                         //
//        Trigger Efficiency scale factor                  //
//                                                         //
//.........................................................//

/*********************************************************************************
 *                                    2018                                       *
 *********************************************************************************/
float AnaScript::TriggEff2018MC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu24
    if(fabs(eta)<=1.479){
      eff = 0.5*0.971878*(1.0+TMath::Erf((pt-23.9589)/(2.0*0.356627)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.958908*(1.0+TMath::Erf((pt-23.9493)/(2.0*0.408312)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.971878*(1.0+TMath::Erf((pt-23.9589)/(2.0*0.356627)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.958908*(1.0+TMath::Erf((pt-23.9493)/(2.0*0.408312)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2018Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.950463*(1.0+TMath::Erf((pt-23.9593)/(2.0*0.375996)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.953162*(1.0+TMath::Erf((pt-23.9459)/(2.0*0.457351)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.950463*(1.0+TMath::Erf((pt-23.9593)/(2.0*0.375996)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.953162*(1.0+TMath::Erf((pt-23.9459)/(2.0*0.457351)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                    2017                                       *
 *********************************************************************************/
float AnaScript::TriggEff2017MC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu27
    if(fabs(eta)<=1.479){
      eff = 0.5*0.960212*(1.0+TMath::Erf((pt-26.9652)/(2.0*0.597564)));
    }
    else if(fabs(eta)>1.479 && fabs(eta)<=2.4){
      eff = 0.5*0.94303*(1.0+TMath::Erf((pt-26.9123)/(2.0*0.747516)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.96683*(1.0+TMath::Erf((pt-31.6521)/(2.0*1.16952)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.977357*(1.0+TMath::Erf((pt-32.7302)/(2.0*1.98741)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2017Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu27
    if(fabs(eta)<=1.479){
      if(pt<=100)
	eff = 0.5*0.929318*(1.0+TMath::Erf((pt-26.9424)/(2.0*0.612448)));
      else
	eff = 0.958305;
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.94163*(1.0+TMath::Erf((pt-26.9092)/(2.0*0.844543)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.955945*(1.0+TMath::Erf((pt-33.0345)/(2.0*0.885676)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.962208*(1.0+TMath::Erf((pt-33.9927)/(2.0*1.55814)));
    }
  }
  return eff;
}
