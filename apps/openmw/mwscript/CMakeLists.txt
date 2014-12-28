#newer FIND_PACKAGE(SWIG REQUIRED)
#ADD_CUSTOM_COMMAND(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/python_interface_wrap.cpp ${CMAKE_CURRENT_SOURCE_DIR}/openmw.py COMMAND "${SWIG_EXECUTABLE}" -c++ -python -o ${CMAKE_CURRENT_SOURCE_DIR}/python_interface_wrap.cpp ${CMAKE_CURRENT_SOURCE_DIR}/python_interface.i)
#ADD_CUSTOM_TARGET(generate_wrap DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/python_interface_wrap.cpp)
#bad, don't make it in the source directory


#old
# start SWIG stuff
#FIND_PACKAGE(SWIG REQUIRED)
#INCLUDE(${SWIG_USE_FILE})

#FIND_PACKAGE(PythonLibs)
#INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

#SET(CMAKE_SWIG_FLAGS "")

#SET_SOURCE_FILES_PROPERTIES(python_interface.i PROPERTIES CPLUSPLUS ON)
##SET_SOURCE_FILES_PROPERTIES(python_interface.i PROPERTIES SWIG_FLAGS "-includeall") #-includeall or -importall if just want typedefs
#SWIG_ADD_MODULE(openmw python python_interface.i aiextensions.cpp)
#SWIG_LINK_LIBRARIES(openmw ${PYTHON_LIBRARIES})


#this creates a shared library object. we can link to this shared library
# object, then have the embedded compiler load the module, getting access to c++
# functions https://mail.python.org/pipermail/tutor/2007-February/052992.html
# what if we just compile the file with everything else? do we still need .so object?
# embedded python can just import module (yes, do this!)

# will need main program to link to python libs
# and add generated source code to list of source files

#ADD_CUSTOM_COMMAND(OUTPUT COMMAND "${SWIG_EXECUTABLE}" -c++ -python python_interface.i)
# ${swig_generated_file_fullname}

#right now this creates both the module and embeds the code

# ok, from http://www.gamedev.net/topic/467136-solution-embedding-python-and-the-import-statement/
# import openmw will import from .so or from running code/memory space

# source_group(game FILES ${CMAKE_CURRENT_SOURCE_DIR}/mwscript/${SWIG_MODULE_OPENMW_REAL_NAME}) do we need this?
#can replace mwscript/python_interfacePYTHON_wrap.cxx with variable

# end SWIG stuff
