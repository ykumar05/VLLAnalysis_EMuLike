//Gen Muon
void AnaScript::GenMuon()
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
      h.genpltmu[0]->Fill(temp.v.Pt());
      h.genpltmu[1]->Fill(temp.v.Eta());
      h.genpltmu[2]->Fill(temp.v.Phi());
      h.genpltmu[3]->Fill(MotherID(i,GenPart_genPartIdxMother[i]));
    }
  }
}

//Gen Electron
void AnaScript::GenElectron()
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
      h.genpltele[0]->Fill(temp.v.Pt());
      h.genpltele[1]->Fill(temp.v.Eta());
      h.genpltele[2]->Fill(temp.v.Phi());
      h.genpltele[3]->Fill(MotherID(i,GenPart_genPartIdxMother[i]));
    }
  }
}

//Gen Z
void AnaScript::GenZ()
{
  for(unsigned int i=0; i< (*nGenPart); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_mass[i]);
    temp.status = GenPart_status[i];
    temp.ind = i;
    temp.pdgid = GenPart_pdgId[i];
    temp.momid=MotherID(i,GenPart_genPartIdxMother[i]);
    //GenZ Block
    bool passcutZ= abs(temp.pdgid)==23;
    if(passcutZ){
      genZ.push_back(temp);
      h.genpltZ[0]->Fill(temp.momid);
    }
  }
}

//SIGNAL:
void AnaScript::createSignalArrays(){
  //Creating signal arrays and flagging the bad events:
  for(unsigned int i=0; i< (*nGenPart); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_mass[i]);
    temp.status = GenPart_status[i];
    temp.ind = i;
    temp.pdgid = GenPart_pdgId[i];
    temp.momid = GenPart_pdgId[GenPart_genPartIdxMother[i]]; //Not fixing the mother right now
    bool mother_is_Z = (temp.momid == 23);
    bool mother_is_W = (fabs(temp.momid) == 24);
    bool not_its_own_mother = (temp.momid != temp.pdgid); //To avoid overcounting

    //Finding daughters:
    vector<int> daughter_ind, daughter_id;
    daughter_ind.clear(); daughter_id.clear();

    for(unsigned int j=0; j< (*nGenPart); j++){
      float id = GenPart_pdgId[j];
      float momid = MotherID(j,GenPart_genPartIdxMother[j]);
      //remove identical daughetrs:
      bool unique_daughter = true;
      if(momid == GenPart_pdgId[i]){ //If mother of the j-th particle is the i-th particle,
	for(int k=0; k<(int)daughter_id.size(); k++){
	  if(id == daughter_id.at(k)) unique_daughter = false;
	}
	if(unique_daughter){
	  daughter_ind.push_back(j); //Then the particle at j-th index is a daughter.
	  daughter_id.push_back(id);
	}
      }
    }
    temp.dauind = daughter_ind;
    temp.dauid = daughter_id;

    //Setting decaymodes:
    //If the particle decays into W, Z or H, decaymode = 1, 2 or 3 respectively.
    temp.decaymode = 0;
    for(int j=0; j<(int)temp.dauid.size(); j++){
      if(fabs(temp.dauid[j]) == 23)      temp.decaymode = 2; //Z
      else if(fabs(temp.dauid[j]) == 24) temp.decaymode = 1; //W
      else if(fabs(temp.dauid[j]) == 25) temp.decaymode = 3; //H
    }   
    
    if(fabs(temp.pdgid) == 17 && not_its_own_mother){
      if(temp.pdgid == 17) temp.charge = -1;
      else if(temp.pdgid == -17) temp.charge = +1;
      vllep.push_back(temp);
    }

    else if(fabs(temp.pdgid) == 18 && not_its_own_mother){
      if(temp.pdgid == 18) temp.charge = -1;
      else if(temp.pdgid == -18) temp.charge = +1;
      vlnu.push_back(temp);
    }
  }
}
