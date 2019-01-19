#pragma once

#include "pycpp/object.hpp"
#include "pycpp/function.hpp"
#include "pycpp/instance.hpp"

namespace pycpp
{
    class method
        : public pycpp::object
    {
    public:
        void set_function( const pycpp::function_ptr & _function );
        const pycpp::function_ptr & set_function() const;

        void set_self( const pycpp::instance_ptr & _self );
        const pycpp::instance_ptr & set_self() const;

    public:
        pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider ) override;

    protected:
        pycpp::instance_ptr m_self;
        pycpp::function_ptr m_function;
    };
    //////////////////////////////////////////////////////////////////////////
    typedef stdex::intrusive_ptr<method> method_ptr;
    //////////////////////////////////////////////////////////////////////////
}