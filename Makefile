objs = a.o compile_check_struct_pointer_type.o
target = test.exe
CC = g++ -std=c++11

$(target) : $(objs)
	g++ -o $(target) $(objs)

compile_check_struct_pointer_type.o : compile_check_struct_pointer_type.cpp
	$(CC) -c compile_check_struct_pointer_type.cpp

a.o : a.cpp static_assert.h
	$(CC) -c a.cpp

.PHONY : clean
clean :
	rm $(target) $(objs)
