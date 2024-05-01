# 🎹 🎧 Song Database 🎧 🎹
![Main Menu Screenshot](https://github.com/noor-i/SongDatabase/assets/57691234/ec631ed4-b05a-4bf0-b9b2-181e1891170c)




## Description
This project is an Object-Oriented Programming (OOP) implementation of a complex song database system using C++. It allows users to perform operations like searching, sorting, adding, and deleting data. 

The database stores records, each record is comprised of (Genre, Song Name, Artist, and Year).


## Design Layout 
- playlist.cpp: Main file
- Database.h, Database.cpp: Database management
- Menu.h, Menu.cpp: Menu interface
- Song.h, Song.cpp: Song class definition
- Makefile: Compilation configuration
- database.txt: Text file containing database records

## Usage 💻
**Compile the Program:** Use the provided Makefile to compile the program. Open a terminal and navigate to the project directory. Then, run the following commands:
```
$ make
$ ./output
```  
## Features
- Utilizes dynamically allocated arrays instead of vectors
- Cross-platform compatibility (developed on macOS, compiles on Ubuntu Linux)
- Compiled with C++11 standard
- Includes a Makefile for easy compilation and execution

## Additional Features
Here are some of the sub menus that branch off from the main menu.

![Screenshot 2024-05-01 at 2 47 54 AM](https://github.com/noor-i/SongDatabase/assets/57691234/362f26d0-a3d5-4f59-ba6d-c6df47309cf9)

![Screenshot 2024-05-01 at 2 53 11 AM](https://github.com/noor-i/SongDatabase/assets/57691234/b1b12bb5-1c29-47df-8ffc-cb0b65bf1d1f)

*Sample of record formatting:*
```
R&B,Crazy in Love,Beyoncé feat. Jay-Z,2003
Kpop,90's Love,NCTU,2020
```






