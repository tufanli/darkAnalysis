#if !defined(__CINT__)
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#endif /* !defined(__CINT__) */

void createRoot()
{
  //  TFile *in = new TFile("../boone1_541.root");
  TFile *in = new TFile("Flux.root");
  TTree *inTree = (TTree *)in->Get("h102");

  const int nbrPi=1000;
  Int_t nmult;
  Int_t id[nbrPi];
  Float_t mom[nbrPi][3];

  inTree->SetBranchAddress("nmult",&nmult);
  inTree->SetBranchAddress("id",&id);
  inTree->SetBranchAddress("mom",&mom);

  // create a root output with all darkSectorEvents
  TFile *output = new TFile("darkSector.root","RECREATE");
  TTree *treeOut = new TTree("tree","darkSectorEvents");

  darkSectorEvent *event = new darkSectorEvent();
  //  treeOut->Branch("noSplit","darkSectorEvent",&event,32000,0);
  treeOut->Branch("split","darkSectorEvent",&event,32000,1);
  //  treeOut->Branch("noSplit",&event,16000,0);
  //  treeOut->Branch("split",&event,16000,1);

  treeOut->SetDirectory(output);
  treeOut->BranchRef();

  for(Int_t i=0;i<inTree->GetEntries();i++)
  //  for(Int_t i=0;i<100000;i++)
    {
      inTree->GetEntry(i);

      event = new darkSectorEvent();
      event->setEventId(i);
      event->setEventMultiplicity(nmult);

      darkSectorTrack *track =0;
      for(Int_t j=0;j<nmult;j++)
	{
	  track = new darkSectorTrack();
	  track->setTrackEventId(i);
	  track->setTrackId(j);
	  track->setTrackPDG(id[j]);
	  track->setTrackPx(mom[j][0]);
	  track->setTrackPy(mom[j][1]);
	  track->setTrackPz(mom[j][2]);

	  Float_t pt = TMath::Sqrt(mom[j][0]*mom[j][0]+mom[j][1]*mom[j][1]);
	  track->setTrackPt(pt);

	  Float_t p = TMath::Sqrt(mom[j][0]*mom[j][0]+mom[j][1]*mom[j][1]+mom[j][2]*mom[j][2]);
	  track->setTrackMomentum(p);
	  event->addTrackToEvent(track);
	  // event->addTrackToList(track);
	}
      treeOut->Fill();
      event->Clear();
    }
  output->Write();
}
