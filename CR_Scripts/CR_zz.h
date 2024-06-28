void AnaScript::CR_zz(){

  //Counting the number of OSSF pairs
  int LightLeptonOSSFN = getOSSFN();
  int OnZn = 0;

  if(is_l4_event){
    //if(fabs(LightLepton.at(0).id*LightLepton.at(1).id*LightLepton.at(2).id*LightLepton.at(3).id) == 28561){
    //Defining the mass of the possible pairs
    float pair01mass = OSSFMass(0,1);
    float pair02mass = OSSFMass(0,2);
    float pair03mass = OSSFMass(0,3);
    float pair12mass = OSSFMass(1,2);
    float pair13mass = OSSFMass(1,3);
    float pair23mass = OSSFMass(2,3);

    int pair01 = 76<pair01mass && pair01mass<106;
    int pair02 = 76<pair02mass && pair02mass<106;
    int pair03 = 76<pair03mass && pair03mass<106;
    int pair12 = 76<pair12mass && pair12mass<106;
    int pair13 = 76<pair13mass && pair13mass<106;
    int pair23 = 76<pair23mass && pair23mass<106;
  
    if(pair01+pair23==2)
      OnZn=2;
    else if(pair02+pair13==2)
      OnZn=2;
    else if(pair03+pair12==2)
      OnZn=2;
  }
  
  float evt_weight = 1.0;  
  if(LightLeptonOSSFN == 2){
    if(OnZn==2){//Double OnZ
      if((int)bJets.size()==0){//Bjet==0
	if(*MET_pt<60){
	  h.ZZ_CR[29]->Fill(1,evt_weight);
	  h.ZZ_CR[30]->Fill((int)LightLepton.size(),evt_weight);
	  h.ZZ_CR[31]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
	  h.ZZ_CR[32]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
	  h.ZZ_CR[33]->Fill(LightLepton.at(2).v.Pt(),evt_weight);
	  h.ZZ_CR[34]->Fill(LightLepton.at(3).v.Pt(),evt_weight);
	  h.ZZ_CR[35]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
	  h.ZZ_CR[36]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
	  h.ZZ_CR[37]->Fill(LightLepton.at(2).v.Eta(),evt_weight);
	  h.ZZ_CR[38]->Fill(LightLepton.at(3).v.Eta(),evt_weight);
	  h.ZZ_CR[39]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
	  h.ZZ_CR[40]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
	  h.ZZ_CR[41]->Fill(LightLepton.at(2).v.Phi(),evt_weight);
	  h.ZZ_CR[42]->Fill(LightLepton.at(3).v.Phi(),evt_weight);
	  //------>Event Level Kinematics
	  h.ZZ_CR[43]->Fill(LT,evt_weight);
	  h.ZZ_CR[44]->Fill(*MET_pt,evt_weight);
	  h.ZZ_CR[45]->Fill(LT_MET,evt_weight);
	  //------>Angular Variables
	  h.ZZ_CR[46]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),evt_weight);
	  h.ZZ_CR[47]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),evt_weight);
	  h.ZZ_CR[48]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*MET_phi),evt_weight);
	  h.ZZ_CR[49]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*MET_phi),evt_weight);
	  h.ZZ_CR[50]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
	  h.ZZ_CR[51]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),evt_weight);
	  h.ZZ_CR[52]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	  h.ZZ_CR[53]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),evt_weight);
	  h.ZZ_CR[54]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	  h.ZZ_CR[55]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	  //------>Transverse Mass
	  h.ZZ_CR[56]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),evt_weight);
	  h.ZZ_CR[57]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),evt_weight);
	  h.ZZ_CR[58]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),evt_weight);
	  h.ZZ_CR[59]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*MET_pt,*MET_phi),evt_weight);
	  //------>DeltaR Plots
	  h.ZZ_CR[60]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
	  h.ZZ_CR[61]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),evt_weight);
	  h.ZZ_CR[62]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),evt_weight);
	  h.ZZ_CR[63]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),evt_weight);
	  h.ZZ_CR[64]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),evt_weight);
	  h.ZZ_CR[65]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),evt_weight);
	  //Invariant Mass
	  h.ZZ_CR[66]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),evt_weight);
	  h.ZZ_CR[67]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),evt_weight);
	  h.ZZ_CR[68]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),evt_weight);
	  h.ZZ_CR[69]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),evt_weight);
	  h.ZZ_CR[70]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),evt_weight);
	  h.ZZ_CR[71]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),evt_weight);
	  if((int)Jets.size()>0)
	    h.ZZ_CR[72]->Fill(HT,evt_weight);
	  h.ZZ_CR[73]->Fill(ST,evt_weight);
	  h.ZZ_CR[75]->Fill((int)bJets.size(),evt_weight);
	  h.ZZ_CR[76]->Fill((int)Jets.size(),evt_weight);
	}
      }
    }
  }
}
