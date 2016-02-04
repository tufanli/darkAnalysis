#ifndef DARKSECTOREVENT_H
#define DARKSECTOREVENT_H

#include "TObject.h"
#include "TObjArray.h"
#include "TList.h"
//#include "TClonesArray.h"

class darkSectorTrack;

class darkSectorEvent : public TObject
{
 public:
	// *** constructors
	darkSectorEvent();
	darkSectorEvent(const darkSectorEvent &a);

	// *** destructor
	virtual ~darkSectorEvent();

	// *** setters
	void setEventId(Long64_t Id){m_evId=Id;}
	void setEventFileNumber(Long64_t number){m_evFileNumber=number;}
	void setEventMultiplicity(Int_t multiplicity){m_evMultiplicity=multiplicity;}

	// *** getters
	Long64_t getEventId(){return m_evId;}
	Long64_t getEventFileNumber(){return m_evFileNumber;}
	Int_t getEventMultiplicity(){return m_evMultiplicity;}

	// *** useful functions
	TObjArray *eventTracks() {return m_evTracks;} // all tracks
	void addTrackToEvent(darkSectorTrack *track);
	darkSectorTrack *getTrack(Int_t i); // track at i

 protected:
	Long64_t m_evId;
	Long64_t m_evFileNumber;
	Int_t m_evMultiplicity;
	TObjArray *m_evTracks;
 public:
	ClassDef(darkSectorEvent,1)
};

#endif
