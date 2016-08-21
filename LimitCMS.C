//TOP-13-009
void LimitCMS(){
  const int nChannels = nChannels = 3;
  TH1F *signal = new TH1F("signal","signal",nChannels, 0., nChannels);
  TH1F *bkg = new TH1F("bkg","bkg",nChannels, 0., nChannels);
  TH1F *data = new TH1F("data","data",nChannels, 0., nChannels);      

  //mu 7 TeV
  data->SetBinContent(1,1883);
  data->SetBinError(1,sqrt(1883.0));

  //mu 8 TeV
  data->SetBinContent(2,7023);
  data->SetBinError(2,sqrt(7023.0));

  //ele 8 TeV
  data->SetBinContent(3,6301);
  data->SetBinError(3,sqrt(6301));

  // 
  bkg->SetBinContent(1,1920.);
  bkg->SetBinError(1,110);

  //
  bkg->SetBinContent(2,7060.);
  bkg->SetBinError(2,370);

  //
  bkg->SetBinContent(3,6240.);
  bkg->SetBinError(3,320);
      
  float r_step = 0.5;
  int steps = 10;
  TH1F *cls = new TH1F("cls", "cls",
		       steps, (0.5 * r_step), ((0.5 + steps) * r_step));
  for(int i = 1; i < (steps + 1); i++) {
    std::cout << "  r    : " << i * r_step  << std::endl;
    //Wp 2 TeV.
    signal->SetBinContent(1,1.05 * i * r_step);
    signal->SetBinContent(2,5.38 * i * r_step);   
    signal->SetBinContent(3,4.13 * i * r_step);  
  
    signal->SetBinError(1,0.2 * signal->GetBinContent(1)); 
    signal->SetBinError(2,0.2 * signal->GetBinContent(2)); 
    signal->SetBinError(3,0.25 * signal->GetBinContent(3));
 
    TLimitDataSource* mydatasource = new TLimitDataSource(signal,bkg,data);
    TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
     

    std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
    cls->Fill((i * r_step), myconfidence->CLs());

    delete mydatasource;
    delete myconfidence;

  }
  cls->Draw();
}
