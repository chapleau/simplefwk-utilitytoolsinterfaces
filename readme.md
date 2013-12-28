#Simple framework - Utility tools interfaces

``simplefwk-utilitytoolsinterfaces`` contains the ``IObjectHolder`` and ``IRootNtupleWriterTool`` interface header files. It also contains concrete ``IObjectHolder`` classes.

##installation

A makefile is provided for unix-like operating systems (tested on Mac OS X 10.7.5). Requirements: 
* C++11 compliant c++ compiler (e.g. g++ 4.8)
* [boost][]

(All the above can be obtained through [macports][] for Max OS X systems.)

##Usage

The easiest way to register TTree branches with the concrete classes is by means of a macro:

````c++
//helper macros
#define REGBRANCH_S(name, type, initVal) m_ntuple_helper->registerBranch(#name, new SingleObjectHolder< type >(initVal));
#define REGBRANCH_V(name, type)          m_ntuple_helper->registerBranch(#name, new VectorObjectHolder< type >());
````

Here, **SingleObjectHolder** is used to register a branch containing a single data object per event (such as an integer, a float, or a double, etc.). A default initial value can be specified. 

**VectorObjectHolder** is used for vector of data objects (such as a vector of floats).

With the help of those macros, one can readily register branches to the ROOT ntuple write tool:

````c++
REGBRANCH_S(target, int, -1)
REGBRANCH_V(features, double)
````

In a single event, the ``IRootNtupleWriterTool::pushBack`` method is to be called once for branches associated with a single data object (**SingleObjectHolder**) and as many as needed for vector of data objects (**VectorObjectHolder**). I.e., in a single event :

````c++
int my_target = 3;
m_ntuple_helper->pushBack("target", boost::any(&my_target));

for ( auto const & it : features ) {

  m_ntuple_helper->pushBack("features", boost::any(&it));

}
````

[boost]: http://www.boost.org/
[macports]: http://www.macports.org/
