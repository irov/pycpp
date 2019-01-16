#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;
	typedef stdex::intrusive_ptr<class object> object_ptr;
	typedef stdex::intrusive_ptr<class scope> scope_ptr;
	typedef stdex::intrusive_ptr<class type> type_ptr;
	typedef stdex::intrusive_ptr<class list> list_ptr;
	typedef stdex::intrusive_ptr<class dict> dict_ptr;
	typedef stdex::intrusive_ptr<class string> string_ptr;

	typedef std::function<void( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::list_ptr &, const pycpp::dict_ptr & )> lambda_call_args_provider_t;

	class object
		: public stdex::intrusive_ptr_base
	{
	public:
		void set_attr( const pycpp::string_ptr & _name, const pycpp::object_ptr & _object );
		const pycpp::object_ptr & get_attr( const pycpp::string_ptr & _name ) const;

	public:
		virtual pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider );

	protected:
		type_ptr m_type;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<object> object_ptr;
	//////////////////////////////////////////////////////////////////////////
}