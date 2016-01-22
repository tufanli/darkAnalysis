#include "darkSectorFinalState.h"

ClassImp(darkSectorFinalState)

darkSectorFinalState::darkSectorFinalState()
{
  m_trEnergy = 0;
  m_trInvMass = 0;


}

darkSectorFinalState::darkSectorFinalState(const darkSectorFinalState &a)
{
   m_trEnergy = a.m_trEnergy;
   m_trInvMass = a.m_trInvMass;


}


darkSectorFinalState::~darkSectorFinalState()
{

}
