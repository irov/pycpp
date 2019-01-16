#pragma once

#include <memory.h>

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	template<class T>
	class allocator
	{
	public:
		inline void * operator new (size_t _size)
		{
			return malloc( _size );
		}

		inline void operator delete (void * _ptr, size_t _size)
		{
			(void)_size;

			free( _ptr );
		}

		inline void * operator new []( size_t _size )
		{
			return malloc( _size );
		}

			inline void operator delete []( void * _ptr, size_t _size )
		{
			(void)_size;

			free( _ptr );
		}
	};
}