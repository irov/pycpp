#pragma once

#include "pycpp/intrusive_ptr.hpp"

namespace pycpp
{
	//////////////////////////////////////////////////////////////////////////
	template<class T>
	class pointer_t
	{
	public:
		pointer_t( std::nullptr_t )
			: m_pointer( nullptr )
		{
		}

		pointer_t( T * _pointer )
			: m_pointer( _pointer )
		{
		}

		pointer_t( const pointer_t & _pointer )
			: m_pointer( _pointer.m_pointer )
		{
		}

	public:
		pointer_t & operator = ( const pointer_t & _pointer )
		{
			this->m_pointer = _pointer.m_pointer;

			return *this;
		}

	public:
		operator T * () const
		{
			return m_pointer;
		}

		template<class U>
		operator U * () const
		{
			U * t = static_cast<U *>(m_pointer);

			return t;
		}

	protected:
		T * m_pointer;
	};
	//////////////////////////////////////////////////////////////////////////
	template<class T>
	class pointer_t<intrusive_ptr<T> >
	{
	public:
		pointer_t( std::nullptr_t )
		{
		}

		pointer_t( T * _pointer )
			: m_pointer( _pointer )
		{
		}

		pointer_t( const pointer_t & _pointer )
			: m_pointer( _pointer.m_pointer )
		{
		}

		pointer_t( const intrusive_ptr<T> & _pointer )
			: m_pointer( _pointer )
		{
		}

		template<class U>
		pointer_t( const intrusive_ptr<U> & _pointer )
			: m_pointer( _pointer )
		{
		}

	public:
		operator intrusive_ptr<T>() const
		{
			return m_pointer;
		}

		template<class U>
		operator intrusive_ptr<U>() const
		{
			return intrusive_ptr<U>( m_pointer );
		}

	protected:
		intrusive_ptr<T> m_pointer;
	};
	//////////////////////////////////////////////////////////////////////////
	typedef pointer_t<void> pointer;
	//////////////////////////////////////////////////////////////////////////
}
