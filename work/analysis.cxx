#if !defined(__CINT__)
#include "darkSectorUtilities.h"
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#include "darkSectorVB.h"
#include <vector>
#endif /* !defined(__CINT__) */

void analysis()
{
  TFile *input = new TFile("vb.root");

  //  TFile *input = new TFile("darkSector.root");
  TTree *tr = (TTree *)input->Get("treeVB");

  //  darkSectorEvent *ev = 0;
  darkSectorVB *track = 0;

  TBranch *id = tr->GetBranch("treeVB");
  id->SetAddress(&track);
  
  TH1F *mom = new TH1F("mom","",100,0,15);

  //  for(const darkSectorTrack &ss:darkSectorTrack)

  //  for(Int_t i=0;i<tr->GetEntries();i++)
  for(Int_t i=0;i<10;i++)
    {      
      id->GetEntry(i);
      //      track->Dump();
      cout << track->getTrackPt()<<endl;

      //      darkSectorUtilities ut;
      //      ut.printEventInfo(ev);


      //      TObjArray *trackList = track->vectorBosons();

      //      cout << trackList->GetEntries()<< endl;
      //      TObjArrayIter next(trackList);
      //      TObject *object;

      //      track->Dump();
      //      for(auto const& deneme : TLorentzVector)
      //	cout << "calissss " << endl;
      /*
      while( (object = next()) )
	{TLorentzVector *p = (TLorentzVector *)object;	  
	  
	  cout << "lannn "<<p->E()<<endl;
	  //p->Dump();
	}
      */

      cout << "aaa= " <<track->getInvMassLabFrame() << endl;
      int cnt=0;
      //      darkSectorVB ds;
      std::vector<TLorentzVector> dene;
      dene = track->vectorBosonsVec();
      cout <<dene.size() << endl;
      //      cout << track->vectorBosonsVec()<<endl;
      for(std::vector<TLorentzVector>::iter v = dene.begin(); v != dene.end(); ++v)
	cnt++;
      cout << "count = " << cnt << endl;
    }
  //  mom->Draw();
}
