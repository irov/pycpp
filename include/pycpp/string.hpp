#pragma once

#include "pycpp/object.hpp"

#include <string>

namespace pycpp
{
	class string
		: public pycpp::object
	{
	public:
		void set_value( const char * _value );
		const char * get_value() const;

	protected:
		std::string m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<string> string_ptr;
	//////////////////////////////////////////////////////////////////////////
}