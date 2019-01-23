#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class boolean
		: public pycpp::object
	{
	public:
        void set_value( bool _value );
        bool get_value() const;

	protected:
		bool m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<boolean> boolean_ptr;
	//////////////////////////////////////////////////////////////////////////
}