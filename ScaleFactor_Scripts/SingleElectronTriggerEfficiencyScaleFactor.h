//.........................................................//
//                                                         //
//        Trigger Efficiency scale factor                  //
//                                                         //
//.........................................................//

/*********************************************************************************
 *                                  2016preVFP                                   *
 *********************************************************************************/
float AnaScript::TriggEff2016preVFPMC_Ele27_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.984513*(1.0+TMath::Erf((pt-27.5914)/(2.0*1.0585)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.989446*(1.0+TMath::Erf((pt-26.0586)/(2.0*1.85888)));
  }
  return eff;
}

float AnaScript::TriggEff2016preVFPData_Ele27_WPTight_Gsf( float pt, float eta)
{
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.980431*(1.0+TMath::Erf((pt-26.6311)/(2.0*0.977291)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.984774*(1.0+TMath::Erf((pt-27.5187)/(2.0*1.33533)));
  }
  return eff;
}

/*********************************************************************************
 *                                  2016postVFP                                  *
 *********************************************************************************/
float AnaScript::TriggEff2016postVFPMC_Ele27_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.983934*(1.0+TMath::Erf((pt-27.5947)/(2.0*1.06344)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.988555*(1.0+TMath::Erf((pt-26.0556)/(2.0*1.85987)));
  }
  return eff;
}

float AnaScript::TriggEff2016postVFPData_Ele27_WPTight_Gsf( float pt, float eta)
{
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.975241*(1.0+TMath::Erf((pt-26.6834)/(2.0*1.08336)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.981091*(1.0+TMath::Erf((pt-27.7339)/(2.0*1.44615)));
  }
  return eff;
}

/*********************************************************************************
 *                                    2017                                       *
 *********************************************************************************/
float AnaScript::TriggEff2017MC_Ele32_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.96683*(1.0+TMath::Erf((pt-31.6521)/(2.0*1.16952)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.977357*(1.0+TMath::Erf((pt-32.7302)/(2.0*1.98741)));
  }
  return eff;
}

float AnaScript::TriggEff2017Data_Ele32_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
      eff = 0.5*0.955945*(1.0+TMath::Erf((pt-33.0345)/(2.0*0.885676)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.962208*(1.0+TMath::Erf((pt-33.9927)/(2.0*1.55814)));
  }
  return eff;
}

/*********************************************************************************
 *                                    2018                                       *
 *********************************************************************************/
float AnaScript::TriggEff2018MC_Ele32_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.971841*(1.0+TMath::Erf((pt-33.0664)/(2.0*0.830281)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.981582*(1.0+TMath::Erf((pt-33.9066)/(2.0*1.55882)));
  }
  return eff;
}

float AnaScript::TriggEff2018Data_Ele32_WPTight_Gsf( float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(eta)<=1.479){
    eff = 0.5*0.962897*(1.0+TMath::Erf((pt-33.1188)/(2.0*0.844886)));
  }
  else if(fabs(eta)>1.479){
    eff = 0.5*0.975043*(1.0+TMath::Erf((pt-32.9805)/(2.0*1.18094)));
  }
  return eff;
}
