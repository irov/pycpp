#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	typedef stdex::intrusive_ptr<class klass> klass_ptr;

	typedef std::function<void( const pycpp::kernel_ptr &, const pycpp::scope_ptr &, const pycpp::list_ptr &, const pycpp::dict_ptr & )> lambda_call_args_provider_t;

	class instance
		: public pycpp::object
	{
    public:
        void set_klass( const pycpp::klass_ptr & _klass );
        const pycpp::klass_ptr & get_klass() const;

	protected:
		klass_ptr m_klass;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<instance> instance_ptr;
	//////////////////////////////////////////////////////////////////////////
}