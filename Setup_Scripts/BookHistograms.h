void AnaScript::BookHistograms(){
  h.nevt = new TH1F("nEvents","0-Total events, 1-Total events ran, 2-Total events with trigger applied",5,-1,4);
  h.acceptance[0] = new TH1F("Acceptance","Acceptance_0(N_Generated)_1(4L)_2(3L)_3(2LSS)_4(2LOS)_5(1L2J)",6,0,6);
  h.acceptance[1] = new TH1F("finalstates_for_LL","Acceptance_0(N_Generated)_1(4L)_2(3L)_3(2LSS)_4(1L2J)",6,0,6);
  h.acceptance[2] = new TH1F("finalstates_for_LN","Acceptance_0(N_Generated)_1(4L)_2(3L)_3(2LSS)_4(1L2J)",6,0,6);
  h.acceptance[3] = new TH1F("finalstates_for_NN","Acceptance_0(N_Generated)_1(4L)_2(3L)_3(2LSS)_4(1L2J)",6,0,6);

  //Trigger Plots
  h.triggerRes[0] = new TH1F("HLT_IsoMu24","HLT_IsoMu24",3,0,3);
  h.triggerRes[1] = new TH1F("HLT_Ele32_WPTight_Gsf","HLT_Ele32_WPTight_Gsf",3,0,3);
  h.triggerRes[2] = new TH1F("HLT_Ele27_WPTight_Gsf","HLT_Ele27_WPTight_Gsf",3,0,3);

  /******************************************************
   *    Object level plots: (before event selection)    *
   ******************************************************/
  //GenMuons
  h.genpltmu[0]  = new TH1F("GenMuon_pt" ,      "GenMuon_pt",  500,0,500);
  h.genpltmu[1]  = new TH1F("GenMuon_eta",      "GenMuon_eta", 200,-4,4);
  h.genpltmu[2]  = new TH1F("GenMuon_phi",      "GenMuon_phi", 200,-4,4);
  h.genpltmu[3]  = new TH1F("GenMuon_MotherID", "GenMuon_MotherID", 1200,-600,600);
  
  //GenElectrons
  h.genpltele[0]  = new TH1F("GenElectron_pt" ,      "GenElectron_pt",  500,0,500);
  h.genpltele[1]  = new TH1F("GenElectron_eta",      "GenElectron_eta", 200,-4,4);
  h.genpltele[2]  = new TH1F("GenElectron_phi",      "GenElectron_phi", 200,-4,4);
  h.genpltele[3]  = new TH1F("GenElectron_MotherID", "GenElectron_MotherID", 1200,-600,600);

  //Z Plots
  h.genpltZ[0]  = new TH1F("GenZ_MOMID" ,      "GenZ_MOMID_pt",  1200,-600,600);
  //Light Leptons
  h.llep[0]  = new TH1F("nLightLeptons", "nLightLeptons", 10,0,10);
  h.llep[1]  = new TH1F("nlooseLeptons", "nlooseLeptons", 10,0,10);

  //Electrons
  h.ele[0]  = new TH1F("nElectrons",                  "nElectrons",                  10,0,10);
  h.ele[1]  = new TH1F("Electron_pt",                 "Electron_pt",                 500,0,500);
  h.ele[2]  = new TH1F("Electron_eta",                "Electron_eta",                200,-4,4);
  h.ele[3]  = new TH1F("Electron_phi",                "Electron_phi",                200,-4,4);
  h.ele[4]  = new TH1F("LeadingElectron_pt",          "LeadingElectron_pt",          500,0,500);
  h.ele[5]  = new TH1F("LeadingElectron_eta",         "LeadingElectron_eta",         200,-4,4);
  h.ele[6]  = new TH1F("LeadingElectron_phi",         "LeadingElectron_phi",         200,-4,4);
  h.ele[7]  = new TH1F("SubLeadingElectron_pt",       "SubLeadingElectron_pt",       500,0,500);
  h.ele[8]  = new TH1F("SubLeadingElectron_eta",      "SubLeadingElectron_eta",      200,-4,4);
  h.ele[9]  = new TH1F("SubLeadingElectron_phi",      "SubLeadingElectron_phi",      200,-4,4);
  h.ele[10] = new TH1F("dPhi_LeadingElectron_MET",    "dPhi_LeadingElectron_MET",    200,-4,4);
  h.ele[11] = new TH1F("dPhi_SubLeadingElectron_MET", "dPhi_SubLeadingElectron_MET", 200,-4,4);

  //Muons
  h.mu[0]  = new TH1F("nMuons",                  "nMuons",                  10,0,10);
  h.mu[1]  = new TH1F("Muon_pt",                 "Muon_pt",                 500,0,500);
  h.mu[2]  = new TH1F("Muon_eta",                "Muon_eta",                200,-4,4);
  h.mu[3]  = new TH1F("Muon_phi",                "Muon_phi",                200,-4,4);
  h.mu[4]  = new TH1F("LeadingMuon_pt",          "LeadingMuon_pt",          500,0,500);
  h.mu[5]  = new TH1F("LeadingMuon_eta",         "LeadingMuon_eta",         200,-4,4);
  h.mu[6]  = new TH1F("LeadingMuon_phi",         "LeadingMuon_phi",         200,-4,4);
  h.mu[7]  = new TH1F("SubLeadingMuon_pt",       "SubLeadingMuon_pt",       500,0,500);
  h.mu[8]  = new TH1F("SubLeadingMuon_eta",      "SubLeadingMuon_eta",      200,-4,4);
  h.mu[9]  = new TH1F("SubLeadingMuon_phi",      "SubLeadingMuon_phi",      200,-4,4);
  h.mu[10] = new TH1F("dPhi_LeadingMuon_MET",    "dPhi_LeadingMuon_MET",    200,-4,4);
  h.mu[11] = new TH1F("dPhi_SubLeadingMuon_MET", "dPhi_SubLeadingMuon_MET", 200,-4,4);

  //Jets
  h.jet[0]  = new TH1F("nJets",   "nJets",   10,0,10);
  h.jet[1]  = new TH1F("nBJets",  "nBJets",  10,0,10);
  h.jet[2]  = new TH1F("Jet_Pt",  "Jet_Pt",  500,0,500);
  h.jet[3]  = new TH1F("BJet_Pt", "BJet_Pt", 500,0,500);

  //MET
  h.met[0] = new TH1F("MET_pt",  "MET_pt",  500,0,500);
  h.met[1] = new TH1F("MET_phi", "MET_phi", 200,-4,4);

  //EventLevel Variables
  h.lt[0]     = new TH1F("LT",     "LT",     1000,0,1000);
  h.lt_met[0] = new TH1F("LT+MET", "LT+MET", 1000,0,1000);

  //dR Plots
  h.dR[0] = new TH1F("dRMin_Muon_GenMuon",         "dRMin_Muon_GenMuon",         50,0,1);
  h.dR[1] = new TH1F("dRMin_Electron_GenElectron", "dRMin_Electron_GenElectron", 50,0,1);

  //MotherID Plots
  h.momid[0] = new TH1F("MotherId_RecoMuons",     "MotherId_RecoMuons(RecoMuons matched to GenMuons)",             1200,-600,600);
  h.momid[1] = new TH1F("MotherId_RecoElectrons", "MotherId_RecoElectrons(RecoElectrons matched to GenElectrons)", 1200,-600,600);

  //Decay Modes
  h.decayMode[0] = new TH1F("RecoMuon_DecayMode",        "RecoMuon_DecayModes_Z(1)_W(2)_H(3)_L(4)_N(5)",     10,0,10);
  h.decayMode[1] = new TH1F("RecoElectron_DecayMode",    "RecoElectron_DecayModes_Z(1)_W(2)_H(3)_L(4)_N(5)", 10,0,10);
  h.decayMode[2] = new TH1F("VLLDoublet_ProductionMode", "VLLDoublet_ProductionModes_LL(1)_LN(2)_NN(3)",     5,0,5);

  //4L Event Variables
  h.hist_l4[0]  = new TH1F("4L_nLightLeptons", "4L_nLightLeptons", 5,0,5);
  h.hist_l4[1]  = new TH1F("4L_L0_pt",         "4L_L0_pt",         500,0,500);
  h.hist_l4[2]  = new TH1F("4L_L1_pt",         "4L_L1_pt",         500,0,500);
  h.hist_l4[3]  = new TH1F("4L_L2_pt",         "4L_L2_pt",         500,0,500);
  h.hist_l4[4]  = new TH1F("4L_L3_pt",         "4L_L3_pt",         500,0,500);
  h.hist_l4[5]  = new TH1F("4L_L0_eta",        "4L_L0_eta",        200,-4,4);
  h.hist_l4[6]  = new TH1F("4L_L1_eta",        "4L_L1_eta",        200,-4,4);
  h.hist_l4[7]  = new TH1F("4L_L2_eta",        "4L_L2_eta",        200,-4,4);
  h.hist_l4[8]  = new TH1F("4L_L3_eta",        "4L_L3_eta",        200,-4,4);
  h.hist_l4[9]  = new TH1F("4L_L0_phi",        "4L_L0_phi",        200,-4,4);
  h.hist_l4[10] = new TH1F("4L_L1_phi",        "4L_L1_phi",        200,-4,4);
  h.hist_l4[11] = new TH1F("4L_L2_phi",        "4L_L2_phi",        200,-4,4);
  h.hist_l4[12] = new TH1F("4L_L3_phi",        "4L_L3_phi",        200,-4,4);
  h.hist_l4[13] = new TH1F("4L_LT",            "4L_LT",            500,0,500);
  h.hist_l4[14] = new TH1F("4L_MET",           "4L_MET",           500,0,500);
  h.hist_l4[15] = new TH1F("4L_LT+MET",        "4L_LT+MET",        500,0,500);
  h.hist_l4[16] = new TH1F("4L_dPhi_L0MET",    "4L_dPhi_L0MET",    100,0,3.15);
  h.hist_l4[17] = new TH1F("4L_dPhi_L1MET",    "4L_dPhi_L1MET",    100,0,3.15);
  h.hist_l4[18] = new TH1F("4L_dPhi_L2MET",    "4L_dPhi_L2MET",    100,0,3.15);
  h.hist_l4[19] = new TH1F("4L_dPhi_L3MET",    "4L_dPhi_L3MET",    100,0,3.15);
  h.hist_l4[20] = new TH1F("4L_dPhi_L0L1",     "4L_dPhi_L0L1",     100,0,3.15);
  h.hist_l4[21] = new TH1F("4L_dPhi_L0L2",     "4L_dPhi_L0L2",     100,0,3.15);
  h.hist_l4[22] = new TH1F("4L_dPhi_L0L3",     "4L_dPhi_L0L3",     100,0,3.15);
  h.hist_l4[23] = new TH1F("4L_dPhi_L1L2",     "4L_dPhi_L1L2",     100,0,3.15);
  h.hist_l4[24] = new TH1F("4L_dPhi_L1L3",     "4L_dPhi_L1L3",     100,0,3.15);
  h.hist_l4[25] = new TH1F("4L_dPhi_L2L3",     "4L_dPhi_L2L3",     100,0,3.15);
  h.hist_l4[26] = new TH1F("4L_MT_L0",         "4L_MT_L0",         200,0,200);
  h.hist_l4[27] = new TH1F("4L_MT_L1",         "4L_MT_L1",         200,0,200);
  h.hist_l4[28] = new TH1F("4L_MT_L2",         "4L_MT_L2",         200,0,200);
  h.hist_l4[29] = new TH1F("4L_MT_L3",         "4L_MT_L3",         200,0,200);
  h.hist_l4[30] = new TH1F("4L_dR_L0L1",       "4L_dR_L0L1",       100,0,4);
  h.hist_l4[31] = new TH1F("4L_dR_L0L2",       "4L_dR_L0L2",       100,0,4);
  h.hist_l4[32] = new TH1F("4L_dR_L0L3",       "4L_dR_L0L3",       100,0,4);
  h.hist_l4[33] = new TH1F("4L_dR_L1L2",       "4L_dR_L1L2",       100,0,4);
  h.hist_l4[34] = new TH1F("4L_dR_L1L3",       "4L_dR_L1L3",       100,0,4);
  h.hist_l4[35] = new TH1F("4L_dR_L2L3",       "4L_dR_L2L3",       100,0,4);
  h.hist_l4[36] = new TH1F("4L_InvMass_L0L1",  "4L_InvMass_L0L1",  200,0,200);
  h.hist_l4[37] = new TH1F("4L_InvMass_L0L2",  "4L_InvMass_L0L2",  200,0,200);
  h.hist_l4[38] = new TH1F("4L_InvMass_L0L3",  "4L_InvMass_L0L3",  200,0,200);
  h.hist_l4[39] = new TH1F("4L_InvMass_L1L2",  "4L_InvMass_L1L2",  200,0,200);
  h.hist_l4[40] = new TH1F("4L_InvMass_L1L3",  "4L_InvMass_L1L3",  200,0,200);
  h.hist_l4[41] = new TH1F("4L_InvMass_L2L3",  "4L_InvMass_L2L3",  200,0,200);
  h.hist_l4[42] = new TH1F("4L_HT",            "4L_HT",            500,0,500);
  h.hist_l4[43] = new TH1F("4L_ST",            "4L_ST",            800,0,800);
  h.hist_l4[44] = new TH1F("4L_NBJets",        "4L_NBJets",        5,0,5);
  h.hist_l4[45] = new TH1F("4L_NJets",         "4L_NJets",         5,0,5);
  for(int i=0; i<46; i++)
    h.hist_l4[i]->Sumw2();

  //3L Event Variables
  h.hist_l3[0]  = new TH1F("3L_nLightLeptons", "3L_nLightLeptons", 5,0,5);
  h.hist_l3[1]  = new TH1F("3L_L0_pt",         "3L_L0_pt",         500,0,500);
  h.hist_l3[2]  = new TH1F("3L_L1_pt",         "3L_L1_pt",         500,0,500);
  h.hist_l3[3]  = new TH1F("3L_L2_pt",         "3L_L2_pt",         500,0,500);
  h.hist_l3[4]  = new TH1F("3L_L0_eta",        "3L_L0_eta",        200,-4,4);
  h.hist_l3[5]  = new TH1F("3L_L1_eta",        "3L_L1_eta",        200,-4,4);
  h.hist_l3[6]  = new TH1F("3L_L2_eta",        "3L_L2_eta",        200,-4,4);
  h.hist_l3[7]  = new TH1F("3L_L0_phi",        "3L_L0_phi",        200,-4,4);
  h.hist_l3[8]  = new TH1F("3L_L1_phi",        "3L_L1_phi",        200,-4,4);
  h.hist_l3[9]  = new TH1F("3L_L2_phi",        "3L_L2_phi",        200,-4,4);
  h.hist_l3[10] = new TH1F("3L_LT",            "3L_LT",            500,0,500);
  h.hist_l3[11] = new TH1F("3L_MET",           "3L_MET",           500,0,500);
  h.hist_l3[12] = new TH1F("3L_LT+MET",        "3L_LT+MET",        500,0,500);
  h.hist_l3[13] = new TH1F("3L_dPhi_L0MET",    "3L_dPhi_L0MET",    100,0,3.15);
  h.hist_l3[14] = new TH1F("3L_dPhi_L1MET",    "3L_dPhi_L1MET",    100,0,3.15);
  h.hist_l3[15] = new TH1F("3L_dPhi_L2MET",    "3L_dPhi_L2MET",    100,0,3.15);
  h.hist_l3[16] = new TH1F("3L_dPhi_L0L1",     "3L_dPhi_L0L1",     100,0,3.15);
  h.hist_l3[17] = new TH1F("3L_dPhi_L0L2",     "3L_dPhi_L0L2",     100,0,3.15);
  h.hist_l3[18] = new TH1F("3L_dPhi_L1L2",     "3L_dPhi_L1L2",     100,0,3.15);
  h.hist_l3[19] = new TH1F("3L_MT_L0",         "3L_MT_L0",         200,0,200);
  h.hist_l3[20] = new TH1F("3L_MT_L1",         "3L_MT_L1",         200,0,200);
  h.hist_l3[21] = new TH1F("3L_MT_L2",         "3L_MT_L2",         200,0,200);
  h.hist_l3[22] = new TH1F("3L_dR_L0L1",       "3L_dR_L0L1",       100,0,4);
  h.hist_l3[23] = new TH1F("3L_dR_L0L2",       "3L_dR_L0L2",       100,0,4);
  h.hist_l3[24] = new TH1F("3L_dR_L1L2",       "3L_dR_L1L2",       100,0,4);
  h.hist_l3[25] = new TH1F("3L_InvMass_L0L1",  "3L_InvMass_L0L1",  200,0,200);
  h.hist_l3[26] = new TH1F("3L_InvMass_L0L2",  "3L_InvMass_L0L2",  200,0,200);
  h.hist_l3[27] = new TH1F("3L_InvMass_L1L2",  "3L_InvMass_L1L2",  200,0,200);
  h.hist_l3[28] = new TH1F("3L_HT",            "3L_HT",            500,0,500);
  h.hist_l3[29] = new TH1F("3L_ST",            "3L_ST",            800,0,800);
  h.hist_l3[30] = new TH1F("3L_NBJets",        "3L_NBJets",        5,0,5);
  h.hist_l3[31] = new TH1F("3L_NJets",         "3L_NJets",         5,0,5);
  for(int i=0; i<32; i++)
    h.hist_l3[i]->Sumw2();
  
  //2L SS Event Variables
  h.hist_l2SS[0]  = new TH1F("2LSS_nLightLeptons", "2LSS_nLightLeptons", 5,0,5);
  h.hist_l2SS[1]  = new TH1F("2LSS_L0_pt",         "2LSS_L0_pt",         500,0,500);
  h.hist_l2SS[2]  = new TH1F("2LSS_L1_pt",         "2LSS_L1_pt",         500,0,500);
  h.hist_l2SS[3]  = new TH1F("2LSS_L0_eta",        "2LSS_L0_eta",        200,-4,4);
  h.hist_l2SS[4]  = new TH1F("2LSS_L1_eta",        "2LSS_L1_eta",        200,-4,4);
  h.hist_l2SS[5]  = new TH1F("2LSS_L0_phi",        "2LSS_L0_phi",        200,-4,4);
  h.hist_l2SS[6]  = new TH1F("2LSS_L1_phi",        "2LSS_L1_phi",        200,-4,4);
  h.hist_l2SS[7]  = new TH1F("2LSS_LT",            "2LSS_LT",            500,0,500);
  h.hist_l2SS[8]  = new TH1F("2LSS_MET",           "2LSS_MET",           500,0,500);
  h.hist_l2SS[9]  = new TH1F("2LSS_LT+MET",        "2LSS_LT+MET",        500,0,500);
  h.hist_l2SS[10] = new TH1F("2LSS_HT",            "2LSS_HT",            500,0,500);
  h.hist_l2SS[11] = new TH1F("2LSS_ST",            "2LSS_ST",            800,0,800);
  h.hist_l2SS[12] = new TH1F("2LSS_dPhi_L0MET",    "2LSS_dPhi_L0MET",    100,0,4);
  h.hist_l2SS[13] = new TH1F("2LSS_dPhi_L1MET",    "2LSS_dPhi_L1MET",    100,0,4);
  h.hist_l2SS[14] = new TH1F("2LSS_dPhi_L0L1",     "2LSS_dPhi_L0L1",     100,0,4);
  h.hist_l2SS[15] = new TH1F("2LSS_MT_L0",         "2LSS_MT_L0",         200,0,200);
  h.hist_l2SS[16] = new TH1F("2LSS_MT_L1",         "2LSS_MT_L1",         200,0,200);
  h.hist_l2SS[17] = new TH1F("2LSS_dR_L0L1",       "2LSS_dR_L0L1",       100,0,4);
  h.hist_l2SS[18] = new TH1F("2LSS_InvMass_L0L1",  "2LSS_InvMass_L0L1",  200,0,200);
  for(int i=0; i<19; i++)
    h.hist_l2SS[i]->Sumw2();

  //1L2J Event Variables
  h.hist_l12j[0]  = new TH1F("1L2J_nLightLeptons", "1L2J_nLightLeptons", 5,0,5);
  h.hist_l12j[1]  = new TH1F("1L2J_nJets",         "1L2J_nJets",         5,0,5);
  h.hist_l12j[2]  = new TH1F("1L2J_L0_pt",         "1L2J_L0_pt",         500,0,500);
  h.hist_l12j[3]  = new TH1F("1L2J_J0_pt",         "1L2J_J0_pt",         500,0,500);
  h.hist_l12j[4]  = new TH1F("1L2J_J1_pt",         "1L2J_J1_pt",         500,0,500);
  h.hist_l12j[5]  = new TH1F("1L2J_L0_eta",        "1L2J_L0_eta",        200,-4,4);
  h.hist_l12j[6]  = new TH1F("1L2J_J0_eta",        "1L2J_J0_eta",        200,-4,4);
  h.hist_l12j[7]  = new TH1F("1L2J_J1_eta",        "1L2J_J1_eta",        200,-4,4);
  h.hist_l12j[8]  = new TH1F("1L2J_L0_phi",        "1L2J_L0_phi",        200,-4,4);
  h.hist_l12j[9]  = new TH1F("1L2J_J0_phi",        "1L2J_J0_phi",        200,-4,4);
  h.hist_l12j[10] = new TH1F("1L2J_J1_phi",        "1L2J_J1_phi",        200,-4,4);
  h.hist_l12j[11] = new TH1F("1L2J_MT_L0",         "1L2J_MT_L0",         200,0,200);
  h.hist_l12j[12] = new TH1F("1L2J_MT_J0",         "1L2J_MT_J0",         200,0,200);
  h.hist_l12j[13] = new TH1F("1L2J_MT_J1",         "1L2J_MT_J1",         200,0,200);
  h.hist_l12j[14] = new TH1F("1L2J_dPhi_L0MET",    "1L2J_dPhi_L0MET",    100,0,4);
  h.hist_l12j[15] = new TH1F("1L2J_dPhi_J0MET",    "1L2J_dPhi_J0MET",    100,0,4);
  h.hist_l12j[16] = new TH1F("1L2J_dPhi_J1MET",    "1L2J_dPhi_J1MET",    100,0,4);
  h.hist_l12j[17] = new TH1F("1L2J_dPhi_L0J0",     "1L2J_dPhi_L0J0",     100,0,4);
  h.hist_l12j[18] = new TH1F("1L2J_dPhi_L0J1",     "1L2J_dPhi_L0J1",     100,0,4);
  h.hist_l12j[19] = new TH1F("1L2J_dPhi_J0J1",     "1L2J_dPhi_J0J1",     100,0,4);
  h.hist_l12j[20] = new TH1F("1L2J_dPhi_JOJ1_L0",  "1L2J_dPhi_J0J1_L0",  100,0,4);
  h.hist_l12j[21] = new TH1F("1L2J_dPhi_J0J1_MET", "1L2J_dPhi_J0J1_MET", 100,0,4);
  h.hist_l12j[22] = new TH1F("1L2J_dPhi_LJJ_MET",  "1L2J_dPhi_LJJ_MET",  100,0,4);
  h.hist_l12j[23] = new TH1F("1L2J_dPhi_LJJ_L0",   "1L2J_dPhi_LJJ_L0",   100,0,4);
  h.hist_l12j[24] = new TH1F("1L2J_dPhi_LJJ_J0",   "1L2J_dPhi_LJJ_J0",   100,0,4);
  h.hist_l12j[25] = new TH1F("1L2J_dPhi_LJJ_J1",   "1L2J_dPhi_LJJ_J1",   100,0,4);
  h.hist_l12j[26] = new TH1F("1L2J_InvMass_J0J1",  "1L2J_InvMass_J0J1",  200,0,200);
  h.hist_l12j[27] = new TH1F("1L2J_pT_J0J1",       "1L2J_pT_J0J1",       500,0,500);
  h.hist_l12j[28] = new TH1F("1L2J_MT_J0J1",       "1L2J_MT_J0J1",       200,0,200);
  h.hist_l12j[29] = new TH1F("1L2J_dR_J0J1",       "1L2J_dR_J0J1",       100,0,4);
  h.hist_l12j[30] = new TH1F("1L2J_InvMass_LJJ",   "1L2J_InvMass_LJJ",   500,0,500);
  h.hist_l12j[31] = new TH1F("1L2J_pT_LJJ",        "1L2J_pT_LJJ",        500,0,500);
  h.hist_l12j[32] = new TH1F("1L2J_MET",           "1L2J_MET",           500,0,500);
  h.hist_l12j[33] = new TH1F("1L2J_HT",            "1L2J_HT",            500,0,500);
  h.hist_l12j[34] = new TH1F("1L2J_ST",            "1L2J_ST",            1000,0,1000);
  for(int i=0; i<35; i++)
    h.hist_l12j[i]->Sumw2();

  //WZ Control Region Plots
  h.WZ_CR[0]  = new TH1F("3M_Chosen12_Mass01",      "3M_Chosen12_Mass01",      200,0,200);
  h.WZ_CR[1]  = new TH1F("3M_Chosen12_TransMass2",  "3M_Chosen12_TransMass2",  200,0,200);
  h.WZ_CR[2]  = new TH1F("3M_Chosen12_Mass02",      "3M_Chosen12_Mass02",      200,0,200);
  h.WZ_CR[3]  = new TH1F("3M_Chosen12_TransMass1",  "3M_Chosen12_TransMass1",  200,0,200);
  h.WZ_CR[4]  = new TH1F("3M_Chosen23_Mass02",      "3M_Chosen23_Mass02",      200,0,200);
  h.WZ_CR[5]  = new TH1F("3M_Chosen23_TransMass1",  "3M_Chosen23_TransMass1",  200,0,200);
  h.WZ_CR[6]  = new TH1F("3M_Chosen23_Mass12",      "3M_Chosen23_Mass12",      200,0,200);
  h.WZ_CR[7]  = new TH1F("3M_Chosen23_TransMass0",  "3M_Chosen23_TransMass0",  200,0,200);
  h.WZ_CR[8]  = new TH1F("3M_Chosen13_Mass01",      "3M_Chosen13_Mass01",      200,0,200);
  h.WZ_CR[9]  = new TH1F("3M_Chosen13_TransMass2",  "3M_Chosen13_TransMass2",  200,0,200);
  h.WZ_CR[10] = new TH1F("3M_Chosen13_Mass12",      "3M_Chosen13_Mass12",      200,0,200);
  h.WZ_CR[11] = new TH1F("3M_Chosen13_TransMass0",  "3M_Chosen13_TransMass0",  200,0,200);
  h.WZ_CR[12] = new TH1F("3E_Chosen12_Mass01",      "3E_Chosen12_Mass01",      200,0,200);
  h.WZ_CR[13] = new TH1F("3E_Chosen12_TransMass2",  "3E_Chosen12_TransMass2",  200,0,200);
  h.WZ_CR[14] = new TH1F("3E_Chosen12_Mass02",      "3E_Chosen12_Mass02",      200,0,200);
  h.WZ_CR[15] = new TH1F("3E_Chosen12_TransMass1",  "3E_Chosen12_TransMass1",  200,0,200);
  h.WZ_CR[16] = new TH1F("3E_Chosen23_Mass02",      "3E_Chosen23_Mass02",      200,0,200);
  h.WZ_CR[17] = new TH1F("3E_Chosen23_TransMass1",  "3E_Chosen23_TransMass1",  200,0,200);
  h.WZ_CR[18] = new TH1F("3E_Chosen23_Mass12",      "3E_Chosen23_Mass12",      200,0,200);
  h.WZ_CR[19] = new TH1F("3E_Chosen23_TransMass0",  "3E_Chosen23_TransMass0",  200,0,200);
  h.WZ_CR[20] = new TH1F("3E_Chosen13_Mass01",      "3E_Chosen13_Mass01",      200,0,200);
  h.WZ_CR[21] = new TH1F("3E_Chosen13_TransMass2",  "3E_Chosen13_TransMass2",  200,0,200);
  h.WZ_CR[22] = new TH1F("3E_Chosen13_Mass12",      "3E_Chosen13_Mass12",      200,0,200);
  h.WZ_CR[23] = new TH1F("3E_Chosen13_TransMass0",  "3E_Chosen13_TransMass0",  200,0,200);
  h.WZ_CR[24] = new TH1F("1E2M_Chosen1_Mass01",     "1E2M_Chosen1_Mass01",     200,0,200);
  h.WZ_CR[25] = new TH1F("1E2M_Chosen1_TransMass2", "1E2M_Chosen1_TransMass2", 200,0,200);
  h.WZ_CR[26] = new TH1F("1E2M_Chosen2_Mass02",     "1E2M_Chosen2_Mass02",     200,0,200);
  h.WZ_CR[27] = new TH1F("1E2M_Chosen2_TransMass1", "1E2M_Chosen2_TransMass1", 200,0,200);
  h.WZ_CR[28] = new TH1F("1E2M_Chosen3_Mass12",     "1E2M_Chosen3_Mass12",     200,0,200);
  h.WZ_CR[29] = new TH1F("1E2M_Chosen3_TransMass0", "1E2M_Chosen3_TransMass0", 200,0,200);
  h.WZ_CR[30] = new TH1F("1M2E_Chosen1_Mass01",     "1M2E_Chosen1_Mass01",     200,0,200);
  h.WZ_CR[31] = new TH1F("1M2E_Chosen1_TransMass2", "1M2E_Chosen1_TransMass2", 200,0,200);
  h.WZ_CR[32] = new TH1F("1M2E_Chosen2_Mass02",     "1M2E_Chosen2_Mass02",     200,0,200);
  h.WZ_CR[33] = new TH1F("1M2E_Chosen2_TransMass1", "1M2E_Chosen2_TransMass1", 200,0,200);
  h.WZ_CR[34] = new TH1F("1M2E_Chosen3_Mass12",     "1M2E_Chosen3_Mass12",     200,0,200);
  h.WZ_CR[35] = new TH1F("1M2E_Chosen3_TransMass0", "1M2E_Chosen3_TransMass0", 200,0,200);
  h.WZ_CR[36] = new TH1F("MassArray_3L_Size",       "MassArray_3L_Size",       5,0,5);
  h.WZ_CR[37] = new TH1F("TrMassArray_3L_Size",     "TrMassArray_3L_Size",     5,0,5);
  h.WZ_CR[38] = new TH1F("WZ_CR_Test",              "WZ_CR_Test",              3,0,3);
  h.WZ_CR[39] = new TH1F("WZ_nLightLeptons",        "WZ_nLightLeptons",        5,0,5);
  h.WZ_CR[40] = new TH1F("WZ_L0_pt",                "WZ_L0_pt",                400,0,400);
  h.WZ_CR[41] = new TH1F("WZ_L1_pt",                "WZ_L1_pt",                175,0,175);
  h.WZ_CR[42] = new TH1F("WZ_L2_pt",                "WZ_L2_pt",                100,0,100);
  h.WZ_CR[43] = new TH1F("WZ_L0_eta",               "WZ_L0_eta",               200,-4,4);
  h.WZ_CR[44] = new TH1F("WZ_L1_eta",               "WZ_L1_eta",               200,-4,4);
  h.WZ_CR[45] = new TH1F("WZ_L2_eta",               "WZ_L2_eta",               200,-4,4);
  h.WZ_CR[46] = new TH1F("WZ_L0_phi",               "WZ_L0_phi",               200,-4,4);
  h.WZ_CR[47] = new TH1F("WZ_L1_phi",               "WZ_L1_phi",               200,-4,4);
  h.WZ_CR[48] = new TH1F("WZ_L2_phi",               "WZ_L2_phi",               200,-4,4);
  h.WZ_CR[49] = new TH1F("WZ_LT",                   "WZ_LT",                   500,0,500);
  h.WZ_CR[50] = new TH1F("WZ_MET",                  "WZ_MET",                  500,50,500);
  h.WZ_CR[51] = new TH1F("WZ_LT+MET",               "WZ_LT+MET",               800,0,800);
  h.WZ_CR[52] = new TH1F("WZ_dPhi_L0MET",           "WZ_dPhi_L0MET",           100,0,3.15);
  h.WZ_CR[53] = new TH1F("WZ_dPhi_L1MET",           "WZ_dPhi_L1MET",           100,0,3.15);
  h.WZ_CR[54] = new TH1F("WZ_dPhi_L2MET",           "WZ_dPhi_L2MET",           100,0,3.15);
  h.WZ_CR[55] = new TH1F("WZ_dPhi_L0L1",            "WZ_dPhi_L0L1",            100,0,3.15);
  h.WZ_CR[56] = new TH1F("WZ_dPhi_L0L2",            "WZ_dPhi_L0L2",            100,0,3.15);
  h.WZ_CR[57] = new TH1F("WZ_dPhi_L1L2",            "WZ_dPhi_L1L2",            100,0,3.15);
  h.WZ_CR[58] = new TH1F("WZ_MT_L0",                "WZ_MT_L0",                200,0,200);
  h.WZ_CR[59] = new TH1F("WZ_MT_L1",                "WZ_MT_L1",                200,0,200);
  h.WZ_CR[60] = new TH1F("WZ_MT_L2",                "WZ_MT_L2",                200,0,200);
  h.WZ_CR[61] = new TH1F("WZ_dR_L0L1",              "WZ_dR_L0L1",              100,0,4);
  h.WZ_CR[62] = new TH1F("WZ_dR_L0L2",              "WZ_dR_L0L2",              100,0,4);
  h.WZ_CR[63] = new TH1F("WZ_dR_L1L2",              "WZ_dR_L1L2",              100,0,4);
  h.WZ_CR[64] = new TH1F("WZ_InvMass_L0L1",         "WZ_InvMass_L0L1",         200,0,200);
  h.WZ_CR[65] = new TH1F("WZ_InvMass_L0L2",         "WZ_InvMass_L0L2",         200,0,200);
  h.WZ_CR[66] = new TH1F("WZ_InvMass_L1L2",         "WZ_InvMass_L1L2",         200,0,200);
  h.WZ_CR[67] = new TH1F("WZ_HT",                   "WZ_HT",                   800,0,800);
  h.WZ_CR[68] = new TH1F("WZ_ST",                   "WZ_ST",                   1000,0,1000);
  h.WZ_CR[69] = new TH1F("WZ_EvtWeight",            "WZ_EvtWeight",            100,0.5,1.5);
  h.WZ_CR[70] = new TH1F("WZ_NBJets",               "WZ_NBJets",               5,0,5);
  h.WZ_CR[71] = new TH1F("WZ_NJets",                "WZ_NJets",                5,0,5);
  h.WZ_CR[72] = new TH1F("WZ_OnZMass",              "WZ_OnZMass",              200,0,200);
  h.WZ_CR[73] = new TH1F("WZ_TrMass(WLep)",         "WZ_TrMass(WLep)",         200,0,200);
  h.WZ_CR[74] = new TH1F("WZ_MET_Test",             "WZ_MET_Test",             500,0,500);
  h.WZ_CR[75] = new TH1F("WZ_SoftestLepPt",         "WZ_SoftestLepPt",         500,0,500);
  for(int i=0; i<76; i++)
    h.WZ_CR[i]->Sumw2();

  //ZZ Control Region Plots
  h.ZZ_CR[0]  = new TH1F("4M_Pair12_M01",       "4M_Pair12_M01",       200,0,200);
  h.ZZ_CR[1]  = new TH1F("4M_Pair12_M23",       "4M_Pair12_M23",       200,0,200);
  h.ZZ_CR[2]  = new TH1F("4M_Pair12_M02",       "4M_Pair12_M23",       200,0,200);
  h.ZZ_CR[3]  = new TH1F("4M_Pair12_M13",       "4M_Pair12_M23",       200,0,200);
  h.ZZ_CR[4]  = new TH1F("4M_Pair13_M01",       "4M_Pair13_M01",       200,0,200);
  h.ZZ_CR[5]  = new TH1F("4M_Pair13_M23",       "4M_Pair13_M23",       200,0,200);
  h.ZZ_CR[6]  = new TH1F("4M_Pair13_M03",       "4M_Pair13_M03",       200,0,200);
  h.ZZ_CR[7]  = new TH1F("4M_Pair13_M12",       "4M_Pair13_M12",       200,0,200);
  h.ZZ_CR[8]  = new TH1F("4M_Pair23_M02",       "4M_Pair23_M23",       200,0,200);
  h.ZZ_CR[9]  = new TH1F("4M_Pair23_M13",       "4M_Pair23_M23",       200,0,200);
  h.ZZ_CR[10] = new TH1F("4M_Pair23_M03",       "4M_Pair23_M03",       200,0,200);
  h.ZZ_CR[11] = new TH1F("4M_Pair23_M12",       "4M_Pair23_M12",       200,0,200);
  h.ZZ_CR[12] = new TH1F("4E_Pair12_M01",       "4E_Pair12_M01",       200,0,200);
  h.ZZ_CR[13] = new TH1F("4E_Pair12_M23",       "4E_Pair12_M23",       200,0,200);
  h.ZZ_CR[14] = new TH1F("4E_Pair12_M02",       "4E_Pair12_M23",       200,0,200);
  h.ZZ_CR[15] = new TH1F("4E_Pair12_M13",       "4E_Pair12_M23",       200,0,200);
  h.ZZ_CR[16] = new TH1F("4E_Pair13_M01",       "4E_Pair13_M01",       200,0,200);
  h.ZZ_CR[17] = new TH1F("4E_Pair13_M23",       "4E_Pair13_M23",       200,0,200);
  h.ZZ_CR[18] = new TH1F("4E_Pair13_M03",       "4E_Pair13_M03",       200,0,200);
  h.ZZ_CR[19] = new TH1F("4E_Pair13_M12",       "4E_Pair13_M12",       200,0,200);
  h.ZZ_CR[20] = new TH1F("4E_Pair23_M02",       "4E_Pair23_M23",       200,0,200);
  h.ZZ_CR[21] = new TH1F("4E_Pair23_M13",       "4E_Pair23_M23",       200,0,200);
  h.ZZ_CR[22] = new TH1F("4E_Pair23_M03",       "4E_Pair23_M03",       200,0,200);
  h.ZZ_CR[23] = new TH1F("4E_Pair23_M12",       "4E_Pair23_M12",       200,0,200);
  h.ZZ_CR[24] = new TH1F("MassArray_4L_Size_I", "MassArray_4L_Size_I", 5,0,5);
  h.ZZ_CR[25] = new TH1F("MassArray_4L_Size_F", "MassArray_4L_Size_F", 5,0,5);
  h.ZZ_CR[26] = new TH1F("ZZ_CR_4Mu",           "ZZ_CR_4Mu",           5,0,5);
  h.ZZ_CR[27] = new TH1F("ZZ_CR_4Ele",          "ZZ_CR_4Ele",          5,0,5);
  h.ZZ_CR[28] = new TH1F("ZZ_CR_2Ele2Mu",       "ZZ_CR_2Ele2Mu",       5,0,5);
  h.ZZ_CR[29] = new TH1F("ZZ_CR_Test",          "ZZ_CR_Test",          5,0,5);
  h.ZZ_CR[30] = new TH1F("ZZ_nLightLeptons",    "ZZ_nLightLeptons",    5,0,5);
  h.ZZ_CR[31] = new TH1F("ZZ_L0_pt",            "ZZ_L0_pt",            250,0,250);
  h.ZZ_CR[32] = new TH1F("ZZ_L1_pt",            "ZZ_L1_pt",            200,0,200);
  h.ZZ_CR[33] = new TH1F("ZZ_L2_pt",            "ZZ_L2_pt",            100,0,100);
  h.ZZ_CR[34] = new TH1F("ZZ_L3_pt",            "ZZ_L3_pt",            75,0,75);
  h.ZZ_CR[35] = new TH1F("ZZ_L0_eta",           "ZZ_L0_eta",           200,-4,4);
  h.ZZ_CR[36] = new TH1F("ZZ_L1_eta",           "ZZ_L1_eta",           200,-4,4);
  h.ZZ_CR[37] = new TH1F("ZZ_L2_eta",           "ZZ_L2_eta",           200,-4,4);
  h.ZZ_CR[38] = new TH1F("ZZ_L3_eta",           "ZZ_L3_eta",           200,-4,4);
  h.ZZ_CR[39] = new TH1F("ZZ_L0_phi",           "ZZ_L0_phi",           200,-4,4);
  h.ZZ_CR[40] = new TH1F("ZZ_L1_phi",           "ZZ_L1_phi",           200,-4,4);
  h.ZZ_CR[41] = new TH1F("ZZ_L2_phi",           "ZZ_L2_phi",           200,-4,4);
  h.ZZ_CR[42] = new TH1F("ZZ_L3_phi",           "ZZ_L3_phi",           200,-4,4);
  h.ZZ_CR[43] = new TH1F("ZZ_LT",               "ZZ_LT",               450,0,450);
  h.ZZ_CR[44] = new TH1F("ZZ_MET",              "ZZ_MET",              200,0,200);
  h.ZZ_CR[45] = new TH1F("ZZ_LT+MET",           "ZZ_LT+MET",           500,0,500);
  h.ZZ_CR[46] = new TH1F("ZZ_dPhi_L0MET",       "ZZ_dPhi_L0MET",       100,0,3.15);
  h.ZZ_CR[47] = new TH1F("ZZ_dPhi_L1MET",       "ZZ_dPhi_L1MET",       100,0,3.15);
  h.ZZ_CR[48] = new TH1F("ZZ_dPhi_L2MET",       "ZZ_dPhi_L2MET",       100,0,3.15);
  h.ZZ_CR[49] = new TH1F("ZZ_dPhi_L3MET",       "ZZ_dPhi_L3MET",       100,0,3.15);
  h.ZZ_CR[50] = new TH1F("ZZ_dPhi_L0L1",        "ZZ_dPhi_L0L1",        100,0,3.15);
  h.ZZ_CR[51] = new TH1F("ZZ_dPhi_L0L2",        "ZZ_dPhi_L0L2",        100,0,3.15);
  h.ZZ_CR[52] = new TH1F("ZZ_dPhi_L0L3",        "ZZ_dPhi_L0L3",        100,0,3.15);
  h.ZZ_CR[53] = new TH1F("ZZ_dPhi_L1L2",        "ZZ_dPhi_L1L2",        100,0,3.15);
  h.ZZ_CR[54] = new TH1F("ZZ_dPhi_L1L3",        "ZZ_dPhi_L1L3",        100,0,3.15);
  h.ZZ_CR[55] = new TH1F("ZZ_dPhi_L2L3",        "ZZ_dPhi_L2L3",        100,0,3.15);
  h.ZZ_CR[56] = new TH1F("ZZ_MT_L0",            "ZZ_MT_L0",            200,0,200);
  h.ZZ_CR[57] = new TH1F("ZZ_MT_L1",            "ZZ_MT_L1",            200,0,200);
  h.ZZ_CR[58] = new TH1F("ZZ_MT_L2",            "ZZ_MT_L2",            200,0,200);
  h.ZZ_CR[59] = new TH1F("ZZ_MT_L3",            "ZZ_MT_L3",            200,0,200);
  h.ZZ_CR[60] = new TH1F("ZZ_dR_L0L1",          "ZZ_dR_L0L1",          100,0,4);
  h.ZZ_CR[61] = new TH1F("ZZ_dR_L0L2",          "ZZ_dR_L0L2",          100,0,4);
  h.ZZ_CR[62] = new TH1F("ZZ_dR_L0L3",          "ZZ_dR_L0L3",          100,0,4);
  h.ZZ_CR[63] = new TH1F("ZZ_dR_L1L2",          "ZZ_dR_L1L2",          100,0,4);
  h.ZZ_CR[64] = new TH1F("ZZ_dR_L1L3",          "ZZ_dR_L1L3",          100,0,4);
  h.ZZ_CR[65] = new TH1F("ZZ_dR_L2L3",          "ZZ_dR_L2L3",          100,0,4);
  h.ZZ_CR[66] = new TH1F("ZZ_InvMass_L0L1",     "ZZ_InvMass_L0L1",     200,0,200);
  h.ZZ_CR[67] = new TH1F("ZZ_InvMass_L0L2",     "ZZ_InvMass_L0L2",     200,0,200);
  h.ZZ_CR[68] = new TH1F("ZZ_InvMass_L0L3",     "ZZ_InvMass_L0L3",     200,0,200);
  h.ZZ_CR[69] = new TH1F("ZZ_InvMass_L1L2",     "ZZ_InvMass_L1L2",     200,0,200);
  h.ZZ_CR[70] = new TH1F("ZZ_InvMass_L1L3",     "ZZ_InvMass_L1L3",     200,0,200);
  h.ZZ_CR[71] = new TH1F("ZZ_InvMass_L2L3",     "ZZ_InvMass_L2L3",     200,0,200);
  h.ZZ_CR[72] = new TH1F("ZZ_HT",               "ZZ_HT",               200,0,200);
  h.ZZ_CR[73] = new TH1F("ZZ_ST",               "ZZ_ST",               600,0,600);
  h.ZZ_CR[74] = new TH1F("ZZ_EvtWeight",        "ZZ_EvtWeight",        100,0.5,1.5);
  h.ZZ_CR[75] = new TH1F("ZZ_NBJets",           "ZZ_NBJets",           5,0,5);
  h.ZZ_CR[76] = new TH1F("ZZ_NJets",            "ZZ_NJets",            5,0,5);
  h.ZZ_CR[77] = new TH1F("ZZ_InvMass_SelPairs", "ZZ_InvMass_SelPairs", 40,70,110);
  for(int i=0; i<78; i++)
    h.ZZ_CR[i]->Sumw2();

  //DY Control Region Plots
  h.DY_CR[0]  = new TH1F("DY_nLightLeptons", "DY_nLightLeptons",    5,0,5);
  h.DY_CR[1]  = new TH1F("DY_L0_pt",         "DY_L0_pt",            250,0,250);
  h.DY_CR[2]  = new TH1F("DY_L0_eta",        "DY_L0_eta",           200,-4,4);
  h.DY_CR[3]  = new TH1F("DY_L0_phi",        "DY_L0_phi",           200,-4,4);
  h.DY_CR[4]  = new TH1F("DY_L1_pt",         "DY_L1_pt",            200,0,200);
  h.DY_CR[5]  = new TH1F("DY_L1_eta",        "DY_L1_eta",           200,-4,4);
  h.DY_CR[6]  = new TH1F("DY_L1_phi",        "DY_L1_phi",           200,-4,4);
  h.DY_CR[7]  = new TH1F("DY_LT",            "DY_LT",               450,0,450);
  h.DY_CR[8]  = new TH1F("DY_MET",           "DY_MET",              200,0,200);
  h.DY_CR[9]  = new TH1F("DY_LT+MET",        "DY_LT+MET",           500,0,500);
  h.DY_CR[10] = new TH1F("DY_NJets",         "DY_NJets",            6,0,6);
  h.DY_CR[11] = new TH1F("DY_NBJets",        "DY_NBJets",           5,0,5);
  h.DY_CR[12] = new TH1F("DY_HT",            "DY_HT",               200,0,200);
  h.DY_CR[13] = new TH1F("DY_ST",            "DY_ST",               600,0,600);
  h.DY_CR[14] = new TH1F("DY_dPhi_L0MET",    "DY_dPhi_L0MET",       100,0,3.15);
  h.DY_CR[15] = new TH1F("DY_dPhi_L1MET",    "DY_dPhi_L1MET",       100,0,3.15);
  h.DY_CR[16] = new TH1F("DY_dPhi_L0L1",     "DY_dPhi_L0L1",        100,0,3.15);
  h.DY_CR[17] = new TH1F("DY_dR_L0L1",       "DY_dR_L0L1",          100,0,4);
  h.DY_CR[18] = new TH1F("DY_InvMass_L0L1",  "DY_InvMass_L0L1",     200,0,200);
  h.DY_CR[19] = new TH1F("DY_ZPt",           "DY_ZPt",              100,0,100);
  for(int i=0; i<20; i++)
    h.DY_CR[i]->Sumw2();

  //MisID CR Plots: Closure Testing(Data and Prompt Backgrounds plotted here!)
  h.MisId_CR[0] = new TH1F("MisIdCR_L2_Pt", "MisIdCR_L2_Pt", 200, 0,200);
  h.MisId_CR[1] = new TH1F("DYClosure_L2_Pt",   "DYClosure_L2_Pt",   200, 0,200);
  h.MisId_CR[2] = new TH1F("DYClosure_LT",      "DYClosure_LT",      500, 0,500);
  h.MisId_CR[3] = new TH1F("DYClosure_LT_MET",  "DYClosure_LT_MET",  500, 0,500);
  h.MisId_CR[4] = new TH1F("DYClosure_HT",      "DYClosure_HT",      500, 0,500);
  h.MisId_CR[5] = new TH1F("DYClosure_ST",      "DYClosure_ST",      800, 0,800);
  h.MisId_CR[6] = new TH1F("DYClosure_L2MT",    "DYClosure_L2MT",    200, 0,200);
  h.MisId_CR[7] = new TH1F("DYClosure_n3L",    "DYClosure_n3L",      2, 0,2);

}
