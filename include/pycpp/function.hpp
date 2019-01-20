#pragma once

#include "pycpp/object.hpp"
#include "pycpp/declaration.hpp"

namespace pycpp
{
    typedef std::vector<pycpp::string_ptr> vector_attributes_t;
    typedef std::function<void( const pycpp::kernel_ptr &, vector_attributes_t &, pycpp::string_ptr &, pycpp::string_ptr & )> lambda_func_declaration_t;
    typedef std::function<pycpp::object_ptr( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::object_ptr & )> lambda_call_t;

	class function
		: public pycpp::object
	{
    public:
        void set_name( const pycpp::string_ptr & _name );
        const pycpp::string_ptr & get_name() const;

        void set_attributes( const pycpp::vector_attributes_t & _attributes );
        const pycpp::vector_attributes_t & get_attributes() const;

        void set_args( const pycpp::string_ptr & _args );
        const pycpp::string_ptr & get_args() const;

        void set_kwds( const pycpp::string_ptr & _kwds );
        const pycpp::string_ptr & get_kwds() const;

        void set_lambda_call( const lambda_call_t & _lambda );
        const lambda_call_t & get_lambda_call() const;

	public:
		pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const pycpp::lambda_call_args_provider_t & _argsProvider ) override;

	protected:
        pycpp::string_ptr m_name;
        
        vector_attributes_t m_attributes;

        pycpp::string_ptr m_args;
        pycpp::string_ptr m_kwds;

        pycpp::lambda_call_t m_lambda_call;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<function, object> function_ptr;
	//////////////////////////////////////////////////////////////////////////
}