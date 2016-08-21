#define LHE_WP_cxx
#include "iostream"
#include "LHE_WP.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
using namespace std;

void LHE_WP::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L LHE_WP.C
//      Root > LHE_WP t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TH1F *hTopBDR = new TH1F("TopBDR","TopBDR", 100, 0, 4000);
   TH1F *hTopBDRWrongPro = new TH1F("TopBDRWrongPro","TopBDRWrongPro", 100, 0, 4000);

   Long64_t nentries = fChain->GetEntriesFast();
   int WrongProduction = 0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if ( jentry % 1000 == 0 ){  
	fprintf(stdout, "\rProcessed events: %6d of %6d ", jentry + 1, nentries);
	fflush(stdout);
      }
      
     int TopInd = -1;
     int BottomInd = -1;
     int WpInd = -1;

      for(int i=0; i < Particle_size; i++){
      // 	cout<<i<<" PID "<<Particle_PID[i]<<endl;
	if(abs(Particle_PID[i]) == 6 && TopInd == -1)
	  TopInd = i;

	if(abs(Particle_PID[i]) == 5 && BottomInd == -1)
	  BottomInd = i;

	if(abs(Particle_PID[i]) == 34 && WpInd == -1)
	  WpInd = i;
      }

  
	for(int i=0; i < Particle_size; i++){
	  cout<<i<<" PID "<<Particle_PID[i]<<" Mo1 "<<Particle_Mother1[i]<<endl;
	}
    if(WpInd == -1){	WrongProduction++;
      }
      
      TLorentzVector Top(Particle_Px[TopInd], Particle_Py[TopInd], Particle_Pz[TopInd], Particle_E[TopInd]);

      TLorentzVector Bottom(Particle_Px[BottomInd], Particle_Py[BottomInd], Particle_Pz[BottomInd], Particle_E[BottomInd]);
      
      float TopBDR = (Top + Bottom).M();//Top.DeltaR(Bottom);

      hTopBDR->Fill(TopBDR);
     
      if(WpInd == -1)
	hTopBDRWrongPro->Fill(TopBDR);
   }
   cout<<" WrongProduction "<<WrongProduction<<endl;

   TCanvas *MyC = new TCanvas("MyC","MyC");
   hTopBDR->Draw();
   hTopBDRWrongPro->Draw("sames");
}
