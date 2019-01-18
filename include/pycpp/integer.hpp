#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class integer
		: public pycpp::object
	{
	public:
		void set_value( int32_t _value )
		{
			m_value = _value;
		}

		int32_t get_value() const
		{
			return m_value;
		}

	public:
		int32_t m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<integer> integer_ptr;
	//////////////////////////////////////////////////////////////////////////
}