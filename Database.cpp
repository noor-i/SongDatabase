// Database.cpp
#include "Database.h"

// Constructors
Database::Database(){}

Database::Database(Song *songs, int capacity, int numSongs){
    this->songs = new Song[capacity];
    this->capacity = capacity;
    this->numSongs = 0;
}

// Destructor
Database::~Database(){
    delete[] songs;
}

// Getters
int Database::getCapacity() const{
    return capacity;
}

int Database::getCurrentSize() const{
    return numSongs;
}

// Add a record
/*
(1 mark) When the user chooses to enter a record, then your program asks
them to enter each piece of data in the record. After the user enters valid
data, then your program should say the record has been added, and go back to
the main menu.

******(1 mark) If the record already exists in the database, then you should
tell the user the record already exists and not add a new record.

******(1 mark) Don't let the user enter invalid data. For instance, when
entering the year a song was published, if the user enters out-of-range
numbers, like -343 or 2201, then your program should re-ask the user for a
valid number.

(1 mark) If the user enters the wrong type of data, then your program
should re-ask the user for correct data. For instance, when entering the year
a song was published, if the user enters a string like "this year", then your
program should re-ask the user for a valid number.
*/
void Database::addSong(const Song &song){
    if(songDuplicate(song) == true){
        std::cout << "This song already exists in the playlist." << std::endl;
        return;
    }
    if(isValidYear(song.getYear()) == true){
        std::cout << "The year is not valid." << std::endl;
        return;
    }
    else{
        songs[numSongs] = song;
        numSongs++;
        std::cout << "Song added!" << std::endl;
        return;
    }
}

// Checks if a the song exists in the playlist already.
bool Database::songDuplicate(const Song &song){
    for(int i = 0; i< numSongs; i++){
        if (songs[i].getGenre() == song.getGenre() && 
            songs[i].getTitle() == song.getTitle() &&
            songs[i].getArtist() == song.getArtist() &&
            songs[i].getYear() == song.getYear()){
            return true;
            }
        else{
            return false;
        }
    }
}

// Checks if a valid year is used for input.
bool Database::isValidYear(int year){
    if (year < 0 || year > 2025){
        return false;
    }
    else{
        return true;
    }
}


/*
(1 mark) When searching for strings, one kind of search should print all
records where the typed-in string from the user exactly matches the
appropriate field of a record.
*/
void Database::stringSearch(std::string string){
    for(int i = 0; i< numSongs; i++){
        if(songs[i].getGenre() == string || 
           songs[i].getTitle() == string ||
           songs[i].getArtist() == string){
                std::cout << "Genre: " << songs[i].getGenre() 
                          << " Title: " << songs[i].getTitle()
                          << " Artist: " << songs[i].getArtist()
                          << " Year: " << songs[i].getYear() << std::endl;
            }
        else {
            std::cout << "No results found." << std::endl;
        }
        
    }
}

/*
(1 mark) When searching for strings, one kind of search should print all
records where the typed-in string from the user occurs as a substring in the
appropriate field of a record.
*/
void Database::substringSearch(std::string string){
    
}


void Database::numberSearch(int number){
    return;
}




// Deleting a Record 
/*
(1 mark) When deleting a record, one way to do this is to search by the
exact string that occurs in a field of the record.
(1 mark) When deleting a record, one way to do this is to search for a
substring that occurs in a field of the record.
(1 mark) When deleting a record, one way to do this is to search by the
exact number that occurs in a field of the record.
(1 mark) When deleting a record, one way to do this is to search for
numbers in a field that appear in a low to high range of numbers.
In all cases of deleting records:
    display the searched-for records to the user, and then ask them if they are
    sure they want to delete them

    if no matching records are found, then print a helpful message to the screen
    telling the user this
void Database::deleteSong(const Song& song){
    
}
*/
