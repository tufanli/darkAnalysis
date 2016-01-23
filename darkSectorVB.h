#ifndef DARKSECTORVB_H
#define DARKSECTORVB_H

#include "darkSectorTrack.h"

#include "TObjArray.h"
#include "TClonesArray.h"
#include "TLorentzVector.h"

#include <vector>

class darkSectorVB : public darkSectorTrack
{
 public:
  // *** constructors
  darkSectorVB();
  darkSectorVB(const darkSectorVB &a);
  
  // *** destructor
  virtual ~darkSectorVB();
  
  // *** setters
  Float_t setInvMassLabFrame(Float_t invmass){m_vbInvMassLab=invmass;}
  Float_t setInvMassCenterOfMass(Float_t invmass){m_vbInvMassCM=invmass;}
  
  // *** getters
  Float_t getInvMassLabFrame(){return m_vbInvMassLab;}
  Float_t getInvMassCenterOfMass(){return m_vbInvMassCM;}
  
  // *** useful functions
  // TObjArray *vectorBosons() {return m_vbTracks;} // all vb tracks
  // TObjArray *initialPhotons() {return m_photonTracks;} // all photon tracks
  
  // TClonesArray *vectorBosons() {return m_vbTracks;} // all vb tracks
  // TClonesArray *initialPhotons() {return m_photonTracks;} // all photon tracks
  
  std::vector<TLorentzVector> vectorBosonsVec(){return m_vbTracks_vec;}
  std::vector<TLorentzVector> initialPhotonsVec(){return m_photonTracks_vec;}
  
  void addVBVec(const TLorentzVector track);
  void addPhotonVec(const TLorentzVector track);

 protected:
  Float_t m_vbInvMassLab;
  Float_t m_vbInvMassCM;
  // TObjArray *m_vbTracks;
  // TObjArray *m_photonTracks;
  
  // TClonesArray *m_vbTracks;
  // TClonesArray *m_photonTracks;

  std::vector<TLorentzVector> m_vbTracks_vec;
  std::vector<TLorentzVector> m_photonTracks_vec;
  
 public:
  ClassDef(darkSectorVB,1);
};

#endif
