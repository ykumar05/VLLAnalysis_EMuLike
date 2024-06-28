void AnaScript::CR_WZ(){
  //Clearing the Mass Arrays
  MassArray_3L.clear();
  TransverseMassArray_3L.clear();
  
  //Initializing different masses for 3L Final state
  float mass_01 = 0.0;
  float mass_02 = 0.0;
  float mass_12 = 0.0;

  //Defining
  bool is3mu     = false;
  bool is3ele    = false;
  bool is1ele2mu = false;
  bool is1mu2ele = false;

  //Boolean for chosen pairs
  bool chosen1 = false;
  bool chosen2 = false;
  bool chosen3 = false;
  
  if(is_l3_event){//Light lepton passes trigger threshold and exactly 3L event
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 2197)
      is3mu = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1331)
      is3ele = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1859)
      is1ele2mu = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1573)
      is1mu2ele = true;
  }
  
  //Introducing Event Weights
  float Evt_Weight = 1.0;
  float TriggerWeight = 1.0; 
  if(_data == 0){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
      if(_year == 2018){
	TriggerWeight = (1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())))/(1-(1-TriggEff2018MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())));
	Evt_Weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
      }
      if(_year == 2017){
	TriggerWeight = (1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())))/(1-(1-TriggEff2017MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())));
	Evt_Weight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
      }
    }
    h.WZ_CR[69]->Fill(Evt_Weight);
  }
  
  /***************************************************************************************
   *         Define Scale factors for all 4 kinds of Final state possible here           *
   ***************************************************************************************/ 
  
  /********************************************
   *                  3 Muons                 *
   ********************************************/
  if(is3mu){
    h.WZ_CR[72]->Fill(1,Evt_Weight);
    //Forming pairs of OSSF Muons: Each event will have two pair of OSSF muons and only one correspond to Z and the the leftover muon certainly originates from a W.
    if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
      mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      chosen1 = true;
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
      mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      chosen2 = true;
    }
    if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
      mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      chosen3 = true;
    }

    if(chosen1 && chosen2){
      if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	h.WZ_CR[0]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[1]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
      }
      else{
	h.WZ_CR[2]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[3]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
      }
    }
    if(chosen2 && chosen3){
      if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[4]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[5]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
      }
      else{
	h.WZ_CR[6]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[7]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
      }
    }
    if(chosen1 && chosen3){
      if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[8]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[9]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
      }
      else{
	h.WZ_CR[10]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[11]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
      }
    }
  }

  /********************************************
     *                3 Electrons               *
     ********************************************/
    if(is3ele){
      h.WZ_CR[72]->Fill(2,Evt_Weight);
      //Forming pairs of OSSF Muons: Each event will have two pair of OSSF electons and only one correspond to Z and the the leftover electron certainly originates from a W.
      if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
	mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
	chosen1 = true;
      }
      if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
	mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
	chosen2 = true;
      }
      if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
	mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
	chosen3 = true;
      }

      if(chosen1 && chosen2){
	if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	  h.WZ_CR[12]->Fill(mass_01,Evt_Weight);
	  h.WZ_CR[13]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
	}
	else{
	  h.WZ_CR[14]->Fill(mass_02,Evt_Weight);
	  h.WZ_CR[15]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
	}
      }
      if(chosen2 && chosen3){
	if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	  h.WZ_CR[16]->Fill(mass_02,Evt_Weight);
	  h.WZ_CR[17]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
	}
	else{
	  h.WZ_CR[18]->Fill(mass_12,Evt_Weight);
	  h.WZ_CR[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
	}
      }
      if(chosen1 && chosen3){
	if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	  h.WZ_CR[20]->Fill(mass_01,Evt_Weight);
	  h.WZ_CR[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
	}
	else{
	  h.WZ_CR[22]->Fill(mass_12,Evt_Weight);
	  h.WZ_CR[23]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
	}
      }
    }

    /********************************************
     *          1 Electron & 2 Muons            *
     ********************************************/
    if(is1ele2mu){
      h.WZ_CR[72]->Fill(3,Evt_Weight);
      if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
      mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      chosen1 = true;
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
      mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      chosen2 = true;
    }
    if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
      mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      chosen3 = true;
    }
    if(chosen1){
      h.WZ_CR[24]->Fill(mass_01,Evt_Weight);
      h.WZ_CR[25]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
    }
    if(chosen2){
      h.WZ_CR[26]->Fill(mass_02,Evt_Weight);
      h.WZ_CR[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
    }
    if(chosen3){
      h.WZ_CR[28]->Fill(mass_12,Evt_Weight);
      h.WZ_CR[29]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
    }
  }
            
  /********************************************
   *          1 Muon & 2 Electrons            *
   ********************************************/
  if(is1mu2ele){
    h.WZ_CR[72]->Fill(3,Evt_Weight);
    if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
      mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      chosen1 = true;
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
      mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      chosen2 = true;
    }
    if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
      mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      chosen3 = true;
    }
    if(chosen1){
      h.WZ_CR[30]->Fill(mass_01,Evt_Weight);
      h.WZ_CR[31]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi));
    }
    if(chosen2){
      h.WZ_CR[32]->Fill(mass_02,Evt_Weight);
      h.WZ_CR[33]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi));
    }
    if(chosen3){
      h.WZ_CR[34]->Fill(mass_12,Evt_Weight);
      h.WZ_CR[35]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
      MassArray_3L.push_back(mass_01);
      TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
    }
  }

      
  //Extending the definition of the CR
  if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
    h.WZ_CR[36]->Fill((int)MassArray_3L.size(),Evt_Weight);
    h.WZ_CR[37]->Fill((int)TransverseMassArray_3L.size(),Evt_Weight);
    h.WZ_CR[72]->Fill(MassArray_3L[0],Evt_Weight);
    h.WZ_CR[73]->Fill(TransverseMassArray_3L[0],Evt_Weight);
    h.WZ_CR[74]->Fill(*MET_pt,Evt_Weight);
    h.WZ_CR[75]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
    if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
      if(50<TransverseMassArray_3L.at(0) && TransverseMassArray_3L.at(0)<150){//Transverse Mass
	if(*MET_pt>50 && *MET_pt<150){
	  if(LightLepton.at(2).v.Pt()>20){//Softest Lepton Pt
	    if((int)bJets.size()==0){
	      h.WZ_CR[38]->Fill(1,Evt_Weight);
	      h.WZ_CR[39]->Fill((int)LightLepton.size(),Evt_Weight);
	      h.WZ_CR[40]->Fill(LightLepton.at(0).v.Pt(),Evt_Weight);
	      h.WZ_CR[41]->Fill(LightLepton.at(1).v.Pt(),Evt_Weight);
	      h.WZ_CR[42]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
	      h.WZ_CR[43]->Fill(LightLepton.at(0).v.Eta(),Evt_Weight);
	      h.WZ_CR[44]->Fill(LightLepton.at(1).v.Eta(),Evt_Weight);
	      h.WZ_CR[45]->Fill(LightLepton.at(2).v.Eta(),Evt_Weight);
	      h.WZ_CR[46]->Fill(LightLepton.at(0).v.Phi(),Evt_Weight);
	      h.WZ_CR[47]->Fill(LightLepton.at(1).v.Phi(),Evt_Weight);
	      h.WZ_CR[48]->Fill(LightLepton.at(2).v.Phi(),Evt_Weight);
	      //------>Event Level Kinematics
	      h.WZ_CR[49]->Fill(LT,Evt_Weight);
	      h.WZ_CR[50]->Fill(*MET_pt,Evt_Weight);
	      h.WZ_CR[51]->Fill(LT_MET,Evt_Weight);
	      //------>Angular Variables
	      h.WZ_CR[52]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),Evt_Weight);
	      h.WZ_CR[53]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.WZ_CR[54]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.WZ_CR[55]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),Evt_Weight);
	      h.WZ_CR[56]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),Evt_Weight);
	      h.WZ_CR[57]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*MET_phi),Evt_Weight);
	      //------>Transverse Mass
	      h.WZ_CR[58]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	      h.WZ_CR[59]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	      h.WZ_CR[60]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),Evt_Weight);
	      //------>DeltaR Plots
	      h.WZ_CR[61]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),Evt_Weight);
	      h.WZ_CR[62]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      h.WZ_CR[63]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      //Invariant Mass
	      h.WZ_CR[64]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),Evt_Weight);
	      h.WZ_CR[65]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),Evt_Weight);
	      h.WZ_CR[66]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),Evt_Weight);
	      if((int)Jets.size()>0)
		h.WZ_CR[67]->Fill(HT,Evt_Weight);
	      h.WZ_CR[68]->Fill(ST,Evt_Weight);
	      h.WZ_CR[70]->Fill((int)bJets.size(),Evt_Weight);
	      h.WZ_CR[71]->Fill((int)Jets.size(),Evt_Weight);
	    }
	  }
	}
      }
    }
  }

}

 
