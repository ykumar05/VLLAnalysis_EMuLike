double AnaScript::LeptonID_SFUL18(int id, float pt, float eta)
{
  float SF = 1.0;

  //MUON: 2018
  if(fabs(id)==13){
    if(_year==2018)
      SF = getScaleFactors_Muons_Reco_UL18(eta,pt)*getScaleFactors_Muons_ID_UL18(eta,pt)*getScaleFactors_Muons_ISO_UL18(eta, pt);
  }
  //Electron: 2018
  if(fabs(id)==11){
    if(_year==2018)
      SF = getScaleFactors_Electrons_Reco_UL18(eta,pt)*getScaleFactors_Electrons_IDIso_UL18(eta,pt);
  }
  
  return SF;
}

double AnaScript::LeptonID_SFUL17(int id, float pt, float eta)
{
  float SF = 1.0;

  //MUON
  if(fabs(id)==13){
    if(_year==2017)
      SF = getScaleFactors_Muons_Reco_UL17(eta,pt)*getScaleFactors_Muons_ID_UL17(eta,pt)*getScaleFactors_Muons_ISO_UL17(eta, pt);
  }
  //Electron
  if(fabs(id)==11){
    if(_year==2017)
      SF = getScaleFactors_Electrons_Reco_UL17(eta,pt)*getScaleFactors_Electrons_IDIso_UL17(eta,pt);
  }
  return SF;
}

double AnaScript::ZpTFactor_DY(int MCSample, TLorentzVector v1, TLorentzVector v2){
  float ZpTFactor = 1.0;
  float ZpT = (v1+v2).Pt();
  if(MCSample == 1 || MCSample == 2){
    if(ZpT < 10.0)
      ZpTFactor = 1.04416;
    if(10.0 < ZpT && ZpT < 20.0)
      ZpTFactor = 1.20045;
    if(20.0 < ZpT && ZpT < 30.0)
      ZpTFactor = 0.9946;
    if(30.0 < ZpT && ZpT < 40.0)
      ZpTFactor = 0.7204;
    if(40.0 < ZpT && ZpT < 50.0)
      ZpTFactor = 0.61608;
    if(50.0 < ZpT && ZpT < 60.0)
      ZpTFactor = 0.577426;
    if(60.0 < ZpT && ZpT < 70.0)
      ZpTFactor = 0.558496;
    if(70.0 < ZpT && ZpT < 80.0)
      ZpTFactor = 0.542947;
    if(80.0 < ZpT && ZpT < 90.0)
      ZpTFactor = 0.525769;
    if(90.0 < ZpT)
      ZpTFactor = 0.319028;
  }
  return ZpTFactor;
}

double AnaScript::JetReWeighting_DY(int MCSample, vector<Particle>Jets){
  float JetReWeightingFactor = 1.0;

  if(MCSample == 1 || MCSample == 2){
    if((int)Jets.size() < 1)
      JetReWeightingFactor = 1.07382;
    if(1 < (int)Jets.size() && (int)Jets.size() < 2)
      JetReWeightingFactor = 0.768377;
    if(2 < (int)Jets.size() && (int)Jets.size() < 3)
      JetReWeightingFactor = 0.541722;
    if(3 < (int)Jets.size() && (int)Jets.size() < 4)
      JetReWeightingFactor = 0.606028;
    if(4 < (int)Jets.size())
      JetReWeightingFactor = 0.671453;
  }
  return JetReWeightingFactor;
}

