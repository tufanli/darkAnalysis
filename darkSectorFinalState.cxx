#include "darkSectorFinalState.h"

ClassImp(darkSectorFinalState)

darkSectorFinalState::darkSectorFinalState()
{
  m_trEnergy = 0;
  m_trInvMass = 0;
  m_trPX = 0;
  m_trPY = 0;
  m_trPZ = 0;
  m_trX = 0;
  m_trY = 0;
  m_trZ = 0;
  m_decaySBND = 0;
  m_decayUBOONE = 0;
  m_decayICARUS = 0;
}

darkSectorFinalState::darkSectorFinalState(const darkSectorFinalState &a)
{
   m_trEnergy = a.m_trEnergy;
   m_trInvMass = a.m_trInvMass;
   m_trPX = a.m_trPX;
   m_trPY = a.m_trPY;
   m_trPZ = a.m_trPZ;
   m_trX = a.m_trX;
   m_trY = a.m_trY;
   m_trZ = a.m_trZ;
   m_decaySBND = a.m_decaySBND;
   m_decayUBOONE = a.m_decayUBOONE;
   m_decayICARUS = a.m_decayICARUS;
}


darkSectorFinalState::~darkSectorFinalState()
{

}
