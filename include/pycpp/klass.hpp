#pragma once

#include "pycpp/type.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/list.hpp"
#include "pycpp/dict.hpp"
#include "pycpp/function.hpp"

#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;

	class klass
		: public pycpp::scope
	{
	public:
        void set_name( const pycpp::string_ptr & _name );
        const pycpp::string_ptr & get_name() const;

    public:
        void set_functions( const pycpp::dict_ptr & _functions );
        const pycpp::dict_ptr & get_functions() const;

	public:
        void add_base( const pycpp::object_ptr & _base );
        const pycpp::vector_objects_t & get_bases() const;

    public:
        void make_function( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _key, const lambda_func_declaration_t & _declaration, const lambda_call_t & _lambda );
        const pycpp::object_ptr & get_function( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key );

    protected:
        pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider ) override;

	protected:
		pycpp::string_ptr m_name;
                
        pycpp::vector_objects_t m_bases;

        pycpp::dict_ptr m_functions;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<klass> klass_ptr;
	//////////////////////////////////////////////////////////////////////////
}