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
		m_factory_klass = new pycpp::factory_pool<pycpp::klass, 256>();		
		m_factory_boolean = new pycpp::factory_pool<pycpp::boolean, 256>();
		m_factory_integer = new pycpp::factory_pool<pycpp::integer, 256>();
		m_factory_real = new pycpp::factory_pool<pycpp::real, 256>();
		m_factory_string = new pycpp::factory_pool<pycpp::string, 256>();

		m_global_scope = m_factory_scope->create_object();

		m_cache_none = new factorable_unique<pycpp::none>();
		m_cache_true = m_factory_boolean->create_object();
		m_cache_true->set_value( true );
		m_cache_false = m_factory_boolean->create_object();
		m_cache_false->set_value( false );

		m_cache_real_zero = m_factory_real->create_object();
		m_cache_real_zero->set_value( 0.f );

		m_cache_real_one = m_factory_real->create_object();
		m_cache_real_one->set_value( 1.f );

		for( int32_t index = -256; index != 256; ++index )
		{
			 pycpp::integer_ptr integer = m_factory_integer->create_object();
			 integer->set_value( index );

			 m_cache_integers[index + 256] = integer;
		}

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
		pycpp::klass_ptr klass = m_factory_klass->create_object();

		klass->set_name( _name );

		return klass;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::integer_ptr kernel::make_integer( int32_t _value )
	{
		if( _value >= -256 && _value <= 255 )
		{
			return m_cache_integers[_value + 256];
		}

		pycpp::integer_ptr integer = m_factory_integer->create_object();

		integer->set_value( _value );

		return integer;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::real_ptr kernel::make_real( float _value )
	{
		if( _value == 0.f )
		{
			return m_cache_real_zero;
		}
		else if( _value == 1.f )
		{
			return m_cache_real_one;
		}

		pycpp::real_ptr real = m_factory_real->create_object();

		real->set_value( _value );

		return real;
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
	bool kernel::op_equal( const pycpp::object_ptr & _left, const pycpp::object_ptr & _rigth ) const
	{
		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr kernel::op_add( const pycpp::object_ptr & _left, const pycpp::object_ptr & _rigth ) const
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
		pycpp::scope_ptr scope = m_factory_scope->create_object();

		scope->set_parent( _scope );

		return scope;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::none_ptr & kernel::get_none() const
	{
		return m_cache_none;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::boolean_ptr & kernel::get_true() const
	{
		return m_cache_true;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::boolean_ptr & kernel::get_false() const
	{
		return m_cache_false;
	}

}