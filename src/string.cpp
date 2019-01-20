#pragma once

#include "pycpp/string.hpp"

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	void string::set_value( const std::string & _value )
	{
		m_value = _value;
	}
	//////////////////////////////////////////////////////////////////////////
	const std::string & string::get_value() const
	{
		return m_value;
	}
    //////////////////////////////////////////////////////////////////////////
    bool string::op_equal( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const
    {
        pycpp::string * other_string = stdex::intrusive_get<pycpp::string *>( _other );

        const std::string & other_string_value = other_string->get_value();

        return m_value == other_string_value;
    }
}