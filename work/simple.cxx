#if !defined(__CINT__)
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#include "darkSectorUtilities.h"
#include "darkSectorMeson.h"
#include "darkSectorFinalState"
#endif /* !defined(__CINT__) */

// ---------------------------------------------------------------------
// ---    This is meant as a skeleton code to demonstrate how to 
// ---   walk through the code and create the output .root files
// ---
// ---    The path dependencies shown here are expected to be in 
// ---    darkAnalysis/work directory. You can write this to run 
// ---    anywhere if you include the path for the gSystem->Load
// --- and the path dependency for the input ROOT files appropriately
// ----------------------------------------------------------------------



void simple()
{
  gSystem->Load("../../../lib/libdarkSector_darkAnalysis");

  darkSectorUtilities util;
  
  // ### Common naming format for the util.creat...blahblah "
  // ### util.createFluxFile("Inputfile.root", "extension commmon word", "tree", "output.root") ###
  
  
  // ### Creates Flux files from UBooNE BNB Beamline Files ###
  util.createFluxFile("../Root_flux","boone","h102","flux_ben.root"); // bu
  // ### Creates Pi0 Flux from the previously inputed file ###
  util.createPi0File("flux_ben.root","tree","pi0_ben.root"); // bu
  // ### Creates the heavier mesons (for each pi0 create all 5 heavier mesons ###
  util.createMesonFile("pi0_ben.root","treePi0","meson_ben.root");//bu
  // ### Creates the appropriate flux of heavier mesons via random selection of the appropriate branching ratio ###
  util.createFluxFromMesonFile("meson_ben.root","treeMeson","mesonFlux.root");
  // ### Creates the Vector Bosons from the meson flux ###
  // ### Warning: This does not recreate the file, but instead adds to the file
  // ### so if you want to create this file fresh, you will want to delete mesonFlux.root
  // ### and then re-run
  util.createMediatorFile("mesonFlux.root","treeMeson","vb.root");//bu
  
  // ### Creates the decay of the vector boson from the flux of vector bosons ###
  util.createDecayFile("vb.root","treeVB","decay.root");//bu
	
}
