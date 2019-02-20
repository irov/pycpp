#pragma once

#include "pycpp/object.hpp"

#include <vector>

namespace pycpp
{
	class tuple
		: public pycpp::object
	{
	public:
        void reserve( size_t _size );

	public:
        void append( const pycpp::object_ptr & _object );

        const pycpp::object_ptr & get( size_t _index ) const;

	protected:
		typedef std::vector<pycpp::object_ptr> vector_element_t;
		vector_element_t m_elements;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<tuple> tuple_ptr;
	//////////////////////////////////////////////////////////////////////////
}