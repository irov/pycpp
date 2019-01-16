#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>

#include <functional>

#include "pycpp/kernel.hpp"
#include "pycpp/object.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/klass.hpp"

/*
def test(a, b):
	return a + b

class A(object):
	def __init__(self, a, b):
		self.a = a
		self.b = b
		self.c = 3
		self.d = test(a, b)
		pass
*/

void generate_class_A( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope )
{
	{
		pycpp::function_ptr function_test = _kernel->make_function( _kernel->make_string( "test" )
			, []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
		{
			_arguments.emplace_back( _kernel->make_string( "a" ) );
			_arguments.emplace_back( _kernel->make_string( "b" ) );
		}, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, pycpp::object * _self )
		{
			return _kernel->opp_add( _scope->get_attr( _kernel->make_string( "a" ) ), _scope->get_attr( _kernel->make_string( "b" ) ) );
		} );

		_scope->set_attr( _kernel->make_string( "test" ), function_test );
	}

	{
		pycpp::klass_ptr klass_A = _kernel->make_klass( _kernel->make_string( "A" ) );

		klass_A->add_base( _scope->get_attr( _kernel->make_string( "object" ) ) );
		
		{
			pycpp::function_ptr function___init__ = _kernel->make_function( _kernel->make_string( "test" )
				, []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
			{
				_arguments.emplace_back( _kernel->make_string( "a" ) );
				_arguments.emplace_back( _kernel->make_string( "b" ) );
			}, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, pycpp::object * _self )
			{
				_self->set_attr( _kernel->make_string( "a" ), _scope->get_attr( _kernel->make_string( "a" ) ) );
				_self->set_attr( _kernel->make_string( "b" ), _scope->get_attr( _kernel->make_string( "b" ) ) );
				_self->set_attr( _kernel->make_string( "c" ), _kernel->make_integer( 3 ) );
				_self->set_attr( _kernel->make_string( "d" ), _scope->get_attr( _kernel->make_string( "test" ) )->call( _kernel, _scope
					, [_self]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
				{
					_args->push_back( _scope->get_attr( _kernel->make_string( "a" ) ) );
					_args->push_back( _scope->get_attr( _kernel->make_string( "b" ) ) );
				} ) );

				return _kernel->ret_none();
			} );

			klass_A->set_attr( _kernel->make_string( "__init__" ), function___init__ );
		}

		_scope->set_attr( _kernel->make_string( "A" ), klass_A );
	}
};

void main()
{
	pycpp::kernel_ptr kernel = pycpp::create_kernel();

	const pycpp::scope_ptr & global_scope = kernel->get_global_scope();

	pycpp::scope_ptr module_scope = kernel->make_scope( global_scope );

	generate_class_A( kernel, module_scope );
}