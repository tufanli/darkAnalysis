#if !defined(__CINT__)
#include "darkSectorUtilities.h"
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#include "darkSectorVB.h"
#include <vector>
#endif /* !defined(__CINT__) */

void analysis_multiplicities()
{
  TFile *input = new TFile("flux_ben.root");

  //  TFile *input = new TFile("darkSector.root");
  TTree *tr = (TTree *)input->Get("tree");

  cout << "deneme == "<< tr->GetEntries()<< endl;
  //  darkSectorEvent *ev = 0;

  darkSectorEvent *ev = 0;

  TBranch *id = tr->GetBranch("event");
  id->SetAddress(&ev);
  
  TH1F *mult = new TH1F("mult","",20,0,20);
  TH1F *man = new TH1F("man","",20,0,20);

  TH1F *theta = new TH1F("theta","",20,-5,5);
  TH1F *hslope = new TH1F("hslope","",20,-5,5);
  TH1F *mom = new TH1F("mom","",42,-1,20);

  TH1F *allP = new TH1F("allP","",60,-10,20);

  Int_t man_mult=0,man_mult_p=0,man_mult_n=0,man_mult_pPlus=0,
    man_mult_pMinos=0,man_mult_kMinos=0,man_mult_kPlus=0,man_mult_k0=0;

  TCanvas *c = new TCanvas("c","p and slope",1600,2100);
  c->cd();
  c->Divide(2,3);
  int c_entries=0;
  for(Int_t i=0;i<tr->GetEntries();i++)
  // for(Int_t i=0;i<1000;i++)
    {      
      id->GetEntry(i);
      mult->Fill(ev->getEventMultiplicity());
      
      TObjArray *trackList = ev->eventTracks();
      TObjArrayIter next(trackList);
      TObject *object;

      //      Int_t man_mult=0;
      while( (object = next()) )
	{
	  darkSectorTrack *track = (darkSectorTrack *) object;

	  allP->Fill(track->getTrackMomentum());

	  TVector3 tr_vector;
	  tr_vector.SetXYZ(track->getTrackPx(),track->getTrackPy(),track->getTrackPz());

	  if(track->getTrackPt()<1 && track->getTrackPDG()==2212)
	    {
	      man_mult_p++;
	      
	      // theta->Fill(tr_vector.Theta());
	      //mom->Fill(track->getTrackMomentum());
	      
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==2112)
	    {
	      man_mult_n++;
	     
	      //	      theta->Fill(tr_vector.Theta());
	      //	      mom->Fill(track->getTrackMomentum());
	      
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==211)
	    {
	      man_mult_pPlus++;
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==-211)
	    {
	      man_mult_pMinos++;
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==-321)
	    {
	      man_mult_kMinos++;
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==321)
	    {
	      man_mult_kPlus++;
	    }
	  if(track->getTrackPt()<1 && track->getTrackPDG()==130)
	    {
	      man_mult_k0++;
	      theta->Fill(tr_vector.Theta());
	      mom->Fill(track->getTrackMomentum());
	    }
	}
      man->Fill(man_mult);
    }

  cout << "Proton = " << man_mult_p << ", " << (float)man_mult_p/tr->GetEntries()<< endl;
  cout << "Neutron = " << man_mult_n << ", " << (float)man_mult_n/tr->GetEntries()<< endl;
  cout << "pi- = " << man_mult_pMinos <<  ", " << (float)man_mult_pMinos/tr->GetEntries()<< endl;
  cout << "pi+ = " << man_mult_pPlus << ", " << (float)man_mult_pPlus/tr->GetEntries()<< endl;
  cout << "K+ = " << man_mult_kPlus <<  ", " << (float)man_mult_kPlus/tr->GetEntries()<< endl;
  cout << "K0 = " << man_mult_k0 <<  ", " << (float)man_mult_k0/tr->GetEntries()<< endl;
  cout << "K- = " << man_mult_kMinos <<  ", " << (float)man_mult_kMinos/tr->GetEntries()<< endl;
  

  c_entries++;
  c->cd(c_entries);
  allP->Draw();

  c_entries++;
  c->cd(c_entries);
  //  hslope->Draw();

  c_entries++;
  c->cd(c_entries);
  mom->Draw();

  c_entries++;
  c->cd(c_entries);
  theta->Draw();


  //  cout << man_mult << endl;
  //  float aa = man_mult/246000;
  //  cout << aa << endl;
  //  mult->Draw();
  //  man->SetLineColor(kRed);
  //  man->Draw();
}
