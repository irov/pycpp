#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

#include "pycpp/none.hpp"
#include "pycpp/string.hpp"
#include "pycpp/integer.hpp"
#include "pycpp/klass.hpp"
#include "pycpp/function.hpp"

#include <stdint.h>

namespace pycpp
{
	class kernel
		: public stdex::intrusive_ptr_base
	{
	public:
		void initialize();
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
		const pycpp::none_ptr & ret_none() const;

	protected:
		pycpp::none_ptr m_none;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<kernel> kernel_ptr;
	//////////////////////////////////////////////////////////////////////////
	pycpp::kernel_ptr create_kernel();
	//////////////////////////////////////////////////////////////////////////
}