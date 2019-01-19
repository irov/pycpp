#include "pycpp/klass.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void klass::set_name( const pycpp::string_ptr & _name )
    {
        m_name = _name;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & klass::get_name() const
    {
        return m_name;
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::add_base( const pycpp::object_ptr & _base )
    {
        m_bases.emplace_back( _base );
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::set_function( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::function_ptr & _function )
    {
        function_desc_t desc;
        desc.key = _key;
        desc.function = _function;

        m_functions.emplace_back( desc );

        this->set_attr( _kernel, _key, _function );
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr klass::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider )
    {
        pycpp::instance_ptr self = _kernel->make_instance( this );

        for( const function_desc_t & desc : m_functions )
        {
            self->set_attr( _kernel, desc.key, desc.function );
        }

        const object_ptr & object_init = this->get_attr( _kernel, _kernel->make_string( "__init__" ) );

        object_init->call( _kernel, _scope, self, _argsProvider );

        return self;
    }
}