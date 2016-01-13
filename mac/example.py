import sys
from ROOT import gSystem
gSystem.Load("libdarkSector_darkAnalysis")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing darkAnalysis..."

sys.exit(0)

