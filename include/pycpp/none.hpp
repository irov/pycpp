#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class none
		: public pycpp::object
	{
	public:
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<none> none_ptr;
	//////////////////////////////////////////////////////////////////////////
}