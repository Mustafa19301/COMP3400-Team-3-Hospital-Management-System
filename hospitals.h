#ifndef HOSPITALS_H
#define HOSPITALS_H

#include <iostream>
#include <string>
using namespace std;

class Hospitals {
private:
    string Hospital_ID;
    string Location;
    int Capacity;

public:
    //parametrized constructor
    Hospitals(string hospitalid, string section, int cap);

    //functions given from UML Class Diagram
    //function can be either void or double depending on implementation
    //this may not be used (will look into this (minor mistake))
    void Pay (double x, string ID);

    //this function uses void to admit patient
    //exisiting patients and new patients
    void Admit();
};

#endif