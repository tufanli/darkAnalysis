#ifndef DARKSECTORDECAYPROBABILITY_CXX
#define DARKSECTORDECAYPROBABILITY_CXX

#include "darkSectorDecayProbability.h"

ClassImp(darkSectorDecayProbability)

darkSectorDecayProbability::darkSectorDecayProbability()
{
  m_trDecProb = 0;
}

darkSectorDecayProbability::darkSectorDecayProbability(const darkSectorDecayProbability &a)
{
  m_trDecProb = a.m_trDecProb;
}

darkSectorDecayProbability::~darkSectorDecayProbability()
{}
#endif
