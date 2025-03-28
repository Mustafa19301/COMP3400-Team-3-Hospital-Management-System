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

    //function for billing hospital, this may need some attributes to work

    //billing will be given until the patient is treated and discharged
    //follows the same path as the patients fee using random generator
    //random generator should not be giving random values (use seed to fix the issue)

    //once the pharmacy bill directly to the hospital, the hopsital would then have to pay them back
    //following the same path that uses the random generator (seed) to pay the pharmacy back

    //functin for delivering prescription drugs

    //connection with the hopsital to ask for prescription drugs as it will be delivered to them
    //general prescription drugs (nothing too complicated)
};

#endif