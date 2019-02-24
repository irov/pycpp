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
        m_factory_type = new pycpp::factory_pool<pycpp::type, 256>();
		m_factory_scope = new pycpp::factory_pool<pycpp::scope, 256>();
		m_factory_klass = new pycpp::factory_pool<pycpp::klass, 256>();		
        m_factory_instance = new pycpp::factory_pool<pycpp::instance, 256>();
		m_factory_boolean = new pycpp::factory_pool<pycpp::boolean, 256>();
		m_factory_integer = new pycpp::factory_pool<pycpp::integer, 256>();
		m_factory_real = new pycpp::factory_pool<pycpp::real, 256>();
		m_factory_string = new pycpp::factory_pool<pycpp::string, 256>();
        m_factory_function = new pycpp::factory_pool<pycpp::function, 256>();
        m_factory_method = new pycpp::factory_pool<pycpp::method, 256>();
        m_factory_dict = new pycpp::factory_pool<pycpp::dict, 256>();
        m_factory_list = new pycpp::factory_pool<pycpp::list, 256>();
        m_factory_tuple = new pycpp::factory_pool<pycpp::tuple, 256>();
        m_factory_module = new pycpp::factory_pool<pycpp::module, 256>();

        m_global_scope = this->make_scope( nullptr );

		m_cache_none = new factorable_unique<pycpp::none>();
		m_cache_true = m_factory_boolean->create_object();
		m_cache_true->set_value( true );
		m_cache_false = m_factory_boolean->create_object();
		m_cache_false->set_value( false );

        m_cache_string_empty = m_factory_string->create_object();
        m_cache_tuple_empty = m_factory_tuple->create_object();
        
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
    void kernel::set_builtin( const pycpp::string_ptr & _name, const pycpp::object_ptr & _builtin )
    {
        m_global_scope->set_attr( this, _name, _builtin );
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr kernel::get_builtin( const pycpp::string_ptr & _name ) const
    {
        pycpp::object_ptr builtin = m_global_scope->get_attr( this, _name );

        return builtin;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::type_ptr kernel::make_type( const pycpp::string_ptr & _name )
    {
        pycpp::type_ptr type = m_factory_type->create_object();

        type->set_name( _name );

        return type;
    }
	//////////////////////////////////////////////////////////////////////////
	pycpp::function_ptr kernel::make_function( const pycpp::string_ptr & _name, const pycpp::scope_ptr & _scope, const lambda_func_declaration_t & _declaration, const lambda_call_t & _lambda )
	{
        pycpp::function_ptr function = m_factory_function->create_object();

        function->set_name( _name );
        function->set_scope( _scope );

        vector_attributes_t attributes;
        pycpp::string_ptr args;
        pycpp::string_ptr kwds;
        _declaration( this, attributes, args, kwds );

        function->set_attributes( attributes );
        function->set_args( args );
        function->set_kwds( kwds );

        function->set_lambda_call( _lambda );

		return function;
	}
    //////////////////////////////////////////////////////////////////////////
    pycpp::method_ptr kernel::make_method( const pycpp::instance_ptr & _self, const pycpp::function_ptr & _function )
    {
        pycpp::method_ptr method = m_factory_method->create_object();

        method->set_self( _self );
        method->set_function( _function );

        return method;
    }
	//////////////////////////////////////////////////////////////////////////
	pycpp::klass_ptr kernel::make_klass( const pycpp::string_ptr & _name, const pycpp::scope_ptr & _scope, const lambda_klass_basses_t & _basses, const lambda_klass_attributes_t & _attributes, const lambda_klass_methods_t & _methods )
	{
		pycpp::klass_ptr klass = m_factory_klass->create_object();

		klass->set_name( _name );

        klass->set_parent( _scope );

        pycpp::dict_ptr functions = this->make_dict( 0 );
        klass->set_functions( functions );

        vector_objects_t basses;
        _basses( this, klass, klass );
        _attributes( this, klass, klass );
        _methods( this, klass, klass );

		return klass;
	}
    //////////////////////////////////////////////////////////////////////////
    pycpp::instance_ptr kernel::make_instance( const pycpp::klass_ptr & _klass )
    {
        pycpp::instance_ptr instance = m_factory_instance->create_object();

        instance->set_klass( _klass );

        pycpp::dict_ptr attributes = this->make_dict( 0 );

        instance->set_attributes( attributes );

        return instance;
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
	pycpp::string_ptr kernel::make_string( const std::string & _name )
	{
        if( _name.empty() == true )
        {
            return m_cache_string_empty;
        }

		pycpp::string_ptr string = m_factory_string->create_object();

		string->set_value( _name );

		return string;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::list_ptr kernel::make_list( size_t _size )
	{
        pycpp::list_ptr list = m_factory_list->create_object();

        list->reserve( _size );

		return list;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::dict_ptr kernel::make_dict( size_t _capacity )
	{
        pycpp::dict_ptr dict = m_factory_dict->create_object();
        
		return dict;
	}
    //////////////////////////////////////////////////////////////////////////
    pycpp::tuple_ptr kernel::make_tuple( size_t _capacity )
    {
        if( _capacity == 0 )
        {
            return m_cache_tuple_empty;
        }

        pycpp::tuple_ptr tuple = m_factory_tuple->create_object();

        return tuple;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::module_ptr kernel::make_module( const pycpp::string_ptr & _name )
    {
        pycpp::module_ptr module = m_factory_module->create_object();

        module->set_name( _name );

        pycpp::scope_ptr module_scope = this->make_scope( m_global_scope );

        module->set_parent( module_scope );

        return module;
    }
	//////////////////////////////////////////////////////////////////////////
	bool kernel::op_equal( const pycpp::object_ptr & _left, const pycpp::object_ptr & _right ) const
	{
        if( _left->get_type() == _right->get_type() )
        {
            bool result = _left->op_equal( this, _right );

            return result;
        }

		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr kernel::op_add( const pycpp::object_ptr & _left, const pycpp::object_ptr & _right ) const
	{
        if( _left->get_type() == _right->get_type() )
        {
            pycpp::object_ptr result = _left->op_add( this, _right );

            return result;
        }

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

        pycpp::dict_ptr attributes = this->make_dict( 0 );

        scope->set_attributes( attributes );

		return scope;
	}
    //////////////////////////////////////////////////////////////////////////
    void kernel::make_builtin_function( const pycpp::string_ptr & _name, const lambda_func_declaration_t & _declaration, const lambda_call_t & _lambda )
    {
        pycpp::function_ptr function = this->make_function( _name, m_global_scope, _declaration, _lambda );

        m_global_scope->set_attr( this, _name, function );
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
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & kernel::get_string_empty() const
    {
        return m_cache_string_empty;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::tuple_ptr & kernel::get_tuple_empty() const
    {
        return m_cache_tuple_empty;
    }
}