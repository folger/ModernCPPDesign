#include "../Include/CreatePolicy.h"
#include <string>

class Widget
{
public:
	Widget()
	{
		printf("Widget::Widget\n");
	}
	~Widget()
	{
		printf("Widget::~Widget\n");
	}
	Widget* Clone()
	{
		printf("Widget::Clone\n");
		return new Widget;
	}
	void Destroy()
	{
		printf("Widget::Destroy\n");
		delete this;
	}
private:
	std::string msg_;
};

template <template <class> class CreatePolicy = OpNewCreator>
class WidgetManager : public CreatePolicy<Widget>
{
};

void test_WidgetManager()
{
	WidgetManager<OpNewCreator> widgetMngr1;
	Widget* pWidget1 = widgetMngr1.Create();
	widgetMngr1.Destroy(pWidget1);

	WidgetManager<MallocCreator> widgetMngr2;
	Widget* pWidget2 = widgetMngr2.Create();
	widgetMngr2.Destroy(pWidget2);

	Widget* pWidgetPrototype = new Widget;
	WidgetManager<PrototypeCreator> widgetMngr3;
	widgetMngr3.SetPrototype(pWidgetPrototype);
	Widget* pWidget3 = widgetMngr3.Create();
	widgetMngr3.Destroy(pWidget3);
	delete pWidgetPrototype;
}
