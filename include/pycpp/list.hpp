#pragma once

#include "pycpp/object.hpp"

#include <vector>

namespace pycpp
{
	class list
		: public pycpp::object
	{
	public:
		void push_back( const pycpp::object_ptr & _object )
		{
			m_elements.emplace_back( _object );
		}

		const pycpp::object_ptr & get( size_t _index ) const
		{
			return m_elements[_index];
		}

	protected:
		typedef std::vector< pycpp::object_ptr> vector_element_t;
		vector_element_t m_elements;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<list> list_ptr;
	//////////////////////////////////////////////////////////////////////////
}