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
  Float_t setInvMass(Float_t invmass){m_vbInvMass=invmass;}
  Int_t setMediatorInterceptSBND(Int_t inter){m_vbInterceptSBND=inter;}
  Int_t setMediatorInterceptUBOONE(Int_t inter){m_vbInterceptUBOONE=inter;}
  Int_t setMediatorInterceptICARUS(Int_t inter){m_vbInterceptICARUS=inter;}

  // *** getters
  Float_t getInvMass(){return m_vbInvMass;}
  Int_t getMediatorInterceptSBND(){return m_vbInterceptSBND;}
  Int_t getMediatorInterceptUBOONE(){return m_vbInterceptUBOONE;}
  Int_t getMediatorInterceptICARUS(){return m_vbInterceptICARUS;}

  // *** all possible VB and initial photons
  std::vector<TLorentzVector> vectorBosonsVec(){return m_vbTracks_vec;}
  std::vector<TLorentzVector> initialPhotonsVec(){return m_photonTracks_vec;}
  void addVBVec(const TLorentzVector track);
  void addPhotonVec(const TLorentzVector track);

 protected:
  Float_t m_vbInvMass;
  Int_t m_vbInterceptSBND;
  Int_t m_vbInterceptUBOONE;
  Int_t m_vbInterceptICARUS;

  std::vector<TLorentzVector> m_vbTracks_vec;
  std::vector<TLorentzVector> m_photonTracks_vec;

 public:
  ClassDef(darkSectorVB,1);
};

#endif
