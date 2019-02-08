Exc: main.o Executive.o course.o
	g++ -std=c++11 -g -Wall main.o Executive.o course.o -o Exc

main.o: main.cpp Executive.h Executive.cpp course.h course.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h course.h course.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

course.o: course.h 
	g++ -std=c++11 -g -Wall -c course.cpp

clean: 
	rm *.o Exc


