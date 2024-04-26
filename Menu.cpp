// Menu.cpp
#include "Menu.h"

Menu::Menu(){};

void Menu::displayMainMenu() const{
    std::cout << "Welcome to the Song Database\n" <<
                 "-----------------------------\n" <<
                 "(1) Add a song\n" <<
                 "(2) Find a song\n" <<
                 "(3) Delete a song\n" <<
                 "(4) List songs\n" <<
                 "(5) Quit\n\n" << 
                 "Select your option: " << std::endl;
}

