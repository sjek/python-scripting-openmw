#SomethingScript in morrowind.omwgame has a short named hello you can use
#no need to "from openmw import *"
from openmw import *

def run():
    print("health: " + str((gethealth("player"))))
    print("hello i'm a criminal")
    setpccrimelevel(100000000)
    print("flying: " + str(getflying("player")))
    setflying("player",1)
    print("flying: " + str(getflying("player")))
    print("random100: " + str(omwget("random100")))
    omwset("random100",42)
    print("random100: " + str(omwget("random100")))
    print("SomethingScript.hello: " + str(omwget("SomethingScript.hello")))
    omwset("SomethingScript.hello",42.0)
    print("SomethingScript.hello: " + str(omwget("SomethingScript.hello")))
