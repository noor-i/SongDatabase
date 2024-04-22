#ifndef DATABASE_H
#define DATABASE_H
// Database Class: stores all records.
#include <string>
#include "Song.h"

class Database {
    Song *songs; // pointer to  the 1st  element of array
    int capacity; // total size of array
    int numSongs; // current number of songs in array

public:
    // Constructors
    Database();
    Database(Song *songs, int capacity, int numSongs);
    // Destructor
    ~Database();

    // Methods
    void addSong(const Song &song);
    //void removeSong(const Song &song);

};

#endif DATABASE_H
