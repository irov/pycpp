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
		void set_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value ) override;
		const pycpp::object_ptr & get_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;
		void del_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) override;
		bool has_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const override;

	public:
		struct element_type
		{
			uint32_t hash;
			pycpp::object_ptr key;
			pycpp::object_ptr value;
		};

	protected:
		uint32_t m_size;

		typedef std::vector<element_type> vector_element_t;
		vector_element_t m_elements;

	protected:
		void hashtable_push( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value );
		const pycpp::object_ptr & hashtable_find( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key ) const;
		bool hashtable_exist( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key ) const;
		pycpp::object_ptr hashtable_pop( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key );
		void hashtable_increase( const pycpp::kernel_ptr & _kernel );
		void hashtable_create( const pycpp::kernel_ptr & _kernel, uint32_t _capacity );
		void hashtable_rebalance( const pycpp::kernel_ptr & _kernel, uint32_t _capacity );
	};
	//////////////////////////////////////////////////////////////////////////
	typedef stdex::intrusive_ptr<dict> dict_ptr;
	//////////////////////////////////////////////////////////////////////////
}