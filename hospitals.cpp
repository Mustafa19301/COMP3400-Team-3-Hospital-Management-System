#include "hospitals.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// parametrized constructor called here
Hospitals::Hospitals(string hospitalid, string section, int cap) : Hospital_ID(hospitalid), Location(section), Capacity(cap)
{
    this->Hospital_ID = hospitalid;
    this->Location = section;
    this->Capacity = cap;
}

/*
Auth: Spondon: OG:Mustafa & at bottom
Reason: new one loads them dynamically so one hospital isnt overloaded
        and makes it so if a paitent is already in a hospital it doesnt go to dynamic
*/
void Hospitals::loadpatients(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Cannot open file " << filename << "\n";
        return;
    }

    string line;
    map<string, int> hospitalCounts = {
        {"Windsor Regional Hospital", 0},
        {"Erie Shore Regional Hospital", 0},
        {"Tecumseh Regional Hospital", 0},
        {"Kingsville Regional Hospital", 0},
        {"Amherstburg Regional Hospital", 0}};
    string id, fname, lname, dob, address, phone, disease, treatment;
    double billed;
    string checkinStr;
    bool checkin;
    int daysAdmitted;
    while (getline(file, line))
    {
        istringstream iss(line);

        iss >> std::quoted(id) >> std::quoted(fname) >> std::quoted(lname) >> std::quoted(dob) >> std::quoted(address) >> std::quoted(phone) >> std::quoted(disease) >> std::quoted(treatment) >> billed >> checkinStr >> daysAdmitted;

        checkin = (checkinStr == "True");

        // Find hospital with least patients and under capacity
        string selectedHospital;
        int minPatients = INT_MAX;

        for (const auto &entry : hospitalCounts)
        {
            if (entry.second < 20 && entry.second < minPatients)
            {
                selectedHospital = entry.first;
                minPatients = entry.second;
            }
        }

        if (selectedHospital.empty())
        {
            cerr << "All hospitals are at full capacity. Patient " << id << " could not be admitted.\n";
            continue;
        }

        hospitalCounts[selectedHospital]++;

        // Construct a Patients object
        Patients p(id, fname, lname, dob, address, phone, disease, treatment, billed, checkin, daysAdmitted, selectedHospital);

        // Add only to this hospital's local data
        if (selectedHospital == Location)
        {
            hospitalData[Location].push_back(p);
        }
    }

    file.close();
}

/*
auth:   Spondon OG:Mustafa & at bottom
reason: New one makes it so it reads from the file and not memory
        uses uses paitent class set/get instead of hospital struct
*/
void Hospitals::listpatients()
{
    std::ifstream file("res/PatientsRecords.txt");
    if (!file)
    {
        std::cerr << "Error: Cannot open res/PatientsRecords.txt\n";
        return;
    }

    std::cout << "Patients in " << Location << ":\n";

    string line, id, fname, lname, dob, address, phone, disease, treatment, checkinStr, hospitalName;
    double billed;
    bool checkin;
    int daysAdmitted;
    while (getline(file, line))
    {
        std::istringstream iss(line);

        iss >> std::quoted(id) >> std::quoted(fname) >> std::quoted(lname) >> std::quoted(dob) >> std::quoted(address) >> std::quoted(phone) >> std::quoted(disease) >> std::quoted(treatment) >> billed >> checkinStr >> daysAdmitted >> std::quoted(hospitalName);

        checkin = (checkinStr == "True");

        if (hospitalName == Location)
        {
            std::cout << left
                      << "ID:" << setw(10) << id
                      << "Name:" << setw(20) << (fname + " " + lname)
                      << "DOB:" << setw(15) << dob
                      << "Address:" << setw(35) << address
                      << "Phone:" << setw(25) << phone
                      << "Disease:" << setw(15) << disease
                      << "Treatment:" << setw(20) << treatment
                      << "Billed:$" << setw(10) << fixed << setprecision(2) << billed
                      << "Checkin:" << setw(10) << (checkin ? "True" : "False")
                      << "Days Admitted:" << daysAdmitted
                      << "\n";
        }
    }

    file.close();
}

void Hospitals::relocatepatient()
{
    // implementation of the relocate patient will go here

    // its in paients.cpp
}
void Hospitals::Admit()
{
    // implementation of the admit patient will go here

    // its in paients.cpp
}

// void Hospitals::Pay(double x, string id){
// implementation of the paying bill will go here
//}

