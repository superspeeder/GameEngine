#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <Windows.h>
#include <directx/d3d12.h>
#include <directx/d3dx12.h>
#include <dxgi1_6.h>

#include <glm/glm.hpp>

#include <spdlog/spdlog.h>

#include <cassert>

namespace eng
{
    inline std::shared_ptr<spdlog::logger> logger;
}

#define ENG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::eng::logger, __VA_ARGS__)
#define ENG_ERROR(...) SPDLOG_LOGGER_ERROR(::eng::logger, __VA_ARGS__)
#define ENG_WARN(...) SPDLOG_LOGGER_WARN(::eng::logger, __VA_ARGS__)
#define ENG_INFO(...) SPDLOG_LOGGER_INFO(::eng::logger, __VA_ARGS__)
#define ENG_DEBUG(...) SPDLOG_LOGGER_DEBUG(::eng::logger, __VA_ARGS__)
#define ENG_TRACE(...) SPDLOG_LOGGER_TRACE(::eng::logger, __VA_ARGS__)

#define ENG_TRACE_ENTER ENG_TRACE("Enter " __FUNCTION__)
#define ENG_TRACE_EXIT ENG_TRACE("Exit " __FUNCTION__)

#define ENG_EZ_ASSERT_STR(condition) "(" #condition ") == false"

#define ENG_ASSERTC(condition, comment) assert((condition) && (comment))
#define ENG_ASSERT(condition) ENG_ASSERTC((condition),ENG_EZ_ASSERT_STR(condition))

#define ENG_ASSERT_NONNULL(variable) ENG_ASSERTC(((variable) != nullptr), ("(" #variable ") == nullptr"))

#define ENG_WCNAME L"ENG_WC"