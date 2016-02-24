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
  
  // *** step-1A: convert a *single* simulation root file (uboone*.root) or Flux.root to "darkSector" class object and save into "simulatedFlux.root" file
  static void createSingleFluxFile(const char *inputRootFileName, 
				   const char *treeName, 
				   const char *outputRootFileName);

  // *** step-1B: convert serveral simulation root files (uboone*.root) or Flux.root to "darkSector" class objects and save into "simulatedFlux.root" file
  // (loops over every flux file in directory); ext denotes keyword for a specific root file (e.g. uboone)
  static void createFluxFile(const char *dirName, 
			     const char *ext, 
			     const char *treeName, 
			     const char *outputRootFileName);
    
  // *** step-2: create pi+/pi-/pi0 flux file from "simulatedFlux.root" and save into "simulatedPionFlux.root"
  static void createSinglePiFluxFile(const char *inputRootFileName, 
				     const char *treeName, 
				     const char *outputRootFileName,
				     Int_t pdg);

  // *** step-3 create pi0 file
  static void createPi0File(const char *inputRootFileName, 
			    const char *treeName, 
			    const char *outputRootFileName);

  // *** step-4: create meson file
  // Note: this file is without any weighting, a maximum of 5 mesons (eta, rho ,...) may be created for each pi0 mother
  static void createMesonFile(const char *inputRootFileName, 
			      const char *treeName, 
			      const char *outputRootFileName);

  // *** step-5: create meson flux file
  // Applies branching ratio from arxiv 1405.7049v1 "Leptophobic Dark Matter at Neutrino Factories", Table I 
  // It uses output of createMesonFile
  static void createFluxFromMesonFile(const char *inputRootFileName,
				      const char *treeName,
				      const char *outputRootName);

  // ---> Decay Width ratios Tulin paper arXiv:1404.4370v1
  static void applyBosonToMesonDecayWidthRatio(const char *inputRootFileName, 
					       const char *treeName, const char *outputName);
  
  // *** step-6: create VB file
  // *** mediator interception with detectors are also in the function
  static void createMediatorFile(const char *inputRootFileName, 
				 const char *treeName, 
				 const char *outputRootFileName);

  // *** step-7: create decay file --> Jonathan
  // ---> probablity of decay
  // ---> decay position,
  static void createDecayFile(const char *inputRootFileName, 
			      const char *treeName, 
			      const char *outputRootFileName);


  // *** step-8: convert to HEP format



  // *** simple print utilities to get event and track information
  void printEventInfo(darkSectorEvent *ev);
  void printTrackInfo(darkSectorTrack *tr);


 public:
  ClassDef(darkSectorUtilities,1)
    };

#endif
