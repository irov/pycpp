#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

#include "pycpp/klass.hpp"
#include "pycpp/string.hpp"

namespace pycpp
{
	class scope
		: public stdex::intrusive_ptr_base
	{
	public:
		void set_attr( const pycpp::string_ptr & _name, const pycpp::object_ptr & _object )
		{

		}

		const pycpp::object_ptr & get_attr( const pycpp::string_ptr & _name ) const
		{
			return pycpp::object_ptr::none();
		}
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<scope> scope_ptr;
	//////////////////////////////////////////////////////////////////////////
}