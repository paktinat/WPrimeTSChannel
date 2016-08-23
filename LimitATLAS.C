//        doi:10.1016/j.physletb.2016.03.017
void LimitATLAS(){
  const int nChannels = 1;
  TH1F *signal = new TH1F("signal","signal",nChannels, 0., nChannels);
  TH1F *bkg = new TH1F("bkg","bkg",nChannels, 0., nChannels);
  TH1F *data = new TH1F("data","data",nChannels, 0., nChannels);      

  //
  data->SetBinContent(1,14677.0);
  data->SetBinError(1,sqrt(14677.0));


  // 
  bkg->SetBinContent(1,14670.0);
  bkg->SetBinError(1,180.0);

  float r_step = 0.5;
  int steps = 5;
  TH1F *cls = new TH1F("cls", "cls",
		       steps, (0.5 * r_step), ((0.5 + steps) * r_step));
  for(int i = 1; i < (steps + 1); i++) {
    std::cout << "  r    : " << i * r_step  << std::endl;
    //Wp 2 TeV.
    // signal->SetBinContent(1,6.35 * i * r_step);
    
    //Wp 1 TeV FEWZ NNLO XSection
    //signal->SetBinContent(1, 15 * 540.0/5.61 * i * r_step);

    //Wp 1.75 TeV 1208.4858
    //signal->SetBinContent(1, 0.643 * 540.0/5.61 * i * r_step);

    //Wp 1.5 TeV 1208.4858
    // signal->SetBinContent(1, 1.6 * 540.0/5.61 * i * r_step);

    // float WpXS8TeV = 0.066; //Wp 2 TeV.
    // float WpXS8TeV = 0.207;//Wp 1750 GeV
    // float WpXS8TeV = 0.524;//Wp 1500 GeV
    //float WpXS8TeV = 1.409;//Wp 1250 GeV
    //float WpXS8TeV = 3.180;//Wp 1000 GeV 1208.4858
    float WpXS8TeV = 1.073;//Wp 1250 GeV 1208.4858

    signal->SetBinContent(1, WpXS8TeV * (540/5.61) * i * r_step);

    signal->SetBinError(1,0.1 * signal->GetBinContent(1)); 
 
    TLimitDataSource* mydatasource = new TLimitDataSource(signal,bkg,data);
    TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
     

    std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
    cls->Fill((i * r_step), myconfidence->CLs());

    delete mydatasource;
    delete myconfidence;

  }
  cls->Draw();
}
