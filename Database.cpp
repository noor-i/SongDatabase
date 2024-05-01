// Database.cpp
#include "Database.h"

//default constructor 
Database::Database() : songs(new Song[30]), capacity(30), numSongs(0) {}

//parameterized constructor
Database::Database(Song *songs, int capacity, int numSongs)
    : songs(new Song[capacity]), capacity(capacity), numSongs(numSongs)
{
    for (int i = 0; i < numSongs; i++) {
        this->songs[i] = songs[i];
    }
}

//copy constructor
Database::Database(const Database& other)
    : songs(new Song[other.capacity]), capacity(other.capacity), numSongs(other.numSongs)
{
    for (int i = 0; i < numSongs; i++) {
        songs[i] = other.songs[i];
    }
}

//capacity constructor
Database::Database(int cap) : songs(new Song[cap]), capacity(cap), numSongs(0) {}

// Destructor
Database::~Database()
{
    delete[] songs;
}

int Database::getCapacity() const
{
    return capacity;
}

int Database::getCurrentSize() const
{
    return numSongs;
}

void Database::printSong(int i){
    std::cout << songs[i].getGenre()
                      << ", " << songs[i].getTitle()
                      << ", " << songs[i].getArtist()
                      << ", " << songs[i].getYear() << std::endl;
}

