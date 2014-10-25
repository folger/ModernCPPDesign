#include "../Include/compile_check_struct_pointer_type.h"

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

