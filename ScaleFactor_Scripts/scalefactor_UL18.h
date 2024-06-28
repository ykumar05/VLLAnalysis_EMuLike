//Reco Scale Factors(Electrons): 2018
double AnaScript::getScaleFactors_Electrons_Reco_UL18(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.99895179271698;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.99895179271698;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.1436463594436646;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9888888597488404;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 1.0768293142318726;
    if(0.0<eta && eta<1.0) 
      scale_factor = 1.0768293142318726;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9888888597488404;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.1436463594436646;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.99895179271698;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.99895179271698;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.98353910446167;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9887179732322692;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9754385948181152;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.98238343000412;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9886831045150756;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9865702390670776;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9864583611488342;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.987525999546051;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9791013598442078;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9870129823684692;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9877049326896667;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9866803288459778;
    }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.98670756816864;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9887869358062744;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.96592116355896;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.98353910446167;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9877426028251648;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9876922965049744;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9855072498321532;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9886128306388856;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.98031085729599;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9741935729980468;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9887869358062744;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9887869358062744;
    }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.996926248073578;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9939024448394777;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0338428020477295;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9979296326637268;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9897330403327942;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9897540807724;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9897540807724;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9897330403327942;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9979296326637268;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0338428020477295;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9939024448394777;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.996926248073578;
    }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9989827275276184;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.007128357887268;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.030803084373474;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9938271641731262;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9959100484848022;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9959058165550232;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9959058165550232;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9959100484848022;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9938271641731262;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.030803084373474;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.007128357887268;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9989827275276184;
    }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2018
