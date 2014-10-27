#include <cstdio>
#include "../Include/SmartPtr.h"

class Widget
{
public:
	void PrintMe()
	{
		printf("I am a Widget\n");
	}
};

void test_SmartPtr()
{
	typedef SmartPtr<Widget, NoChecking, SingleThread> WidgetPtr;
	typedef SmartPtr<Widget, EnsureNotNull, SingleThread> SafeWidgetPtr;

	WidgetPtr wp1;
	wp1->PrintMe();
	SafeWidgetPtr wp2;
	wp2->PrintMe();
}
