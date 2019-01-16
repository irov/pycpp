#pragma once

#include "pycpp/object.hpp"
#include "pycpp/declaration.hpp"

namespace pycpp
{
	class function
		: public pycpp::object
	{
	public:
		virtual pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider );

	protected:
		pycpp::declaration_ptr m_declaration;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<function> function_ptr;
	//////////////////////////////////////////////////////////////////////////
}