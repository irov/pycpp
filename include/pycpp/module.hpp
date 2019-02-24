#pragma once

#include "pycpp/scope.hpp"

namespace pycpp
{
	class module
		: public pycpp::scope
	{
	public:
        void set_name( const pycpp::string_ptr & _name );
        const pycpp::string_ptr & get_name();

    protected:
        pycpp::string_ptr m_name;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<module> module_ptr;
	//////////////////////////////////////////////////////////////////////////
}