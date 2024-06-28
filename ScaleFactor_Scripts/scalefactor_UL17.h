//RecoScaleFactors(Electrons): 2017
double AnaScript::getScaleFactors_Electrons_Reco_UL17(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0136841535568235;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0126183032989502;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.092337965965271;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 1.0033222436904907;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 1.047619104385376;
    if(0.0<eta && eta<1.0) 
      scale_factor = 1.047619104385376;
    if(1.0<eta && eta<1.444) 
      scale_factor = 1.0033222436904907;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.092337965965271;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0126183032989502;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0136841535568235;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9814624190330504;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.986652970314026;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9261430501937866;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9803516268730164;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9866666793823242;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9876543283462524;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9886481165885924;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9917355179786682;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.98221755027771;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.978723406791687;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9876543283462524;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.986652970314026;
    }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9836233258247375;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9867346882820128;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9574015140533448;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9825819730758668;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9887983798980712;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.988752543926239;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9897540807724;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9938398599624634;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.98343688249588;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9817400574684144;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9897750616073608;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9867346882820128;
    }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9764344096183776;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.004094123840332;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0240436792373655;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9887640476226808;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.998976469039917;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.984725058078766;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.984725058078766;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.998976469039917;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9887640476226808;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0240436792373655;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.004094123840332;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9764344096183776;
    }
  if(100<pt && pt<500){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.978830635547638;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9878296256065368;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.04966139793396;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.988752543926239;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9949341416358948;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 1.0010162591934204;
    if(0.0<eta && eta<0.5) 
      scale_factor = 1.0010162591934204;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9949341416358948;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.988752543926239;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.04966139793396;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9878296256065368;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.978830635547638;
    }
  return scale_factor;
}

