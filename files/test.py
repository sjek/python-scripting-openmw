#SomethingScript in morrowind.omwgame has a short named hello you can use
#from openmw import *
from openmw import gethealth, setpccrimelevel, getflying, setflying, set

print("health: " + str((gethealth("player"))))

print("hello i'm a criminal")
setpccrimelevel(100000000)

print("flying: " + str(getflying("player")))
setflying("player",1)
print("flying: " + str(getflying("player")))
set("random100",30)
set("SomethingScript.hello",30)