// loading in patients by reading filename
// void Hospitals::loadpatients(const string &filename)
// {
//     ifstream file(filename);
//     if (!file)
//     {
//         std::cerr << "Error: Cannot open file " << filename << "\n";
//         return;
//     }
//     string line;
//     int startIndex = 0;
//     int endIndex = 0;
//     // split patient records so each hospital have equal patients
//     if (Location == "Windsor Regional Hospital")
//     {
//         startIndex = 0;
//         endIndex = 21;
//     }
//     else if (Location == "Erie Shore Regional Hospital")
//     {
//         startIndex = 21;
//         endIndex = 41;
//     }
//     else if (Location == "Tecumseh Regional Hospital")
//     {
//         startIndex = 41;
//         endIndex = 61;
//     }
//     else if (Location == "Kingsville Regional Hospital")
//     {
//         startIndex = 61;
//         endIndex = 81;
//     }
//     else if (Location == "Amherstburg Regional Hospital")
//     {
//         startIndex = 81;
//         endIndex = 101;
//     }
//     // reads file and structure its layout
//     int count = 0;
//     while (getline(file, line))
//     {
//         if (count >= startIndex && count < endIndex)
//         {
//             istringstream iss(line);
//             Patient p;
//             string checkinStr;
//             iss >> std::quoted(p.id) >> std::quoted(p.fname) >> std::quoted(p.lname) >> std::quoted(p.dob) >> std::quoted(p.address) >> std::quoted(p.phone) >> std::quoted(p.disease) >> std::quoted(p.treatment) >> p.billed >> checkinStr >> p.daysAdmitted;
//             p.checkin = (checkinStr == "True");
//             hospitalData[Location].push_back(p);
//         }
//         count++;
//         if (count >= endIndex)
//             break;
//     }
//     file.close();
// }

// lists the patients records from the txt file onto output
// void Hospitals::listpatients()
// {
//     std::cout << "Patients in " << Location << ":\n";
//     for (const auto &p : hospitalData[Location])
//     {
//         std::cout << "ID: " << p.id << " | Name: " << p.fname << " " << p.lname << " | Date of Birth: "
//                   << p.dob << " | Address: " << p.address << " | Phone Num: " << p.phone << " | Disease: " << p.disease
//                   << " | Treatment: " << p.treatment << " | Billed: $" << p.billed << " | Checkin status: " << (p.checkin ? "True" : "False")
//                   << " | Days Admitted: " << p.daysAdmitted << "\n";
//     }
// }

// relocate patients to different hospitals
// void Hospitals::relocatepatient()
// {
//     string patientID, newHospital;
//     std::cout << "Enter Patient ID: ";
//     std::cin >> patientID;
//     auto &patients = hospitalData[Location];
//     auto it = find_if(patients.begin(), patients.end(), [&](const Patient &p)
//                       { return p.id == patientID; });
//     // if patient that is willing to relocate cannot be found, print error message
//     if (it == patients.end())
//     {
//         std::cout << "Patient not found in " << Location << ".\n";
//         return;
//     }
//     // otherwise ask user to enter the new hospital in which the patient is relocating to
//     std::cout << "Enter New Hospital to which the patient is relocating: ";
//     std::cin.ignore();
//     getline(cin, newHospital);
//     // if statements to grab the hospital name and assign that destination for relocating patients records
//     Hospitals *destinationHospital = nullptr;
//     if (newHospital == "Windsor Regional Hospital")
//     {
//         destinationHospital = &Windsor;
//     }
//     else if (newHospital == "Erie Shore Regional Hospital")
//     {
//         destinationHospital = &Erie;
//     }
//     else if (newHospital == "Tecumseh Regional Hospital")
//     {
//         destinationHospital = &Tecumseh;
//     }
//     else if (newHospital == "Kingsville Regional Hospital")
//     {
//         destinationHospital = &Kingsville;
//     }
//     else if (newHospital == "Amherstburg Regional Hospital")
//     {
//         destinationHospital = &Amherstburg;
//     }
//     else
//     {
//         std::cout << "Invalid Hospital name. Please enter a proper Hospital name" << "\n";
//         return;
//     }
//     Patient relocatingpatient = *it;
//     patients.erase(it);
//     destinationHospital->hospitalData[destinationHospital->Location].push_back(relocatingpatient);
//     // prints confirmation message stating that patient has successfully relocated
//     std::cout << "Patient ID " << patientID << " relocated to " << newHospital << "\n";
// }