#include "pycpp/method.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void method::set_function( const pycpp::function_ptr & _function )
    {
        m_function = _function;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::function_ptr & method::set_function() const
    {
        return m_function;
    }
    //////////////////////////////////////////////////////////////////////////
    void method::set_self( const pycpp::instance_ptr & _self )
    {
        m_self = _self;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::instance_ptr & method::set_self() const
    {
        return m_self;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr method::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider )
    {
        //m_function->call( _kernel, _scope, _self )

        return _kernel->get_none();
    }
}