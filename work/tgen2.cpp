{
  gSystem.Load("libPhysics");
  TLorentzVector lab(0.17,0.32,4.84,4.938);
  TLorentzVector zero(0.0,0.0,0.0,0.0);

  cout << "LAB = "<< lab[0]<< ", "<< lab[1]<< ", " << lab[2]<< ", " << lab[3]
       << ", rho = " << lab.Rho()<< ", theta = "<< lab.Theta()
       << ", phi = "<< lab.Phi()<< endl;

  TLorentzVector W = lab+zero;
  lab.Boost(-W.BoostVector());

  cout << "CM = "<< lab[0]<< ", "<< lab[1]<< ", " << lab[2]<< ", " << lab[3]
       << ", rho = " << lab.Rho()<< ", theta = "<< lab.Theta()
       << ", phi = "<< lab.Phi()
       << endl;

  /*

  Double_t masses[3]={0.938,0.135,0.135};

  TGenPhaseSpace event;
  event.SetDecay(W,3,masses);

  event.Generate();
  TLorentzVector *pProton = event.GetDecay(0);
  TLorentzVector *pPi0 = event.GetDecay(1);
  TLorentzVector *pPi02 = event.GetDecay(2);
  
  TH1D *h = new TH1D("his","theta",100,0,180);
  h->Fill(pProton->Theta()*57.3);

  
  for(Int_t n=0;n<100000;n++)
    {
      event.Generate();
      TLorentzVector *pProton = event.GetDecay(0);
      TLorentzVector *pPi0 = event.GetDecay(1);
      TLorentzVector *pPi02 = event.GetDecay(2);
      h->Fill(pProton->Theta()*57.3);
    }
  */
  //  h->Draw();
}
