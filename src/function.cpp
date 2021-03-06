#include "pycpp/function.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void function::set_name( const pycpp::string_ptr & _name )
    {
        m_name = _name;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & function::get_name() const
    {
        return m_name;
    }
    //////////////////////////////////////////////////////////////////////////
    void function::set_scope( const pycpp::scope_ptr & _scope )
    {
        m_scope = _scope;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::scope_ptr & function::get_scope() const
    {
        return m_scope;
    }
    //////////////////////////////////////////////////////////////////////////
    void function::set_attributes( const pycpp::vector_attributes_t & _attributes )
    {
        m_attributes = _attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::vector_attributes_t & function::get_attributes() const
    {
        return m_attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    void function::set_args( const pycpp::string_ptr & _args )
    {
        m_args = _args;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & function::get_args() const
    {
        return m_args;
    }
    //////////////////////////////////////////////////////////////////////////
    void function::set_kwds( const pycpp::string_ptr & _kwds )
    {
        m_kwds = _kwds;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & function::get_kwds() const
    {
        return m_kwds;
    }
    //////////////////////////////////////////////////////////////////////////
    void function::set_lambda_call( const lambda_call_t & _lambda )
    {
        m_lambda_call = _lambda;
    }
    //////////////////////////////////////////////////////////////////////////
    const lambda_call_t & function::get_lambda_call() const
    {
        return m_lambda_call;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr function::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const pycpp::lambda_call_args_provider_t & _argsProvider )
    {
        pycpp::list_ptr args = _kernel->make_list( 0 );
        pycpp::dict_ptr kwds = _kernel->make_dict( 0 );

        _argsProvider( _kernel, _scope, _self, args, kwds );

        pycpp::scope_ptr call_scope = _kernel->make_scope( m_scope );

        uint32_t attr_iterator = 0;
        for( const pycpp::string_ptr & attr : m_attributes )
        {
            const pycpp::object_ptr & value = args->get( attr_iterator );

            call_scope->set_attr( _kernel, attr, value );

            ++attr_iterator;
        }

        if( m_args != nullptr )
        {
            pycpp::tuple_ptr args_slice = args->slice_tuple( _kernel, attr_iterator );

            call_scope->set_attr( _kernel, m_args, args_slice );
        }
        
        pycpp::object_ptr result = m_lambda_call( _kernel, call_scope, _self );
        
        return result;
    }
}