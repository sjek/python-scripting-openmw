#!/usr/bin/python3

#usage:
# python3 iwyu-on-json.py build/compile_commands.json
#build first, then remove $CMAKE_SOURCE_DIRECTORY with sed from parse compile_commands.json
# then run this from $CMAKE_SOURCE_DIRECTORY (without driver)

import json
import subprocess
import sys
import os
import multiprocessing as mp

srcdir = os.getcwd()+"/"
print(srcdir)

def run(cmd):
	stringCmd = u" ".join(cmd)
#	print(stringCmd)
	subprocess.call(stringCmd, shell=True)

def runIWYUGDB(wd, args):
	cmd =[u"gdb", u"--args"]
	cmd.extend(basecmd)
	cmd.extend(args)
	run(cmd)

def runIWYU(wd, args):
	cmd = basecmd[:]
	cmd.extend(args)
	run(cmd)

f = open(sys.argv[1], "r")
tunits = json.load(f)

extraArg = u" ".join([u"-Xiwyu " + x for x in sys.argv[2:]])

#basecmd = [u"include-what-you-use", u"-Xiwyu", u"--verbose=2", extraArg] #  "-working-directory", wd]
basecmd = [u"include-what-you-use",extraArg]

#for tu in tunits:
def runcommands(tu):
	 oldDriver = tu["command"].split(None)[0]
	 cmd = tu["command"].replace(oldDriver, u"")
	 cmd = cmd.replace(srcdir, u"")
	 runIWYU(tu["directory"], [cmd])

pool = mp.Pool(processes=4)
pool.map(runcommands, tunits)
