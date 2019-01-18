#pragma once

#include "pycpp/object.hpp"
#include "pycpp/type.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/list.hpp"
#include "pycpp/dict.hpp"

#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;

	class klass
		: public pycpp::object
	{
	public:
		void set_name( const pycpp::string_ptr & _name )
		{
			m_name = _name;
		}

		const pycpp::string_ptr & get_name() const
		{
			return m_name;
		}

	public:
		void add_base( const pycpp::object_ptr & _base )
		{

		}

	protected:
		pycpp::string_ptr m_name;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<klass> klass_ptr;
	//////////////////////////////////////////////////////////////////////////
}