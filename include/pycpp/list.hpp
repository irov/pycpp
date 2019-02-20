#pragma once

#include "pycpp/object.hpp"
#include "pycpp/tuple.hpp"

#include <vector>

namespace pycpp
{
	class list
		: public pycpp::object
	{
    public:
        void reserve( size_t _size );

	public:
        void append( const pycpp::object_ptr & _object );        
        const pycpp::object_ptr & get( size_t _index ) const;
        size_t size() const;

    public:
        pycpp::list_ptr slice( const pycpp::kernel_ptr & _kernel, size_t _offset ) const;
        pycpp::tuple_ptr slice_tuple( const pycpp::kernel_ptr & _kernel, size_t _offset ) const;

	protected:
		typedef std::vector<pycpp::object_ptr> vector_element_t;
		vector_element_t m_elements;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<list> list_ptr;
	//////////////////////////////////////////////////////////////////////////
}