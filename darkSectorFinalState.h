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
	void setFSP_PX(Float_t PX){m_trPX = PX;}
	void setFSP_PY(Float_t PY){m_trPY = PY;}
	void setFSP_PZ(Float_t PZ){m_trPZ = PZ;}
	void setFSP_X(Float_t X){m_trX = X;}
	void setFSP_Y(Float_t Y){m_trY = Y;}
	void setFSP_Z(Float_t Z){m_trZ = Z;}
	void setFSPDecaySBND(Int_t inter){m_decaySBND=inter;}
	void setFSPDecayUBOONE(Int_t inter){m_decayUBOONE=inter;}
	void setFSPDecayICARUS(Int_t inter){m_decayICARUS=inter;}

	// ### Getters ###
	Float_t getFSPEnergy(){return m_trEnergy;}
	Float_t getFSPInvMass(){return m_trInvMass;}
	Float_t getFSP_PX(){return m_trPX;}
	Float_t getFSP_PY(){return m_trPY;}
	Float_t getFSP_PZ(){return m_trPZ;}
	Float_t getFSP_X(){return m_trX;}
	Float_t getFSP_Y(){return m_trY;}
	Float_t getFSP_Z(){return m_trZ;}
	Int_t getFSPDecaySBND(){return m_decaySBND;}
	Int_t getFSPDecayUBOONE(){return m_decayUBOONE;}
	Int_t getFSPDecayICARUS(){return m_decayICARUS;}

protected:
	Float_t m_trEnergy;
	Float_t m_trInvMass;
	Float_t m_trPX;
	Float_t m_trPY;
	Float_t m_trPZ;
	Float_t m_trX;
	Float_t m_trY;
	Float_t m_trZ;
	Int_t m_decaySBND;
	Int_t m_decayUBOONE;
	Int_t m_decayICARUS;

public:
	ClassDef(darkSectorFinalState,1);	
	



};

#endif
