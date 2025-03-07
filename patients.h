#ifndef PATIENTS_H
#define PATIENTS_H

#include <iostream>
#include <string>
using namespace std;

class Patients
{
private:
    string Patient_ID;     // Patient's Identifican Document
    string P_Fname;        // Patient's first name
    string P_Lname;        // Patient's last name
    string P_DOB;          // Patient's Date of birth
    string P_Address;      // Patient's Address
    string P_Phone;        // // String instead of long int since we can just parse it later
    string P_Disease;      // Paitent's Illness
    string P_Treatment;    // Paitent's required treatment
    double P_Payment_Info; // // Should probbaly rename
    double P_Salary;       // // Dont know why we have this one?
    bool P_Checkin;        // Paitent checked in status
    int P_DaysAdmmited;    // Number of days Admmited

public:
    // parametrized constructor
    Patients(string id, string first, string last, string dob, string address, string phone, string illness, string treatment, double paymentInfo, double salary, bool checkedin, int daysAdmmit);

    void Relocate(string id, string P_Disease, string P_Treatment);
    // function to relocate the patient with their sickness info

    void Update_Address(string id, string add);
    void Update_Phone(string id, string phone);
    void Update_Disease(string id, string illness);
    void Update_Treatment(string id, string treat);
    void Update_Payment_Info(string id, double info);
    void Update_Checkin(string id, bool checkedin);
    void Update_DaysAdmmited(string id, int days);
    // funtions to update vars

    void Charge_Patient(string id);
    // funtion to issue a bill to the paitent

    void Attending_Doc(string id);
    // funtion to output the patient's attending doctor
    void Primary_Doc(string id);
    // funtion to output the patient's attending doctor
};

#endif