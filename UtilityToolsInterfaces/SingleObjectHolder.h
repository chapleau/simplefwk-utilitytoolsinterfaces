#ifndef UTILITYTOOLSINTERFACES_SINGLEOJECTHOLDER_H
#define UTILITYTOOLSINTERFACES_SINGLEOJECTHOLDER_H

#include "UtilityToolsInterfaces/IObjectHolder.h"

template <class T>
class SingleObjectHolder
   : virtual public IObjectHolder
{

 public:
    virtual ~SingleObjectHolder();
    SingleObjectHolder(T);
    SingleObjectHolder(T, T);

    int clear();
    
    bool isempty();

    void getRawPointers(std::vector<std::pair<void*, std::string> > & ptrs);

    int push_back(const boost::any& data_);

    const std::type_info& getTypeInfo();

    std::string getClassName();
        
protected:
    void setClassName(const std::string& cn);

 private:
 
       T  m_ptr;
       std::string m_classname;
       T m_initValue;

};

#endif
