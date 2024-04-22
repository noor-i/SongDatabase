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

    // Methods
    void addSong(const Song &song);
    

};

#endif //DATABASE_H
