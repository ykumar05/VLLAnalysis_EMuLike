/*************************************************************************
 *                            Light Leptons                              *
 *************************************************************************/

void skimmer::createLightLeptons(){

  /***********************************
   *              Muons              *
   ***********************************/
  for(unsigned int i=0; i<(*nMuon); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(Muon_pt[i],Muon_eta[i],Muon_phi[i],0.105);
    temp.id = -13*Muon_charge[i];
    temp.ind = i;
    temp.charge = Muon_charge[i];
    temp.sip3d = Muon_sip3d[i];
    temp.reliso03 = Muon_pfRelIso03_all[i];
    temp.reliso04 = Muon_pfRelIso04_all[i];
    
    bool ptetacut = temp.v.Pt()>10 && fabs(temp.v.Eta())<2.4;
    bool promptmuon = fabs(Muon_dxy[i])<0.05 && fabs(Muon_dz[i])<0.1;
    bool passcut_loosemuon = ptetacut && Muon_pfRelIso04_all[i]<1.0 && Muon_looseId[i] && promptmuon;
    bool mediumId = Muon_mediumId[i];
    
    if(passcut_loosemuon){
      LightLepton.push_back(temp);
    }
  }
  
  /***********************************
   *            Electrons            *
   ***********************************/
  for(unsigned int i=0; i< (*nElectron); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(Electron_pt[i],Electron_eta[i],Electron_phi[i],0.000511); 
    temp.sip3d = Electron_sip3d[i];
    temp.id = -11*Electron_charge[i];
    temp.ind = i;
    temp.charge = Electron_charge[i];

    bool ptetacut = temp.v.Pt()>10 && fabs(temp.v.Eta())<2.4;
    bool isprompt = false;
    if(fabs(temp.v.Eta())<=1.479){//for barrel
      if(fabs(Electron_dxy[i])<0.05 && fabs(Electron_dz[i])<0.1)
	isprompt = true;
    }
    if(fabs(temp.v.Eta())>1.479){//endcap
      if(fabs(Electron_dxy[i])<0.1 && fabs(Electron_dz[i])<0.2)
	isprompt = true;
    }
    bool passcut_looseele = ptetacut && Electron_cutBased[i]>1 && isprompt;

    if(passcut_looseele){
      LightLepton.push_back(temp);
    }
  }//For electrons
}

/***********************************
 *               Taus              *
 ***********************************/
void skimmer::createTaus(){
  for(unsigned int i=0; i< (*nTau); i++){
    //Set the energy corrections according the decay modes:
    float tlv_corr = 1.;
    if(_year==2016){
      if(Tau_decayMode[i]==0)  tlv_corr = 0.994;
      if(Tau_decayMode[i]==1)  tlv_corr = 0.995;
      if(Tau_decayMode[i]>9)   tlv_corr = 1;
    }
    if(_year==2017){
      if(Tau_decayMode[i]==0)  tlv_corr = 1.007;
      if(Tau_decayMode[i]==1)  tlv_corr = 0.998;
      if(Tau_decayMode[i]==10) tlv_corr = 1.001;
      if(Tau_decayMode[i]==11) tlv_corr = 0.999;
    }
    if(_year==2018){
      if(Tau_decayMode[i]==0)  tlv_corr = 0.987;
      if(Tau_decayMode[i]==1)  tlv_corr = 0.995;
      if(Tau_decayMode[i]==10) tlv_corr = 0.998;
      if(Tau_decayMode[i]==11) tlv_corr = 1;
    }

    Particle temp;
    temp.v.SetPtEtaPhiM(Tau_pt[i],Tau_eta[i],Tau_phi[i],1.77);
    temp.v *= tlv_corr; //energy correction
    temp.id = -15*Tau_charge[i];
    temp.ind = i;
    
    bool ptetacut = temp.v.Pt()>20 && fabs(temp.v.Eta())<2.3;
    bool DeepTauID_tight = Tau_idDeepTau2017v2p1VSe[i]>15 && Tau_idDeepTau2017v2p1VSmu[i]>3 && Tau_idDeepTau2017v2p1VSjet[i]>127;
    bool passcut_tight = ptetacut && DeepTauID_tight && fabs(Tau_dz[i]<0.2);
    if(passcut_tight)
      Tau.push_back(temp);
  }
}

/***********************************
 *              Jets               *
 ***********************************/
void skimmer::createJets(){
  for(unsigned int i=0; i< (*nJet); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(Jet_pt[i],Jet_eta[i],Jet_phi[i],Jet_mass[i]);
    temp.ind = i;
    if(_data == 0)
      temp.hadronflavor = Jet_hadronFlavour[i];
    
    bool ptetacut = temp.v.Pt()>30 && fabs(temp.v.Eta())<2.4;
    bool jetID = _year == 2016 ? Jet_jetId[i]>=1 : Jet_jetId[i]>=2; //if 2016, >=1; else >=2
    bool passcut = ptetacut && jetID;
    
    if(passcut){
      Jets.push_back(temp);
      if(_year == 2017 && Jet_btagDeepB[i]>0.3040)
	bJets.push_back(temp);
      if(_year == 2018 && Jet_btagDeepB[i]>0.4184)
	bJets.push_back(temp);
    }
  }
}


