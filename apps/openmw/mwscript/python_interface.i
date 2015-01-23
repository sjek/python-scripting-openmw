%module openmw
 %{
 /* Includes the header in the wrapper code */
 #include "openmwbindings.hpp"
 #include "openmwbindings0.hpp"
 %}

%ignore interpreter;
%ignore context;
%ignore Data;
%ignore getData;
%ignore stackReturn;

%include "std_string.i"


 /* Parse the header file to generate wrappers */
%include "openmwbindings.hpp"
%include "openmwbindings0.hpp"
%include "../../../components/interpreter/types.hpp"

