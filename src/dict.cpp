#include "pycpp/dict.hpp"

#include "pycpp/kernel.hpp"

namespace pycpp
{	
	//////////////////////////////////////////////////////////////////////////
	dict::dict()
	{
	}
	//////////////////////////////////////////////////////////////////////////
	dict::~dict()
	{
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::set_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _object )
	{

	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::object_ptr & dict::get_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		return pycpp::object_ptr::none();
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::del_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
	{
		if( m_size == 0 )
		{
			return;
		}

		uint32_t hash = _key->hash( _kernel );

		pycpp::object_ptr element = this->hashtable_pop( _kernel, m_capacity, hash, _key );

		--m_size;
	}
	//////////////////////////////////////////////////////////////////////////
	bool dict::has_attr( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr dict::hashtable_pop( const pycpp::kernel_ptr & _kernel, uint32_t _capacity, uint32_t _hash, const pycpp::object_ptr & _key )
	{
		uint32_t hash_mask = _capacity - 1;
		uint32_t mask = _hash;

		for( uint32_t probe = _hash; ; probe >>= 5 )
		{
			element_type & record = m_elements[mask & hash_mask];

			if( record.value == nullptr )
			{
				return nullptr;
			}

			if( record.hash == _hash && _kernel->op_equal( record.key, _key ) )
			{
				pycpp::object_ptr pop_element = record.value;

				record.value.set( reinterpret_cast<pycpp::object *>(~0) );

				return pop_element;
			}

			mask = (mask << 2) + mask + probe + 1;
		}
	}
}