#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

#include <vector>
#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;
	typedef stdex::intrusive_ptr<class scope> scope_ptr;
	typedef stdex::intrusive_ptr<class object> object_ptr;
	
	typedef std::vector<pycpp::string_ptr> vector_attributes_t;
	typedef std::function<void( const pycpp::kernel_ptr &, vector_attributes_t &, pycpp::string_ptr &, pycpp::string_ptr & )> lambda_func_declaration_t;
	typedef std::function<pycpp::object_ptr( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, pycpp::object * )> lambda_call_t;

	class type
		: public stdex::intrusive_ptr_base
	{
	public:
		void set_call( const lambda_call_t & _call )
		{
			m_call = _call;
		}

		const lambda_call_t & get_call() const
		{
			return m_call;
		}

	protected:
		lambda_call_t m_call;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<type> type_ptr;
	//////////////////////////////////////////////////////////////////////////
}