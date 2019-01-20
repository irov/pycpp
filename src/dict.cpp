#include "pycpp/dict.hpp"

#include "pycpp/kernel.hpp"

namespace pycpp
{	
	//////////////////////////////////////////////////////////////////////////
	dict::dict()
        : m_size( 0 )
	{
	}
	//////////////////////////////////////////////////////////////////////////
	dict::~dict()
	{
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::set_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value )
	{
		uint32_t capacity = m_elements.size();

		uint32_t test_size = m_size * 3 + 1;
		uint32_t test_capacity = capacity * 2;
		if( test_size > test_capacity )
		{
			this->hashtable_increase( _kernel );
		}

		uint32_t hash = _key->hash( _kernel );

		this->hashtable_push( _kernel, hash, _key, _value );

		++m_size;
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::object_ptr & dict::get_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		if( m_size == 0 )
		{
			return pycpp::object_ptr::none();
		}

		uint32_t hash = _key->hash( _kernel );

		const pycpp::object_ptr & element = this->hashtable_find( _kernel, hash, _key );

		return element;
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::del_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key )
	{
		if( m_size == 0 )
		{
			return;
		}

		uint32_t hash = _key->hash( _kernel );

		pycpp::object_ptr element = this->hashtable_pop( _kernel, hash, _key );

		--m_size;
	}
	//////////////////////////////////////////////////////////////////////////
	bool dict::has_element( const pycpp::kernel_ptr & _kernel, const pycpp::object_ptr & _key ) const
	{
		if( m_size == 0 )
		{
			return false;
		}

		uint32_t hash = _key->hash( _kernel );

		bool result = this->hashtable_exist( _kernel, hash, _key );

		return result;
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::hashtable_push( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key, const pycpp::object_ptr & _value )
	{
		uint32_t capacity = m_elements.size();
		uint32_t hash_mask = capacity - 1;
		uint32_t mask = _hash;

		for( uint32_t probe = _hash; ; probe >>= 5 )
		{
			element_type & record = m_elements[mask & hash_mask];

			if( record.value == nullptr || record.value.get() == reinterpret_cast<const pycpp::object *>(~0) )
			{
				record.hash = _hash;
				record.key = _key;
				record.value = _value;

				break;
			}

			mask = (mask << 2) + mask + probe + 1;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	const pycpp::object_ptr & dict::hashtable_find( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key ) const
	{
		uint32_t capacity = m_elements.size();
		uint32_t hash_mask = capacity - 1;
		uint32_t mask = _hash;

		for( uint32_t probe = _hash; ; probe >>= 5 )
		{
			const element_type & record = m_elements[mask & hash_mask];

			if( record.value == nullptr )
			{
				return pycpp::object_ptr::none();
			}

			if( record.hash == _hash && _kernel->op_equal( record.key, _key ) )
			{
				if( record.value.get() == reinterpret_cast<const pycpp::object *>(~0) )
				{
					return pycpp::object_ptr::none();
				}

				return record.value;
			}

			mask = (mask << 2) + mask + probe + 1;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	bool dict::hashtable_exist( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key ) const
	{
		uint32_t capacity = m_elements.size();
		uint32_t hash_mask = capacity - 1;
		uint32_t mask = _hash;

		for( uint32_t probe = _hash; ; probe >>= 5 )
		{
			const element_type & record = m_elements[mask & hash_mask];

			if( record.value == nullptr )
			{
				return false;
			}

			if( record.hash == _hash && _kernel->op_equal( record.key, _key ) )
			{
				if( record.value.get() == reinterpret_cast<const pycpp::object *>(~0) )
				{
					return false;
				}

				return true;
			}

			mask = (mask << 2) + mask + probe + 1;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	pycpp::object_ptr dict::hashtable_pop( const pycpp::kernel_ptr & _kernel, uint32_t _hash, const pycpp::object_ptr & _key )
	{
		uint32_t capacity = m_elements.size();
		uint32_t hash_mask = capacity - 1;
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
	//////////////////////////////////////////////////////////////////////////
	void dict::hashtable_increase( const pycpp::kernel_ptr & _kernel )
	{
		if( m_elements.empty() == true )
		{			
			this->hashtable_create( _kernel, 8 );

			return;
		}

		uint32_t old_capacity = m_elements.capacity();

		uint32_t new_capacity = (old_capacity << 1);

		this->hashtable_rebalance( _kernel, new_capacity );
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::hashtable_create( const pycpp::kernel_ptr & _kernel, uint32_t _capacity )
	{
		m_elements.resize( _capacity );

		for( uint32_t index = 0; index != _capacity; ++index )
		{
			element_type & record = m_elements[index];

			record.hash = 0;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	void dict::hashtable_rebalance( const pycpp::kernel_ptr & _kernel, uint32_t _capacity )
	{
		uint32_t old_capacity = m_elements.size();

		vector_element_t old_elements;
		m_elements.swap( old_elements );

		for( uint32_t index = 0; index != old_capacity; ++index )
		{
			element_type & record = old_elements[index];

			if( record.value == nullptr || record.value.get() == reinterpret_cast<const pycpp::object *>(~0) )
			{
				continue;
			}

			this->hashtable_push( _kernel, record.hash, record.key, record.value );
		}
	}
}