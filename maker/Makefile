objs = main.o ../UnitTest/maker/WidgetManager.o ../UnitTest/maker/SmartPtr.o
target = test.exe
CC = g++ -Wall -std=c++11

$(target) : $(objs)
	g++ -o $(target) $(objs)

main.o : ../main.cpp
	$(CC) -c ../main.cpp

.PHONY : clean
clean :
	rm $(target) $(objs)
