#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class boolean
		: public pycpp::object
	{
	public:
		void set_value( bool _value )
		{
			m_value = _value;
		}

		bool get_value() const
		{
			return m_value;
		}

	protected:
		bool m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<boolean> boolean_ptr;
	//////////////////////////////////////////////////////////////////////////
}