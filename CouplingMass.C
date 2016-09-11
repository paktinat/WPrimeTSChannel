void CouplingMass(){
  const int nPoints = 14; //Number of measurements
  double couplings[nPoints] = {TMath::Power(1/50.,1/4.), TMath::Power(1/20.,1/4.), TMath::Power(1/10.,1/4.), TMath::Power(1/8.,1/4.), TMath::Power(1/6.,1/4.), TMath::Power(1/4.,1/4.), TMath::Power(1/3.,1/4.), TMath::Power(1/2.,1/4.), TMath::Power(1.,1/4.), TMath::Power(2.0,1/4.), TMath::Power(4.,1/4.), TMath::Power(6.,1/4.), TMath::Power(8.,1/4.), TMath::Power(10.,1/4.)};

  double massObsgL[nPoints] = {560, 685, 785, 825, 875, 980, 1050, 1145, 1290, 1465, 1640, 1765, 1840, 1890};
  double massExpgL[nPoints] = {540, 660, 760, 800, 850, 950, 1010, 1120, 1255, 1440, 1610, 1730, 1800, 1860};
 
  double massObsgR[nPoints] = {565, 715, 840, 880, 950, 1035, 1100, 1190, 1360, 1530, 1720, 1835, 1915, 1975};
  double massExpgR[nPoints] = {545, 695, 815, 860, 920, 1005, 1065, 1160, 1325, 1500, 1690, 1795, 1870, 1935};

  TCanvas *MyCgL = new TCanvas("MyCgL","MyCgL");
  TGraph *graphObsgL = new TGraph(nPoints, couplings, massObsgL);
  graphObsgL->Draw("APC");
  graphObsgL->SetMaximum(2000);
  graphObsgL->SetMinimum(400);
  graphObsgL->GetYaxis()->SetTitle("m_{W'} (GeV)");
  graphObsgL->GetXaxis()->SetTitle("a^{L}");
  graphObsgL->GetYaxis()->SetTitleOffset(1.3);
  graphObsgL->SetFillColor(4);
  graphObsgL->SetFillStyle(3007);
  graphObsgL->SetLineColor(4);
  graphObsgL->SetLineWidth(-701);
  
  TLatex *tex = new TLatex(0.4,1600,"Left-Handed  W' a^{R} = 0");
  tex->SetTextFont(42);
  tex->SetTextSize(0.04026846);
  tex->SetLineWidth(2);
  tex->Draw();


  TCanvas *MyCgR = new TCanvas("MyCgR","MyCgR");
  TGraph *graphObsgR = new TGraph(nPoints, couplings, massObsgR);
  graphObsgR->Draw("APC");
  graphObsgR->SetMaximum(2000);
  graphObsgR->SetMinimum(400);
  graphObsgR->GetYaxis()->SetTitle("m_{W'} (GeV)");
  graphObsgR->GetXaxis()->SetTitle("a^{R}");
  graphObsgR->GetYaxis()->SetTitleOffset(1.3);
  graphObsgR->SetFillColor(4);
  graphObsgR->SetFillStyle(3007);
  graphObsgR->SetLineColor(4);
  graphObsgR->SetLineWidth(-701);
  
  tex = new TLatex(0.4,1600,"Right-Handed W' a^{L} = 0");
  tex->SetTextFont(42);
  tex->SetTextSize(0.04026846);
  tex->SetLineWidth(2);
  tex->Draw();


}
