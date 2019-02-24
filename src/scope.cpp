#include "pycpp/scope.hpp"
#include "pycpp/kernel.hpp"
#include "pycpp/dict.hpp"
#include "pycpp/klass.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void scope::set_parent( const pycpp::scope_ptr & _parent )
    {
        m_parent = _parent;
    }
    //////////////////////////////////////////////////////////////////////////
    void scope::set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value )
    {
        m_attributes->set_element( _kernel, _key, _value );
    }
    //////////////////////////////////////////////////////////////////////////
    void scope::set_attributes( const pycpp::dict_ptr & _attributes )
    {
        m_attributes = _attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::dict_ptr & scope::get_attributes() const
    {
        return m_attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr scope::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
    {
        const pycpp::object_ptr & attr = m_attributes->get_element( _kernel, _key );

        if( attr != nullptr )
        {
            return attr;
        }

        if( m_parent == nullptr )
        {
            return nullptr;
        }

        pycpp::object_ptr parent_attr = m_parent->get_attr( _kernel, _key );

        return parent_attr;
    }
    //////////////////////////////////////////////////////////////////////////
    void scope::del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
    {
        m_attributes->del_element( _kernel, _key );
    }
    //////////////////////////////////////////////////////////////////////////
    bool scope::has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
    {
        bool result = m_attributes->has_attr( _kernel, _key );

        return result;
    }
    //////////////////////////////////////////////////////////////////////////

}