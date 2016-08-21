//        doi:10.1016/j.physletb.2016.03.017
void LimitATLAS(){
  const int nChannels = nChannels = 1;
  TH1F *signal = new TH1F("signal","signal",nChannels, 0., nChannels);
  TH1F *bkg = new TH1F("bkg","bkg",nChannels, 0., nChannels);
  TH1F *data = new TH1F("data","data",nChannels, 0., nChannels);      

  //
  data->SetBinContent(1,14677);
  data->SetBinError(1,sqrt(14677.0));


  // 
  bkg->SetBinContent(1,14670);
  bkg->SetBinError(1,180);

  float r_step = 0.5;
  int steps = 10;
  TH1F *cls = new TH1F("cls", "cls",
		       steps, (0.5 * r_step), ((0.5 + steps) * r_step));
  for(int i = 1; i < (steps + 1); i++) {
    std::cout << "  r    : " << i * r_step  << std::endl;
    //Wp 2 TeV.
    signal->SetBinContent(1,6.35 * i * r_step);
  
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
