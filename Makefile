CC=g++
exe_file=program4

$(exe_file): room.o event.o wumpus.o bat.o pit.o gold.o driver.o
	$(CC) -o $(exe_file) room.o event.o wumpus.o bat.o pit.o gold.o driver.o
room.o: room.cpp
	$(CC) -c room.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bat.o: bat.cpp
	$(CC) -c bat.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
