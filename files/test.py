from openmw import *

print("health: " + str((gethealth("player"))))

print("hello i'm a criminal")
setpccrimelevel(100000000)

print("flying: " + str(getflying("player")))
setflying("player",1)
print("flying: " + str(getflying("player")))
set("random100",30)
