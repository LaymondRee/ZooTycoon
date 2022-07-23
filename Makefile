CC=g++
exe_file=program3

$(exe_file): zoo.o animals.o sealion.o tiger.o blackbear.o driver.o
	$(CC) -o $(exe_file) zoo.o animals.o sealion.o tiger.o blackbear.o driver.o
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animals.o: animals.cpp
	$(CC) -c animals.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
blackbear.o: blackbear.cpp
	$(CC) -c blackbear.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
