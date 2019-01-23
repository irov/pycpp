#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	typedef stdex::intrusive_ptr<class klass> klass_ptr;

	class instance
		: public pycpp::object
	{
    public:
        void set_klass( const pycpp::klass_ptr & _klass );
        const pycpp::klass_ptr & get_klass() const;

        void set_attributes( const pycpp::dict_ptr & _attributes );
        const pycpp::dict_ptr & get_attributes() const;

    public:
        void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value ) override;
        pycpp::object_ptr get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
        void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
        bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;


	protected:
        pycpp::klass_ptr m_klass;

        pycpp::dict_ptr m_attributes;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<instance> instance_ptr;
	//////////////////////////////////////////////////////////////////////////
}