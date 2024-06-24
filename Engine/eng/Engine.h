#pragma once

#include "eng/framework.h"

namespace eng
{
    class Engine
    {
    public:
        Engine(HINSTANCE hInstance, int nCmdShow);
        ~Engine();

        [[nodiscard]] HINSTANCE getInstanceHandle() const
        {
            return m_InstanceHandle;
        }

        [[nodiscard]] int getCmdShow() const
        {
            return m_CmdShow;
        }

    private:
        HINSTANCE m_InstanceHandle;
        int m_CmdShow;
    };

    extern Engine* engine;

    void init(HINSTANCE hInstance, int nCmdShow);

    __forceinline void init()
    {
        init(GetModuleHandleW(nullptr), SW_NORMAL);
    }

    void terminate();
}
