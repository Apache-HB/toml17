#pragma once

#include <cstdint>
#include <cstdio>

#ifndef TOML17_PRINT
#   define TOML17_PRINT(val, line, file) std::printf("[%s:%llu] = %s", file, line, std::to_string(val))
#endif

namespace toml17::detail
{
    template<typename T>
    void mimic_throw(T val, std::uint_fast64_t line, const char* file)
    {
#if TOML17_EXCEPTIONS
        throw val;
#else
        TOML17_PRINT(val, line, file);
        std::abort();
#endif
    }
}