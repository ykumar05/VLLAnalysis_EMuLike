#define AnaScript_cxx
#include "AnaScript.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//Setup Function Scripts
#include "Setup_Scripts/BookHistograms.h"
#include "Setup_Scripts/CustomFunctions.h"
#include "Setup_Scripts/ProduceGenCollection.h"
#include "Setup_Scripts/ProduceRecoCollection.h"

//Control Region Functions
//#include "CR_Scripts/CR_zz.h"
#include "CR_Scripts/CR_WZ.h"
#include "CR_Scripts/CR_ZZ.h"
#include "CR_Scripts/CR_DY.h"

//Scale Factors
#include "ScaleFactor_Scripts/scalefactor_UL18.h"
#include "ScaleFactor_Scripts/scalefactor_UL17.h"
#include "ScaleFactor_Scripts/TriggerEfficiencyScaleFactor.h"
#include "ScaleFactor_Scripts/ApplyScaleFactors.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2018.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_UL18.h"

void AnaScript::Begin(TTree * /*tree*/)
{
  TString option = GetOption();
}

void AnaScript::SlaveBegin(TTree * /*tree*/)
{
  time(&start);

  TString option = GetOption();
  nEvtTotal = 0;
  nEvtRan = 0;
  nEvtTrigger= 0;
  nEvtBad = 0;
  //nEvtSkim = 0;
  n_l2OS = 0;
  n_l2SS = 0;
  n_l3 = 0;
  n_l4 = 0;
  n_l12j = 0;

  _HstFile = new TFile(_HstFileName,"recreate");
  //Call the function to book the histograms we declared in Hists.
  BookHistograms();


}

void AnaScript::SlaveTerminate()
{
  _HstFile->Write();
  _HstFile->Close();

  float goodevtfrac = ((float)nEvtRan)/((float)nEvtTotal);
  float trigevtfrac = ((float)nEvtTrigger)/((float)nEvtTotal);

  cout<<"---------------------------------------------"<<endl;
  cout<<"Summary:"<<endl;
  cout<<"Total events = "<<nEvtTotal<<endl;
  cout<<"Total events ran = "<<nEvtRan<<" ("<<goodevtfrac*100<<" %)"<<endl;
  cout<<"Total Triggered events = "<<nEvtTrigger<<" ("<<trigevtfrac*100<<" %)"<<endl;
  if(_flag == "doublet")
    cout<<"Total discarded events for VLL Doublet = "<<nEvtBad<<endl;
  cout<<"---------------------------------------------"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  cout<<"               Event Selection                 "<<endl;
  cout<<"-----------------------------------------------"<<endl;
  cout<<"Events with 4 or more Light Leptons = "<<n_l4<<endl;
  cout<<"Events with 3 Light Leptons         = "<<n_l3<<endl;
  cout<<"Events with 2LSS Light Leptons      = "<<n_l2SS<<endl;
  cout<<"Events with 2LOS Light Leptons      = "<<n_l2OS<<endl;
  cout<<"Events with 1L2J Final state        = "<<n_l12j<<endl;
  
  time(&end);

  double time_taken = double(end-start);
  cout<<"Time taken by the program is= "<<fixed<<time_taken<<setprecision(5);
  cout<<"sec"<<endl;
}

void AnaScript::Terminate()
{
  
}

