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

    def foo():
        print(self.a)
        print(self.b)
        print(self.c)
        print(self.d)
        pass

a = A(1, 2)
a.foo()
*/

class module_test
{
public:
    struct constant_t
    {
        pycpp::string_ptr string_test;
        pycpp::string_ptr string_a;
        pycpp::string_ptr string_b;
        pycpp::string_ptr string_c;
        pycpp::string_ptr string_d;
        pycpp::string_ptr string_A;
        pycpp::string_ptr string_object;
        pycpp::string_ptr string___init__;

        pycpp::integer_ptr integer_1;
        pycpp::integer_ptr integer_2;
        pycpp::integer_ptr integer_3;
    };

    void make_constant( const pycpp::kernel_ptr & _kernel )
    { 
        constant.string_test = _kernel->make_string( "test" );
        constant.string_a = _kernel->make_string( "a" );
        constant.string_b = _kernel->make_string( "b" );
        constant.string_c = _kernel->make_string( "c" );
        constant.string_d = _kernel->make_string( "d" );
        constant.string_A = _kernel->make_string( "A" );
        constant.string_object = _kernel->make_string( "object" );
        constant.string___init__ = _kernel->make_string( "__init__" );

        constant.integer_1 = _kernel->make_integer( 1 );
        constant.integer_2 = _kernel->make_integer( 2 );
        constant.integer_3 = _kernel->make_integer( 3 );
    }

    void make_code( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
    {
        {
            pycpp::function_ptr function_test = _kernel->make_function( constant.string_test
                , []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
            {
                _arguments.emplace_back( _kernel->make_string( "a" ) );
                _arguments.emplace_back( _kernel->make_string( "b" ) );
            }, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
            {
                return _kernel->op_add( _scope->get_attr( _kernel, _kernel->make_string( "a" ) ), _scope->get_attr( _kernel, _kernel->make_string( "b" ) ) );
            } );

            _scope->set_attr( _kernel, _kernel->make_string( "test" ), function_test );
        }

        {
            pycpp::klass_ptr klass_A = _kernel->make_klass( _kernel->make_string( "A" ) );

            klass_A->add_base( _scope->get_attr( _kernel, _kernel->make_string( "object" ) ) );

            {
                pycpp::function_ptr function___init__ = _kernel->make_function( _kernel->make_string( "__init__" )
                    , []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
                {
                    _arguments.emplace_back( _kernel->make_string( "a" ) );
                    _arguments.emplace_back( _kernel->make_string( "b" ) );
                }, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
                {
                    _self->set_attr( _kernel, _kernel->make_string( "a" ), _scope->get_attr( _kernel, _kernel->make_string( "a" ) ) );
                    _self->set_attr( _kernel, _kernel->make_string( "b" ), _scope->get_attr( _kernel, _kernel->make_string( "b" ) ) );
                    _self->set_attr( _kernel, _kernel->make_string( "c" ), _kernel->make_integer( 3 ) );
                    _self->set_attr( _kernel, _kernel->make_string( "d" ), _scope->get_attr( _kernel, _kernel->make_string( "test" ) )->call( _kernel, _scope, _self
                        , []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
                    {
                        _args->append( _scope->get_attr( _kernel, _kernel->make_string( "a" ) ) );
                        _args->append( _scope->get_attr( _kernel, _kernel->make_string( "b" ) ) );
                    } ) );

                    return _kernel->get_none();
                } );

                klass_A->set_function( _kernel, _kernel->make_string( "__init__" ), function___init__ );
            }

            {
                pycpp::function_ptr function_foo = _kernel->make_function( _kernel->make_string( "foo" )
                    , []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
                {
                }, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
                {
                    //print( self.a )
                    //print( self.b )
                    //print( self.c )
                    //print( self.d )
                    _scope->get_attr( _kernel, _kernel->make_string( "print" ) )->call( _kernel, _scope, _self
                        , []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
                    {
                        _args->append( _self->get_attr( _kernel, _kernel->make_string( "a" ) ) );
                        _args->append( _self->get_attr( _kernel, _kernel->make_string( "b" ) ) );
                        _args->append( _self->get_attr( _kernel, _kernel->make_string( "c" ) ) );
                        _args->append( _self->get_attr( _kernel, _kernel->make_string( "d" ) ) );
                    } );

                    return _kernel->get_none();
                } );

                klass_A->set_function( _kernel, _kernel->make_string( "foo" ), function_foo );
            }

            _scope->set_attr( _kernel, _kernel->make_string( "A" ), klass_A );
        }

        {
            _scope->set_attr( _kernel, _kernel->make_string( "a" ), _scope->get_attr( _kernel, _kernel->make_string( "A" ) )->call( _kernel, _scope, _self
                , []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
            {
                _args->append( _kernel->make_integer( 1 ) );
                _args->append( _kernel->make_integer( 2 ) );
            } ) );

            _scope->get_attr( _kernel, _kernel->make_string( "a" ) )->get_attr( _kernel, _kernel->make_string( "foo" ) )->call( _kernel, _scope, _self
                , []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
            {
            } );
        }
    }

protected:
    constant_t constant;
};

void main()
{
	pycpp::kernel_ptr kernel = pycpp::create_kernel();

    pycpp::function_ptr builtin_print = kernel->make_function( kernel->make_string( "print" )
        , []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
    {
        _args = _kernel->make_string( "args" );
    }, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
    {
        pycpp::list_ptr args = _scope->get_attr( _kernel, _kernel->make_string( "args" ) );

        size_t args_size = args->size();

        for( size_t args_index = 0; args_index != args_size; ++args_index )
        {
            const pycpp::object_ptr & arg = args->get( args_index );

            std::string arg_string = arg->to_string( _kernel );

            printf( "%s", arg_string.c_str() );
        }

        printf( "\n" );

        return _kernel->get_none();
    } );

    kernel->set_builtin( kernel->make_string( "print" ), builtin_print );

	const pycpp::scope_ptr & global_scope = kernel->get_global_scope();

	pycpp::scope_ptr module_scope = kernel->make_scope( global_scope );
    
    module_test test;
    test.make_constant( kernel );
    test.make_code( kernel, module_scope, module_scope );
}