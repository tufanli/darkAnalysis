#include "darkSectorVB.h"
//#include "TObjArray.h"

ClassImp(darkSectorVB)

darkSectorVB::darkSectorVB()
{
  m_vbMass = 0;
  m_vbInvMass = 0;
  m_vbInterceptSBND=0;
  m_vbInterceptUBOONE=0;
  m_vbInterceptICARUS=0;
}

darkSectorVB::darkSectorVB(const darkSectorVB &a)
{
  m_vbMass = a.m_vbMass;
  m_vbInvMass = a.m_vbInvMass;
  m_vbInterceptSBND=a.m_vbInterceptSBND;
  m_vbInterceptUBOONE=a.m_vbInterceptUBOONE;
  m_vbInterceptICARUS=a.m_vbInterceptICARUS;
}

darkSectorVB::~darkSectorVB()
{

}
void darkSectorVB::addVBVec(const TLorentzVector track)
{
  m_vbTracks_vec.push_back(track);
}

void darkSectorVB::addPhotonVec(const TLorentzVector track)
{
  m_photonTracks_vec.push_back(track);
}
