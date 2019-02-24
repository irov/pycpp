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
    const pycpp::vector_objects_t & klass::get_bases() const
    {
        return m_bases;
    }
    //////////////////////////////////////////////////////////////////////////
    void klass::make_function( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _key, const lambda_func_declaration_t & _declaration, const lambda_call_t & _lambda )
    {
        pycpp::function_ptr function = _kernel->make_function( m_name, _scope, _declaration, _lambda );

        m_functions->set_element( _kernel, _key, function );
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