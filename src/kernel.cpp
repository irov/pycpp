#include "pycpp/kernel.hpp"
#include "pycpp/factorable_unique.hpp"
#include "pycpp/factory_pool.hpp"

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	pycpp::kernel_ptr create_kernel()
	{
		pycpp::kernel_ptr kernel = new pycpp::factorable_unique<pycpp::kernel>();

		kernel->initialize();

		return kernel;
	}
	//////////////////////////////////////////////////////////////////////////
	bool kernel::initialize()
	{
		m_factory_scope = new pycpp::factory_pool<pycpp::scope, 256>();
		m_factory_string = new pycpp::factory_pool<pycpp::string, 256>();

		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	void kernel::finalize()
	{
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::function_ptr kernel::make_function( const pycpp::string_ptr & _name, const lambda_func_declaration_t & _declaration, const lambda_call_t & _function )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::klass_ptr kernel::make_klass( const pycpp::string_ptr & _name )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::integer_ptr kernel::make_integer( int32_t _value )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::string_ptr kernel::make_string( const char * _name )
	{
		pycpp::string_ptr string = m_factory_string->create_object();

		string->set_value( _name );

		return string;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::list_ptr kernel::make_list( size_t _size )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::dict_ptr kernel::make_dict( size_t _capacity )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr kernel::opp_add( const pycpp::object_ptr & _left, const pycpp::object_ptr & _rigth )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::scope_ptr & kernel::get_global_scope() const
	{
		return m_global_scope;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::scope_ptr kernel::make_scope( const pycpp::scope_ptr & _scope )
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::none_ptr & kernel::ret_none() const
	{
		return m_none;
	}
}