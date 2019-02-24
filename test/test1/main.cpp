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
    MODULE = "test"

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
        pycpp::string_ptr string_print;
        pycpp::string_ptr string_foo;
        pycpp::string_ptr string_MODULE;

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
        constant.string_print = _kernel->make_string( "print" );
        constant.string_foo = _kernel->make_string( "foo" );
        constant.string_MODULE = _kernel->make_string( "MODULE" );

        constant.integer_1 = _kernel->make_integer( 1 );
        constant.integer_2 = _kernel->make_integer( 2 );
        constant.integer_3 = _kernel->make_integer( 3 );
    }

#define PYCPP_CONSTANT_STRING(X) constant.string_##X
#define PYCPP_CONSTANT_INTEGER(X) constant.integer_##X

    void make_code( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::module_ptr & _self )
    {
        _scope->make_function( _kernel, PYCPP_CONSTANT_STRING( test )
            , [this]( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
        {
            _arguments.emplace_back( PYCPP_CONSTANT_STRING( a ) );
            _arguments.emplace_back( PYCPP_CONSTANT_STRING( b ) );
        }, [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
        {
            return _kernel->op_add( _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( a ) ), _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( b ) ) );
        } );

        _scope->make_klass( _kernel, PYCPP_CONSTANT_STRING( A )
            , [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::klass_ptr & _klass )
        {
            _klass->add_base( _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( object ) ) );
        }, [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::klass_ptr & _klass )
        {
            _klass->set_attr( _kernel, PYCPP_CONSTANT_STRING( MODULE ), _kernel->make_string( "test" ) );
        }, [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::klass_ptr & _klass )
        {
            _klass->make_function( _kernel, _scope, PYCPP_CONSTANT_STRING( __init__ )
                , [this]( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
            {
                _arguments.emplace_back( PYCPP_CONSTANT_STRING( a ) );
                _arguments.emplace_back( PYCPP_CONSTANT_STRING( b ) );
            }, [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
            {
                _self->set_attr( _kernel, PYCPP_CONSTANT_STRING( a ), _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( a ) ) );
                _self->set_attr( _kernel, PYCPP_CONSTANT_STRING( b ), _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( b ) ) );
                _self->set_attr( _kernel, PYCPP_CONSTANT_STRING( c ), PYCPP_CONSTANT_INTEGER( 3 ) );
                _self->set_attr( _kernel, PYCPP_CONSTANT_STRING( d ), _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( test ) )->call( _kernel, _scope, _self
                    , [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
                {
                    _args->append( _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( a ) ) );
                    _args->append( _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( b ) ) );
                } ) );

                return _kernel->get_none();
            } );

            _klass->make_function( _kernel, _scope, PYCPP_CONSTANT_STRING( foo )
                , [this]( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
            {
            }, [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
            {
                //print( self.a )
                //print( self.b )
                //print( self.c )
                //print( self.d )
                _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( print ) )->call( _kernel, _scope, _self
                    , [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
                {
                    _args->append( _self->get_attr( _kernel, PYCPP_CONSTANT_STRING( a ) ) );
                    _args->append( _self->get_attr( _kernel, PYCPP_CONSTANT_STRING( b ) ) );
                    _args->append( _self->get_attr( _kernel, PYCPP_CONSTANT_STRING( c ) ) );
                    _args->append( _self->get_attr( _kernel, PYCPP_CONSTANT_STRING( d ) ) );
                } );

                return _kernel->get_none();
            } );
        } );

        _scope->set_attr( _kernel, PYCPP_CONSTANT_STRING( a ), _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( A ) )->call( _kernel, _scope, _self
            , [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
        {
            _args->append( PYCPP_CONSTANT_INTEGER( 1 ) );
            _args->append( PYCPP_CONSTANT_INTEGER( 2 ) );
        } ) );

        _scope->get_attr( _kernel, PYCPP_CONSTANT_STRING( a ) )->get_attr( _kernel, PYCPP_CONSTANT_STRING( foo ) )->call( _kernel, _scope, _self
            , [this]( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::scope_ptr & _self, const pycpp::list_ptr & _args, const pycpp::dict_ptr & _kwds )
        {
        } );
    }

protected:
    constant_t constant;
};

void main()
{
	pycpp::kernel_ptr kernel = pycpp::create_kernel();

    kernel->make_builtin_function( kernel->make_string( "print" )
        , []( const pycpp::kernel_ptr & _kernel, pycpp::vector_attributes_t & _arguments, pycpp::string_ptr & _args, pycpp::string_ptr & _kwds )
    {
        _args = _kernel->make_string( "args" );
    }, []( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self )
    {
        pycpp::tuple_ptr args = _scope->get_attr( _kernel, _kernel->make_string( "args" ) );

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

	pycpp::module_ptr module = kernel->make_module( kernel->make_string( "test" ) );

    module_test test;
    test.make_constant( kernel );
    test.make_code( kernel, module, module );
}