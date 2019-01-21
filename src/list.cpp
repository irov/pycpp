#include "pycpp/list.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void list::push_back( const pycpp::object_ptr & _object )
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
}