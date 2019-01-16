#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	typedef stdex::intrusive_ptr<class klass> klass_ptr;

	typedef std::function<void( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::list_ptr &, const pycpp::dict_ptr & )> lambda_call_args_provider_t;

	class instance
		: public pycpp::object
	{
	public:
		pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider ) override;

	protected:
		klass_ptr m_klass;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<instance> instance_ptr;
	//////////////////////////////////////////////////////////////////////////
}