#pragma once

#include "pycpp/factorable_unique.hpp"
#include "pycpp/factorable.hpp"
#include "pycpp/pointer.hpp"

namespace pycpp
{
    class factory
		: public factorable_unique<factorable>
    {
    public:
		virtual pointer create_object() = 0;
		virtual void destroy_object( factorable * _object ) = 0;
    };
    //////////////////////////////////////////////////////////////////////////
    typedef intrusive_ptr<factory> factory_ptr;
    //////////////////////////////////////////////////////////////////////////
}
