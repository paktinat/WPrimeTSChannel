//TOP-13-009
void LimitCMS(){
  const int nChannels = 3;
  TH1F *signal = new TH1F("signal","signal",nChannels, 0., nChannels);
  TH1F *bkg = new TH1F("bkg","bkg",nChannels, 0., nChannels);
  TH1F *data = new TH1F("data","data",nChannels, 0., nChannels);      

  //mu 7 TeV TOP-13-009
  data->SetBinContent(1,1883);
  data->SetBinError(1,sqrt(1883.0));

  //mu 8 TeV TOP-13-009
  data->SetBinContent(2,7023);
  data->SetBinError(2,sqrt(7023.0));

  //ele 8 TeV TOP-13-009
  data->SetBinContent(3,6301);
  data->SetBinError(3,sqrt(6301));

  //mu  7 TeV TOP-13-009
  bkg->SetBinContent(1,1920.);
  bkg->SetBinError(1,110);

  //mu 8 TeV  TOP-13-009
  bkg->SetBinContent(2,7060.);
  bkg->SetBinError(2,370);

  //ele 8 TeV  TOP-13-009
  bkg->SetBinContent(3,6240.);
  bkg->SetBinError(3,320);
      
  float r_step = 0.05;
  int steps = 25;
  TH1F *cls = new TH1F("cls", "cls",
		       steps, (0.5 * r_step), ((0.5 + steps) * r_step));
  for(int i = 1; i < (steps + 1); i++) {
    std::cout << "  r    : " << i * r_step  << std::endl;

    // float WpXS8TeV = 0.066; //Wp 2 TeV.
    // float WpXS7TeV = 0.0349;
    // float WpXS8TeV = 0.207;//Wp 1750 GeV
    // float WpXS7TeV = 0.114;
    // float WpXS8TeV = 0.524;//Wp 1500 GeV
    // float WpXS7TeV = 0.312;
    // float WpXS8TeV = 1.409;//Wp 1250 GeV
    // float WpXS7TeV = 0.914;
    // float WpXS8TeV = 3.180;//Wp 1000 GeV 1208.4858
    // float WpXS7TeV = 2.205;
    float WpXS8TeV = 1.073;//Wp 1250 GeV 1208.4858
    float WpXS7TeV = 0.694;

    signal->SetBinContent(1,WpXS7TeV * (129/4.29) * i * r_step);
    signal->SetBinContent(2,WpXS8TeV * (452/5.55) * i * r_step);   
    signal->SetBinContent(3,WpXS8TeV * (347/5.55) * i * r_step);  


    signal->SetBinError(1,0.1 * signal->GetBinContent(1)); 
    signal->SetBinError(2,0.1 * signal->GetBinContent(2)); 
    signal->SetBinError(3,0.1 * signal->GetBinContent(3));
 
    TLimitDataSource* mydatasource = new TLimitDataSource(signal,bkg,data);
    TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
     

    std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
    cls->Fill((i * r_step), myconfidence->CLs());

    delete mydatasource;
    delete myconfidence;

  }
  cls->Draw();
}
