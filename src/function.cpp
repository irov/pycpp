#include "pycpp/function.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    void function::set_declaration( const pycpp::declaration_ptr & _declaration )
    {
        m_declaration = _declaration;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::declaration_ptr & function::get_declaration() const
    {
        return m_declaration;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr function::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider )
    {
        
        return _kernel->get_none();
    }
}