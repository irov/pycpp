#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class string
		: public pycpp::object
	{
	public:
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<string> string_ptr;
	//////////////////////////////////////////////////////////////////////////
}