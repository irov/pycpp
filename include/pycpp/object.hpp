#pragma once

#include "pycpp/factorable.hpp"

#include <functional>

namespace pycpp
{
	typedef intrusive_ptr<class kernel> kernel_ptr;
	typedef intrusive_ptr<class object> object_ptr;
	typedef intrusive_ptr<class scope> scope_ptr;
	typedef intrusive_ptr<class type> type_ptr;
	typedef intrusive_ptr<class list> list_ptr;
	typedef intrusive_ptr<class dict> dict_ptr;
	//////////////////////////////////////////////////////////////////////////
	typedef std::function<void( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::list_ptr &, const pycpp::dict_ptr & )> lambda_call_args_provider_t;
	//////////////////////////////////////////////////////////////////////////
	class object
		: public pycpp::factorable
	{
	public:
		virtual void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object );
		virtual const pycpp::object_ptr & get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;
		virtual void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key );
		virtual bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;

	public:
		virtual uint32_t hash( const pycpp::kernel_ptr & _kernel ) const;

	public:
		virtual pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider );

	protected:
		type_ptr m_type;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<object> object_ptr;
	//////////////////////////////////////////////////////////////////////////
}