//IDIso Scale Factors(Electron): 2017
double AnaScript::getScaleFactors_Electrons_IDIso_UL17(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0641509294509888;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0369181632995603;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0371747016906738;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9908088445663452;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.012635350227356;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0055969953536987;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0367279052734375;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.117424249649048;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0115773677825928;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9868593811988832;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9860917925834656;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9647218585014344;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.973045825958252;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9929676651954652;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.990728497505188;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9971264600753784;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9929824471473694;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9799764156341552;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9698376059532166;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9768250584602356;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9834123253822328;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9906213283538818;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.011264085769653;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9988123774528505;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.993228018283844;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.979706883430481;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9721293449401855;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9788418412208556;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9830124378204346;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9954648613929749;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0035587549209597;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9966443181037904;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0044004917144775;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0120482444763184;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.993513524532318;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9967532753944396;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.012061357498169;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0032858848571775;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0055803060531616;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2017
double AnaScript::getScaleFactors_Muons_Reco_UL17(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.0371205652692903;
    if( 20<pt && pt<25)
      scale_factor =  0.9953024686566452;
    if( 25<pt && pt<30)
      scale_factor =  0.997336963959657;
    if( 30<pt && pt<40)
      scale_factor =  0.9998589637860762;
    if( 40<pt && pt<50)
      scale_factor = 0.9996989192141472 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9992867403140626;
    if( 60<pt && pt<120)
      scale_factor =  0.9987532372551404;
    if( 120<pt && pt<3000)
      scale_factor =  0.9987532372551404;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0155193528163595;
    if( 20<pt && pt<25)
      scale_factor =  0.997835231302182;
    if( 25<pt && pt<30)
      scale_factor =  0.998108430594894;
    if( 30<pt && pt<40)
      scale_factor =  0.999698441575575;
    if( 40<pt && pt<50)
      scale_factor =  0.9996785795794768;
    if( 50<pt && pt<60)
      scale_factor =  0.9996068337718907;
    if( 60<pt && pt<120)
      scale_factor =  0.9979892255029518;
    if( 120<pt && pt<3000)
      scale_factor =  0.9979892255029518;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9425928386608312;
    if( 20<pt && pt<25)
      scale_factor = 0.9774500349547384 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9926385124009492 ;
    if( 30<pt && pt<40)
      scale_factor =  0.9990079418864558;
    if( 40<pt && pt<50)
      scale_factor = 0.999447004850786 ;
    if( 50<pt && pt<60)
      scale_factor = 0.998832969729422 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9934707909605992 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9934707909605992 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 0.9804188624012592 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9346039234654976 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9947780248422452 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9913476405385134 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9966131458258156 ;
    if( 50<pt && pt<60)
      scale_factor = 1.000509333359629 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9872165645210326;
    if( 120<pt && pt<3000)
      scale_factor = 0.9872165645210326 ;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2017
double AnaScript::getScaleFactors_Muons_ID_UL17(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9924863614579832;
    if( 20<pt && pt<25)
      scale_factor =  0.9954816932715648;
    if( 25<pt && pt<30)
      scale_factor = 0.9955697844976936 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9951603878132708 ;
    if( 40<pt && pt<50)
      scale_factor =  0.9951105073375844;
    if( 50<pt && pt<60)
      scale_factor = 0.9951976038330612 ;
    if( 60<pt && pt<120)
      scale_factor = 0.994666968105307 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.994666968105307 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor = 0.9956696921512976 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9939450305313444 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9947276454652628 ;
    if( 30<pt && pt<40)
      scale_factor = 0.995398905706962 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9957428336764376 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9955082832064152 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9955641990427432 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9955641990427432 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9933986091392504;
    if( 20<pt && pt<25)
      scale_factor = 0.9927132381475516 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9941829604829172 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9944960514832868 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9949584995961004 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9944590661336324;
    if( 60<pt && pt<120)
      scale_factor = 0.994652812538256 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.994652812538256 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9693846291868856;
    if( 20<pt && pt<25)
      scale_factor =  0.9747230928008838;
    if( 25<pt && pt<30)
      scale_factor = 0.9759171153765592 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9764452514984272 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9758862144605156 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9742452980764128;
    if( 60<pt && pt<120)
      scale_factor = 0.974770219850666 ;
    if( 120<pt && pt<3000)
      scale_factor =  0.974770219850666;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2017
double AnaScript::getScaleFactors_Muons_ISO_UL17(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9947823718048496;
    if( 20<pt && pt<25)
      scale_factor = 1.0016942717758164 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9971703762914856 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9973609608464306 ;
    if( 40<pt && pt<50)
      scale_factor =  0.997806350070658;
    if( 50<pt && pt<60)
      scale_factor = 0.9978293376015096 ;
    if( 60<pt && pt<120)
      scale_factor = 0.998652869099414 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.998652869099414 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0183992947285718;
    if( 20<pt && pt<25)
      scale_factor = 1.0038832134794526 ;
    if( 25<pt && pt<30)
      scale_factor =  1.0075445153230558;
    if( 30<pt && pt<40)
      scale_factor =  1.0020084794113078;
    if( 40<pt && pt<50)
      scale_factor =  0.9992002400422144;
    if( 50<pt && pt<60)
      scale_factor = 0.998833434134476 ;
    if( 60<pt && pt<120)
      scale_factor =  1.000293946420109;
    if( 120<pt && pt<3000)
      scale_factor =  1.000293946420109;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  1.0284365276526;
    if( 20<pt && pt<25)
      scale_factor = 1.0231949144028831 ;
    if( 25<pt && pt<30)
      scale_factor =  1.0139222529965777;
    if( 30<pt && pt<40)
      scale_factor = 1.006437043406326 ;
    if( 40<pt && pt<50)
      scale_factor = 1.0024938664942575 ;
    if( 50<pt && pt<60)
      scale_factor = 1.0010470387044712 ;
    if( 60<pt && pt<120)
      scale_factor =  1.0004498131972417;
    if( 120<pt && pt<3000)
      scale_factor =  1.0004498131972417;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  1.0300218449052083;
    if( 20<pt && pt<25)
      scale_factor =  1.024066132761046;
    if( 25<pt && pt<30)
      scale_factor =  1.0156122873346385;
    if( 30<pt && pt<40)
      scale_factor = 1.0060772873232575 ;
    if( 40<pt && pt<50)
      scale_factor =  1.002661144530422;
    if( 50<pt && pt<60)
      scale_factor = 1.0005458111900405 ;
    if( 60<pt && pt<120)
      scale_factor =  1.0005556400044369;
    if( 120<pt && pt<3000)
      scale_factor =  1.0005556400044369;
  }
  return scale_factor;
}
