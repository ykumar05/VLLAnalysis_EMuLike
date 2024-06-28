float skimmer::delta_phi(float phi1, float phi2){
  phi1 = TVector2::Phi_0_2pi(phi1);
  phi2 = TVector2::Phi_0_2pi(phi2);
  float dphi = fabs(phi1 - phi2);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  return dphi;
}

int skimmer::MotherID(int partindex, int momindex){
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

float skimmer::transv_mass(float lepE, float lepphi, float met, float metphi){
  float dphi = fabs(lepphi - metphi);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  float mT = sqrt(2* lepE * met *(1-cos(dphi)));
  return mT;
}

//Cleaning funtions:
bool skimmer::clean_from_array(Particle target, vector<Particle> array, float dRcut){
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

void skimmer::SortGenObjects(){
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

void skimmer::SortRecoObjects(){
  //LightLeptons
  for(int i=0; i<(int)LightLepton.size()-1; i++){
    for(int j=i+1; j<(int)LightLepton.size(); j++){
      if(LightLepton[i].v.Pt() < LightLepton[j].v.Pt())
	swap(LightLepton.at(i), LightLepton.at(j));
    }
  }
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
}
