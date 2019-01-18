#pragma once

#include "pycpp/object.hpp"

#include <vector>

namespace pycpp
{
	class dict
		: public pycpp::object
	{
	public:
		dict();
		~dict() override;

	public:
		void set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object ) override;
		const pycpp::object_ptr & get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
		void del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
		bool has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;

	public:
		struct element_type
		{
			uint32_t hash;
			pycpp::object_ptr key;
			pycpp::object_ptr value;
		};

	protected:
		uint32_t m_size;
		uint32_t m_capacity;

		typedef std::vector<element_type> vector_element_t;
		vector_element_t m_elements;

	protected:
		pycpp::object_ptr hashtable_pop( const pycpp::kernel_ptr & _kernel, uint32_t _capacity, uint32_t _hash, const pycpp::object_ptr & _key );
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<dict> dict_ptr;
	//////////////////////////////////////////////////////////////////////////
}