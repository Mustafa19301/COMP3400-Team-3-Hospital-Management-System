#ifndef PHARMACIES_H
#define PHARMACIES_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Pharmacies {
private:
    string Pharmacies_ID;
    double Pharm_Salary;

public:
    //parametrized constructor
    Pharmacies(string id, double salary);

    static vector<string> pharmacieslist;
    static vector<string> prescriptiondruglist;

    static void createpharmacies();
    static void Bill_Hosp(string hospitalName, string pharmaciesname, string prescriptiondrugname);
    static void Deliver_Meds(string hospitalName, string pharmaciesname, string prescriptiondrugname);
};

#endif