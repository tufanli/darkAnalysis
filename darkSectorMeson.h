#ifndef DARKSECTORMESON_H
#define DARKSECTORMESON_H

//#include "TObject.h"
#include "darkSectorTrack.h"

//class darkSectorEvent;

class darkSectorMeson : public darkSectorTrack
{
 public:
	// *** constructors
	darkSectorMeson();
	darkSectorMeson(const darkSectorMeson &a);

	// *** destructor
	virtual ~darkSectorMeson();

	// *** setters
	Float_t setMesonEnergy(Float_t en){m_trEnergy = en;}
	Float_t setMesonMass(Float_t mass){m_trMass = mass;}
	Float_t setMesonInvMass(Float_t massIn){m_trInvMass = massIn;}

	// *** getters
	Float_t getMesonEnergy(){return m_trEnergy;}
	Float_t getMesonMass(){return m_trMass;}
	Float_t getMesonInvMass(){return m_trInvMass;}

 protected:
	Float_t m_trEnergy;
	Float_t m_trMass;
	Float_t m_trInvMass;
 public:
	ClassDef(darkSectorMeson,1);
};

#endif
