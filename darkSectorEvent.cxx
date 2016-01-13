#include "darkSectorEvent.h"
#include "darkSectorTrack.h"

ClassImp(darkSectorEvent)

darkSectorEvent::darkSectorEvent()
{
  m_evId=0;
  m_evFileNumber=0;
  m_evMultiplicity=0;
  m_evTracks = new TObjArray;
}

darkSectorEvent::darkSectorEvent(const darkSectorEvent &a)
{
  m_evId=a.m_evId;
  m_evFileNumber=a.m_evFileNumber;
  m_evMultiplicity=a.m_evMultiplicity;
  m_evTracks = new TObjArray(*(a.m_evTracks));
}

darkSectorEvent::~darkSectorEvent()
{
  delete m_evTracks;
  m_evTracks=0;
}

void darkSectorEvent::addTrackToEvent(darkSectorTrack *track)
{
  m_evTracks->Add(track);
}

//void darkSectorEvent::addTrackToList(darkSectorTrack *track)
//{
//m_evListTracks->Add(track);
//return m_evListTracks;
//}

darkSectorTrack* darkSectorEvent::getTrack(Int_t i)
{
  return dynamic_cast <darkSectorTrack*>(m_evTracks->At(i));
}

