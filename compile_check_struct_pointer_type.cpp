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


#define OOBJECT_X_FIELDS \
	X(char, valid) \
	X(char, update) \
	X(char*, bState) \
	X(void*, pOverlapped)


struct	tagOOBJECT {
#pragma push_macro("X")
#define X(type, name) type name;
	OOBJECT_X_FIELDS
#pragma pop_macro("X")
};


#pragma push_macro("X")
	#define X(_type, name)		, std::is_pointer<_type>::type
	static_assert( TrueEnding<std::false_type OOBJECT_X_FIELDS >::value , "" );

#pragma pop_macro("X")

template <int QQ>
class AAAAA
{
	char sz[QQ];
};
