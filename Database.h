#ifndef DATABASE_H
#define DATABASE_H
// Database Class: stores all records.
#include <string>
#include "Song.h"

class Database {
private:
    Song *songs; // pointer to the 1st element of array
    int capacity; // total size of array
    int numSongs; // current number of songs in array

public:
    // Constructors
    Database();
    Database(Song *songs, int capacity, int numSongs);
    Database(const Database& other);

    // Destructor
    ~Database();

    //Getters
    int getCapacity() const; // get capacity 
    int getCurrentSize() const; // get current number of songs in playlist

    /* Methods */
    // Adding songs
    void addSong(const Song& song); 

    // Finding songs
    void stringSearch(std::string string); 
    void substringSearch(std::string string);
    void yearSearch(int year);
    void rangeSearch(int year1, int year2);

    // Deleting songs
    void deleteByString(std::string string);
    void deleteBySubString(std::string string);
    void deleteByYear(int year);
    
    //Helpers
    bool songDuplicate(const Song &song);
    bool isValidYear(int year);
    void deleteRecord(int index);
};

#endif //DATABASE_H
