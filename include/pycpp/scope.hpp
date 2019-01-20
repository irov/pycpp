#pragma once

#include "pycpp/object.hpp"

#include "pycpp/string.hpp"

namespace pycpp
{
	class scope
		: public pycpp::object
	{
	public:
        void set_parent( const pycpp::scope_ptr & _parent );
        const pycpp::scope_ptr & get_parent() const;

    public:
        void set_attributes( const pycpp::dict_ptr & _attributes );
        const pycpp::dict_ptr & get_attributes() const;

    public:
        void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value ) override;
        pycpp::object_ptr get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
        void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
        bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;

	protected:
		pycpp::scope_ptr m_parent;

        pycpp::dict_ptr m_attributes;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef pycpp::intrusive_ptr<scope> scope_ptr;
	//////////////////////////////////////////////////////////////////////////
}