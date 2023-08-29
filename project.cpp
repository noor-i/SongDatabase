// main file
#include <iostream>
#include "Song.h"


int main() {

Song s1;
s1.setTitle("DNA");
s1.setSinger("BTS");
s1.setYear(2017);

std::cout << s1.getSong() << std::endl;
}
