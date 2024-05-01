// Menu.cpp
#include "Menu.h"

Menu::Menu(Database &db):db(db){}

void Menu::displayMainMenu() const{
    std::cout << "\nWelcome to the Song Database\n" <<
                 "-----------------------------\n" <<
                 "(1) Add a song\n" <<
                 "(2) Find a song\n" <<
                 "(3) Delete a song\n" <<
                 "(4) List songs\n" <<
                 "(5) Quit\n\n" << 
                 "Select your option: " << std::endl;
}

int Menu::getUserChoice() const{
    int input;
    std::cin >> input;
    if (std::cin.fail() || input < 1 || input > 5) {
        std::cin.clear();  // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer 
        std::cout << "\nThat option does not exist. Please select from 1-5.\n\n";
        return getUserChoice();
    }
    else{
        std::cin.ignore();
        return input;
    }
}

void Menu::fullMenu()
{
    displayMainMenu();
    int choice = getUserChoice();

    switch (choice)
    {
    case 1:
        addMenu();
        break;
    case 2:
        findMenu();
        break;
    case 3:
        deleteMenu();
        break;
    case 4:
        listMenu();
        break;
    default:
        std::cout << "\nGoodbye!" << std::endl;
        break;
    }
}

void Menu::addMenu(){
    Song newSong;
    std::string genre, songName, artist;
    int year;
    std::cout << "\nEnter the genre: \n";
    std::cin >> genre;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "Enter song title: \n";
    std::getline(std::cin, songName);

    std::cout << "Enter song artist: \n";
    std::getline(std::cin, artist);

    std::cout << "Enter song year: \n";;
    while (!(std::cin >> year) || !db.isValidYear(year)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid year. Please re-enter a year: \n";
    }

    newSong = Song(genre, songName, artist, year);
    db.addSong(newSong);
    std::cout << "Song added!\n" << std::endl;
    fullMenu();
}

void Menu::findMenu(){
    std::cout << "\nFind a Song\n" <<
                 "------------\n" <<
                 "You can search by: \n\n" <<
                 "(1) Name of song\n" <<
                 "(2) Name of artist\n" <<
                 "(3) Name of genre\n" <<
                 "(4) Year \n" <<
                 "(5) Year Range (XXXX, YYYY)\n" <<
                 "(6) Return to Main Menu\n\n" <<
                 "Select your option: " << std::endl; 
    int choice;
    std::cin >> choice;
    std::cin.ignore();  // Ignore the newline character
    if(std::cin.fail() || choice < 1 || choice > 7){
        std::cin.clear(); // clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        std::cout << "\nThat option does not exist, Please try again.\n\n";
        return findMenu();
    }
    if(choice == 1){
        std::cout << "\nEnter a song name:\n";
        std::string songName;
        std::getline(std::cin, songName);
        std::cout << "--------------\n";
        db.songNameSearch(songName);
        return findMenu();
    }
    if(choice == 2){
        std::cout << "\nEnter an artist name:\n";
        std::string artistName;
        std::getline(std::cin, artistName);
        std::cout << "--------------\n";
        db.artistSearch(artistName);
        return findMenu();
    }
    if(choice == 3){
        std::cout << "\nEnter a genre name:\n";
        std::string genreName;
        std::getline(std::cin, genreName);
        std::cout << "--------------\n";
        db.genreSearch(genreName);
        return findMenu();
    }
    if(choice == 4){
        std::cout << "\nEnter a year:\n";
        int year;
        std::cin >> year;
        std::cin.ignore();  // Ignore the newline character
        std::cout << "--------------\n";
        db.yearSearch(year);
        return findMenu();
    }
    if(choice == 5){
        std::cout << "\nTo enter a year range, please enter the first year:\n";
        int year1;
        int year2;
        std::cin >> year1;
        std::cin.ignore();  // Ignore the newline character
        std::cout << "Enter the second year:\n";
        std::cin >> year2;
        std::cin.ignore();  // Ignore the newline character
        std::cout << "--------------\n";
        db.rangeSearch(year1, year2);
        return findMenu();
    }
    else if(choice == 6) {
        fullMenu();
    }
}

void Menu::deleteMenu(){
    std::cout << "\nDelete by:\n" <<
                 "---------------\n" <<
                 "(1) Keyword\n" <<
                 "(2) Year\n" <<
                 "(3) Year Range (XXXX, YYYY)\n" <<
                 "(4) Main Menu\n" << std::endl;
    int input;
    std::cin >> input;

    if(std::cin.fail() || input < 1 || input > 4){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        std::cout << "\nThat option does not exist, Please try again.\n\n";
        deleteMenu();
    }
    if(input == 1){
        std::cout << "\nEnter a Genre, Song name, or Artist:\n" << std::endl;
        std::string keyword;

        while(!(std::cin >> keyword)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "\nPlease try again.\n\n";
        }
        db.deleteByString(keyword);
        deleteMenu();
    }
    if(input == 2){
        std::cout << "\nEnter a Year:\n" << std::endl;
        int year;

        if(!(std::cin >> year)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "\nNot a valid year. Please try again.\n\n";
            deleteMenu();
        }
        db.deleteByYear(year);
        deleteMenu();
    } 
    if(input == 3){
        std::cout << "\nEnter the first year of the range:\n";
        int year1, year2;
        std::cin >> year1;
        std::cin.ignore();

        std::cout << "\nEnter the second year of the range:\n";
        std::cin >> year2;
        std::cin.ignore();

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "\nPlease try again.\n\n";
            deleteMenu();
        }
        db.deleteByRange(year1, year2);
        deleteMenu();
    }
    else if(input == 4){
        fullMenu();
    }   
}

