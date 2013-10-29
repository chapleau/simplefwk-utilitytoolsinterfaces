#ifndef UTILITYTOOLSINTERFACES_VECTOROJECTHOLDER_H
#define UTILITYTOOLSINTERFACES_VECTOROJECTHOLDER_H

#include "UtilityToolsInterfaces/IObjectHolder.h"


template <class T>
class VectorObjectHolder
   : virtual public IObjectHolder
{

 public:
    virtual ~VectorObjectHolder();
    VectorObjectHolder();
    VectorObjectHolder(std::vector<T>* ptr);

    int clear();
    
    bool isempty();

    void getRawPointers(std::vector<std::pair<void*, std::string> > & ptrs);

    int push_back(const boost::any& data_);
    void reserve(std::size_t);

    const std::type_info& getTypeInfo();

    std::string getClassName();
        
protected:
    void setClassName(const std::string& cn);

 private:

       std::vector<T> * m_ptr;
       std::string m_classname;

};


#endif

