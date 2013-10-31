#include "UtilityToolsInterfaces/VectorObjectHolder.h"
#include <utility>
#include <typeinfo>


template <class T>
VectorObjectHolder<T>::~VectorObjectHolder() 
{ 
if (m_ptr) { m_ptr->clear(); delete m_ptr; m_ptr = 0;}
}

template <class T>
VectorObjectHolder<T>::VectorObjectHolder() : 
    m_ptr(new std::vector<T>()), m_classname("") 
{ }

template <class T>
VectorObjectHolder<T>::VectorObjectHolder(std::vector<T>* ptr) : 
    m_ptr(ptr), m_classname("") 
{ }

template <class T>
int VectorObjectHolder<T>::clear() {

         std::size_t siz = (m_ptr) ? m_ptr->size() : 0;

         if (m_ptr) m_ptr->clear();
         else return 0;
    
         //reserve memory based on previous size
         if (siz > 0) m_ptr->reserve(siz);

         return 1;
}
    
template <class T>
bool VectorObjectHolder<T>::isempty() {
        
        return ((m_ptr) ? m_ptr->empty() : true); 
}

template <class T>
void VectorObjectHolder<T>::getRawPointers(std::vector<std::pair<void*, std::string> > & ptrs) {
        ptrs.push_back(std::make_pair(static_cast<void*>(&m_ptr), std::string("")));
    
}

template <class T>
int VectorObjectHolder<T>::push_back(const boost::any& data_) {
                                                                                                                            
        const T* const* data_casted = boost::any_cast<const T*>(&data_);
        if (!data_casted) return 0;
        
        const T* data_ptr = *data_casted;

        m_ptr->push_back(*data_ptr);

        return 1;
}

template <class T>
void VectorObjectHolder<T>::reserve(std::size_t siz) {
  
     m_ptr->reserve(siz);
 
}

template <class T>
const std::type_info& VectorObjectHolder<T>::getTypeInfo() { return typeid(std::vector<T>); }

template <class T>
std::string VectorObjectHolder<T>::getClassName() { return m_classname; }
        
template <class T>
void VectorObjectHolder<T>::setClassName(const std::string& cn) { m_classname = cn; }

//template class definition
template class VectorObjectHolder<int>;
template class VectorObjectHolder<float>;
template class VectorObjectHolder<std::string>;
//template class VectorObjectHolder<std::vector<int> >;
//template class VectorObjectHolder<std::vector<float> >;


