float AnaScript::delta_phi(float phi1, float phi2){
  phi1 = TVector2::Phi_0_2pi(phi1);
  phi2 = TVector2::Phi_0_2pi(phi2);
  float dphi = fabs(phi1 - phi2);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  return dphi;
}

int AnaScript::MotherID(int partindex, int momindex){
  int parid =GenPart_pdgId[partindex];
  int momid = GenPart_pdgId[momindex];
  while(parid==momid){
    partindex=momindex;
    momindex=GenPart_genPartIdxMother[momindex];
    parid =GenPart_pdgId[partindex];
    momid = GenPart_pdgId[momindex];
  }
  return momid;
}

float AnaScript::transv_mass(float lepE, float lepphi, float met, float metphi){
  float dphi = fabs(lepphi - metphi);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  float mT = sqrt(2* lepE * met *(1-cos(dphi)));
  return mT;
}

//Cleaning funtions:
bool AnaScript::clean_from_array(Particle target, vector<Particle> array, float dRcut){
  bool result = true; //cleaned
  float dRmin = 1000.0;
  for(int i=0; i<(int)array.size(); i++){
    float dR = target.v.DeltaR(array.at(i).v);
    if(dR < dRmin) dRmin = dR;
  }
  //If the minimum dR of any Particle from the array with the target Particle is less than the dRcut,
  //then the target is not isolated.
  if(dRmin < dRcut) result = false;
  return result;
}

void AnaScript::SortGenObjects(){
  //genMuons:
  for(int i=0; i<(int)genMuon.size()-1; i++){
    for(int j=i+1; j<(int)genMuon.size(); j++){
      if(genMuon[i].v.Pt() < genMuon[j].v.Pt())
	swap(genMuon.at(i), genMuon.at(j));
    }
  }
//genElectrons:
  for(int i=0; i<(int)genElectron.size()-1; i++){
    for(int j=i+1; j<(int)genElectron.size(); j++){
      if(genElectron[i].v.Pt() < genElectron[j].v.Pt())
	swap(genElectron.at(i), genElectron.at(j));
    }
  }
  //genLightLeptons:
  for(int i=0; i<(int)genLightLepton.size()-1; i++){
    for(int j=i+1; j<(int)genLightLepton.size(); j++){
      if(genLightLepton[i].v.Pt() < genLightLepton[j].v.Pt())
	swap(genLightLepton.at(i), genLightLepton.at(j));
    }
  }
}

void AnaScript::SortVLL(){
  //vllep:
  for(int i=0; i<(int)vllep.size()-1; i++){
    for(int j=i+1; j<(int)vllep.size(); j++){
      if(vllep[i].v.Pt() < vllep[j].v.Pt())
	swap(vllep.at(i), vllep.at(j));
    }
  }
  //vlnu:
  for(int i=0; i<(int)vlnu.size()-1; i++){
    for(int j=i+1; j<(int)vlnu.size(); j++){
      if(vlnu[i].v.Pt() < vlnu[j].v.Pt())
	swap(vlnu.at(i), vlnu.at(j));
    }
  }
}

void AnaScript::SortRecoObjects(){
  //Jets:
  for(int i=0; i<(int)Jets.size()-1; i++){
    for(int j=i+1; j<(int)Jets.size(); j++){
      if(Jets[i].v.Pt() < Jets[j].v.Pt())
	swap(Jets.at(i), Jets.at(j));
    }
  }
  //bJets:
  for(int i=0; i<(int)bJets.size()-1; i++){
    for(int j=i+1; j<(int)bJets.size(); j++){
      if(bJets[i].v.Pt() < bJets[j].v.Pt())
	swap(bJets.at(i), bJets.at(j));
    }
  }
  //LooseLeptons:
  for(int i=0; i<(int)loosellep.size()-1; i++){
    for(int j=i+1; j<(int)loosellep.size(); j++){
      if(loosellep[i].v.Pt() < loosellep[j].v.Pt())
	swap(loosellep.at(i), loosellep.at(j));
    }
  }
  //LightLeptons:
  for(int i=0; i<(int)LightLepton.size()-1; i++){
    for(int j=i+1; j<(int)LightLepton.size(); j++){
      if(LightLepton[i].v.Pt() < LightLepton[j].v.Pt())
	swap(LightLepton.at(i), LightLepton.at(j));
    }
  }
  //Muons:
  for(int i=0; i<(int)Muon.size()-1; i++){
    for(int j=i+1; j<(int)Muon.size(); j++){
      if(Muon[i].v.Pt() < Muon[j].v.Pt())
	swap(Muon.at(i), Muon.at(j));
    }
  }
  //Electrons:
  for(int i=0; i<(int)Electron.size()-1; i++){
    for(int j=i+1; j<(int)Electron.size(); j++){
      if(Electron[i].v.Pt() < Electron[j].v.Pt())
	swap(Electron.at(i), Electron.at(j));
    }
  }
}

//DISTINCT OSSFN PAIR//
int AnaScript::getOSSFN()
{
  if(is_l4_event){
    Particle lep0=LightLepton.at(0), lep1=LightLepton.at(1),lep2=LightLepton.at(2),lep3=LightLepton.at(3); 
    if(abs(lep0.id)==abs(lep1.id) && lep0.charge != lep1.charge && abs(lep2.id)==abs(lep3.id) && lep2.charge != lep3.charge) return 2;  
    if(abs(lep0.id)==abs(lep2.id) && lep0.charge != lep2.charge && abs(lep1.id)==abs(lep3.id) && lep1.charge != lep3.charge) return 2;
    if(abs(lep0.id)==abs(lep3.id) && lep0.charge != lep3.charge && abs(lep2.id)==abs(lep1.id) && lep2.charge != lep1.charge) return 2;
    else return 0;
  }
  else return 0;
}

float AnaScript::getInvMass(TLorentzVector a,TLorentzVector b)
{
  return (a+b).M();
}

//is OSSF?
bool AnaScript::isOSSF(int i, int j)
{
  bool result= false;
  Particle lep_i=LightLepton.at(i),lep_j=LightLepton.at(j);
  if(abs(lep_i.id)==abs(lep_j.id) && lep_i.charge != lep_j.charge ){
    result=true;
  }
  return result;
}

float AnaScript::OSSFMass(int i, int j)
{
  float mass=-1.0;
  Particle lep_i=LightLepton.at(i),lep_j=LightLepton.at(j);
  if(abs(lep_i.id)==abs(lep_j.id) && lep_i.charge != lep_j.charge ){
    mass=getInvMass(lep_i.v,lep_j.v);
  }
  return mass;
}

float AnaScript::OSSFMass_MisId(int i, int j)
{
  float mass=-1.0;
  Particle lep_i=loosellep.at(i),lep_j=loosellep.at(j);
  if(abs(lep_i.id)==abs(lep_j.id) && lep_i.charge != lep_j.charge ){
    mass=getInvMass(lep_i.v,lep_j.v);
  }
  return mass;
}

bool AnaScript::IsGenMuonMatched(TLorentzVector t)
{
  bool genmatch = false;
  for(int i = 0; i < (int)genMuon.size(); i++){    
    if(t.DeltaR(genMuon.at(i).v) < 0.1){
      genmatch = true;
      break;
    }
  }
  return genmatch;
}

bool AnaScript::IsGenElectronMatched(TLorentzVector t)
{
  bool genmatch = false;
  //GenElectron Matching
  for(int i = 0; i<(int)genElectron.size(); i++){    
    if(t.DeltaR(genElectron.at(i).v) < 0.1){
      genmatch = true;
      break;
    }
  }
  return genmatch;
}


