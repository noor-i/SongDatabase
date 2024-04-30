output: playlist.o Song.o Database.o Menu.o
	g++ playlist.o Song.o Database.o Menu.o -o output

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

Database.o: Database.cpp Database.h
	g++ -c Database.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

playlist.o: playlist.cpp
	g++ -c playlist.cpp

clean:
	rm *.o output