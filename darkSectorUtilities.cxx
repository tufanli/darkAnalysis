#include "darkSectorUtilities.h"
#include "darkSectorTrack.h"
#include "darkSectorEvent.h"
#include "darkSectorMeson.h"
#include "darkSectorVB.h"
#include "darkSectorFinalState.h"

#include "TMath.h"
#include "TSystemDirectory.h"
#include "TList.h"
#include "TSystemFile.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TGenPhaseSpace.h"

#include <iostream>
using std::cout;
using std::endl;

ClassImp(darkSectorUtilities)

Int_t createIdFromFileName(const TString &fname);

darkSectorUtilities::darkSectorUtilities()
{

}

darkSectorUtilities::darkSectorUtilities(const darkSectorUtilities &util)
{

}

darkSectorUtilities::~darkSectorUtilities()
{

}

TFile *darkSectorUtilities::createSingleFluxFile(const char *inputRootFileName, const char *treeName, const char *outputRootFileName)
{
  //  std::cout << __PRETTY_FUNCTION__ << std::endl;
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  TTree *treeOut = new TTree("tree","darkSectorEvents");

  darkSectorEvent *event=0;
  treeOut->Branch("event","darkSectorEvent",&event,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();

  TFile *in = new TFile(inputRootFileName);
  //  if(treeName!="h102"){std::cerr<< "wrong tree name to create flux file !!!" << std::endl; in=NULL; return in;}
  TTree *t = (TTree *)in->Get(treeName);

  const int nbrPi=1000;
  Int_t nmult;
  Int_t id[nbrPi];
  Float_t mom[nbrPi][3];

  t->SetBranchAddress("nmult",&nmult);
  t->SetBranchAddress("id",&id);
  t->SetBranchAddress("mom",&mom);

  std::cout << t->GetEntries()<< std::endl;

  for(Long64_t i=0;i<t->GetEntries();i++)
    {
      t->GetEntry(i);

      event = new darkSectorEvent();
      Long64_t idFile = createIdFromFileName(inputRootFileName);
      Long64_t number = idFile+i+1;
      std::cout << idFile << ", " << number << std::endl;
      event->setEventId(number);
      event->setEventFileNumber(idFile);
      event->setEventMultiplicity(nmult);
      //      event->setPOT(1000);

      darkSectorTrack *track =0;
      for(Int_t j=0;j<nmult;j++)
	{
	  track = new darkSectorTrack();
	  track->setTrackEventId(number);
	  track->setTrackEventFileId(idFile);
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
	  track=0;
	  delete track;
	}
      treeOut->Fill();
      event->Clear();
      delete event;
    }
  output->cd();
  output->Write();
  output->Close();
}

TFile *darkSectorUtilities::createFluxFile(const char *dirName, 
					   const char *ext, 
					   const char *treeName, 
					   const char *outputRootFileName)
{
  // *** this function loops over boone*.root files, 
  // *** converts all events to darkEvent format including darkTracks. 
  // *** During the conversion, it assigns a unique Id for each event depending the file name
  // *** for example event 235 in boone1_541 gets the id 105410235
  // *** if you run the function on a root file having the same structure with boone*.root it works except 
  // *** assigning the id (fileId =0, eventId= increment in the loop ...)
  TSystemDirectory dir(dirName, dirName);
  TList *files = dir.GetListOfFiles();
  if (files)
    {
      TSystemFile *file;
      TString fname;
      TIter next(files);

      TFile *output = new TFile(outputRootFileName,"RECREATE");
      TTree *treeOut = new TTree("tree","darkSectorEvents");
      darkSectorEvent *event=0;
      float pot=0,potInteract=0;
      treeOut->Branch("event","darkSectorEvent",&event,32000,2);

      TTree *treePOT = new TTree("POT","POT");
      treePOT->Branch("POT",&pot);
      treePOT->Branch("POT_int",&potInteract);

      treeOut->SetDirectory(output);
      treeOut->BranchRef();
      
      while ((file=(TSystemFile*)next())) 
	{
	  fname = file->GetName();
	  std::cout << fname<< std::endl;
	  if (!file->IsDirectory() && fname.Contains(ext)&&fname.Contains(".root")) 
	    {	      
	      pot+=1000;

	      TString dene;
	      const char *rootFile = fname;

	      dene.Form("%s/%s",dirName,rootFile);

	      std::cout << "deneme = " << dene << std::endl;
	      TFile *in = new TFile(dene);
	      //if(treeName!="h102"){std::cerr<< "wrong tree name to create flux file !!!" << std::endl; continue;}
	      TTree *t = (TTree *)in->Get(treeName);
	      
	      const int nbrPi=1000;
	      Int_t nmult;
	      Int_t id[nbrPi];
	      Float_t mom[nbrPi][3];
	      
	      t->SetBranchAddress("nmult",&nmult);
	      t->SetBranchAddress("id",&id);
	      t->SetBranchAddress("mom",&mom);

	      potInteract+=t->GetEntries();

	      for(Long64_t i=0;i<t->GetEntries();i++)
		//	      for(Long64_t i=0;i<100000;i++)
		{
		  t->GetEntry(i);
		  
		  event = new darkSectorEvent();
		  Int_t idFile = createIdFromFileName(fname);
		  Int_t number = idFile+i+1;

		  std::cout << idFile << ", " << number << std::endl;
		  event->setEventId(number);
		  event->setEventFileNumber(idFile);
		  event->setEventMultiplicity(nmult);
		  //		  event->setPOT(1000);

		  darkSectorTrack *track =0;
		  for(Int_t j=0;j<nmult;j++)
		    {
		      track = new darkSectorTrack();
		      track->setTrackEventId(number);
		      track->setTrackEventFileId(idFile);
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
		      track =0;
		      delete track;
		    }// tracks
		  treeOut->Fill();
		  event->Clear();
		  delete event;
		} // event
	      delete in;
	      //	      delete t; // calismiyo
	    } // if root file
	}// while
      treePOT->Fill();
      output->cd();
      //      treeOut->Write(TObject::kWriteDelete);
      treeOut->Write();
      treePOT->Write();
      output->Close();
    }// if file
}

TFile *darkSectorUtilities::createSinglePiFluxFile(const char *inputRootFileName, 
						   const char *treeName, 
						   const char *outputRootFileName,
						   Int_t pdg)
{
  TFile *input = new TFile(inputRootFileName);
  TTree *tr = (TTree *)input->Get(treeName);

  darkSectorEvent *ev=0;
  darkSectorTrack *darkTrack=0;

  TBranch *id = tr->GetBranch("event");
  id->SetAddress(&ev);
  
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  
  const char *isim;
  if(pdg == 211)
    isim="piPlus";
  if(pdg == -211)
    isim="piMinus";

  TTree *treeOut = new TTree(isim,"darkSectorPion");
  treeOut->Branch(isim,"darkSectorTrack",&darkTrack,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();
  
  for(Int_t i=0;i<tr->GetEntries();i++)
    {      
      id->GetEntry(i);
      //      darkTrack=0;
      TObjArray *trackList = 0;
      trackList = ev->eventTracks();
      TIter nextTrack(trackList);

      //darkSectorTrack *darkTrack=0;
      while( (darkTrack = (darkSectorTrack*) nextTrack()) )
	{
	  if(darkTrack->getTrackPDG()==pdg)    
	    treeOut->Fill();
	  delete darkTrack;
	}
    }
  output->cd();
  output->Write();
  output->Close();
}

TFile *darkSectorUtilities::createPi0File(const char *inputRootFileName, 
					  const char *treeName, 
					  const char *outputRootFileName)
{
  TFile *input = new TFile(inputRootFileName);
  TTree *tr = (TTree *)input->Get(treeName);
  
  darkSectorEvent *ev=0;
  darkSectorTrack *darkTrack=0;
  
  TBranch *id = tr->GetBranch("event");
  id->SetAddress(&ev);
  
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  TTree *treeOut = new TTree("treePi0","darkSectorPion0");
  treeOut->Branch("treePi0","darkSectorTrack",&darkTrack,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();

  Int_t countPiMinus=0,countPiPlus=0; // more events in this case  
  for(Long64_t i=0;i<tr->GetEntries();i++)
    {      
      id->GetEntry(i);
      TObjArray *trackList = 0;
      trackList = ev->eventTracks();
      TIter nextTrack(trackList);

      while( (darkTrack = (darkSectorTrack*) nextTrack()) )
	{
	  if(darkTrack->getTrackPDG()== 211)    
	    { countPiPlus++; if(countPiPlus % 2 == 0)treeOut->Fill(); delete darkTrack;}

	  if(darkTrack->getTrackPDG()== -211)    
	    { countPiMinus++; if(countPiMinus % 2 == 0)treeOut->Fill();delete darkTrack;}
	}
    }
  output->cd();
  output->Write();
  output->Close();
}

void darkSectorUtilities::printEventInfo(darkSectorEvent *ev)
{
  ev->Dump();
}

void darkSectorUtilities::printTrackInfo(darkSectorTrack *tr)
{
  tr->Dump();
}

TFile *darkSectorUtilities::createMesonFile(const char *inputRootFileName, 
					    const char *treeName, 
					    const char *outputRootFileName)
{
  TFile *input = new TFile(inputRootFileName);
  TTree *tr = (TTree *)input->Get(treeName);
 
  darkSectorTrack *pi0=0;
  darkSectorMeson *meson=0;  

  TBranch *id = tr->GetBranch("treePi0");
  id->SetAddress(&pi0);
  
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  TTree *treeOut = new TTree("treeMeson","darkSectorMeson");
  treeOut->Branch("treeMeson","darkSectorMeson",&meson,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();

  Float_t fakeMass[5] = {0.54785,0.77526,0.78265,0.95778,1.019461};

  for(Long64_t i=0;i<tr->GetEntries();i++)
    //  for(Int_t i=0;i<20;i++)
    {      
      id->GetEntry(i);

      // ### Looping over all the "fake" particles we are trying to create
      for(const auto& fM : fakeMass)
	{
	  meson = new darkSectorMeson();
	  // ### Grabbing the Pi0 3-momentum ###
	  Float_t pi0Momentum = pi0->getTrackMomentum();
      
	  // ### Calculating the Pi0 (inferred) energy ###
	  Float_t iE = TMath::Sqrt(0.139*0.139+pi0Momentum*pi0Momentum);

	  //	  if((iE*iE)>(fM*fM)) ???
	  if(iE>fM)

	    {
	      meson->setMesonMass(fM);
	      // ### The new 3-momentum of the meson is sqrt(E^2 - m^2)
	      Float_t fakePnew = TMath::Sqrt((iE*iE)-(fM*fM)); // meson 3-momentum
	      meson->setTrackMomentum(fakePnew);

	      // ### The new energy given the new momentum sqrt (P^2 - m^2), why do we need this, it is iE??
	      /*
		Float_t fakeE = TMath::Sqrt( (fakePnew*fakePnew) + (fM*fM) ); // meson energy
		meson->setMesonEnergy(fakeE);
		std::cout << iE << ", fake E = " << fakeE << std::endl;
	      */
	      meson->setMesonEnergy(iE);

	      // ### Assigning meson component momentum (e.g. px, py, pz)  ###
	      // ### in a similar ratio as original pi0 component momentum ###
	      Float_t fakePx = (fakePnew*pi0->getTrackPx())/pi0Momentum; 
	      Float_t fakePy = (fakePnew*pi0->getTrackPy())/pi0Momentum;
	      Float_t fakePz = (fakePnew*pi0->getTrackPz())/pi0Momentum;
	      Float_t fakePt = TMath::Sqrt(fakePx*fakePx + fakePy*fakePy);

	      meson->setTrackPx(fakePx); 
	      meson->setTrackPy(fakePy);
	      meson->setTrackPz(fakePz);
	      meson->setTrackPt(fakePt);

	      Int_t id; // meson pdg id
	      if (fM == fakeMass[0]){ id = 221; } //<---Eta
	      if (fM == fakeMass[1]){ id = 223; } //<---Omega
	      if (fM == fakeMass[2]){ id = 113; } //<---Rho
	      if (fM == fakeMass[3]){ id = 331; } //<---Eta-prime
	      if (fM == fakeMass[4]){ id = 333; } //<---phi
	      meson->setTrackPDG(id);

	      // ### Defining temp invariant mass ### --> It is fM actually
	      /*
		Float_t tempInvMass = sqrt( (fakeE*fakeE) - (fakePnew*fakePnew) );
		meson->setMesonInvMass(tempInvMass);
		std::cout << fM << ", inv mass = " << tempInvMass << std::endl;
	      */
	      meson->setMesonInvMass(fM);

	      meson->setTrackEventId(pi0->getTrackEventId());
	      meson->setTrackEventFileId(pi0->getTrackEventFileId());
	      meson->setTrackId(pi0->getTrackId());
	      treeOut->Fill(); // only if meson is created !!, ignore the others...
	    }
	  delete meson;
	}
    }
  output->cd();
  output->Write();
  output->Close();
}

darkSectorMeson *darkSectorUtilities::generateMeson(darkSectorTrack *track)
{
  //  std::cout << __PRETTY_FUNCTION__ << std::endl;
  darkSectorMeson *me= new darkSectorMeson();

  Float_t fakeMass[5] = {0.54785,0.77526,0.78265,0.95778,1.019461};

  // ### Looping over all the "fake" particles we are trying to create
  for(const auto& fM : fakeMass)
    {
      // ### Grabbing the Pi0 3-momentum ###
      float pi0Momentum = track->getTrackMomentum();
      
      // ### Calculating the Pi0 (inferred) energy ###
      float iE = TMath::Sqrt(0.139*0.139+pi0Momentum*pi0Momentum);

      me->setMesonMass(fM);
      me->setTrackEventId(track->getTrackEventId());
      me->setTrackEventFileId(track->getTrackEventFileId());
      me->setTrackId(track->getTrackId());
      
      if((iE*iE)>(fM*fM))
	{
	  // ### The new 3-momentum of the meson is sqrt(E^2 - m^2)
	  Float_t fakePnew = TMath::Sqrt((iE*iE)-(fM*fM)); // meson 3-momentum
	  me->setTrackMomentum(fakePnew);
	  me->setMesonEnergy(iE);
	  me->setMesonInvMass(fM);

	  // ### Assigning meson component momentum (e.g. px, py, pz)  ###
	  // ### in a similar ratio as original pi0 component momentum ###
	  Float_t fakePx = (fakePnew*track->getTrackPx())/pi0Momentum; 
	  Float_t fakePy = (fakePnew*track->getTrackPy())/pi0Momentum;
	  Float_t fakePz = (fakePnew*track->getTrackPz())/pi0Momentum;
	  Float_t fakePt = TMath::Sqrt(fakePx*fakePx + fakePy*fakePy);

	  me->setTrackPx(fakePx); 
	  me->setTrackPy(fakePy);
	  me->setTrackPz(fakePz);
	  me->setTrackPt(fakePt);

	  Int_t id; // meson pdg id
	  if (fM == fakeMass[0]){ id = 221; } //<---Eta
	  if (fM == fakeMass[1]){ id = 223; } //<---Omega
	  if (fM == fakeMass[2]){ id = 113; } //<---Rho
	  if (fM == fakeMass[3]){ id = 331; } //<---Eta-prime
	  if (fM == fakeMass[4]){ id = 333; } //<---phi
	  me->setTrackPDG(id);
	}
      else
	{
	  me->setTrackMomentum(0);
	  me->setMesonEnergy(0);
	  me->setTrackPx(0); 
	  me->setTrackPy(0);
	  me->setTrackPz(0);
	  me->setTrackPt(0);
	  me->setTrackPDG(0);
	  me->setMesonInvMass(0);
	}
    }
  return me; // returns also the cases where energy is not enough to create meson, which in that case everything is set to 0.
}

TFile *darkSectorUtilities::createVBFile(const char *inputRootFileName, 
					 const char *treeName, 
					 const char *outputRootFileName)
{
  // *** sonucta cikan VB ve photon un lab frame deki bilgileri lazim bize
  // *** TLorantzVector yeterli --> px,py,pz,E ve mass lazim
  // *** ek olarak mass ve invmass da ekle

  TFile *input = new TFile(inputRootFileName);
  TTree *tr = (TTree *)input->Get(treeName);
  
  darkSectorMeson *meson=0;  
  darkSectorVB *vb=0;

  TBranch *id = tr->GetBranch("treeMeson");
  id->SetAddress(&meson);
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  TTree *treeOut = new TTree("treeVB","darkSectorVB");
  treeOut->Branch("treeVB","darkSectorVB",&vb,32000,1);
  //  treeOut->Branch("treeVB","darkSectorVB",&vb,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();

  //  for(size_t i=0;i<tr->GetEntries();i++) // *** meson track loop
  for(size_t i=0;i<300;i++)
    {           
      id->GetEntry(i);
      //      if(i%10000 == 0) cout<< i<< endl;

      TLorentzVector mesonLabFrame,mesonLabFrameToBoost; // initialized by (0., 0., 0., 0.)
      mesonLabFrameToBoost.SetPxPyPzE(meson->getTrackPx(),meson->getTrackPy(),meson->getTrackPz(),meson->getMesonEnergy());
      mesonLabFrame = mesonLabFrameToBoost;
     
      // ### Saving the invariant mass in the lab frame ###      
      Double_t mlfinv = mesonLabFrame.Mag();

      TLorentzVector zero; 
      zero.SetPxPyPzE(0,0,0,0);

      TVector3 boost = (mesonLabFrameToBoost+zero).BoostVector();
      mesonLabFrameToBoost.Boost(-boost);

      // ### Defining the meson center-of-mass frame ###
      TLorentzVector mesonCenterOfMass;
     
      // ### Setting the Center-of-Mass variables ###
      mesonCenterOfMass.SetPxPyPzE(mesonLabFrameToBoost.Px(),
				   mesonLabFrameToBoost.Py(),
				   mesonLabFrameToBoost.Pz(),
				   mesonLabFrameToBoost.E());

      Double_t mrfinv = mesonCenterOfMass.Mag(); // meson rest frame invariant mesonMass

      vb=new darkSectorVB();        
      vb->setTrackEventId(meson->getTrackEventId());
      vb->setTrackEventFileId(meson->getTrackEventFileId());
      vb->setTrackId(meson->getTrackId());
      vb->setTrackPDG(meson->getTrackPDG());
      vb->setTrackPx(meson->getTrackPx());
      vb->setTrackPy(meson->getTrackPy());
      vb->setTrackPz(meson->getTrackPz());
      vb->setTrackMomentum(meson->getTrackMomentum());
      vb->setInvMassLabFrame(mlfinv);
      vb->setInvMassCenterOfMass(mrfinv);
          
      int count=0;  
      //      TObjArray *dene = new TObjArray;
      for(float m = 0.140; m<0.630; m+=0.010) // vector boson masses
	{	      
	  // *** decay generator
	  TGenPhaseSpace mesonDecay;

	  if(meson->getMesonMass()>m)
	    {
	      Double_t masses[2] = {m,0.0}; // meson decays to vector boson with mass m and photon

	      // *** eta and eta-prime --> decay in flight
	      if (meson->getTrackPDG() == 221 || meson->getTrackPDG() == 331)
		{
		  //	  TGenPhaseSpace mesonDecay;

		  mesonDecay.SetDecay(mesonLabFrame,2,masses);
		  // ??? gRandom = new TRandom3(0);// gerekiyo mu
		  mesonDecay.Generate(); // !!!! generate 1 random possible final state
		  TLorentzVector *vectorBoson= mesonDecay.GetDecay(0);	  // vb
		  TLorentzVector *initialPhoton = mesonDecay.GetDecay(1); // photon
		  //	  dene->Add(vectorBoson);
		  //		  cout << "dene size= " << dene->GetEntries()<< endl;
		  count++;

		  cout << "vector boson dumpppp " << endl;
		  //vectorBoson->Dump();
		  // initialPhoton->Dump();

		  //		  vb->setEnergy(vectorBoson->E()); // buraya eklenip burda fill edilirse her vb track in bilgileri direk alinabilir ama zaten TLorentz den de cekilebilir

		  //		  vb->addVB(vectorBoson);
		  //		  vb->addPhoton(initialPhoton);

		  vb->addVBVec(*vectorBoson);
		  vb->addPhotonVec(*initialPhoton);
		  
		  vectorBoson=0;
		  initialPhoton=0;
		  delete vectorBoson;
		  delete initialPhoton;
		}
	      else
		{
		  //		  TGenPhaseSpace mesonDecay;
		  mesonDecay.SetDecay(mesonCenterOfMass,2,masses);
		  // ??? gRandom = new TRandom3(0);// gerekiyo mu
		  mesonDecay.Generate(); // !!!! generate 1 random possible final state
		  
		  TLorentzVector *vectorBoson= mesonDecay.GetDecay(0);	  
		  TLorentzVector *initialPhoton = mesonDecay.GetDecay(1);
		  //		  vb->setEnergy(vectorBoson->E());

		  //		  vb->addVB(vectorBoson);
		  //		  vb->addPhoton(initialPhoton);
		  
		  vb->addVBVec(*vectorBoson);
		  vb->addPhotonVec(*initialPhoton);

		  vectorBoson=0;
		  initialPhoton=0;
		  delete vectorBoson;
		  delete initialPhoton;		 
		}
	    } // *** if meson mass > ..
	}// *** for m
      cout << "count = " << count  << endl;
      treeOut->Fill();
      delete vb;
    }
  output->cd();
  output->Write();
  output->Close();
}

TFile *darkSectorUtilities::createDecayFile(const char *inputRootFileName, 
					    const char *treeName, 
					    const char *outputRootFileName)
{
  
  
  // ### Grabbing the input ROOT file of VB's ###
  TFile *input = new TFile(inputRootFileName);
  TTree *tr = (TTree *)input->Get(treeName);
  
  // ### Defining pointer to particles ###
  // darkSectorMeson *meson=0;  
  darkSectorVB *vb=0;
  
  
  // ### Doing this a dumb way for now.....####
  // ### need to write a function that does this cleaner ###
  darkSectorFinalState *fs=0;
  
  
  // ### Grabbing the branch which holds the VB's
  TBranch *id = tr->GetBranch("treeVB");
  id->SetAddress(&vb);
  
  // ### Creating the output file which will contain the ###
  // ###     decay products of the vector bosons         ###
  TFile *output = new TFile(outputRootFileName,"RECREATE");
  TTree *treeOut = new TTree("treeVBDecay","darkSectorVBDecay");
  
  treeOut->Branch("treeVBDecay","darkSectorFinalState",&fs,32000,1);
  treeOut->SetDirectory(output);
  treeOut->BranchRef();
  
  TLorentzVector TempPi0, TempPhoton0, TempPhoton1, TempPhoton2;
  TLorentzVector Temp;
  // ###################################
  // ### Looping over all the events ###
  // ###################################
  //  for(Long64_t i=0;i<tr->GetEntries();i++) // *** meson track loop
  for(Int_t i=0;i<20;i++)
    {      
      // ### Retreive this particular entry ###
      id->GetEntry(i);
      
      std::vector<TLorentzVector> vbTemp = vb->vectorBosonsVec();
      
      for (size_t a = 0; a < vbTemp.size(); a++)
      	{
	std::cout<<"Px = "<<vbTemp[a].Px()<<std::endl;
	// ### Filling a temporary Lorentz Vector ###
        Temp.SetPxPyPzE(vbTemp[a].Px(), vbTemp[a].Py(), vbTemp[a].Pz(), vbTemp[a].E() );
	
	// ### Getting ready to decay the VB ###
        TGenPhaseSpace event_decay;
        // ### Setting the daughters of the vector boson mass ###
        // ###     e.g. pi0 = 135 MeV and photon = 0 MeV      ###
        double daughter_mass[2] = {0.139, 0.0};
	
	event_decay.SetDecay(Temp, 2, daughter_mass);
        // ### Perform the decay ###
        event_decay.Generate();
	
	// ### Grab the information about the particles from the decay ###
        TLorentzVector *pizero = event_decay.GetDecay(0);
        TLorentzVector *photon0 =  event_decay.GetDecay(1);
	
	// ### Making a pointer from the decay to my Temp TLorentz Vector for Pi0's ###
        TempPi0 = *pizero;
        // ### Making a pointer from the decay to my Temp TLorentz Vector for Photon0 ###
        TempPhoton0 = *photon0;
      
        // ### Now we want to decay the Pi0 -> gamma, gamma and store the photons ###
        TGenPhaseSpace event_pi0Daugther;
        double pi0Daughter_mass[2] = {0.0, 0.0};
      
        event_pi0Daugther.SetDecay(TempPi0, 2, pi0Daughter_mass);
        // ### Perform the decay ###
        event_pi0Daugther.Generate();
	
	// ### Grab the information about the particles from the decay ###
	TLorentzVector *photon1 = event_pi0Daugther.GetDecay(0);
        TLorentzVector *photon2 = event_pi0Daugther.GetDecay(1);
	
	// ### Making a pointer from the decay to my Temp TLorentz Vector for Photon1 ###
	TempPhoton1 = *photon1;
	TempPhoton2 = *photon2;
	 
	
	// ### Adding things by brute force for now...going to clean up....####
	fs=new darkSectorFinalState();  
	
	      
        fs->setTrackEventId(vb->getTrackEventId());
        fs->setTrackEventFileId(vb->getTrackEventFileId());
        fs->setTrackId(10001000+a);
        fs->setTrackPDG(22);
        fs->setTrackPx(photon0->Px());
        fs->setTrackPy(photon0->Py());
        fs->setTrackPz(photon0->Pz());
        fs->setFSPEnergy(photon0->E());
        fs->setFSPInvMass(0);
	
	treeOut->Fill();
	
	fs=new darkSectorFinalState();
	fs->setTrackEventId(vb->getTrackEventId());
        fs->setTrackEventFileId(vb->getTrackEventFileId());
        fs->setTrackId(10002000+a);
        fs->setTrackPDG(22);
        fs->setTrackPx(photon1->Px());
        fs->setTrackPy(photon1->Py());
        fs->setTrackPz(photon1->Pz());
        fs->setFSPEnergy(photon1->E());
        fs->setFSPInvMass(0);
	
	treeOut->Fill();
	
	fs=new darkSectorFinalState();
	fs->setTrackEventId(vb->getTrackEventId());
        fs->setTrackEventFileId(vb->getTrackEventFileId());
        fs->setTrackId(10003000+a);
        fs->setTrackPDG(22);
        fs->setTrackPx(photon2->Px());
        fs->setTrackPy(photon2->Py());
        fs->setTrackPz(photon2->Pz());
        fs->setFSPEnergy(photon2->E());
        fs->setFSPInvMass(0);
	
	treeOut->Fill();
	
	}//<---End loop over vector of VB's
      
      
      
      //vb->Dump();
    }///<---End event loop
    
    
output->cd();
  output->Write();
  output->Close();
}


Int_t createIdFromFileName(const TString &fname)
{
  TString dummy;
  dummy = fname;
  dummy.ReplaceAll("boone","");
  dummy.ReplaceAll("_","0");
  dummy.ReplaceAll(".root","0000");

  return dummy.Atoll();
}
