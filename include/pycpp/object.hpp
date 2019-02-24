#pragma once

#include "pycpp/factorable.hpp"

#include <vector>
#include <functional>

namespace pycpp
{
	typedef intrusive_ptr<class kernel> kernel_ptr;
	typedef intrusive_ptr<class object> object_ptr;
	typedef intrusive_ptr<class scope, class object> scope_ptr;
	typedef intrusive_ptr<class type> type_ptr;
	typedef intrusive_ptr<class list> list_ptr;
	typedef intrusive_ptr<class dict> dict_ptr;
    //////////////////////////////////////////////////////////////////////////
    typedef std::vector<pycpp::object_ptr> vector_objects_t;
	//////////////////////////////////////////////////////////////////////////
	typedef std::function<void( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::object_ptr &, const pycpp::list_ptr &, const pycpp::dict_ptr & )> lambda_call_args_provider_t;
	//////////////////////////////////////////////////////////////////////////
	class object
		: public pycpp::factorable
	{
    public:
        void set_type( const pycpp::type_ptr & _type );
        const pycpp::type_ptr & get_type() const;

	public:
		virtual void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value );
		virtual pycpp::object_ptr get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;
		virtual void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key );
		virtual bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;

    public:
        virtual void set_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value );
        virtual const pycpp::object_ptr & get_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;
        virtual void del_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key );
        virtual bool has_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const;        

	public:
		virtual uint32_t hash( const pycpp::kernel_ptr & _kernel ) const;

    public:
        virtual std::string to_string( const pycpp::kernel_ptr & _kernel ) const;

    public:
        virtual bool op_equal( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const;
        virtual pycpp::object_ptr op_add( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const;

	public:
		virtual pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider );

	protected:
		type_ptr m_type;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<object> object_ptr;
	//////////////////////////////////////////////////////////////////////////
}