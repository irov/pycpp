#pragma once

#include "stdex/intrusive_ptr.h"
#include "stdex/intrusive_ptr_base.h"

namespace pycpp
{
	using intrusive_ptr_base = stdex::intrusive_ptr_base;

	template<class T>
	using intrusive_ptr = stdex::intrusive_ptr<T>;
}