#ifndef DARKSECTORUTILITIES_H
#define DARKSECTORUTILITIES_H

#include "TObject.h"
#include "TFile.h"
#include "TTree.h"
#include "TDirectory.h"

class darkSectorTrack;
class darkSectorEvent;
class darkSectorMeson;
class darkSectorVB;
class darkSectorFinalState;

class darkSectorUtilities : public TObject
{
 public:
  darkSectorUtilities();
  darkSectorUtilities(const darkSectorUtilities &util);

  virtual ~darkSectorUtilities();
  
  // *** step-1: convert simulation root files (uboone*.root) or Flux.root to "darkSector" class object and save them into let say "simulatedFlux.root" file
  static void createSingleFluxFile(const char *inputRootFileName, 
				     const char *treeName, 
				     const char *outputRootFileName);

  // cok buyuk dosyada birden fazla ttree olusturuyou AutoSave den!!!
  static void createFluxFile(const char *dirName, 
			       const char *ext, 
			       const char *treeName, 
			       const char *outputRootFileName);
    
  // *** step-2: create pi+/pi-/pi0 flux file from "simulatedFlux.root" and save into let say "simulatedPionFlux.root"
  static void createSinglePiFluxFile(const char *inputRootFileName, 
				       const char *treeName, 
				       const char *outputRootFileName,
				       Int_t pdg);

  static void createPi0File(const char *inputRootFileName, 
			      const char *treeName, 
			      const char *outputRootFileName);

  // *** step-3: create meson file
  // this file is without any weighting, 5 meson(eta, rho ,...) for each pi0
  static void createMesonFile(const char *inputRootFileName, 
				const char *treeName, 
				const char *outputRootFileName);
  // this is the function to create flux meson file. It uses output of createMesonFile
  static void createFluxFromMesonFile(const char *inputRootFileName,
				       const char *treeName,
					const char *outputRootName);

  // ---> Branching ratio Tulin paper 4370

  // *** step-4: create VB file
  // *** mediator interception with detectors are also in the function
  static void createMediatorFile(const char *inputRootFileName, 
			     const char *treeName, 
			     const char *outputRootFileName);

  // *** step-5: create decay file --> Jonathan

  // ---> probablity of decay
  // ---> decay position,
  static void createDecayFile(const char *inputRootFileName, 
				const char *treeName, 
				const char *outputRootFileName);


  // *** step-6: convert to HEP format



  // *** simple print utilities to get event and track information
  void printEventInfo(darkSectorEvent *ev);
  void printTrackInfo(darkSectorTrack *tr);


  //getters

 public:
  ClassDef(darkSectorUtilities,1)
    };

#endif
