#pragma once

#include "pycpp/allocator.hpp"

#include "stdex/template_pool.h"

namespace pycpp
{
	class pool_allocator_default
	{
	public:
		static void * s_malloc( size_t _size, const char * _doc )
		{
			(void)_doc;

			return malloc( _size );
		}

		static void * s_realloc( void * _mem, size_t _size, const char * _doc )
		{
			(void)_doc;

			return realloc( _mem, _size );
		}

		static void s_free( void * _ptr, const char * _doc )
		{
			(void)_doc;

			return free( _ptr );
		}
	};

	template<class Type, uint32_t Count>
	using pool = stdex::template_pool<Type, Count, pool_allocator_default>;
}
