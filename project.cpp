// main file
#include "Song.h"
#include "Database.h"
#include "Menu.h"

int main() {
    Database db;
    db.readFromFile("database.txt");
    Menu menu;
    menu.fullMenu();
}

/*
Song s1 = Song("Indie", "K", "CAS", 2013);
std::cout << "(Genre, Song name, Artist, Year)\n"
                                        << "------------------------------\n"
                                        << s1.getGenre()
                                        << ", " << s1.getTitle()
                                        << ", " << s1.getArtist()
                                        << ", " << s1.getYear()
                                        << std::endl;

s1.setArtist("Cigarettes After Sex");
std::cout << "song artist: " << s1.getArtist()<< "\n";

Database db(8);
db.addSong(s1);
db.deleteByString(s1.getArtist());
*/