Bool_t AnaScript::Process(Long64_t entry)
{
  fReader.SetLocalEntry(entry);
  if(_data == 0)
    fReader_MC  .SetLocalEntry(entry);
  if(_data == 1)
    fReader_Data.SetLocalEntry(entry);

  //Setting verbosity:
  //Verbosity determines the number of processed events after which
  if(_verbosity==0 && nEvtTotal%100000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;      
  else if(_verbosity>0 && nEvtTotal%100000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;

  nEvtTotal++;
  h.nevt->Fill(0);

  GoodEvt2018 = (_year==2018 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2017 = (_year==2017 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2016 = (_year==2016 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  
  GoodEvt = GoodEvt2016 && GoodEvt2017 && GoodEvt2018;

  if(GoodEvt){
    nEvtRan++; //only good events
    h.nevt->Fill(1);
    h.acceptance[0]->Fill(0);
    h.acceptance[1]->Fill(0);
    h.acceptance[2]->Fill(0);
    h.acceptance[3]->Fill(0);

    triggerRes=true; //Always true for MC
    if(_data==1){
      triggerRes=false;
      bool muon_trigger = false;
      bool electron_trigger = false;
      if(_year==2016){muon_trigger = (*HLT_IsoMu24==1); electron_trigger = (*HLT_Ele27_WPTight_Gsf==1);}
      //else if(_year==2017){muon_trigger = (*HLT_IsoMu27==1); electron_trigger = (*HLT_Ele32_WPTight_Gsf_L1DoubleEG==1);}
      else if(_year==2018){muon_trigger = (*HLT_IsoMu24==1); electron_trigger = (*HLT_Ele32_WPTight_Gsf==1);}
      triggerRes = muon_trigger || (!muon_trigger && electron_trigger);
    }
    
    h.triggerRes[0]->Fill(*HLT_IsoMu24);
    h.triggerRes[1]->Fill(*HLT_Ele32_WPTight_Gsf);
    h.triggerRes[2]->Fill(*HLT_Ele27_WPTight_Gsf);

    if(triggerRes){
      nEvtTrigger++; //only triggered events
      h.nevt->Fill(2);

      /*******************************************************
       *               Gen particle block                    *
       *******************************************************/   
      //Clearing the Gen Arrays
      /*bool bad_event = false;
	if(_data == 0){
	genMuon.clear();
	genElectron.clear();
	genZ.clear();
	genLightLepton.clear();
	vllep.clear();
	vlnu.clear();
	
	GenMuon();
	GenElectron();
	GenZ();
	createSignalArrays();
	
	//Sorting the Gen Arrays
	SortGenObjects();
	SortVLL();
	
	//Correcting the Doublet model (flagging out the invalid decays)
	if(_flag=="doublet"){ //for VLLD files
	for(int i=0; i<(int)vlnu.size(); i++){
	for(int j=0; j<(int)vlnu.at(i).dauid.size(); j++){
	if(fabs(vlnu.at(i).dauid[j]) == 25)      
	bad_event = true;
	else if(fabs(vlnu.at(i).dauid[j]) == 23)
	bad_event = true;
	}
	}
	//b) The lepton cannot decay to a W,nu of the corresponding flavor (ele/mu):
	// I am flagging out the events with W(24) as daughetrs of L
	for(int i=0; i<(int)vllep.size(); i++){
	for(int j=0; j<(int)vllep.at(i).dauid.size(); j++){
	if(fabs(vllep.at(i).dauid[j]) == 24)
	bad_event = true;
	}
	}
	}
	}
	//Counting bad events:
	if(bad_event)
	nEvtBad++;*/
    	
      /*******************************************************
       *               Reco particle block                   *
       *******************************************************/   
      //Defining and Clearing the arrays
      //loosetau.clear();
      //Tau.clear();
      Muon.clear();
      Electron.clear();
      LightLepton.clear();
      loosellep.clear();
      looseMuon.clear();
      looseEle.clear();
      Jets.clear();
      bJets.clear();

      //Calling the function that consists the electron and muons block
      //createTaus();
      createLightLeptons();
      createJets();
      
      //Sorting the arrays
      SortRecoObjects();

      //Light Lepton Plots
      h.llep[0]->Fill((int)LightLepton.size());
      h.llep[1]->Fill((int)loosellep.size());

      
      //ELectrons
      h.ele[0]->Fill((int)Electron.size());
      for(int i=0; i<(int)Electron.size(); i++){
	h.ele[1]->Fill(Electron.at(i).v.Pt());
	h.ele[2]->Fill(Electron.at(i).v.Eta());
	h.ele[3]->Fill(Electron.at(i).v.Phi());
      }
      if((int)Electron.size()>1){
	h.ele[4]->Fill(Electron.at(0).v.Pt());
	h.ele[5]->Fill(Electron.at(0).v.Eta());
	h.ele[6]->Fill(Electron.at(0).v.Phi());
	h.ele[7]->Fill(Electron.at(1).v.Pt());
	h.ele[8]->Fill(Electron.at(1).v.Eta());
	h.ele[9]->Fill(Electron.at(1).v.Phi());
	h.ele[10]->Fill(delta_phi(Electron.at(0).v.Phi(),*MET_phi));
	h.ele[11]->Fill(delta_phi(Electron.at(1).v.Phi(),*MET_phi));
      }
      
      //Muons
      h.mu[0]->Fill((int)Muon.size());
      for(int i=0; i<(int)Muon.size(); i++){
	h.mu[1]->Fill(Muon.at(i).v.Pt());
	h.mu[2]->Fill(Muon.at(i).v.Eta());
	h.mu[3]->Fill(Muon.at(i).v.Phi());
      }
      if((int)Muon.size()>1){
	h.mu[4]->Fill(Muon.at(0).v.Pt());
	h.mu[5]->Fill(Muon.at(0).v.Eta());
	h.mu[6]->Fill(Muon.at(0).v.Phi());
	h.mu[7]->Fill(Muon.at(1).v.Pt());
	h.mu[8]->Fill(Muon.at(1).v.Eta());
	h.mu[9]->Fill(Muon.at(1).v.Phi());
	h.mu[10]->Fill(delta_phi(Muon.at(0).v.Phi(),*MET_phi));
	h.mu[11]->Fill(delta_phi(Muon.at(1).v.Phi(),*MET_phi));
      }

      //Jets
      h.jet[0]->Fill((int)Jets.size());
      h.jet[1]->Fill((int)bJets.size());
      for(int i=0; i<(int)Jets.size(); i++){
	h.jet[2]->Fill(Jets.at(i).v.Pt());
      }
      for(int i=0; i<(int)bJets.size(); i++){
	h.jet[3]->Fill(bJets.at(i).v.Pt());
      }
      
      //MET
      h.met[0]->Fill(*MET_pt);
      h.met[1]->Fill(*MET_phi);

      //Filling Event level variable
      LT=0.0;
      LT_MET = 0.0;
      HT = 0.0;
      ST = 0.0;
      if((int)LightLepton.size()>0){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  LT += LightLepton.at(i).v.Pt();
	}
	LT_MET = LT + *MET_pt;
	h.lt[0]->Fill(LT);
	h.lt_met[0]->Fill(LT_MET);
      }
      if((int)Jets.size()>0){
	for(int k=0; k<(int)Jets.size(); k++)
	  HT += Jets.at(k).v.Pt();
      }
      ST = LT_MET + HT;

      /***********************************************************************************
       *                                 Analysis block                                  *
       ***********************************************************************************/
      
      /*************************************
       *         Trigger Definition        *
       *************************************/
      is_l2SS_event = false;
      is_l2OS_event = false;
      is_l12j_event = false;
      is_l3_event   = false;
      is_l4_event   = false;
      evt_trigger   = false;
      
      //4L Inclusive
      if((int)LightLepton.size() > 3){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  if(_year == 2018){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 27)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){	  
	  is_l4_event = true;
	  n_l4++;
	  h.acceptance[0]->Fill(1);
	}
      }
      
      //Exactly 3L
      if((int)LightLepton.size() == 3){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  if(_year == 2018){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 27)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){	  
	  is_l3_event = true;
	  n_l3++;
	  h.acceptance[0]->Fill(2);
	}
      }
      
      //2L SS
      if((int)LightLepton.size()==2){
	if((LightLepton.at(0).id)*(LightLepton.at(1).id) == 169 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == 121 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == 143){
	  for(int i=0; i<(int)LightLepton.size(); i++){
	    if(_year == 2018){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	    if(_year == 2017){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 27)
		evt_trigger = true;
	    }
	  }
	  if(evt_trigger){	  
	    is_l2SS_event = true;
	    n_l2SS++;
	    h.acceptance[0]->Fill(3);
	  }
	}
      }

      //2L OS
      if((int)LightLepton.size()==2){
	if((LightLepton.at(0).id)*(LightLepton.at(1).id) == -169 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == -121 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == -143){
	  for(int i=0; i<(int)LightLepton.size(); i++){
	    if(_year == 2018){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	    if(_year == 2017){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 27)
		evt_trigger = true;
	    }
	  }
	  if(evt_trigger){	  
	    is_l2OS_event = true;
	    n_l2OS++;
	    h.acceptance[0]->Fill(4);
	  }
	}
      }
      
      //1L2J
      else if((int)LightLepton.size()==1 && (int)Jets.size()>1){
	if(_year == 2018){
	  if(fabs(LightLepton.at(0).id) == 11 && LightLepton.at(0).v.Pt() > 32)
	    evt_trigger = true;
	  if(fabs(LightLepton.at(0).id) == 13 && LightLepton.at(0).v.Pt() > 26)
	    evt_trigger = true;
	}
	if(_year == 2017){
	  if(fabs(LightLepton.at(0).id) == 11 && LightLepton.at(0).v.Pt() > 32)
	    evt_trigger = true;
	  if(fabs(LightLepton.at(0).id) == 13 && LightLepton.at(0).v.Pt() > 27)
	    evt_trigger = true;
	}
	if(evt_trigger){	  
	  is_l12j_event = true;
	  n_l12j++;
	  h.acceptance[0]->Fill(5);
	}
      }
      
      /*****************************************
       *             Scale Factors             *
       *****************************************/
      float EvtWeight = 1.0;
      float TriggerWeight = 1.0;
      if(_data ==0){
	
	//Four Lepton Events
	if(is_l4_event){
	  if(_year == 2018){
	    TriggerWeight = (1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())))/(1-(1-TriggEff2018MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())));
	    EvtWeight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL18(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight;
	  }
	  if(_year == 2017){
	    TriggerWeight = (1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())))/(1-(1-TriggEff2017MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())));
	    EvtWeight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL17(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight;
	  }
	}

	//Three lepton events
	if(is_l3_event){
	  if(_year == 2018){
	    TriggerWeight = (1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())))/(1-(1-TriggEff2018MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())));
	    EvtWeight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	  }
	  if(_year == 2017){
	    TriggerWeight = (1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())))/(1-(1-TriggEff2017MC(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017MC(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())));
	    EvtWeight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	  }
	}
	
      }
    
      
      /*****************************************************
       *             Event level variables: 4L             *
       *****************************************************/
      if(is_l4_event){
	if(LT>150){
	  if(*MET_pt>60){
	    if(ST>250){
	      //------>Kinematics
	      h.hist_l4[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l4[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l4[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l4[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l4[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	      h.hist_l4[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l4[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l4[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l4[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	      h.hist_l4[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l4[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l4[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      h.hist_l4[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l4[13]->Fill(LT,EvtWeight);
	      h.hist_l4[14]->Fill(*MET_pt,EvtWeight);
	      h.hist_l4[15]->Fill(LT_MET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l4[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),EvtWeight);
	      h.hist_l4[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),EvtWeight);
	      h.hist_l4[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*MET_phi),EvtWeight);
	      h.hist_l4[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*MET_phi),EvtWeight);
	      h.hist_l4[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l4[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l4[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	      h.hist_l4[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	      h.hist_l4[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	      h.hist_l4[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l4[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l4[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l4[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l4[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4[43]->Fill(ST,EvtWeight);
	      h.hist_l4[42]->Fill(HT,EvtWeight);
	      h.hist_l4[44]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l4[45]->Fill((int)Jets.size(),EvtWeight);
	    }
	  }
	}
      }
      
      /*****************************************************
       *             Event level variables: 3L             *
       *****************************************************/
      if(is_l3_event){
	if(LT>175){
	  if(*MET_pt>150){
	    //------>Kinematics
	    h.hist_l3[0]->Fill((int)LightLepton.size(),EvtWeight);
	    h.hist_l3[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	    h.hist_l3[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	    h.hist_l3[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	    h.hist_l3[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	    h.hist_l3[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	    h.hist_l3[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	    h.hist_l3[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	    h.hist_l3[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	    h.hist_l3[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	    //------>Event Level Kinematics
	    h.hist_l3[10]->Fill(LT,EvtWeight);
	    h.hist_l3[11]->Fill(*MET_pt,EvtWeight);
	    h.hist_l3[12]->Fill(LT_MET,EvtWeight);
	    //------>Angular Variables
	    h.hist_l3[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	    h.hist_l3[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l3[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l3[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),EvtWeight);
	    h.hist_l3[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),EvtWeight);
	    h.hist_l3[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*MET_phi),EvtWeight);
	    //------>Transverse Mass
	    h.hist_l3[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	    h.hist_l3[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	    h.hist_l3[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	    //------>DeltaR Plots
	    h.hist_l3[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	    h.hist_l3[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    h.hist_l3[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    //Invariant Mass
	    h.hist_l3[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	    h.hist_l3[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l3[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l3[29]->Fill(ST,EvtWeight);
	    h.hist_l3[28]->Fill(HT,EvtWeight);
	    h.hist_l3[30]->Fill((int)bJets.size(),EvtWeight);
	    h.hist_l3[31]->Fill((int)Jets.size(),EvtWeight);
	  }
	}
      }
      
      /*****************************************************
       *           Event level variables: 2LSS             *
       *****************************************************/
      if(is_l2SS_event){
	//------>Kinematics
	h.hist_l2SS[0]->Fill((int)LightLepton.size(),EvtWeight);
	h.hist_l2SS[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	h.hist_l2SS[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	h.hist_l2SS[3]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	h.hist_l2SS[4]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	h.hist_l2SS[5]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	h.hist_l2SS[6]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	//------>Event Level Kinematics
	h.hist_l2SS[7]->Fill(LT,EvtWeight);
	h.hist_l2SS[8]->Fill(*MET_pt,EvtWeight);
	h.hist_l2SS[9]->Fill(LT_MET,EvtWeight);
	h.hist_l2SS[10]->Fill(HT,EvtWeight);
	h.hist_l2SS[11]->Fill(ST,EvtWeight);
	//------>Angular Variables
	h.hist_l2SS[12]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	h.hist_l2SS[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi),EvtWeight);
	h.hist_l2SS[14]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*MET_phi),EvtWeight);
	//------>Transverse Mass
	h.hist_l2SS[15]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	h.hist_l2SS[16]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*MET_pt,*MET_phi),EvtWeight);
	//------>DeltaR Plots
	h.hist_l2SS[17]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	//Invariant Mass
	h.hist_l2SS[18]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
      }

      /*****************************************************
       *            Event level variables: 1L2J            *
       *****************************************************/
      if(is_l12j_event){
	//Kinematics
	h.hist_l12j[0]->Fill((int)LightLepton.size());
	h.hist_l12j[1]->Fill((int)Jets.size());
	h.hist_l12j[2]->Fill(LightLepton.at(0).v.Pt());
	h.hist_l12j[3]->Fill(Jets.at(0).v.Pt());
	h.hist_l12j[4]->Fill(Jets.at(1).v.Pt());
	h.hist_l12j[5]->Fill(LightLepton.at(0).v.Eta());
	h.hist_l12j[6]->Fill(Jets.at(0).v.Eta());
	h.hist_l12j[7]->Fill(Jets.at(1).v.Eta());
	h.hist_l12j[8]->Fill(LightLepton.at(0).v.Phi());
	h.hist_l12j[9]->Fill(Jets.at(0).v.Phi());
	h.hist_l12j[10]->Fill(Jets.at(1).v.Phi());
	//------>Transverse Mass
	h.hist_l12j[11]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*MET_pt,*MET_phi));
	h.hist_l12j[12]->Fill(transv_mass(Jets.at(0).v.Pt(),Jets.at(0).v.Phi(),*MET_pt,*MET_phi));
	h.hist_l12j[13]->Fill(transv_mass(Jets.at(1).v.Pt(),Jets.at(1).v.Phi(),*MET_pt,*MET_phi));
	//Angular Variables
	h.hist_l12j[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*MET_phi));
	h.hist_l12j[15]->Fill(delta_phi(Jets.at(0).v.Phi(),*MET_phi));
	h.hist_l12j[16]->Fill(delta_phi(Jets.at(1).v.Phi(),*MET_phi));
	h.hist_l12j[17]->Fill(delta_phi(Jets.at(0).v.Phi(),LightLepton.at(0).v.Phi()));
	h.hist_l12j[18]->Fill(delta_phi(Jets.at(1).v.Phi(),LightLepton.at(0).v.Phi()));
	h.hist_l12j[19]->Fill(delta_phi(Jets.at(0).v.Phi(),Jets.at(1).v.Phi()));
	h.hist_l12j[20]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v).Phi(),LightLepton.at(0).v.Phi()));
	h.hist_l12j[21]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v).Phi(),*MET_phi));
	h.hist_l12j[22]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).Phi(),*MET_phi));
	h.hist_l12j[23]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).Phi(),LightLepton.at(0).v.Phi()));
	h.hist_l12j[24]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).Phi(),Jets.at(0).v.Phi()));
	h.hist_l12j[25]->Fill(delta_phi((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).Phi(),Jets.at(1).v.Phi()));
	//DiJet system
	h.hist_l12j[26]->Fill((Jets.at(0).v+Jets.at(1).v).M());
	h.hist_l12j[27]->Fill((Jets.at(0).v+Jets.at(1).v).Pt());
	h.hist_l12j[28]->Fill(transv_mass((Jets.at(0).v+Jets.at(1).v).Pt(),(Jets.at(0).v+Jets.at(1).v).Phi(),*MET_pt,*MET_phi));
	//dR
	h.hist_l12j[29]->Fill(Jets.at(0).v.DeltaR(Jets.at(1).v));
	//ljj system
	h.hist_l12j[30]->Fill((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).M());
	h.hist_l12j[31]->Fill((Jets.at(0).v+Jets.at(1).v+LightLepton.at(0).v).Pt());
	//Event Level Kinematics
	h.hist_l12j[32]->Fill(*MET_pt);
	h.hist_l12j[33]->Fill(HT);
	h.hist_l12j[34]->Fill(ST);
      }
      //Defining the Control Regions
      CR_WZ();
      CR_ZZ();
      //CR_zz();
      CR_DY();
            
    }//TriggeredEvts
  }//GoodEvt
  return kTRUE;
}
