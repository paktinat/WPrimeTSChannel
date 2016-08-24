void LimitCombined(){
  
  vector<float> Data;
  vector<float> Bkg;
  vector<float> BkgErr;
  vector<float> sChYield;
  vector<float> sChXSec;
  vector<float> SignalRelErr;
  vector<float*> XSec;
  
  const int nWpMassInd = 6; //number of mass points
  int   WpMass[nWpMassInd]         = { 1000,     1250,     1500,     1750,     2000,      2250};

  float WpPlus8TeV[nWpMassInd]     = {0.901,     0.308,    0.115,   0.0456,   0.0187,   0.00798};//FEWZ NLO
  float WpMinus8TeV[nWpMassInd]    = {0.347,     0.109,   0.0394,   0.0155,  0.00658,   0.00296};//FEWZ NLO

  float WpPlus7TeV[nWpMassInd]     = {0.640,     0.202,   0.0693,   0.0251,  0.00948,   0.00381};
  float WpMinus7TeV[nWpMassInd]    = {0.235,    0.0696,   0.0236,  0.00878,  0.00353,   0.00153}; 

  float WpPlus1p96TeV[nWpMassInd]  = {0.00771, 0.00175, 0.000741, 0.000377, 0.000187, 0.0000709};
  float WpMinus1p96TeV[nWpMassInd] = {0.00771, 0.00175, 0.000741, 0.000377, 0.000187, 0.0000709};

  float WpTotalWidth[nWpMassInd]   = {33.08,     41.52,    49.93,    58.34,    66.72,     75.11};//MG5_aMC_v2_4_3
  float WpPartialWidth[nWpMassInd] = {2.788,     3.485,    4.182,    4.879,    5.576,     6.273};//MG5_aMC_v2_4_3
  float WptbWidth[nWpMassInd]      = {7.991,    10.156,   12.297,   14.424,   16.541,    18.653};//MG5_aMC_v2_4_3

  float Wp1p96TeV[nWpMassInd], Wp7TeV[nWpMassInd], Wp8TeV[nWpMassInd];

  for(int nM = 0; nM < nWpMassInd; nM++){
    cout<<" WpMass "<<WpMass[nM]<<" :: "<<WpTotalWidth[nM]/WpPartialWidth[nM]<<" BR :: "<<WpPartialWidth[nM]/WpTotalWidth[nM]<<endl;
    cout<<" BR tb :: "<<WptbWidth[nM]/WpTotalWidth[nM]<<endl;
    Wp1p96TeV[nM] = (WpPlus1p96TeV[nM] + WpMinus1p96TeV[nM]) * WptbWidth[nM]/WpPartialWidth[nM];
    Wp7TeV[nM] = (WpPlus7TeV[nM] + WpMinus7TeV[nM]) * WptbWidth[nM]/WpPartialWidth[nM];
    Wp8TeV[nM] = (WpPlus8TeV[nM] + WpMinus8TeV[nM]) * WptbWidth[nM]/WpPartialWidth[nM];

    cout<<" 1.96 ::  "<<Wp1p96TeV[nM]<<", 7 ::  "<<Wp7TeV[nM]<<", 8 ::  "<<Wp8TeV[nM]<<endl;

  }

  float Observed_r[nWpMassInd];
  float Expected_r[nWpMassInd];
  float Expected_Minus1_r[nWpMassInd];
  float Expected_Plus1_r[nWpMassInd];
  float WpMass_x[nWpMassInd];

  //CMS mu 7 TeV TOP-13-009
  Data.push_back(1883.0);
  Bkg.push_back(1920.);
  BkgErr.push_back(110.);
  sChYield.push_back(129.);
  sChXSec.push_back(4.29);
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp7TeV);

  //CMS mu 8 TeV TOP-13-009
  Data.push_back(7023.0);
  Bkg.push_back(7060.);
  BkgErr.push_back(370.);
  sChYield.push_back(452.);
  sChXSec.push_back(5.55);
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp8TeV);

  //CMS ele 8 TeV TOP-13-009
  Data.push_back(6301.0);
  Bkg.push_back(6240.);
  BkgErr.push_back(320.);
  sChYield.push_back(347.);
  sChXSec.push_back(5.55);
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp8TeV);
  
  //ATLAS     doi:10.1016/j.physletb.2016.03.017
  Data.push_back(14677.0);
  Bkg.push_back(14670.);
  BkgErr.push_back(180.);
  sChYield.push_back(540.);
  sChXSec.push_back(5.61);
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp8TeV);

  //CDF 1Tb 2jets  TABLE1  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(7128.0);
  Bkg.push_back(7235.);
  BkgErr.push_back(908.);
  sChYield.push_back(98.);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

 //CDF 1T1Lb 2jets  TABLE1  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(680.0);
  Bkg.push_back(674.3);
  BkgErr.push_back(64.2);
  sChYield.push_back(36.4);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

 //CDF 2Tb 2jets  TABLE1  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(507.0);
  Bkg.push_back(524.5);
  BkgErr.push_back(43.);
  sChYield.push_back(46.1);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //CDF 1Tb 3jets  TABLE2  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(3613.0);
  Bkg.push_back(3774.);
  BkgErr.push_back(369.);
  sChYield.push_back(50.);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //CDF 1T1Lb 3jets  TABLE2  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(388.0);
  Bkg.push_back(352.);
  BkgErr.push_back(26.3);
  sChYield.push_back(13.3);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //CDF 2Tb 3jets  TABLE2  doi:10.1103/PhysRevLett.115.061801
  Data.push_back(274.0);
  Bkg.push_back(278.);
  BkgErr.push_back(17.5);
  sChYield.push_back(16.2);
  sChXSec.push_back(1.05);//Fig 5 10.1103/PhysRevLett.112.231803
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);
  
  //D0 2j1b  Table1  doi:10.1016/j.physletb.2013.09.048
  Data.push_back(6859.0);
  Bkg.push_back(6952.);
  BkgErr.push_back(399.);
  sChYield.push_back(112);
  sChXSec.push_back(1.04);//Ref 4 of the same paper
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //D0 2j2b  Table1  doi:10.1016/j.physletb.2013.09.048
  Data.push_back(1286.0);
  Bkg.push_back(1240.);
  BkgErr.push_back(112.);
  sChYield.push_back(83.);
  sChXSec.push_back(1.04);//Ref 4 of the same paper
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //D0 3j1b  Table1  doi:10.1016/j.physletb.2013.09.048
  Data.push_back(2725.0);
  Bkg.push_back(2891.);
  BkgErr.push_back(243.);
  sChYield.push_back(33.);
  sChXSec.push_back(1.04);//Ref 4 of the same paper
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  //D0 3j1b  Table1  doi:10.1016/j.physletb.2013.09.048
  Data.push_back(1233.0);
  Bkg.push_back(1220.);
  BkgErr.push_back(164.);
  sChYield.push_back(29.);
  sChXSec.push_back(1.04);//Ref 4 of the same paper
  SignalRelErr.push_back(0.1);
  XSec.push_back(Wp1p96TeV);

  const int nChannels = Data.size();

  TH1F *signal = new TH1F("signal","signal",nChannels, 0., nChannels);
  TH1F *bkg = new TH1F("bkg","bkg",nChannels, 0., nChannels);
  TH1F *data = new TH1F("data","data",nChannels, 0., nChannels);      

  for(int ii = 0; ii < nChannels; ii++){
    data->SetBinContent(ii+1, Data[ii]);
    data->SetBinError(ii+1, sqrt(Data[ii]));
    
    bkg->SetBinContent(ii+1, Bkg[ii]);
    bkg->SetBinError(ii+1, sqrt(BkgErr[ii]));
    
    std::cout << "  bkg    : " << bkg->GetBinContent(ii+1)  << std::endl;
  }

  float r_step = 0.05;
  int steps = 100;
  TH1F *Observed[nWpMassInd];
  TH1F *Expected[nWpMassInd];
  TH1F *Expected_Plus1[nWpMassInd];
  TH1F *Expected_Minus1[nWpMassInd];
  TCanvas *MyC[nWpMassInd];

  TFile* f = TFile::Open("wPrime.root" , "RECREATE");

  for(int wpMassInd = 0; wpMassInd < nWpMassInd; wpMassInd++){

    char buf[50];
    sprintf(buf,"Observed_%d", WpMass[wpMassInd]);
    Observed[wpMassInd] = new TH1F(buf, buf, steps, (0.5 * r_step), ((0.5 + steps) * r_step));
    
    sprintf(buf,"Exp_%d", WpMass[wpMassInd]);   
    Expected[wpMassInd] = new TH1F(buf, buf,  steps, (0.5 *r_step), ((0.5+ steps) *r_step));

    sprintf(buf,"ExpPlus1_%d", WpMass[wpMassInd]);   
    Expected_Plus1[wpMassInd] = new TH1F(buf, buf,  steps, (0.5 *r_step), ((0.5+ steps) *r_step));

    sprintf(buf,"ExpMinus1_%d", WpMass[wpMassInd]);   
    Expected_Minus1[wpMassInd] = new TH1F(buf, buf,  steps, (0.5 *r_step), ((0.5+ steps) *r_step));

    for(int i = 1; i < (steps + 1); i++) {
     
      for(int jj = 0; jj < nChannels; jj++){
	signal->SetBinContent(jj+1, XSec[jj][wpMassInd] * (sChYield[jj]/sChXSec[jj]) * i * r_step);
	signal->SetBinError(jj+1, SignalRelErr[jj] * signal->GetBinContent(jj+1)); 
      }
      
      TLimitDataSource* mydatasource = new TLimitDataSource(signal,bkg,data);
      TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
      
      //if(wpMassInd == 1)
      //std::cout << "  r    : " << i * r_step  << "  CLs    : " << myconfidence->CLs()  << std::endl;
      Observed[wpMassInd]->Fill((i * r_step), myconfidence->CLs());
      Expected_Plus1[wpMassInd]->Fill((i * r_step), myconfidence->GetExpectedCLs_b(1));
      Expected_Minus1[wpMassInd]->Fill((i * r_step), myconfidence->GetExpectedCLs_b(-1));
      Expected[wpMassInd]->Fill((i * r_step), myconfidence->GetExpectedCLs_b(0));

      delete mydatasource;
      delete myconfidence;
    }
    sprintf(buf,"Canvas_%d", WpMass[wpMassInd]);   
    MyC[wpMassInd] = new TCanvas(buf,buf); 
    Observed[wpMassInd]->Draw();
    Expected_Plus1[wpMassInd]->Draw("same");
    Expected_Minus1[wpMassInd]->Draw("same");
    Expected[wpMassInd]->Draw("same");
   
    WpMass_x[wpMassInd] = WpMass[wpMassInd] * 1.0;
    
    Int_t last = Observed[wpMassInd]->FindLastBinAbove(0.05);
    std::cout << "   last = Observed  : " << last  << std::endl;
    Observed_r[wpMassInd] = Observed[wpMassInd]->GetBinLowEdge(last) + Observed[wpMassInd]->GetBinWidth(last);
    
    std::cout << "   Observed[wpMassInd]->GetBinLowEdge(last)  : " << Observed[wpMassInd]->GetBinLowEdge(last)  << std::endl;
    std::cout << "  Observed[wpMassInd]->GetBinWidth(last) : " << Observed[wpMassInd]->GetBinWidth(last) << std::endl;
    std::cout << "  Observed_r[wpMassInd] : " << Observed_r[wpMassInd] << std::endl;

    last = Expected[wpMassInd]->FindLastBinAbove(0.05);
   
    Expected_r[wpMassInd] = Expected[wpMassInd]->GetBinLowEdge(last) + Expected[wpMassInd]->GetBinWidth(last);

    last = Expected_Minus1[wpMassInd]->FindLastBinAbove(0.05);
   
    Expected_Minus1_r[wpMassInd] = Expected_Minus1[wpMassInd]->GetBinLowEdge(last) + Expected_Minus1[wpMassInd]->GetBinWidth(last);

    last = Expected_Plus1[wpMassInd]->FindLastBinAbove(0.05);
   
    Expected_Plus1_r[wpMassInd] = Expected_Plus1[wpMassInd]->GetBinLowEdge(last) + Expected_Plus1[wpMassInd]->GetBinWidth(last);

    Observed[wpMassInd]->Write();
    Expected[wpMassInd]->Write();
    Expected_Plus1[wpMassInd]->Write();
    Expected_Minus1[wpMassInd]->Write();
    MyC[wpMassInd]->Write();
    delete MyC[wpMassInd];
  }

  TCanvas *Exclusion = new TCanvas("Exclusion","Exclusion");

  TGraph *gObserved = new TGraph(nWpMassInd, WpMass_x, Observed_r);

  gObserved->Draw("APC");

  TGraph *gExpected = new TGraph(nWpMassInd, WpMass_x, Expected_r);

  gExpected->Draw("PC");

  TGraph *gExpected_Plus1 = new TGraph(nWpMassInd, WpMass_x, Expected_Plus1_r);

  gExpected_Plus1->Draw("PC");
 
  TGraph *gExpected_Minus1 = new TGraph(nWpMassInd, WpMass_x, Expected_Minus1_r);

  gExpected_Minus1->Draw("PC");

  gObserved->Write();
  gExpected->Write();
  gExpected_Plus1->Write();
  gExpected_Minus1->Write();
  Exclusion->Write();
  f->Close();
}
