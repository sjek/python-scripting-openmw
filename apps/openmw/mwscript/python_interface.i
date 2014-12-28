%module openmw
 %{
 /* Includes the header in the wrapper code */
 #include "aiextensions.hpp"
 %}

%ignore installOpcodes;

%include "std_string.i"


 /* Parse the header file to generate wrappers */
%include "aiextensions.hpp"

