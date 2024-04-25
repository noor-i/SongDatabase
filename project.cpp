// main file
#include "Song.h"
#include "Database.h"
//#include "Menu.h"


int main() {
Song s1 = Song("indie", "K", "CAS", 2013);

std::cout << "song artist: " << s1.getArtist()<< "\n";
std::cout << "song genre: " << s1.getGenre()<< "\n";
std::cout << "song title: " << s1.getTitle()<< "\n";
std::cout << "song year: " << s1.getYear()<< "\n";

s1.setArtist("Cigarettes After Sex");

std::cout << "song artist: " << s1.getArtist()<< "\n";

Database db(8);

db.addSong(s1);
db.deleteByString(s1.getArtist());


}
