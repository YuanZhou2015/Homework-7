
all: yuan

yuan:earthquake.o station.o yuan.o

yuan: earthquake.o station.o yuan.o
	g++ -Wall -o yuan earthquake.o station.o yuan.o

earthquake.o: earthquake.cpp
	g++ -Wall -c earthquake.cpp

station.o: station.cpp
	g++ -Wall -c station.cpp

yuan.o: yuan.cpp
	g++ -Wall -c yuan.cpp

clean:
	rm yuan.o
