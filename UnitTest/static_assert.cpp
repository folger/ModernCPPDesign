#include "../Include/static_assert.h"

template <int QQ, typename T = char>
class AAAAA
{
	T sz[QQ];
};

int test_static_assert()
{
	AAAAA<10> aa;
	AAAAA<10, double> bb;
	STATIC_ASSERT(sizeof(aa) == 10);
	STATIC_ASSERT(sizeof(bb) == 80);
	return 0;
}
