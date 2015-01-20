%module openmw
 %{
 /* Includes the header in the wrapper code */
 #include "openmwbindings.hpp"
 %}

%ignore interpreter;
%ignore context;
%ignore Data;
%ignore getData;

%include "std_string.i"


 /* Parse the header file to generate wrappers */
%include "openmwbindings.hpp"
%include "../../../components/interpreter/types.hpp"

