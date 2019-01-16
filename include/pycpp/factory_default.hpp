#pragma once

#include "pycpp/factory.hpp"

namespace pycpp
{
    template<class Type>
    class factory_default
        : public factory
    {
    public:
		factory_default()
        {
        }

		~factory_default() override
		{
		}

    protected:
		pointer create_object() override
        {
			stdex::intrusive_ptr_add_ref( this );

			Type * object = new Type();

			object->set_factory( this );

			return object;
        }

		void destroy_object( factorable * _obj ) override
        {
			delete static_cast<Type*>(_obj);

			stdex::intrusive_ptr_dec_ref( this );
        }
    };
}
