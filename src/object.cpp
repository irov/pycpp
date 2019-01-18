#include "pycpp/object.hpp"
#include "pycpp/type.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	void object::set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object )
	{

	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::object_ptr & object::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		const pycpp::object_ptr & obj = m_type->get_attr( _kernel, _key );

		return obj;
	}
	//////////////////////////////////////////////////////////////////////////
	void object::del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
	{

	}
	//////////////////////////////////////////////////////////////////////////
	bool object::has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		bool result = m_type->has_attr( _kernel, _key );

		return result;
	}
	//////////////////////////////////////////////////////////////////////////
	uint32_t object::hash( const pycpp::kernel_ptr & _kernel ) const
	{
		return ~0;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr object::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider )
	{
		const lambda_call_t & lambda_call = m_type->get_call();

		pycpp::list_ptr args = _kernel->make_list( 0 );
		pycpp::dict_ptr kwds = _kernel->make_dict( 0 );

		_argsProvider( _kernel, _scope, args, kwds );

		pycpp::object_ptr ret = lambda_call( _kernel, _scope, this );

		return pycpp::object_ptr::none();
	}
}