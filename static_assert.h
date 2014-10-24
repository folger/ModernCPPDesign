#pragma once

template<bool> struct CTAssert;
template <> struct CTAssert<true> {};
#define STATIC_ASSERT(_b) do {CTAssert<_b> _junk;} while (0)
