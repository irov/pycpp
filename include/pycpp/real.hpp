#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class real
		: public pycpp::object
	{
	public:
		void set_value( float _value )
		{
			m_value = _value;
		}

		float get_value() const
		{
			return m_value;
		}

	public:
		float m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<real> real_ptr;
	//////////////////////////////////////////////////////////////////////////
}