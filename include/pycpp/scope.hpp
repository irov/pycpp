#pragma once

#include "pycpp/object.hpp"

#include "pycpp/string.hpp"

namespace pycpp
{
	class scope
		: public pycpp::object
	{
	public:
		void set_parent( const pycpp::scope_ptr & _parent )
		{
			m_parent = _parent;
		}

	protected:
		pycpp::scope_ptr m_parent;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef pycpp::intrusive_ptr<scope> scope_ptr;
	//////////////////////////////////////////////////////////////////////////
}