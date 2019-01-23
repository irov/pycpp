#include "pycpp/integer.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    integer::integer()
        : m_value( 0 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    integer::~integer()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    void integer::set_value( int32_t _value )
    {
        m_value = _value;
    }
    //////////////////////////////////////////////////////////////////////////
    int32_t integer::get_value() const
    {
        return m_value;
    }
    //////////////////////////////////////////////////////////////////////////
    std::string integer::to_string( const pycpp::kernel_ptr & _kernel ) const
    {
        return std::to_string( m_value );
    }
    //////////////////////////////////////////////////////////////////////////
    bool integer::op_equal( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const
    {
        pycpp::integer * other_integer = stdex::intrusive_get<pycpp::integer *>( _other );

        int32_t other_integer_value = other_integer->get_value();

        return m_value == other_integer_value;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::object_ptr integer::op_add( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const
    {
        pycpp::integer * other_integer = stdex::intrusive_get<pycpp::integer *>( _other );

        int32_t other_integer_value = other_integer->get_value();

        int32_t new_value = m_value + other_integer_value;

        pycpp::integer_ptr new_integer = _kernel->make_integer( new_value );

        return new_integer;
    }
}