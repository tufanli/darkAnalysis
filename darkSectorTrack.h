#ifndef DARKSECTORTRACK_H
#define DARKSECTORTRACK_H

#include "TObject.h"

//class darkSectorEvent;

class darkSectorTrack : public TObject
{
 public:
	// *** constructors
	darkSectorTrack();
	darkSectorTrack(const darkSectorTrack &a);

	// *** destructor
	virtual ~darkSectorTrack();

	// *** setters
	void setTrackEventId(Long64_t id){m_trEventId=id;}
	void setTrackEventFileId(Long64_t file){m_trEventFileId=file;}
	void setTrackId(Int_t id){m_trId = id;}
	void setTrackPDG(Int_t pdg){m_trPDG = pdg;}
	void setTrackPx(Float_t Px){m_trPx = Px;}
	void setTrackPy(Float_t Py){m_trPy = Py;}
	void setTrackPz(Float_t Pz){m_trPz = Pz;}
	void setTrackPt(Float_t pt){m_trPt = pt;}
	void setTrackMomentum(Float_t momentum){m_trMomentum = momentum;}

	// *** getters
	Long64_t getTrackEventId(){return m_trEventId;}
	Long64_t getTrackEventFileId(){return m_trEventFileId;}
	Int_t getTrackId(){return m_trId;}
	Int_t getTrackPDG(){return m_trPDG;}
	Float_t getTrackPx(){return m_trPx;}
	Float_t getTrackPy(){return m_trPy;}
	Float_t getTrackPz(){return m_trPz;}
	Float_t getTrackPt(){return m_trPt;}
	Float_t getTrackMomentum(){return m_trMomentum;}

 protected:
	Long64_t m_trEventId;
	Long64_t m_trEventFileId;
	Long64_t m_trId;
	Int_t m_trPDG;
	Float_t m_trPx;
	Float_t m_trPy;
	Float_t m_trPz;
	Float_t m_trPt;
	Float_t m_trMomentum;

 public:
	ClassDef(darkSectorTrack,1);
};

#endif
