
all: yuan

yuan: human.o yuan.o
	g++ -Wall -o yuan human.o yuan.o



human.o: human.cpp
	g++ -Wall -c human.cpp

yuan.o: yuan.cpp
	g++ -Wall -c yuan.cpp

clean:
	rm yuan.o
