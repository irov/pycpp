#pragma once

#include "pycpp/intrusive_ptr.hpp"

namespace pycpp
{
    class factory;

    class factorable
        : public intrusive_ptr_base
    {
    public:
        factorable();
        ~factorable() override;

    public:
        void set_factory( factory * _factory );
		inline factory * get_factory() const noexcept;

    private:
        void destroy() override;

    protected:
		factory * m_factory;
    };
    //////////////////////////////////////////////////////////////////////////
    typedef intrusive_ptr<factorable> factorable_ptr;
    //////////////////////////////////////////////////////////////////////////
    inline factory * factorable::get_factory() const noexcept
    {
        return m_factory;
    }
}
