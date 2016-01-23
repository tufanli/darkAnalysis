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
	Long64_t setTrackEventId(Long64_t id){m_trEventId=id;}
	Long64_t setTrackEventFileId(Long64_t file){m_trEventFileId=file;}
	Int_t setTrackId(Int_t id){m_trId = id;}
	Int_t setTrackPDG(Int_t pdg){m_trPDG = pdg;}
	Float_t setTrackPx(Float_t Px){m_trPx = Px;}
	Float_t setTrackPy(Float_t Py){m_trPy = Py;}
	Float_t setTrackPz(Float_t Pz){m_trPz = Pz;}
	Float_t setTrackPt(Float_t pt){m_trPt = pt;}
	Float_t setTrackMomentum(Float_t momentum){m_trMomentum = momentum;}

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
