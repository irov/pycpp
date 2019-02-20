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
    void klass::set_scope( const pycpp::scope_ptr & _scope )
    {
        m_scope = _scope;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::scope_ptr & klass::get_scope() const
    {
        return m_scope;
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::set_functions( const pycpp::dict_ptr & _functions )
    {
        m_functions = _functions;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::dict_ptr & klass::get_functions() const
    {
        return m_functions;
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::add_base( const pycpp::object_ptr & _base )
    {
        m_bases.emplace_back( _base );
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::set_function( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::function_ptr & _function )
    {
        m_functions->set_element( _kernel, _key, _function );
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::object_ptr & klass::get_function( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
    {
        const pycpp::object_ptr & function = m_functions->get_element( _kernel, _key );

        return function;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr klass::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider )
    {
        pycpp::instance_ptr self = _kernel->make_instance( this );

        object_ptr object_init = self->get_attr( _kernel, _kernel->make_string( "__init__" ) );

        object_init->call( _kernel, _scope, self, _argsProvider );

        return self;
    }
}