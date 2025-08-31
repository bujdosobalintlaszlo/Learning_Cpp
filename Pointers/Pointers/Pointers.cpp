// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
int main()
{
    //pointers = variabletaht stores a memory address of another variable sometimes it`s easier to work with an address
    //& - address operatot
    //* - dereference operator
    std::string name = "Name1";

    //pointer for name it should be of the same data type as the variable it`s pointing to
    //naming a pointer starts with p...
    std::string* pName = &name;

    //std::cout << pName; - address will be written on the console
    //std::cout << *pName; - actuall value will be written on the screen, acccessing the value of the address

    int age = 21;
    int* pAge = &age;
    std::string cards[5] = {"Pikatchu","Charizard"};
    std::string *pCards = cards;
}


