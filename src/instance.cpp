#include "pycpp/instance.hpp"
#include "pycpp/type.hpp"
#include "pycpp/kernel.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void instance::set_klass( const pycpp::klass_ptr & _klass )
    {
        m_klass = _klass;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::klass_ptr & instance::get_klass() const
    {
        return m_klass;
    }
}