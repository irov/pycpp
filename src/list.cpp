#include "pycpp/list.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void list::reserve( size_t _size )
    {
        m_elements.reserve( _size );
    }
    //////////////////////////////////////////////////////////////////////////
    void list::append( const pycpp::object_ptr & _object )
    {
        m_elements.emplace_back( _object );
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::object_ptr & list::get( size_t _index ) const
    {
        return m_elements[_index];
    }
    //////////////////////////////////////////////////////////////////////////
    size_t list::size() const
    {
        return m_elements.size();
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::list_ptr list::slice( const pycpp::kernel_ptr & _kernel, size_t _offset ) const
    {
        size_t elements_size = m_elements.size();

        if( _offset >= elements_size )
        {
            return _kernel->make_list( 0 );
        }

        size_t new_size = elements_size - _offset;

        pycpp::list_ptr new_list = _kernel->make_list( new_size );

        for( size_t slice_iterator = _offset; slice_iterator != elements_size; ++slice_iterator )
        {
            const pycpp::object_ptr & element = this->get( slice_iterator );

            new_list->append( element );
        }

        return new_list;
    }
    //////////////////////////////////////////////////////////////////////////
    pycpp::tuple_ptr list::slice_tuple( const pycpp::kernel_ptr & _kernel, size_t _offset ) const
    {
        size_t elements_size = m_elements.size();

        if( _offset >= elements_size )
        {
            return _kernel->make_tuple( 0 );
        }

        size_t new_size = elements_size - _offset;

        pycpp::tuple_ptr new_tuple = _kernel->make_tuple( new_size );

        for( size_t slice_iterator = _offset; slice_iterator != elements_size; ++slice_iterator )
        {
            const pycpp::object_ptr & element = this->get( slice_iterator );

            new_tuple->append( element );
        }

        return new_tuple;
    }
}