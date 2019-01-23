#pragma once

#include "pycpp/intrusive_ptr.hpp"

#include "pycpp/none.hpp"
#include "pycpp/boolean.hpp"
#include "pycpp/integer.hpp"
#include "pycpp/real.hpp"
#include "pycpp/string.hpp"
#include "pycpp/klass.hpp"
#include "pycpp/instance.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/function.hpp"
#include "pycpp/method.hpp"
#include "pycpp/dict.hpp"
#include "pycpp/list.hpp"
#include "pycpp/tuple.hpp"

#include "pycpp/factory.hpp"

#include <stdint.h>

namespace pycpp
{
	class kernel
		: public intrusive_ptr_base
	{
	public:
		bool initialize();
		void finalize();

    public:
        void set_builtin( const pycpp::string_ptr & _name, const pycpp::object_ptr & _builtin );
        pycpp::object_ptr get_builtin( const pycpp::string_ptr & _name ) const;

	public:
        pycpp::type_ptr make_type( const pycpp::string_ptr & _name );
		pycpp::function_ptr make_function( const pycpp::string_ptr & _name, const lambda_func_declaration_t & _declaration, const lambda_call_t & _lambda );
        pycpp::method_ptr make_method( const pycpp::instance_ptr & _self, const pycpp::function_ptr & _function );
		pycpp::klass_ptr make_klass( const pycpp::string_ptr & _name );
        pycpp::instance_ptr make_instance( const pycpp::klass_ptr & _klass );
		pycpp::integer_ptr make_integer( int32_t _value );
		pycpp::real_ptr make_real( float _value );
		pycpp::string_ptr make_string( const std::string & _name );
		pycpp::list_ptr make_list( size_t _size );
		pycpp::dict_ptr make_dict( size_t _capacity );
        pycpp::tuple_ptr make_tuple( size_t _capacity );

	public:
		bool op_equal( const pycpp::object_ptr & _left, const pycpp::object_ptr & _right ) const;
		pycpp::object_ptr op_add( const pycpp::object_ptr & _left, const pycpp::object_ptr & _right ) const;

	public:
		const pycpp::scope_ptr & get_global_scope() const;

	public:
		pycpp::scope_ptr make_scope( const pycpp::scope_ptr & _scope );

	public:
		const pycpp::none_ptr & get_none() const;        
		const pycpp::boolean_ptr & get_true() const;
		const pycpp::boolean_ptr & get_false() const;

        const pycpp::string_ptr & get_string_empty() const;
        const pycpp::tuple_ptr & get_tuple_empty() const;

	protected:
		pycpp::scope_ptr m_global_scope;

        pycpp::factory_ptr m_factory_type;
		pycpp::factory_ptr m_factory_scope;
		pycpp::factory_ptr m_factory_klass;
		pycpp::factory_ptr m_factory_boolean;
		pycpp::factory_ptr m_factory_integer;
        pycpp::factory_ptr m_factory_instance;
		pycpp::factory_ptr m_factory_real;
		pycpp::factory_ptr m_factory_string;
        pycpp::factory_ptr m_factory_function;
        pycpp::factory_ptr m_factory_method;
        pycpp::factory_ptr m_factory_list;
        pycpp::factory_ptr m_factory_dict;
        pycpp::factory_ptr m_factory_tuple;

		pycpp::none_ptr m_cache_none;        
		pycpp::boolean_ptr m_cache_true;
		pycpp::boolean_ptr m_cache_false;

        pycpp::string_ptr m_cache_string_empty;
        pycpp::tuple_ptr m_cache_tuple_empty;

		pycpp::real_ptr m_cache_real_zero;
		pycpp::real_ptr m_cache_real_one;

		pycpp::integer_ptr m_cache_integers[512];
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<kernel> kernel_ptr;
	//////////////////////////////////////////////////////////////////////////
	pycpp::kernel_ptr create_kernel();
	//////////////////////////////////////////////////////////////////////////
}