void Menu::listMenu(){
    std::cout << "\nListing songs\n" <<
                 "------------\n" <<
                 "You can sort songs by: \n\n" <<
                 "(1) Genre\n" <<
                 "(2) Song name\n" <<
                 "(3) Artist\n" <<
                 "(4) Year \n" <<
                 "(5) Return to Main Menu\n\n" <<
                 "Select your option: " << std::endl; 
    int choice;
    std::cin >> choice;
    std::cin.ignore();  // Ignore the newline character
    if (std::cin.fail() || choice < 1 || choice > 5) {
        std::cin.clear();  // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        std::cout << "\nThat option does not exist, Please try again.\n\n";
        return listMenu();
    }
    if(choice == 1){
        subListGenreMenu();          
    }
    if(choice == 2){
        subListSongNameMenu(); 
    }   
    if(choice == 3){
        subListArtistMenu();
    } 
    if(choice == 4){
        subListYearMenu(); 
    }
    else if(choice == 5){
        fullMenu();
    }
}

void Menu::subListGenreMenu(){
    std::cout << "\nSort Genres by:\n" <<
                     "-----------------\n" <<
                     "(1) Alphabetical Order\n" <<
                     "(2) Reverse Alphabetical Order\n" <<
                     "(3) Go back\n\n" <<
                     "Select your option: " << std::endl; 

                    int input;
                    std::cin >> input;
                    std::cin.ignore();  // Ignore the newline character
                    if(std::cin.fail() || input < 1 || input > 3){
                        std::cin.clear(); // clear the fail state
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                        std::cout << "\nThat option does not exist, Please try again.\n\n";
                        return subListGenreMenu();
                    }
                    if(input == 1){
                        db.genreAlphaOrder();
                        listMenu();
                    }
                    if(input == 2){
                        db.genreRevAlphaOrder();
                        listMenu();
                    }
                    else if(input == 3){
                        listMenu();
                    }  
}

void Menu::subListSongNameMenu(){
    std::cout << "\nSort Song names by:\n" <<
                     "-----------------\n" <<
                     "(1) Alphabetical Order\n" <<
                     "(2) Reverse Alphabetical Order\n" <<
                     "(3) Go back\n\n" <<
                     "Select your option: " << std::endl; 

                    int input;
                    std::cin >> input;
                    std::cin.ignore();  // Ignore the newline character
                    if(std::cin.fail() || input < 1 || input > 3){
                        std::cin.clear(); // clear the fail state
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                        std::cout << "\nThat option does not exist, Please try again.\n\n";
                        return subListSongNameMenu();
                    }
                    if(input == 1){
                        db.songNameAlphaOrder();
                        listMenu();
                    }
                    if(input == 2){
                        db.songNameRevAlphaOrder();
                        listMenu();
                    }
                    else if(input == 3){
                        listMenu();
                    }  
}

void Menu::subListArtistMenu(){
    std::cout << "\nSort Artists by:\n" <<
                     "------------------\n" <<
                     "(1) Alphabetical Order\n" <<
                     "(2) Reverse Alphabetical Order\n" <<
                     "(3) Go back\n\n" <<
                     "Select your option: " << std::endl;  

                    int input;
                    std::cin >> input;
                    std::cin.ignore();  // Ignore the newline character
                    if(std::cin.fail() || input < 1 || input > 3){
                        std::cin.clear(); // clear the fail state
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the bad input
                        std::cout << "\nThat option does not exist, Please try again.\n\n";
                        return subListArtistMenu();
                    }
                    if(input == 1){
                        db.artistAlphaOrder();
                        listMenu();
                    }
                    if(input == 2){
                        db.artistRevAlphaOrder();
                        listMenu();
                    }
                    else if(input == 3){
                        listMenu();
                    }  
}

void Menu::subListYearMenu(){
    std::cout << "\nSort Years by:\n" <<
                     "-----------------\n" <<
                     "(1) Ascending Order\n" <<
                     "(2) Descending Order\n" <<
                     "(3) Go back\n\n" <<
                     "Select your option: " << std::endl;

                    int input;
                    std::cin >> input;
                    std::cin.ignore();  // Ignore the newline character
                    if(std::cin.fail() || input < 1 || input > 3){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\nThat option does not exist, Please try again.\n\n";
                        return subListYearMenu();
                    }
                    if(input == 1){
                        db.ascendOrder();
                        listMenu();
                    }
                    if(input == 2){
                        db.descendOrder();
                        listMenu();
                    }
                    else if(input == 3){
                        listMenu();
                    }  
}