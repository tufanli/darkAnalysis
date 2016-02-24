#if !defined(__CINT__)
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#include "darkSectorUtilities.h"
#include "darkSectorMeson.h"
#include "darkSectorFinalState.h"
#endif /* !defined(__CINT__) */

void simple()
{
  darkSectorUtilities util;

//  util.createFluxFile("../../Root_flux","boone","h102","flux_ben.root"); // bu
//  util.createPi0File("flux_ben.root","tree","pi0_ben.root"); // bu
//  util.createMesonFile("pi0_ben.root","treePi0","meson_ben.root");//bu
//  util.createFluxFromMesonFile("meson_ben.root","treeMeson","mesonFlux.root"); 
  util.createMediatorFile("mesonFlux.root","treeMeson","vb.root");//bu
  util.applyBosonToMesonDecayWidthRatio("vb.root","treeVB");
//  util.createDecayFile("vb.root","treeVB","decay.root");//bu
	


}
