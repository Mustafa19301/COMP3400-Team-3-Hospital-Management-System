#include "patients.h"

Patients::Patients(string id, string first, string last, string dob, string address, string phone, string illness, string treatment, double paymentInfo, double salary, bool checkedin, int daysAdmmit)
{
    this->Patient_ID = id;
    this->P_Fname = first;
    this->P_Lname = last;
    this->P_DOB = dob;
    this->P_Address = address;
    this->P_Phone = phone;
    this->P_Disease = illness;
    this->P_Treatment = treatment;
    this->P_Payment_Info = paymentInfo;
    
    //fix later
    //this->P_Salary = salary;
    
    this->P_Checkin = checkedin;
    this->P_DaysAdmmited = daysAdmmit;
}

void Patients::Relocate(string id, string P_Disease, string P_Treatment)
{
    if (this->Patient_ID == id)
    {
        // function to relocate the patient with their sickness info
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}

void Patients::Update_Address(string id, string add)
{
    if (this->Patient_ID == id)
    {
        this->P_Address = add;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_Phone(string id, string phone)
{
    if (this->Patient_ID == id)
    {
        this->P_Phone = phone;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_Disease(string id, string illness)
{
    if (this->Patient_ID == id)
    {
        this->P_Disease = illness;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_Treatment(string id, string treat)
{
    if (this->Patient_ID == id)
    {
        this->P_Treatment = treat;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_Payment_Info(string id, double info)
{
    if (this->Patient_ID == id)
    {
        this->P_Payment_Info = info;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_Checkin(string id, bool checkedin)
{
    if (this->Patient_ID == id)
    {
        this->P_Checkin = checkedin;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Update_DaysAdmmited(string id, int days)
{
    if (this->Patient_ID == id)
    {
        this->P_DaysAdmmited = days;
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}

void Patients::Charge_Patient(string id)
{
    if (this->Patient_ID == id)
    {
        // funtion to issue a bill to the paitent
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}

void Patients::Attending_Doc(string id)
{
    // funtion to output the patient's attending doctor
    if (this->Patient_ID == id)
    {
        // cout << "The Attending Doc for this paitent is " << Doctors.get_AttendDoc() << "\n";
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
void Patients::Primary_Doc(string id)
{
    // funtion to output the patient's attending doctor
    if (this->Patient_ID == id)
    {
        // cout << "The Primary Doc for this paitent is " << Doctors.get_PrimeDoc() << "\n";
    }
    else
    {
        cout << "Patient ID does not match with on file\n";
    }
}
