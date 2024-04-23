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

(1 mark) If the record already exists in the database, then you should
tell the user the record already exists and not add a new record.

(1 mark) Don't let the user enter invalid data. For instance, when
entering the year a song was published, if the user enters out-of-range
numbers, like -343 or 2201, then your program should re-ask the user for a
valid number.

(1 mark) If the user enters the wrong type of data, then your program
should re-ask the user for correct data. For instance, when entering the year
a song was published, if the user enters a string like "this year", then your
program should re-ask the user for a valid number.
*/
void Database::addSong(const Song &song){
    if(songDuplicate() == true){
        std::cout << "This song already exists in the playlist." << "\n";
        return;
    }
    if(isValidYear() == true){
        std::cout << "The year is not valid." << "\n";
        return;
    }
}

bool Database::songDuplicate(){
    
}

bool Database::isValidYear(){

}

    /*
    std::string songName;
    std::string artist;
    int year;
    printf("Enter song name: \n");
    std::cin >> songName;
    printf("Enter artist name: \n");
    std::cin >> artist;
    printf("Enter year: \n");
    std::cin >> year;

    printf("New song added!\n");
    */