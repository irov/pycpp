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
    pycpp::object_ptr instance::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
    {
        const pycpp::object_ptr & function = m_klass->get_function( _kernel, _key );

        if( function != nullptr )
        {
            pycpp::method_ptr method = _kernel->make_method( this, function );

            return method;
        }

        pycpp::object_ptr attr = object::get_attr( _kernel, _key );

        return attr;
    }

}