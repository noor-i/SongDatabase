output: playlist.o Song.o Database.o Menu.o
	g++ -std=c++11 playlist.o Song.o Database.o Menu.o -o output

Song.o: Song.cpp Song.h
	g++ -std=c++11 -c Song.cpp

Database.o: Database.cpp Database.h
	g++ -std=c++11 -c Database.cpp

Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp

playlist.o: playlist.cpp
	g++ -std=c++11 -c playlist.cpp

clean:
	rm *.o output