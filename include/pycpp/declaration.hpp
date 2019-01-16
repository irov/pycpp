#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

#include "pycpp/string.hpp"

#include <vector>

namespace pycpp
{
	class declaration
		: public stdex::intrusive_ptr_base
	{
	public:

	protected:
		pycpp::string_ptr m_name;
		
		typedef std::vector<pycpp::string_ptr> vector_attributes_t;
		vector_attributes_t m_attributes;

		pycpp::string_ptr m_args;
		pycpp::string_ptr m_kwds;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<declaration> declaration_ptr;
	//////////////////////////////////////////////////////////////////////////
}