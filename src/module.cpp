#include "pycpp/module.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void module::set_name( const pycpp::string_ptr & _name )
    {
        m_name = _name;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::string_ptr & module::get_name()
    {
        return m_name;
    }
}