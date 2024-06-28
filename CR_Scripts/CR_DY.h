void AnaScript::CR_DY(){
  //Defining booleans
  bool mu2 = false;
  bool e2  = false;

  //Defining the 2Muon/2Electron events(OS)
  if(is_l2OS_event){
    if(LightLepton.at(0).id*LightLepton.at(1).id == -169)
      mu2 = true;
    if(LightLepton.at(0).id*LightLepton.at(1).id == -121)
      e2 = true;
  }
  
  //Calculating Event Weight(Invoking scale factors)
  float evt_weight = 1.0;
  float TriggerWeight = 1.0;
  float ZpTReWeightFactor = 1.0;
  float JetReWeightFactor = 1.0;

  if(_data ==0){
    if(mu2 || e2){
      if(_year == 2018){

	//Trigger Weight
	TriggerWeight = (1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())))/(1-(1-TriggEff2018MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));

	//ZpT ReWeighting
	ZpTReWeightFactor = ZpTFactor_DY(_sample, LightLepton.at(0).v, LightLepton.at(1).v);
	
	//NJet ReWeighting
	JetReWeightFactor = JetReWeighting_DY(_sample, Jets);

	//Final Event Weight: Scale Factors(Lepton, BTag, Trigger)
	evt_weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*TriggerWeight*bTagSF2018(_sample,Jets);
      }
    }
  }

  //2 Muons final state
  if(mu2 || e2){
    float pair01mass = OSSFMass(0,1);
    if(76<pair01mass && pair01mass<106){
      if(*MET_pt<60){//MET<60
	if(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi())>3.0){
	  if((int)bJets.size()==0){
	    h.DY_CR[0]->Fill((int)LightLepton.size(),evt_weight);
	    h.DY_CR[1]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
	    h.DY_CR[2]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
	    h.DY_CR[3]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
	    h.DY_CR[4]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
	    h.DY_CR[5]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
	    h.DY_CR[6]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
	    //------>Event Level Kinematics
	    h.DY_CR[7]->Fill(LT,evt_weight);
	    h.DY_CR[8]->Fill(*MET_pt,evt_weight);
	    h.DY_CR[9]->Fill(LT_MET,evt_weight);
	    h.DY_CR[10]->Fill((int)Jets.size(),evt_weight);
	    h.DY_CR[11]->Fill((int)bJets.size(),evt_weight);
	    h.DY_CR[12]->Fill(HT,evt_weight);
	    h.DY_CR[13]->Fill(ST,evt_weight);
	    //------>Angular Variables
	    h.DY_CR[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),evt_weight);
	    h.DY_CR[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),evt_weight);
	    h.DY_CR[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
	    h.DY_CR[17]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
	    //Invariant Mass
	    h.DY_CR[18]->Fill(pair01mass,evt_weight);
	    h.DY_CR[19]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).Pt(),evt_weight);
	  }
	}
      }
    }
  }
}

























































//2 Electrons final state
/*if(e2){
  float pair01mass = OSSFMass(0,1);
  if(76<pair01mass && pair01mass<106){
  if(*MET_pt<60){//MET<60
  if(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi())>3.0){
  if((int)bJets.size()==0){
  h.DY_CR[0]->Fill((int)LightLepton.size(),evt_weight);
  h.DY_CR[1]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
  h.DY_CR[2]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
  h.DY_CR[3]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
  h.DY_CR[4]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
  h.DY_CR[5]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
  h.DY_CR[6]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
  //------>Event Level Kinematics
  h.DY_CR[7]->Fill(LT,evt_weight);
  h.DY_CR[8]->Fill(*MET_pt,evt_weight);
  h.DY_CR[9]->Fill(LT_MET,evt_weight);
  h.DY_CR[10]->Fill((int)Jets.size(),evt_weight);
  h.DY_CR[11]->Fill((int)bJets.size(),evt_weight);
  if((int)Jets.size()>0){
  h.DY_CR[12]->Fill(HT,evt_weight);
  h.DY_CR[13]->Fill(ST,evt_weight);
  }
  //------>Angular Variables
  h.DY_CR[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),evt_weight);
  h.DY_CR[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),evt_weight);
  h.DY_CR[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
  h.DY_CR[17]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
  //Invariant Mass
  h.DY_CR[18]->Fill(pair01mass,evt_weight);
  }
  }
  }
  }
  }*/


