#include "darkSectorTrack.h"
#include "darkSectorEvent.h"

ClassImp(darkSectorTrack)

darkSectorTrack::darkSectorTrack()
{
  m_trEventId=-9;
  m_trId=-9;
  m_trEventFileId=-9;
  m_trPDG=0;
  m_trPx=0;
  m_trPy=0;
  m_trPz=0;
  m_trPt=0;
  m_trMomentum=0;
}

darkSectorTrack::darkSectorTrack(const darkSectorTrack &a)
{
  m_trEventId=a.m_trEventId;
  m_trId=a.m_trId;
m_trEventFileId=a.m_trEventFileId;
  m_trPDG=a.m_trPDG;
  m_trPx=a.m_trPx;
  m_trPy=a.m_trPy;
  m_trPz=a.m_trPz;
  m_trPt=a.m_trPt;
  m_trMomentum=a.m_trMomentum;

}

darkSectorTrack::~darkSectorTrack()
{

}
