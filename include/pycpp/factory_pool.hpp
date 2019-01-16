#pragma once

#include "pycpp/factory.hpp"

#include "stdex/template_pool.h"

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
			stdex::intrusive_ptr_add_ref( this );

            Type * ptr = m_pool.createT();

			object->set_factory( this );

			return object;
        }

		void destroy_object( factorable * _obj ) override
        {
			Type * ptr = static_cast<Type*>(_obj);

			m_pool.destroyT( ptr );

			stdex::intrusive_ptr_dec_ref( this );
        }

    protected:
        typedef stdex::template_pool<Type, Count> template_pool_t;
		template_pool_t m_pool;
    };
    //////////////////////////////////////////////////////////////////////////
}