double AnaScript::getScaleFactors_Electrons_IDIso_UL18(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0568181276321411;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0353130102157593;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0157480239868164;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.970703125;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9808428883552552;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0078431367874146;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0016286373138428;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0356472730636597;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0014164447784424;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9870466589927672;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9584487676620485;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.967346966266632;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9728997349739076;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9650349617004396;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9750983119010924;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9886845946311952;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9950980544090272;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9861271381378174;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9647887349128724;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9686775207519532;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9732868671417236;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9668246507644652;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9802784323692322;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9852579832077026;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9918032884597778;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9865319728851318;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.966216206550598;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9709821343421936;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9732142686843872;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9693877696990968;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9797979593276978;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9801169633865356;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9978237152099608;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0021858215332031;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.990217387676239;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0054525136947632;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0054824352264404;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.99672132730484;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9854586124420166;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2018
double AnaScript::getScaleFactors_Muons_Reco_UL18(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.04000400946163;
    if( 20<pt && pt<25)
      scale_factor =  0.989014677272758;
    if( 25<pt && pt<30)
      scale_factor =  0.9989055590645546;
    if( 30<pt && pt<40)
      scale_factor =  0.999760853514322;
    if( 40<pt && pt<50)
      scale_factor =  0.999565467845588;
    if( 50<pt && pt<60)
      scale_factor =  0.9998204415944014;
    if( 60<pt && pt<120)
      scale_factor =  0.9975015485587808;
    if( 120<pt && pt<3000)
      scale_factor =  0.9975015485587808;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0334239991476872;
    if( 20<pt && pt<25)
      scale_factor =  0.9832043508246824;
    if( 25<pt && pt<30)
      scale_factor =  0.9962074764783356;
    if( 30<pt && pt<40)
      scale_factor =  0.999066550372675;
    if( 40<pt && pt<50)
      scale_factor =  0.999297799609978;
    if( 50<pt && pt<60)
      scale_factor =  0.999898284881032;
    if( 60<pt && pt<120)
      scale_factor =  0.9978985301114488;
    if( 120<pt && pt<3000)
      scale_factor =  0.9978985301114488;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9052340457842656;
    if( 20<pt && pt<25)
      scale_factor =  0.9932902480824264;
    if( 25<pt && pt<30)
      scale_factor =  0.9941744704916416;
    if( 30<pt && pt<40)
      scale_factor = 0.9981802152409986 ;
    if( 40<pt && pt<50)
      scale_factor =  0.9992437146078612;
    if( 50<pt && pt<60)
      scale_factor =  0.9988904857161484;
    if( 60<pt && pt<120)
      scale_factor =  0.9961937512394232;
    if( 120<pt && pt<3000)
      scale_factor =  0.9961937512394232;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9606433668106512;
    if( 20<pt && pt<25)
      scale_factor =  0.9911896930756448;
    if( 25<pt && pt<30)
      scale_factor =  0.9910856248132396;
    if( 30<pt && pt<40)
      scale_factor =  0.9907553768818946;
    if( 40<pt && pt<50)
      scale_factor =  0.9933622417972257;
    if( 50<pt && pt<60)
      scale_factor =  0.9972680454815808;
    if( 60<pt && pt<120)
      scale_factor =  0.9665749388673832;
    if( 120<pt && pt<3000)
      scale_factor =  0.9665749388673832;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2018
double AnaScript::getScaleFactors_Muons_ID_UL18(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.997503630932556;
    if( 20<pt && pt<25)
      scale_factor =  0.9970098193760408;
    if( 25<pt && pt<30)
      scale_factor =  0.9967038731014324;
    if( 30<pt && pt<40)
      scale_factor =  0.9968067958281034;
    if( 40<pt && pt<50)
      scale_factor =  0.9967508548887346;
    if( 50<pt && pt<60)
      scale_factor =  0.9966229487883712;
    if( 60<pt && pt<120)
      scale_factor =  0.9960404563074258;
    if( 120<pt && pt<3000)
      scale_factor =  0.9960404563074258;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9946687083751804;
    if( 20<pt && pt<25)
      scale_factor =  0.9945901104821656;
    if( 25<pt && pt<30)
      scale_factor =  0.9949123046983688;
    if( 30<pt && pt<40)
      scale_factor =  0.9956851566638726;
    if( 40<pt && pt<50)
      scale_factor =  0.995312757370098;
    if( 50<pt && pt<60)
      scale_factor =  0.9953453170396492;
    if( 60<pt && pt<120)
      scale_factor =  0.9952502092400578;
    if( 120<pt && pt<3000)
      scale_factor =  0.9952502092400578;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9935059740562387;
    if( 20<pt && pt<25)
      scale_factor =  0.9938964039703309;
    if( 25<pt && pt<30)
      scale_factor =  0.9940771317309104;
    if( 30<pt && pt<40)
      scale_factor =  0.9941876412222066;
    if( 40<pt && pt<50)
      scale_factor =  0.9947739560711352;
    if( 50<pt && pt<60)
      scale_factor =  0.9944640815519576;
    if( 60<pt && pt<120)
      scale_factor =  0.9944321015185944;
    if( 120<pt && pt<3000)
      scale_factor =  0.9944321015185944;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9741187787139896;
    if( 20<pt && pt<25)
      scale_factor =  0.9727131632621572;
    if( 25<pt && pt<30)
      scale_factor =  0.9739795198691632;
    if( 30<pt && pt<40)
      scale_factor =  0.9750724343730348;
    if( 40<pt && pt<50)
      scale_factor =  0.9747976871311668;
    if( 50<pt && pt<60)
      scale_factor =  0.9743746068723314;
    if( 60<pt && pt<120)
      scale_factor =  0.970208378910226;
    if( 120<pt && pt<3000)
      scale_factor =  0.970208378910226;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2018
double AnaScript::getScaleFactors_Muons_ISO_UL18(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9855709248030112;
    if( 20<pt && pt<25)
      scale_factor =  0.9915374149428736;
    if( 25<pt && pt<30)
      scale_factor =  0.9892802138927208;
    if( 30<pt && pt<40)
      scale_factor =  0.99429319088059;
    if( 40<pt && pt<50)
      scale_factor =  0.9960381793609222;
    if( 50<pt && pt<60)
      scale_factor =  0.9966122162214248;
    if( 60<pt && pt<120)
      scale_factor =  0.9982512434902386;
    if( 120<pt && pt<3000)
      scale_factor =  0.9982512434902386;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9704305474456316;
    if( 20<pt && pt<25)
      scale_factor =  0.979495631900224;
    if( 25<pt && pt<30)
      scale_factor =  0.986109906870666;
    if( 30<pt && pt<40)
      scale_factor =  0.9882799134496284;
    if( 40<pt && pt<50)
      scale_factor =  0.9920317410868984;
    if( 50<pt && pt<60)
      scale_factor =  0.9944502663616424;
    if( 60<pt && pt<120)
      scale_factor =  0.9964834155289044;
    if( 120<pt && pt<3000)
      scale_factor =  0.9964834155289044;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  1.0033355765204894;
    if( 20<pt && pt<25)
      scale_factor =  1.0015352730781717;
    if( 25<pt && pt<30)
      scale_factor =  0.999623464660824;
    if( 30<pt && pt<40)
      scale_factor =  0.9994357007740622;
    if( 40<pt && pt<50)
      scale_factor =  0.99882097063955;
    if( 50<pt && pt<60)
      scale_factor =  0.999185450924234;
    if( 60<pt && pt<120)
      scale_factor =  0.9995171516432572;
    if( 120<pt && pt<3000)
      scale_factor =  0.9995171516432572;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  1.0252542402601108;
    if( 20<pt && pt<25)
      scale_factor =  1.0198418523288777;
    if( 25<pt && pt<30)
      scale_factor =  1.012454313839175;
    if( 30<pt && pt<40)
      scale_factor =  1.008064837308479;
    if( 40<pt && pt<50)
      scale_factor =  1.0037288955534218;
    if( 50<pt && pt<60)
      scale_factor =  1.0028456983691447;
    if( 60<pt && pt<120)
      scale_factor =  1.0029888816740478;
    if( 120<pt && pt<3000)
      scale_factor =  1.0029888816740478;
  }
  return scale_factor;
}

