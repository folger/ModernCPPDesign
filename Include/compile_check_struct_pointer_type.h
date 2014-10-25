#pragma once

#include <type_traits>

template<typename T1, typename... Args>
struct TrueEnding
{
	enum
	{
		pointer		= TrueEnding<T1>::pointer,
		value		= pointer ? TrueEnding<Args...>::pointer : TrueEnding<Args...>::value,
	};
};

template<typename T1>
struct TrueEnding <T1>
{
	enum
	{
		pointer		= T1::value,
		value		= true,
	};
};

