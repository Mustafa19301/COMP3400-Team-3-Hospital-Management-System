#ifndef PHARMACIES_H
#define PHARMACIES_H

#include <iostream>
#include <string>
using namespace std;

class Pharmacies {
private:
    string Pharmacies_ID;
    double Pharm_Salary;

public:
    //parametrized constructor
    Pharmacies(string id, double salary);

    //function for billing hospital, this may need some attributes to work
    void Bill_Hosp();

    //functin for delivering prescription drugs
    void Deliver_Meds();
};

#endif