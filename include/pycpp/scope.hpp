#pragma once

#include "pycpp/factorable.hpp"

#include "pycpp/klass.hpp"
#include "pycpp/string.hpp"

namespace pycpp
{
	class scope
		: public pycpp::factorable
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
	typedef pycpp::intrusive_ptr<scope> scope_ptr;
	//////////////////////////////////////////////////////////////////////////
}