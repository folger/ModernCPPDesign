#pragma once

template<bool> struct CTAssert;
template <> struct CTAssert<true> {char a;};
#define STATIC_ASSERT(_b) do {CTAssert<_b> _junk = {0};++_junk.a;} while (0)

