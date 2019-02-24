#include "pycpp/instance.hpp"
#include "pycpp/type.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void instance::set_klass( const pycpp::klass_ptr & _klass )
    {
        m_klass = _klass;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::klass_ptr & instance::get_klass() const
    {
        return m_klass;
    }
    //////////////////////////////////////////////////////////////////////////
    void instance::set_attributes( const pycpp::dict_ptr & _attributes )
    {
        m_attributes = _attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::dict_ptr & instance::get_attributes() const
    {
        return m_attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    void instance::set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value )
    {
        m_attributes->set_element( _kernel, _key, _value );
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr instance::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
    {
        pycpp::object_ptr function = m_klass->get_function( _kernel, _key );

        if( function != nullptr )
        {
            pycpp::method_ptr method = _kernel->make_method( this, function );

            return method;
        }

        const pycpp::object_ptr & attr = m_attributes->get_element( _kernel, _key );

        return attr;
    }
    //////////////////////////////////////////////////////////////////////////
    void instance::del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
    {
        m_attributes->del_element( _kernel, _key );
    }
    //////////////////////////////////////////////////////////////////////////
    bool instance::has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
    {
        bool result = m_attributes->has_element( _kernel, _key );

        return result;
    }
}