#pragma once

#include "pycpp/intrusive_ptr.hpp"

#include "pycpp/none.hpp"
#include "pycpp/string.hpp"
#include "pycpp/integer.hpp"
#include "pycpp/klass.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/function.hpp"

#include "pycpp/factory.hpp"

#include <stdint.h>

namespace pycpp
{
	class kernel
		: public intrusive_ptr_base
	{
	public:
		bool initialize();
		void finalize();

	public:
		pycpp::function_ptr make_function( const pycpp::string_ptr & _name, const lambda_func_declaration_t & _declaration, const lambda_call_t & _function );
		pycpp::klass_ptr make_klass( const pycpp::string_ptr & _name );
		pycpp::integer_ptr make_integer( int32_t _value );
		pycpp::string_ptr make_string( const char * _name );
		pycpp::list_ptr make_list( size_t _size );
		pycpp::dict_ptr make_dict( size_t _capacity );

	public:
		pycpp::object_ptr opp_add( const pycpp::object_ptr & _left, const pycpp::object_ptr & _rigth );

	public:
		const pycpp::scope_ptr & get_global_scope() const;

	public:
		pycpp::scope_ptr make_scope( const pycpp::scope_ptr & _scope );

	public:
		const pycpp::none_ptr & ret_none() const;

	protected:
		pycpp::scope_ptr m_global_scope;
		pycpp::none_ptr m_none;

		pycpp::factory_ptr m_factory_scope;
		pycpp::factory_ptr m_factory_string;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<kernel> kernel_ptr;
	//////////////////////////////////////////////////////////////////////////
	pycpp::kernel_ptr create_kernel();
	//////////////////////////////////////////////////////////////////////////
}