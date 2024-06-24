// Engine.cpp : Defines the functions for the static library.
//

#include "eng/pch.h"
#include "eng/Engine.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace eng
{
    Engine* engine;

    LRESULT CALLBACK globalWindowProc(_In_ HWND hWnd, _In_ UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam);

    Engine::Engine(HINSTANCE hInstance, int nCmdShow) : m_InstanceHandle(hInstance), m_CmdShow(nCmdShow)
    {
        ENG_TRACE_ENTER;

        WNDCLASSEXW wc{};
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.cbSize = sizeof(wc);
        wc.lpszClassName = ENG_WCNAME;
        wc.lpfnWndProc = globalWindowProc;
        wc.hbrBackground = reinterpret_cast<HBRUSH>((COLOR_BACKGROUND + 1));
        wc.hInstance = m_InstanceHandle;
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        wc.hIcon = LoadIconW(m_InstanceHandle, IDI_APPLICATION);

        ENG_ASSERTC(RegisterClassExW(&wc) != 0, "Failed to register window class.");


        ENG_TRACE_EXIT;
    }

    Engine::~Engine()
    {
        ENG_TRACE_ENTER;
        ENG_TRACE_EXIT;
    }

    void init(HINSTANCE hInstance, int nCmdShow)
    {
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        logger = std::make_shared<spdlog::logger>("engine", spdlog::sinks_init_list{stdout_sink});

        /// trace enter as soon as we actually have a logger made. any calls to use the logger will fail before this
        ENG_TRACE_ENTER;
        ENG_ASSERT_NONNULL(hInstance);
        ENG_ASSERTC(0 <= nCmdShow && nCmdShow <= SW_MAX, "Invalid enum value for ShowWindow");
        ENG_ASSERTC(engine == nullptr, "Engine shouldn't be initialized more than once.");

        engine = new Engine(hInstance, nCmdShow);

        ENG_TRACE_EXIT;
    }

    void terminate()
    {
        ENG_TRACE_ENTER;
        delete engine;
        engine = nullptr;
        ENG_TRACE_EXIT;
    }

    LRESULT CALLBACK globalWindowProc(_In_ HWND hWnd, _In_ UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
    {
        return DefWindowProcW(hWnd, msg, wParam, lParam);
    }
}
