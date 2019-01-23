#pragma once

#include "pycpp/object.hpp"

namespace pycpp
{
	class integer
		: public pycpp::object
	{
    public:
        integer();
        ~integer() override;

	public:
        void set_value( int32_t _value );
        int32_t get_value() const;

        
    public:
        std::string to_string( const pycpp::kernel_ptr & _kernel ) const override;

    protected:
        bool op_equal( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const override;
        pycpp::object_ptr op_add( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _other ) const override;

	public:
		int32_t m_value;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<integer> integer_ptr;
	//////////////////////////////////////////////////////////////////////////
}