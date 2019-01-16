#pragma once

#include "pycpp/factory.hpp"
#include "pycpp/pool.hpp"

namespace pycpp
{
    template<class Type, uint32_t Count, class F = factory>
    class factory_pool
        : public F
    {
    public:
        factory_pool()
        {
        }

		~factory_pool() override
        {
        }

    protected:
		pointer create_object() override
        {
			F::intrusive_ptr_add_ref( this );

            Type * ptr = m_pool.createT();

			ptr->set_factory( this );

			return ptr;
        }

		void destroy_object( factorable * _factorable ) override
        {
			Type * ptr = static_cast<Type*>(_factorable);

			m_pool.destroyT( ptr );

			F::intrusive_ptr_dec_ref( this );
        }

    protected:
		typedef pycpp::pool<Type, Count> pool_t;
		pool_t m_pool;
    };
    //////////////////////////////////////////////////////////////////////////
}
