//Gen Muon
void skimmer::GenMuon()
{
  int grandmomid=-1;
  for(unsigned int i=0; i< (*nGenPart); i++){
    Particle temp; temp.v.SetPtEtaPhiM(GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_mass[i]);
    temp.status = GenPart_status[i];
    temp.ind = i;
    temp.pdgid = GenPart_pdgId[i];
    temp.momid=MotherID(i,GenPart_genPartIdxMother[i]);
    bool passcutmu= abs(temp.pdgid)==13 && temp.status==1 && temp.v.Pt()>10 && fabs(temp.v.Eta())<2.4;
    bool motherisnotmu= abs(MotherID(i,GenPart_genPartIdxMother[i]))!=13 && GenPart_pdgId[GenPart_genPartIdxMother[i]]!=22;
    passcutmu = passcutmu && motherisnotmu; 
    if(passcutmu){     	
      genMuon.push_back(temp);
      genLightLepton.push_back(temp);
    }
  }
}

//Gen Electron
void skimmer::GenElectron()
{
  int grandmomid=-1;
  for(unsigned int i=0; i< (*nGenPart); i++){
    Particle temp; temp.v.SetPtEtaPhiM(GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_mass[i]);
    temp.status = GenPart_status[i];
    temp.ind = i;
    temp.pdgid = GenPart_pdgId[i];
    temp.momid=MotherID(i,GenPart_genPartIdxMother[i]);
    //GenElectron Block
    bool passcutele= abs(temp.pdgid)==11 && temp.status==1 && temp.v.Pt()>10 && fabs(temp.v.Eta())<2.4;
    bool motherisnotele= abs(MotherID(i,GenPart_genPartIdxMother[i]))!=11 && GenPart_pdgId[GenPart_genPartIdxMother[i]]!=22;
    //Final selection
    passcutele = passcutele && motherisnotele; 
    
    if(passcutele){
      genElectron.push_back(temp);
      genLightLepton.push_back(temp);
    }
  }
}
