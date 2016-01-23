#if !defined(__CINT__)
#include "darkSectorEvent.h"
#include "darkSectorTrack.h"
#include "darkSectorUtilities.h"
#include "darkSectorMeson.h"
#include "darkSectorFinalState"
#endif /* !defined(__CINT__) */

void simple()
{
darkSectorUtilities util;
//util.createSingleFluxFile("boone1_511.root","h102","huhu.root");
//util.createFluxFile("../Root_flux","boone","h102","flux_ben.root"); // bu
//util.createSinglePiFluxFile("huhu.root","tree","pi.root",-211);
 //util.createPi0File("flux_ben.root","tree","pi0_ben.root"); // bu

// util.createMesonFile("pi0_ben.root","treePi0","meson_ben.root");//bu
 //util.createVBFile("meson_ben.root","treeMeson","vb.root");//bu
 util.createDecayFile("vb.root","treeVB","decay.root");//bu

//util.printEventInfo();
}
