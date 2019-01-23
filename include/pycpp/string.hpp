#pragma once

#include "pycpp/object.hpp"

#include <string>

namespace pycpp
{
	class string
		: public pycpp::object
	{
	public:
		void set_value( const std::string & _value );
        const std::string & get_value() const;

    public:
        bool empty() const;

    protected:
        bool op_equal( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const override;

	protected:
		std::string m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<string> string_ptr;
	//////////////////////////////////////////////////////////////////////////
}