#include "darkSectorVB.h"
//#include "TObjArray.h"

ClassImp(darkSectorVB)

darkSectorVB::darkSectorVB()
{
  m_vbInvMassLab = 0;
  m_vbInvMassCM = 0;
  //  m_vbTracks= new TObjArray;
  //  m_photonTracks= new TObjArray;

  //  m_vbTracks= new TClonesArray;
  //  m_photonTracks= new TClonesArray;
}

darkSectorVB::darkSectorVB(const darkSectorVB &a)
{
  m_vbInvMassLab = a.m_vbInvMassLab;
  m_vbInvMassCM = a.m_vbInvMassCM;
  //  m_vbTracks= new TObjArray(*(a.m_vbTracks));
  //  m_photonTracks= new TObjArray(*(a.m_photonTracks));

  //  m_vbTracks= new TClonesArray(*(a.m_vbTracks));
  //  m_photonTracks= new TClonesArray(*(a.m_photonTracks));

}

darkSectorVB::~darkSectorVB()
{
  //  delete m_vbTracks;
  //  delete m_photonTracks;
  //  m_vbTracks=0;
  //  m_photonTracks=0;
}
/*
void darkSectorVB::addVB(TLorentzVector *track)
{
  //  m_vbTracks->Add(track);
  m_vbTracks->AddLast(track);
}

void darkSectorVB::addPhoton(TLorentzVector *track)
{
  //  m_photonTracks->Add(track);
  m_photonTracks->AddLast(track);
}
*/
void darkSectorVB::addVBVec(const TLorentzVector track)
{
  m_vbTracks_vec.push_back(track);
}

void darkSectorVB::addPhotonVec(const TLorentzVector track)
{
  m_photonTracks_vec.push_back(track);
}
