#define skimmer_cxx
#include "skimmer.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//Including the header files:
#include "CustomFunctions.h"
#include "ProduceGenCollection.h"
#include "ProduceRecoCollection.h"

void skimmer::Begin(TTree * /*tree*/)
{
  TString option = GetOption();
}

void skimmer::SlaveBegin(TTree * /*tree*/)
{
  time(&start);

  TString option = GetOption();
  nEvtTotal = 0;
  nEvtRan = 0;
  nEvtTrigger= 0;
  nEvtBad = 0;
  nEvtSkim = 0;
}

void skimmer::SlaveTerminate()
{
  //For Skimmer
  cout<<"Writing Skim File..."<<endl;
  skimTree->Write();
  _SkimFile->Close();
  cout<<" Done! "<<endl;

  float goodevtfrac = ((float)nEvtRan)/((float)nEvtTotal);
  float trigevtfrac = ((float)nEvtTrigger)/((float)nEvtTotal);

  cout<<"---------------------------------------------"<<endl;
  cout<<"Summary:"<<endl;
  cout<<"Total events = "<<nEvtTotal<<endl;
  cout<<"Total events ran = "<<nEvtRan<<" ("<<goodevtfrac*100<<" %)"<<endl;
  cout<<"Total Triggered events = "<<nEvtTrigger<<" ("<<trigevtfrac*100<<" %)"<<endl;
  cout<<"Total Skimmed events = "<<nEvtSkim<<endl;
  
  time(&end);

  double time_taken = double(end-start);
  cout<<"Time taken by the program is= "<<fixed<<time_taken<<setprecision(5);
  cout<<"sec"<<endl;
}

void skimmer::Terminate()
{
  
}

Bool_t skimmer::Process(Long64_t entry)
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
  
  GoodEvt2018 = (_year==2018 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2017 = (_year==2017 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2016 = (_year==2016 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  
  GoodEvt = GoodEvt2016 && GoodEvt2017 && GoodEvt2018;

  if(GoodEvt){
    nEvtRan++; //only good events

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
    
    if(triggerRes){
      nEvtTrigger++; //only triggered events
      
      /*******************************************************
       *               Gen particle block                    *
       *******************************************************/   
      //Clearing the Gen Arrays
      bool bad_event = false;
      if(_data == 0){
	genMuon.clear();
	genElectron.clear();
	genLightLepton.clear();
	
	GenMuon();
	GenElectron();
		
	//Sorting the Gen Arrays
	SortGenObjects();
      }

      /*******************************************************
       *               Reco particle block                   *
       *******************************************************/   
      //Defining and Clearing the arrays
      loosellep.clear();
      looseMuon.clear();
      LightLepton.clear();
      Tau.clear();
      Jets.clear();
      bJets.clear();

      //Calling the function that consists the electron and muons block
      createLightLeptons();
      createTaus();
      createJets();
      
      //Sorting the arrays
      SortRecoObjects();

      float met_pt = *MET_pt;
      float met_phi = *MET_phi;


      /***********************************************************************************
       *                                 Analysis block                                  *
       ***********************************************************************************/
      
      /*************************************
       *         Trigger Definition        *
       *************************************/
      is_l2_event = false;
      evt_trigger   = false;
      
      //2L Inclusive
      if((int)LightLepton.size() >= 2){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  if(_year == 2018){
	    if( fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 32 )
	      evt_trigger = true;
	    if( fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 24 )
	      evt_trigger = true;
	  }
	}
	if(evt_trigger)
	  is_l2_event = true;
      }
      
      if(is_l2_event){
	nEvtSkim++;
	skimTree->Fill();
      }
      
    }//TriggeredEvts
  }//GoodEvt
  return kTRUE;
}
