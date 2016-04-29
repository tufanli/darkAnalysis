#ifndef DARKSECTORDECAYPROBABILITY_H
#define DARKSECTORDECAYPROBABILITY_H

#include "darkSectorTrack.h"
#include <TH1F.h>
#include <TLorentzVector.h>
#include <TMath.h>

class darkSectorDecayProbability : public darkSectorTrack
{

public:

  // ### Constructors ###
  darkSectorDecayProbability(const darkSectorDecayProbability &a);
  darkSectorDecayProbability();

  // ### Destructor ###
  virtual ~darkSectorDecayProbability();

  // ### Setters ###
  void setDecProb(Float_t decProb){m_trDecProb = decProb;}

  // ### Getters ###
  Float_t getDecProb(){return m_trDecProb;}

  // ### VB -> Pi0 + gamma decay width parameters ###                                                                                                                          
  Float_t pionDecConst = 0.093; // pion decay constant 93 MeV                                                                                                                  
  Float_t c_light = 299792458; // speed of light                                                                                                                               
  Float_t alpha_EM = 7.29735257*pow(10.0,-3.0); // fine structure constant                                                                                                     
  Float_t pi0Mass = 0.13497; // Pi0 mass                                                                                                                                       
  Float_t frontend[3] = {110.0,470.0,600.0}; // target to TPC front-end distance for SBND, MicroBooNE, and ICARUS, respectively                                                
  Float_t backend[3] = {113.6,480.0,619.6}; // target to TPC back-end distance for SBND, MicroBooNE and ICARUS, respectively                                                   

  Float_t computeDecayProbability(Float_t alpha_B, 
				  Float_t vb_mass, 
				  TLorentzVector tempVec, 
				  Int_t detectorID)
  {
    // Partial decay width (from arXiv:1404:4370v1)                                                                                                                            
    Float_t partialWidth = alpha_B*alpha_EM*pow(vb_mass,3.0)*pow(96.0,-1.0)
                          *(TMath::Pi(),-3.0)*pow(pionDecConst,-2.0)
                          *pow(1-(pow(pi0Mass,2.0)*pow(vb_mass,-2.0)),3.0);

    // Particle lifetime                                                                                                                                                       
    // AM I MISSING AN HBAR HERE?!?!?!                                                                                                                                         
    Float_t decayLifetime = pow(partialWidth,-1.0);

    // Boost magnitude                                                                                                                                                         
    Float_t boostMag = tempVec.Beta();

    //Flight distance                                                                                                                                                          
    Float_t lbar = boostMag*c_light*decayLifetime;

    return m_trDecProb = TMath::Exp(-frontend[detectorID]/lbar)
                       - TMath::Exp(-backend[detectorID]/lbar);
  }

  // ### Decay probability distributions for each detector & coupling constant
  // The # indicates 10^-# (i.e. the coupling constant order of magnitude)
  TH1F *sbnd1 = new TH1F("sbnd1","",15,log10(0.000000000000001),1);
  TH1F *sbnd2 = new TH1F("sbnd2","",15,log10(0.000000000000001),1);
  TH1F *sbnd3 = new TH1F("sbnd3","",15,log10(0.000000000000001),1);
  TH1F *sbnd4 = new TH1F("sbnd4","",15,log10(0.000000000000001),1);
  TH1F *sbnd5 = new TH1F("sbnd5","",15,log10(0.000000000000001),1);
  TH1F *sbnd6 = new TH1F("sbnd6","",15,log10(0.000000000000001),1);
  TH1F *sbnd7 = new TH1F("sbnd7","",15,log10(0.000000000000001),1);
  TH1F *sbnd8 = new TH1F("sbnd8","",15,log10(0.000000000000001),1);

  TH1F *uboone1 = new TH1F("uboone1","",15,log10(0.000000000000001),1);
  TH1F *uboone2 = new TH1F("uboone2","",15,log10(0.000000000000001),1);
  TH1F *uboone3 = new TH1F("uboone3","",15,log10(0.000000000000001),1);
  TH1F *uboone4 = new TH1F("uboone4","",15,log10(0.000000000000001),1);
  TH1F *uboone5 = new TH1F("uboone5","",15,log10(0.000000000000001),1);
  TH1F *uboone6 = new TH1F("uboone6","",15,log10(0.000000000000001),1);
  TH1F *uboone7 = new TH1F("uboone7","",15,log10(0.000000000000001),1);
  TH1F *uboone8 = new TH1F("uboone8","",15,log10(0.000000000000001),1);

  TH1F *icarus1 = new TH1F("icarus1","",15,log10(0.000000000000001),1);
  TH1F *icarus2 = new TH1F("icarus2","",15,log10(0.000000000000001),1);
  TH1F *icarus3 = new TH1F("icarus3","",15,log10(0.000000000000001),1);
  TH1F *icarus4 = new TH1F("icarus4","",15,log10(0.000000000000001),1);
  TH1F *icarus5 = new TH1F("icarus5","",15,log10(0.000000000000001),1);
  TH1F *icarus6 = new TH1F("icarus6","",15,log10(0.000000000000001),1);
  TH1F *icarus7 = new TH1F("icarus7","",15,log10(0.000000000000001),1);
  TH1F *icarus8 = new TH1F("icarus8","",15,log10(0.000000000000001),1);

 protected: 

  Float_t m_trDecProb;

 public:
  ClassDef(darkSectorDecayProbability,1);


};

#endif
/** @} */ // end of doxygen group 

