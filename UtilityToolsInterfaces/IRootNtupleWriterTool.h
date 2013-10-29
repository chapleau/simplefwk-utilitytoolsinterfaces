///////////////////////// -*- C++ -*- /////////////////////////////
// IRootNtupleWriterTool.h 
// Header file for class IRootNtupleWriterTool
/////////////////////////////////////////////////////////////////// 
#ifndef UTILITYTOOLSINTERFACES_IROOTNTUPLEWRITERTOOL_H
#define UTILITYTOOLSINTERFACES_IROOTNTUPLEWRITERTOOL_H 1



#include "UtilityToolsInterfaces/IObjectHolder.h"


class IRootNtupleWriterTool
  
{

  /////////////////////////////////////////////////////////////////// 
  // Public methods: 
  /////////////////////////////////////////////////////////////////// 
 public:

  /** Destructor: 
   */
  virtual ~IRootNtupleWriterTool() {};

  /////////////////////////////////////////////////////////////////// 
  // Const methods: 
  ///////////////////////////////////////////////////////////////////

  virtual int registerBranch(std::string, IObjectHolder*)  = 0;

  virtual int pushBack(std::string,const boost::any&) = 0;
  
  virtual IObjectHolder* getObjectHolder(std::string) = 0;

 protected:

};
  
  
#endif 
