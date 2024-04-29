// Menu.cpp
#include "Menu.h"

Menu::Menu(){}

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
    if(input == 1 ||input == 2 || input == 3 || input == 4 || input == 5){
        return input;
    }
    else{
        std::cout << "Incorrect selection. Select an option from 1-5.\n" << std::endl;
        return getUserChoice();
    }
}

void Menu::fullMenu()
{
    displayMainMenu();
    int choice = getUserChoice();
    Song newSong;
    std::string genre, songName, artist;
    int year;

    switch (choice)
    {
    case 1:
        std::cout << "Enter the genre: " << std::endl;
        std::cin >> genre;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        std::cout << "Enter song title: "<< std::endl;
        std::getline(std::cin, songName);
        std::cout << "Enter song artist: "<< std::endl;
        std::getline(std::cin, artist);
        std::cout << "Enter song year: "<< std::endl;
        std::cin >> year;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        newSong = Song(genre, songName, artist, year);
        db.addSong(newSong);
        std::cout << "Song added!" << std::endl;
        break;
    case 2:
        subFindMenu();
    default:
        std::cout << "Goodbye!" << std::endl;
        break;
    }
}

void Menu::subFindMenu(){
    std::cout << "\nFind a Song\n" <<
                 "------------\n" <<
                 "You can search by: \n\n" <<
                 "(1) Name of song\n" <<
                 "(2) Name of artist\n" <<
                 "(3) Name of genre\n" <<
                 "(4) Year \n" <<
                 "(5) Year Range (XXXX, YYYY)\n" <<
                 "(6) General search\n" <<
                 "(7) Return to Main Menu\n\n" <<
                 "Select your option: " << std::endl; 
    int choice;
    std::cin >> choice;
    if(choice < 1 || choice > 7){
        std::cout << "That option does not exist, Please try again.";
        return subFindMenu();
    }
    if(choice == 1){
        std::cout << "Enter a song name:\n";
        std::string songName;
        std::cin >> songName;
        db.songNameSearch(songName);
        return subFindMenu();
    }
    if(choice == 2){
        std::cout << "Enter an artist name:\n";
        std::string artistName;
        std::cin >> artistName;
        db.artistSearch(artistName);
        return subFindMenu();
    }
    if(choice == 3){
        std::cout << "Enter a genre name:\n";
        std::string genreName;
        std::cin >> genreName;
        db.genreSearch(genreName);
        return subFindMenu();
    }
    if(choice == 4){
        std::cout << "Enter a year:\n";
        int year;
        std::cin >> year;
        db.yearSearch(year);
        return subFindMenu();
    }
    if(choice == 5){
        std::cout << "To enter a year range, please enter the first year:\n";
        int year1;
        int year2;
        std::cin >> year1;
        std::cout << "Enter the second year:\n";
        std::cin >> year2;
        db.rangeSearch(year1, year2);
        return subFindMenu();
    }
    if(choice == 6){
        std::cout << "Enter any non-numeric keyword:\n";
        std::string substring;
        std::cin >> substring;
        db.substringSearch(substring);
        return subFindMenu();
    }
    else if(choice == 7) {
        fullMenu();
    }
}
