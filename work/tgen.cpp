{
  gSystem.Load("libPhysics");
  TLorentzVector target(0.0,0.0,0.0,0.938);
  TLorentzVector beam(0.0,0.0,10.4,10.4);
  TLorentzVector W = beam+target;

  Double_t masses[3]={0.938,0.135,0.135};

  TGenPhaseSpace event;
  event.SetDecay(W,3,masses);

  event.Generate();
  TLorentzVector *pProton = event.GetDecay(0);
  TLorentzVector *pPi0 = event.GetDecay(1);
  TLorentzVector *pPi02 = event.GetDecay(2);
  
  TH1D *h = new TH1D("his","theta",100,0,180);
  h->Fill(pProton->Theta()*57.3);

  /*
  for(Int_t n=0;n<100000;n++)
    {
      event.Generate();
      TLorentzVector *pProton = event.GetDecay(0);
      TLorentzVector *pPi0 = event.GetDecay(1);
      TLorentzVector *pPi02 = event.GetDecay(2);
      h->Fill(pProton->Theta()*57.3);
    }
  */
  h->Draw();
}
