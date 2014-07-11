#include "UtilityToolsInterfaces/SingleObjectHolder.h"
#include <utility>
#include <typeinfo>
#include <type_traits>


template <class T>
SingleObjectHolder<T>::~SingleObjectHolder() 
{ 

}

template <class T>
SingleObjectHolder<T>::SingleObjectHolder(T init_) : 
    m_ptr(init_), m_classname(""), m_initValue(init_), m_ptr_addr(0) 
{ 
   if ( std::is_class<T>::value ) m_ptr_addr = &m_ptr;
}

template <class T>
SingleObjectHolder<T>::SingleObjectHolder(T ptr, T init_) : 
    m_ptr(ptr), m_classname(""),m_initValue(init_), m_ptr_addr(0)
{ 
   if ( std::is_class<T>::value ) m_ptr_addr = &m_ptr;
}
 
template <class T>
int SingleObjectHolder<T>::clear() {
         m_ptr = m_initValue;
         
         return 1;
}
    
template <class T>
bool SingleObjectHolder<T>::isempty() {
        
        return (m_ptr == m_initValue); 
}

template <class T>
void SingleObjectHolder<T>::getRawPointers(std::vector<std::pair<void*, std::string> > & ptrs) {
        //we return the address directly, and not the address of the pointer.
        if ( !(std::is_class<T>::value) )
           ptrs.push_back(std::make_pair(static_cast<void*>(&m_ptr), std::string("")));
        else 
           ptrs.push_back(std::make_pair(static_cast<void*>(&m_ptr_addr), std::string("")));
}

template <class T>
int SingleObjectHolder<T>::push_back(const boost::any& data_) {
    
        
        const T* const* data_casted = boost::any_cast<const T*>(&data_);
        if (!data_casted) return 0;
        
        const T* data_ptr = *data_casted;

        m_ptr = *data_ptr;
        
        
        return 1;
} 

template <class T>
const std::type_info& SingleObjectHolder<T>::getTypeInfo() { return typeid(T); }

template <class T>
std::string SingleObjectHolder<T>::getClassName() { return m_classname; }
        
template <class T>
void SingleObjectHolder<T>::setClassName(const std::string& cn) { m_classname = cn; }

//template class definition
template class SingleObjectHolder<int>;
template class SingleObjectHolder<unsigned int>;
template class SingleObjectHolder<unsigned long long int>;
template class SingleObjectHolder<float>;
template class SingleObjectHolder<std::string>;