// Print songs
void Database::printSongs()
{
    std::cout << "(Genre, Song name, Artist, Year)\n"
              << "------------------------------" << std::endl;
    for (int i = 0; i < numSongs; i++)
    {
        std::cout << songs[i].getGenre()
                  << ", " << songs[i].getTitle()
                  << ", " << songs[i].getArtist()
                  << ", " << songs[i].getYear()
                  << std::endl;
    }
}

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
void Database::addSong(const Song &song)
{
    if (numSongs >= capacity)
    {
        capacity *= 2;
        Song *newSongs = new Song[capacity];
        for (int i = 0; i < numSongs; i++)
        {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
    }
    if (songDuplicate(song))
    {
        std::cout << "This song already exists in the playlist." << std::endl;
        return;
    }
    if (!isValidYear(song.getYear()))
    {
        std::cout << "The year is not valid." << std::endl;
        return;
    }
    songs[numSongs] = song;
    numSongs++;
    //std::cout << "Song added!\n"; // confirm song has been added
}

// Checks if a the song exists in the playlist already.
bool Database::songDuplicate(const Song &song)
{
    for (int i = 0; i < numSongs; i++)
    {   
        // Checks regular, lowercase, and uppercase input to match duplicate song entries.
        if ((songs[i].getGenre() == song.getGenre() && 
            songs[i].getTitle() == song.getTitle() &&
            songs[i].getArtist() == song.getArtist() &&
            songs[i].getYear() == song.getYear()) ||

            (convertToLowercase(songs[i].getGenre()) == song.getGenre() &&
            convertToLowercase(songs[i].getTitle()) == song.getTitle() &&
            convertToLowercase(songs[i].getArtist()) == song.getArtist() &&
            songs[i].getYear() == song.getYear()) ||

            (convertToUppercase(songs[i].getGenre()) == song.getGenre() &&
            convertToUppercase(songs[i].getTitle()) == song.getTitle() &&
            convertToUppercase(songs[i].getArtist()) == song.getArtist() &&
            songs[i].getYear() == song.getYear())) 
        {
            return true;
        }
    }
    return false;
}

// Checks if a valid year is used for input.
bool Database::isValidYear(int year)
{
    if (year < 0 || year > 2025)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Read songs from database.txt file into a Database object
void Database::readFromFile(const std::string& filename) {
    std::ifstream myFileStream(filename);
    if (!myFileStream.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
    std::string genre, title, artist;
    int year;

    std::string line, myString;
    while(std::getline(myFileStream, line)){//file:where to look, line: where to store that line 
        std::stringstream ss(line);
        std::getline(ss, genre, ','); 
        std::getline(ss, title, ',');
        std::getline(ss, artist, ',');
        std::getline(ss, myString); 
        year = stoi(myString);
        //std::cout << year << std::endl;
        Song song(genre, title, artist, year);
        addSong(song);
    } 
    //printSongs(songs);
    myFileStream.close(); 
}

// Helper: converts genre, song name, artist name to uppercase for finding songs.
// Note: std::transform takes three iterators and a unary operation as arguments. 
std::string Database::convertToUppercase(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;    
}

// Helper: converts genre, song name, artist name to uppercase for finding songs.
std::string Database::convertToLowercase(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower); 
    return str;
}

/*
(1 mark) When searching for strings, one kind of search should print all
records where the typed-in string from the user exactly matches the
appropriate field of a record.
*/
void Database::genreSearch(std::string string)
{
    bool flag = false;
    for(int i = 0; i < numSongs; i++)
    {
        if (convertToLowercase(songs[i].getGenre()) == string ||
            convertToUppercase(songs[i].getGenre()) == string ||
            songs[i].getGenre() == string)
        {
            printSong(i);
            flag = true;
        }
    }
    if (flag == false)
    {
        std::cout << "No results found." << std::endl;
    }
}

void Database::songNameSearch(std::string string)
{
    bool flag = false;
    for (int i = 0; i < numSongs; i++)
    {
        if (convertToLowercase(songs[i].getTitle()) == string ||
            convertToUppercase(songs[i].getTitle()) == string ||
            songs[i].getTitle() == string)
        {
            printSong(i);
            flag = true;
        }
    }
    if (flag == false)
    {
        std::cout << "No results found." << std::endl;
        
    }
}

void Database::artistSearch(std::string string)
{
    bool flag = false;
    for (int i = 0; i < numSongs; i++)
    {
        if (convertToLowercase(songs[i].getArtist()) == string ||
            convertToUppercase(songs[i].getArtist()) == string ||
            songs[i].getArtist() == string)
        {
            printSong(i);
            flag = true;          
        }
    }
    if (flag == false)
    {
        std::cout << "No results found." << std::endl;
    }
}

/*
(1 mark) When searching for numbers, one kind of search should print all
records where the typed-in number from the user exactly matches the
appropriate field of a record.
*/
void Database::yearSearch(int year)
{
    bool flag = false;
    for (int i = 0; i < numSongs; i++)
    {
        if (songs[i].getYear() == year)
        {
            printSong(i);
            flag = true;
        }
    }
    if (flag == false)
    {
        std::cout << "No results found." << std::endl;
    }
}

/*
(1 mark) When searching for numbers, one kind of search should print all
records where the number of the appropriate field of a record is in a range,
from low to high. This would, for example, let the user see all songs in a
song database from the year 2005 to 2015.
*/
void Database::rangeSearch(int year1, int year2)
{
    bool flag = false;
    for (int i = 0; i < numSongs; i++)
    {
        if (songs[i].getYear() >= year1 && 
            songs[i].getYear() <= year2 )
        {
            printSong(i);
            flag = true;
        }
    }
    if (flag == false)
    {
        std::cout << "No results found." << std::endl;
    }
}

/*
(1 mark) When deleting a record, one way to do this is to search by the
exact string that occurs in a field of the record.
*/
// Helper for delete methods.
void Database::deleteRecord(int index)
{
    if (index < 0 || index >= numSongs)
    {
        std::cout << "Invalid index." << std::endl;
    }
    for (int i = index; i < numSongs - 1; i++)
    { // shift the songs down
        songs[i] = songs[i + 1];
    }
    numSongs--;
}

void Database::deleteByString(const std::string& keyword)
{
    for (int i = 0; i < numSongs;){
        if (songs[i].getGenre() == keyword ||
            songs[i].getTitle() == keyword ||
            songs[i].getArtist() == keyword ||

            convertToLowercase(songs[i].getGenre()) == keyword ||
            convertToLowercase(songs[i].getTitle()) == keyword ||
            convertToLowercase(songs[i].getArtist()) == keyword ||

            convertToUppercase(songs[i].getGenre()) == keyword ||
            convertToUppercase(songs[i].getTitle()) == keyword ||
            convertToUppercase(songs[i].getArtist()) == keyword)
            {
            // Print the song
            printSong(i);

            // Ask the user if they want to delete the song
            std::cout << "\nDo you want to delete the following song? (Y/N)\n";
            std::string input;
            std::cin >> input;
            std::cin.ignore();
            // If the user wants to delete the song, delete it
            if (input == "Y" || input == "y")
            {
                deleteRecord(i);
                std::cout << "Song deleted.\n";
                // Do not increment i, because the next song has been shifted to this index
            }
            else
            {
                std::cout << "Deletion cancelled.\n";
                // Increment i, because we're keeping this song
                ++i;
            }
        }
        else
        {
            // Increment i, because this song doesn't match the keyword
            ++i;
        }
    }
}

/*(1 mark) When deleting a record, one way to do this is to search by the
exact number that occurs in a field of the record.*/
void Database::deleteByYear(int year)
{
    for(int i = 0; i < numSongs;){
        if(songs[i].getYear() == year){
            printSong(i);
            std::cout << "\nDo you want to delete the following song? (Y/N)\n";
            std::string input;
            std::cin >> input;
            std::cin.ignore();

            if(std::cin.fail() || input == "n" || input == "N"){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                std::cout << "\nDeletion cancelled." << std::endl;
                ++i; //increment i only if song has not been deleted
            }
            else if(input == "y" || input == "Y"){
                deleteRecord(i);
                std::cout << "\nSong deleted." << std::endl;
                // not incrementing because next song has been shifted here
            }
        }
        else{
            ++i;
        }
    }
}

/*
(1 mark) When deleting a record, one way to do this is to search for
numbers in a field that appear in a low to high range of numbers.
*/
void Database::deleteByRange(int year1, int year2)
{
std::cout << "In progress...." << std::endl;    
}

/*
For each string field in your record, allow the user to list all
records in alphabetical order.
*/
void Database::swap(Song &song1, Song &song2)
{
    Song temp = song1;
    song1 = song2;
    song2 = temp;
}

void Database::genreAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getGenre() > songs[j + 1].getGenre())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

void Database::artistAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getArtist() > songs[j + 1].getArtist())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

void Database::songNameAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getTitle() > songs[j + 1].getTitle())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

/*
For each string field in your record, allow the user to list all
records in reverse alphabetical order.
*/
void Database::genreRevAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getGenre() < songs[j + 1].getGenre())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

void Database::artistRevAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getArtist() < songs[j + 1].getArtist())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

void Database::songNameRevAlphaOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getTitle() < songs[j + 1].getTitle())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

/*
For each numeric field in your record, allow the user to list all
records in ascending order.
*/
void Database::ascendOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getYear() > songs[j + 1].getYear())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}

/*
For each numeric field in your record, allow the user to list all
records in descending order.
*/
void Database::descendOrder()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = 0; j < numSongs - 1 - i; j++)
        {
            if (songs[j].getYear() < songs[j + 1].getYear())
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
    printSongs();
}