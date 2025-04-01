#ifndef HOSPITALS_H
#define HOSPITALS_H
#include "patients.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// struct Patient {
//     string id, fname, lname, dob, address, phone, disease, treatment;
//     double billed;
//     bool checkin;
//     int daysAdmitted;
//     string hospital;
// };

class Hospitals {
private:
    string Hospital_ID;
    string Location;
    int Capacity;
    map<string, vector<Patients>> hospitalData;

public:
    //parametrized constructor
    Hospitals(string hospitalid, string section, int cap);

    void loadpatients(const string& filename);
    void listpatients();
    void relocatepatient();
    void Pay (double x, string ID);

    //this function uses void to admit patient
    //exisiting patients and new patients
    void Admit();
};

//global variables to access main.cpp and hospitals.cpp
extern Hospitals Windsor;
extern Hospitals Erie;
extern Hospitals Tecumseh;
extern Hospitals Kingsville;
extern Hospitals Amherstburg;

#endif