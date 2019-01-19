#include "pycpp/type.hpp"
#include "pycpp/dict.hpp"

namespace pycpp
{
    //////////////////////////////////////////////////////////////////////////
    void type::set_attributes( const pycpp::dict_ptr & _attributes )
    {
        m_attributes = _attributes;
    }
    //////////////////////////////////////////////////////////////////////////
    const pycpp::dict_ptr & type::get_attributes() const
    {
        return m_attributes;
    }
	//////////////////////////////////////////////////////////////////////////
	void type::set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _name, const pycpp::object_ptr & _object )
	{
		m_attributes->set_element( _kernel, _name, _object );
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::object_ptr & type::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _name ) const
	{
		const pycpp::object_ptr & obj = m_attributes->get_element( _kernel, _name );

		return obj;
	}
	//////////////////////////////////////////////////////////////////////////
	void type::del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _name )
	{
		m_attributes->del_element( _kernel, _name );
	}
	//////////////////////////////////////////////////////////////////////////
	bool type::has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _name ) const
	{
		bool result = m_attributes->has_element( _kernel, _name );

		return result;
	}
}