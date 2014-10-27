objs = static_assert.o compile_check_struct_pointer_type.o WidgetManager.o SmartPtr.o
CC = g++ -Wall -std=c++11

all : $(objs)

static_assert.o : ../static_assert.cpp ../../Include/static_assert.h
	$(CC) -c ../static_assert.cpp

compile_check_struct_pointer_type.o : ../compile_check_struct_pointer_type.cpp ../../Include/compile_check_struct_pointer_type.h
	$(CC) -c ../compile_check_struct_pointer_type.cpp

WidgetManager.o : ../WidgetManager.cpp ../../Include/CreatePolicy.h
	$(CC) -c ../WidgetManager.cpp

SmartPtr.o : ../SmartPtr.cpp ../../Include/SmartPtr.h
	$(CC) -c ../SmartPtr.cpp

.PHONY : clean
clean :
	rm $(objs)
