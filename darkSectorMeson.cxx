#include "darkSectorMeson.h"

ClassImp(darkSectorMeson)

darkSectorMeson::darkSectorMeson()
{
  m_trEnergy = 0;
  m_trMass = 0;
  m_trInvMass = 0;
}

darkSectorMeson::darkSectorMeson(const darkSectorMeson &a)
{
  m_trEnergy = a.m_trEnergy;
  m_trMass = a.m_trMass;
  m_trInvMass = a.m_trInvMass;
}

darkSectorMeson::~darkSectorMeson()
{

}
