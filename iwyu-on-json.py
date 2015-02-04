#!/usr/bin/python3

#usage:
# python3 iwyu-on-json.py build/compile_commands.json
#build first, then remove $CMAKE_SOURCE_DIRECTORY with sed from parse compile_commands.json
# then run this from $CMAKE_SOURCE_DIRECTORY (without driver)

import json
import subprocess
import sys

srcdir = "/home/showard/openmw/openmw/"

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

#f = open("compile_commands.json" "r")

f = open(sys.argv[1], "r")
tunits = json.load(f)

extraArg = u" ".join([u"-Xiwyu " + x for x in sys.argv[2:]])

#basedir = u"/home/rpavlik/llvm-trunk/"
#remove scrdir from .json file using sed
#basecmd = [u"include-what-you-use", u"-Xiwyu", u"--verbose=2", extraArg] #  "-working-directory", wd]
basecmd = [u"include-what-you-use",extraArg] #  "-working-directory", wd]

#mappingFiles = ["gcc.libc.imp", "gcc.stl.headers.imp", "gcc.symbols.imp", "google.imp", "third_party.imp"] # "iwyu.gcc.imp"

#for mapping in mappingFiles:
#	basecmd.extend(["-Xiwyu", "--mapping_file="+srcdir+mapping])


for tu in tunits:
	 oldDriver = tu["command"].split(None)[0]
	 cmd = tu["command"].replace(oldDriver, u"")
	 cmd = cmd.replace(srcdir, u"")
	 runIWYU(tu["directory"], [cmd])
