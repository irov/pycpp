#pragma once

#include "pycpp/object.hpp"

#include <vector>
#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;
	typedef stdex::intrusive_ptr<class dict> dict_ptr;
	typedef stdex::intrusive_ptr<class scope> scope_ptr;
	typedef stdex::intrusive_ptr<class string> string_ptr;
	
	typedef std::vector<pycpp::string_ptr> vector_attributes_t;
	typedef std::function<void( const pycpp::kernel_ptr &, vector_attributes_t &, pycpp::string_ptr &, pycpp::string_ptr & )> lambda_func_declaration_t;
	typedef std::function<pycpp::object_ptr( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, pycpp::object * )> lambda_call_t;

	class type
		: public pycpp::object
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

	public:
		void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object ) override;
		const pycpp::object_ptr & get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
		void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
		bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;

	protected:
		pycpp::lambda_call_t m_call;

		pycpp::dict_ptr m_attributes;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<type> type_ptr;
	//////////////////////////////////////////////////////////////////////////
}