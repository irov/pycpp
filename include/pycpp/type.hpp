#pragma once

#include "pycpp/object.hpp"

#include <vector>
#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;
	typedef stdex::intrusive_ptr<class dict> dict_ptr;
	typedef stdex::intrusive_ptr<class scope> scope_ptr;
	typedef stdex::intrusive_ptr<class string> string_ptr;
	
	class type
		: public pycpp::object
	{
    public:
        void set_name( const pycpp::string_ptr & _name );
        const pycpp::string_ptr & get_name() const;

	//public:
 //       void set_call( const pycpp::lambda_call_t & _call );
 //       const pycpp::lambda_call_t & get_call() const;

    public:
        void set_attributes( const pycpp::dict_ptr & _attributes );
        const pycpp::dict_ptr & get_attributes() const;

	public:
		void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object ) override;
		pycpp::object_ptr get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
		void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
		bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;

	protected:
        pycpp::string_ptr m_name;

		//pycpp::lambda_call_t m_call;

		pycpp::dict_ptr m_attributes;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<type> type_ptr;
	//////////////////////////////////////////////////////////////////////////
}