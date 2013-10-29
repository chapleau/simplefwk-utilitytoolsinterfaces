#ifndef UTILITYTOOLSINTERFACES_IOBJECTHOLDER_H
#define UTILITYTOOLSINTERFACES_IOBJECTHOLDER_H
 
// boost include (pointer arbitration)
#include <boost/any.hpp> 
#include <vector>
#include <string>
#include <typeinfo>


class IObjectHolder
{
    
   public:
    
    friend class RootNtupleWriterTool;
    
     virtual ~IObjectHolder() {};

     virtual int clear() = 0;
     virtual bool isempty() = 0;
     virtual int push_back(const boost::any&) = 0;
     virtual void getRawPointers(std::vector<std::pair<void*, std::string> > &) = 0;
     virtual const std::type_info& getTypeInfo() = 0; 
     virtual std::string getClassName() = 0;
    
    protected:
    
     virtual void setClassName(const std::string& ) = 0;

};

#endif
