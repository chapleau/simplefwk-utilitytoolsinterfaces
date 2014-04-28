%module ObjectHolder
%{
#include "UtilityToolsInterfaces/SingleObjectHolder.h"
#include "UtilityToolsInterfaces/VectorObjectHolder.h"
%}


%include "std_string.i"


%include "std_vector.i"

namespace std {
       %template(FloatVector) vector<float>;
       %template(DoubleVector) vector<double>;
       %template(StringVector) vector<string>;
}


class IObjectHolder {
 
  private :
     IObjectHolder();
     ~IObjectHolder();

};


template <class T>
class VectorObjectHolder : virtual public IObjectHolder { 

public:
  VectorObjectHolder();
  

  //~VectorObjectHolder();

};

template <class T>
class SingleObjectHolder : virtual public IObjectHolder { 

public: 
   SingleObjectHolder(T);
   //~SingleObjectHolder();

};

%template(VectorObjectHolder_Int) VectorObjectHolder<int>;
%template(VectorObjectHolder_Float) VectorObjectHolder<float>;
%template(VectorObjectHolder_Double) VectorObjectHolder<double>;
%template(VectorObjectHolder_String) VectorObjectHolder<std::string>;

%template(SingleObjectHolder_Int) SingleObjectHolder<int>;
%template(SingleObjectHolder_UInt) SingleObjectHolder<unsigned int>;
%template(SingleObjectHolder_Float) SingleObjectHolder<float>;

