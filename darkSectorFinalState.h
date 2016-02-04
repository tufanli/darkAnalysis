#ifndef DARKSECTORFINALSTATE_H
#define DARKSECTORFINALSTATE_H

#include "darkSectorTrack.h"


class darkSectorFinalState : public darkSectorTrack
{
public:
	// ### Constructors ###
	darkSectorFinalState(const darkSectorFinalState &a);
	darkSectorFinalState();
	
	// ### Destructor ###
	virtual ~darkSectorFinalState();
	
	// ### Setters ###
	void setFSPEnergy(Float_t en){m_trEnergy = en;}
	void setFSPInvMass(Float_t massIn){m_trInvMass = massIn;}
	
	// ### Getters ###
	Float_t getFSPEnergy(){return m_trEnergy;}
	Float_t getFSPInvMass(){return m_trInvMass;}
	
protected:
	Float_t m_trEnergy;
	Float_t m_trInvMass;

public:
	ClassDef(darkSectorFinalState,1);	
	



};

#endif
