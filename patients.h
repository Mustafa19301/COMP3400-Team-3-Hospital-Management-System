#ifndef PATIENTS_H
#define PATIENTS_H

#include <iostream>
#include <string>
using namespace std;

class Patients
{
private:
    string Patient_ID;  // Patient's Identifican Document
    string P_Fname;     // Patient's first name
    string P_Lname;     // Patient's last name
    string P_DOB;       // Patient's Date of birth
    string P_Address;   // Patient's Address
    string P_Phone;     // // String instead of long int since we can just parse it later
    string P_Disease;   // Paitent's Illness
    string P_Treatment; // Paitent's required treatment
    double P_Billed;    // // Should probbaly rename (rename to P_Billed)
    bool P_Checkin;     // Paitent checked in status
    int P_DaysAdmmited; // Number of days Admmited
    string P_Hospital;  // patient's hospital

public:
    // parametrized constructor
    Patients(string id, string first, string last, string dob, string address, string phone, string illness,
             string treatment, double paymentInfo, bool checkedin, int daysAdmmit, string hospital);
    // update paitent info
    void Update_ID(string id) { Patient_ID = id; }
    void Update_Fname(string fname) { P_Fname = fname; }
    void Update_Lname(string lname) { P_Lname = lname; }
    void Update_DOB(string dob) { P_DOB = dob; }
    void Update_Address(string address) { P_Address = address; }
    void Update_Phone(string phone) { P_Phone = phone; }
    void Update_Disease(string illness) { P_Disease = illness; }
    void Update_Treatment(string treat) { P_Treatment = treat; }
    void Update_Payment_Info(double info) { P_Billed = info; }
    void Update_Checkin(bool checkedin) { P_Checkin = checkedin; }
    void Update_DaysAdmmited(int days) { P_DaysAdmmited = days; }
    void Update_Hospital(string hospital) { P_Hospital = hospital; }
    // get paitent info
    string getID() const { return Patient_ID; }
    string getFname() const { return P_Fname; }
    string getLname() const { return P_Lname; }
    string getDOB() const { return P_DOB; }
    string getAddress() const { return P_Address; }
    string getPhone() const { return P_Phone; }
    string getDisease() const { return P_Disease; }
    string getTreatment() const { return P_Treatment; }
    double getBilled() const { return P_Billed; }
    bool getCheckin() const { return P_Checkin; }
    int getDaysAdmmited() const { return P_DaysAdmmited; }
    string getHospital() const { return P_Hospital; }
    // funtion to issue a bill to the paitent
    void Charge_Patient(string ids);
    // funtion to output patient number and txt gui
    static void Show_Hospital_Occupancy();
    // Patient Management Functionalities 
    static void Discharge_Patient();
    static void Search_Patient();
    static void List_All_Patients();
    static void Update_Patient_Info();
    static void Find_Attending_Doctor();
    static void Find_Primary_Doctor();
    static void Admit_Patient();
    static void Relocate_Patient();
};

#endif