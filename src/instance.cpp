#include "pycpp/instance.hpp"
#include "pycpp/type.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr instance::call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const lambda_call_args_provider_t & _argsProvider )
	{
		const object_ptr & object_init = m_klass->get_attr( _kernel->make_string( "__init__" ) );

		pycpp::object_ptr ret = object_init->call( _kernel, _scope, _argsProvider );

		return ret;
	}
}