#include "hospitals.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

//parametrized constructor called here
Hospitals::Hospitals(string hospitalid, string section, int cap) : Hospital_ID(hospitalid), Location(section), Capacity(cap) {
    this->Hospital_ID = hospitalid;
    this->Location = section;
    this->Capacity = cap;
}

//loading in patients by reading filename
void Hospitals::loadpatients(const string& filename) {
    ifstream file(filename);
    if(!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return;
    }

    string line;
    int startIndex = 0;
    int endIndex = 0;

    //split patient records so each hospital have equal patients
    if (Location == "Windsor Regional Hospital") {
        startIndex = 0;
        endIndex = 21;
    }
    else if (Location == "Erie Shore Regional Hospital") {
        startIndex = 21;
        endIndex = 41;
    }
    else if (Location == "Tecumseh Regional Hospital") {
        startIndex = 41;
        endIndex = 61;
    }
    else if (Location == "Kingsville Regional Hospital") {
        startIndex = 61;
        endIndex = 81;
    }
    else if (Location == "Amherstburg Regional Hospital") {
        startIndex = 81;
        endIndex = 101;
    }

    //reads file and structure its layout
    int count = 0;
    while (getline(file, line)) {
        if (count >= startIndex && count < endIndex) {
            istringstream iss(line);
            Patient p;
            iss >> std::quoted(p.id) >> std::quoted(p.fname) >> std::quoted(p.lname) >> std::quoted(p.dob) 
                >> std::quoted(p.address) >> std::quoted(p.phone) >> std::quoted(p.disease) >> std::quoted(p.treatment) 
                >> p.billed >> p.checkin >> p.daysAdmitted;
        
            hospitalData[Location].push_back(p);
        }
        count++;
        if (count >= endIndex) break;
    }
    file.close();
}

//lists the patients records from the txt file onto output
void Hospitals::listpatients() {
    std::cout << "Patients in " << Location << ":\n";
    for (const auto& p: hospitalData[Location]) {
        std::cout << "ID: " << p.id << " | Name: " << p.fname << " " << p.lname << " | Date of Birth: " 
            << p.dob << " | Address: " << p.address << " | Phone Num: " << p.phone << " | Disease: " << p.disease 
            << " | Treatment: " << p.treatment << " | Days Admitted: " << p.daysAdmitted << "\n";
    }
}

//relocate patients to different hospitals
void Hospitals::relocatepatient() {
    string patientID, newHospital;
    std::cout << "Enter Patient ID: ";
    std::cin >> patientID;

    auto& patients = hospitalData[Location];
    auto it = find_if(patients.begin(), patients.end(), [&](const Patient &p) { return p.id == patientID; });

    //if patient that is willing to relocate cannot be found, print error message
    if (it == patients.end()) {
        std::cout << "Patient not found in " << Location << ".\n";
        return;
    }

    //otherwise ask user to enter the new hospital in which the patient is relocating to
    std::cout << "Enter New Hospital to which the patient is relocating: ";
    std::cin.ignore();
    getline(cin, newHospital);

    //if statements to grab the hospital name and assign that destination for relocating patients records
    Hospitals* destinationHospital = nullptr;
    if (newHospital == "Windsor Regional Hospital") {
        destinationHospital = &Windsor;
    }
    else if (newHospital == "Erie Shore Regional Hospital") {
        destinationHospital = &Erie;
    }
    else if (newHospital == "Tecumseh Regional Hospital") {
        destinationHospital = &Tecumseh;
    }
    else if (newHospital == "Kingsville Regional Hospital") {
        destinationHospital = &Kingsville;
    }
    else if (newHospital == "Amherstburg Regional Hospital") {
        destinationHospital = &Amherstburg;
    }
    else {
        std::cout << "Invalid Hospital name. Please enter a proper Hospital name" << "\n";
        return;
    }

    Patient relocatingpatient = *it;
    patients.erase(it);
    destinationHospital->hospitalData[destinationHospital->Location].push_back(relocatingpatient);

    //prints confirmation message stating that patient has successfully relocated
    std::cout << "Patient ID " << patientID << " relocated to " << newHospital << "\n.";
}

void Hospitals::Admit(){
    //implementation of the admit patient will go here
}

//void Hospitals::Pay(double x, string id){
    //implementation of the paying bill will go here
//}