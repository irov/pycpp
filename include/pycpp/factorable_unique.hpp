#pragma once

#include "pycpp/allocator.hpp"

namespace pycpp
{
	template<class Base>
	class factorable_unique
		: public Base
		, public allocator<Base>
    {
    public:
        template<class ... Args>
		factorable_unique( Args ... args )
            : Base( args ... )
        {
        }

        ~factorable_unique() override
        {
        }

    public:
        void destroy() override
        {
            delete this;
        }
    };
}
