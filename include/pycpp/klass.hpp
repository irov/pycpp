#pragma once

#include "pycpp/object.hpp"
#include "pycpp/type.hpp"
#include "pycpp/scope.hpp"
#include "pycpp/list.hpp"
#include "pycpp/dict.hpp"
#include "pycpp/function.hpp"

#include <functional>

namespace pycpp
{
	typedef stdex::intrusive_ptr<class kernel> kernel_ptr;

	class klass
		: public pycpp::object
	{
	public:
        void set_name( const pycpp::string_ptr & _name );
        const pycpp::string_ptr & get_name() const;

	public:
        void add_base( const pycpp::object_ptr & _base );

    public:
        void set_function( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::function_ptr & _function );

    protected:
        pycpp::object_ptr call( const pycpp::kernel_ptr & _kernel, const pycpp::scope_ptr & _scope, const pycpp::object_ptr & _self, const lambda_call_args_provider_t & _argsProvider ) override;

	protected:
		pycpp::string_ptr m_name;

        typedef std::vector<pycpp::object_ptr> vector_base_t;
        vector_base_t m_bases;

        struct function_desc_t
        {
            pycpp::object_ptr key;
            pycpp::function_ptr function;
        };

        typedef std::vector<function_desc_t> vector_function_desc_t;
        vector_function_desc_t m_functions;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<klass> klass_ptr;
	//////////////////////////////////////////////////////////////////////////
}