%module openmw
 %{
 /* Includes the header in the wrapper code */
 #include "aiextensions.hpp"
 #include "statsextensions.hpp"
 %}

%ignore installOpcodes;

%include "std_string.i"


 /* Parse the header file to generate wrappers */
%include "aiextensions.hpp"
%include "statsextensions.hpp"

