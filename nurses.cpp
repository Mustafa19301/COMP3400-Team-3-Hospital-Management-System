#include "nurses.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<Nurses::Nurse> Nurses::nurseList = {
    {50001, "Nurse Smith", "Amherstburg Regional Hospital", {11000, 11001}},
    {50002, "Nurse Johnson", "Kingsville Regional Hospital", {11002, 11003}},
    {50003, "Nurse Williams", "Kingsville Regional Hospital", {11004, 11005}},
    {50004, "Nurse Brown", "Amherstburg Regional Hospital", {11006, 11007}},
    {50005, "Nurse Jones", "Tecumseh Regional Hospital", {11008, 11009}},
    {50006, "Nurse Miller", "Erie Shore Regional Hospital", {11010, 11011}},
    {50007, "Nurse Davis", "Tecumseh Regional Hospital", {11012, 11013}},
    {50008, "Nurse Garcia", "Amherstburg Regional Hospital", {11014, 11015}},
    {50009, "Nurse Rodriguez", "Kingsville Regional Hospital", {11016, 11017}},
    {50010, "Nurse Wilson", "Tecumseh Regional Hospital", {11018, 11019}},
    {50011, "Nurse Martinez", "Erie Shore Regional Hospital", {11020, 11021}},
    {50012, "Nurse Anderson", "Amherstburg Regional Hospital", {11022, 11023}},
    {50013, "Nurse Taylor", "Tecumseh Regional Hospital", {11024, 11025}},
    {50014, "Nurse Thomas", "Erie Shore Regional Hospital", {11026, 11027}},
    {50015, "Nurse Hernandez", "Amherstburg Regional Hospital", {11028, 11029}},
    {50016, "Nurse Moore", "Tecumseh Regional Hospital", {11030, 11031}},
    {50017, "Nurse Martin", "Erie Shore Regional Hospital", {11032, 11033}},
    {50018, "Nurse Jackson", "Amherstburg Regional Hospital", {11034, 11035}},
    {50019, "Nurse Thompson", "Tecumseh Regional Hospital", {11036, 11037}},
    {50020, "Nurse White", "Windsor Regional Hospital", {11038, 11039}},
    {50021, "Nurse Lopez", "Windsor Regional Hospital", {11040, 11041}},
    {50022, "Nurse Lee", "Amherstburg Regional Hospital", {11042, 11043}},
    {50023, "Nurse Gonzalez", "Erie Shore Regional Hospital", {11044, 11045}},
    {50024, "Nurse Harris", "Tecumseh Regional Hospital", {11046, 11047}},
    {50025, "Nurse Clark", "Amherstburg Regional Hospital", {11048, 11049}},
    {50026, "Nurse Lewis", "Windsor Regional Hospital", {11050, 11051}},
    {50027, "Nurse Robinson", "Amherstburg Regional Hospital", {11052, 11053}},
    {50028, "Nurse Walker", "Erie Shore Regional Hospital", {11054, 11055}},
    {50029, "Nurse Perez", "Amherstburg Regional Hospital", {11056, 11057}},
    {50030, "Nurse Hall", "Kingsville Regional Hospital", {11058, 11059}},
    {50031, "Nurse Young", "Tecumseh Regional Hospital", {11060, 11061}},
    {50032, "Nurse Allen", "Windsor Regional Hospital", {11062, 11063}},
    {50033, "Nurse Sanchez", "Tecumseh Regional Hospital", {11064, 11065}},
    {50034, "Nurse Wright", "Erie Shore Regional Hospital", {11066, 11067}},
    {50035, "Nurse King", "Kingsville Regional Hospital", {11068, 11069}},
    {50036, "Nurse Scott", "Erie Shore Regional Hospital", {11070, 11071}},
    {50037, "Nurse Green", "Kingsville Regional Hospital", {11072, 11073}},
    {50038, "Nurse Baker", "Windsor Regional Hospital", {11074, 11075}},
    {50039, "Nurse Adams", "Kingsville Regional Hospital", {11076, 11077}},
    {50040, "Nurse Nelson", "Erie Shore Regional Hospital", {11078, 11079}},
    {50041, "Nurse Carter", "Tecumseh Regional Hospital", {11080}},
    {50042, "Nurse Tempest", "Tecumseh Regional Hospital", {11081}},
    {50043, "Nurse Uzumaki", "Windsor Regional Hospital", {11082}},
    {50044, "Nurse Foster", "Windsor Regional Hospital", {11083}},
    {50045, "Nurse Mitchell", "Kingsville Regional Hospital", {11084}},
    {50046, "Nurse Simmons", "Kingsville Regional Hospital", {11085}},
    {50047, "Nurse Roberts", "Kingsville Regional Hospital", {11086}},
    {50048, "Nurse Howard", "Windsor Regional Hospital", {11087}},
    {50049, "Nurse Phillips", "Windsor Regional Hospital", {11088}},
    {50050, "Nurse Evans", "Windsor Regional Hospital", {11089}},
    {50051, "Nurse Campbell", "Kingsville Regional Hospital", {11090}},
    {50052, "Nurse Kelly", "Kingsville Regional Hospital", {11091}},
    {50053, "Nurse Parker", "Windsor Regional Hospital", {11092}},
    {50054, "Nurse Ward", "Windsor Regional Hospital", {11093}},
    {50055, "Nurse Price", "Windsor Regional Hospital", {11094}},
    {50056, "Nurse Edwards", "Windsor Regional Hospital", {11095}},
    {50057, "Nurse Collins", "Kingsville Regional Hospital", {11096}},
    {50058, "Nurse Ross", "Kingsville Regional Hospital", {11097}},
};


std::vector<Nurses::Patient> Nurses::patientList = {
    {11000, "Emily Soto"},
    {11001, "Dustin Coleman"},
    {11002, "Amanda Rosario"},
    {11003, "Douglas Ryan"},
    {11004, "Angela Smith"},
    {11005, "Christina Farmer"},
    {11006, "Ray Riley"},
    {11007, "Katherine Valenzuela"},
    {11008, "Rebecca Johnson"},
    {11009, "Edward Moyer"},
    {11010, "Amanda Caldwell"},
    {11011, "Mark Moore"},
    {11012, "Monique Hill"},
    {11013, "Jacob Hanna"},
    {11014, "Sean Young"},
    {11015, "Summer Diaz"},
    {11016, "Beverly Hendricks"},
    {11017, "Valerie Spears"},
    {11018, "Richard Martin"},
    {11019, "John Pitts"},
    {11020, "Jason Gallegos"},
    {11021, "Sandra Williams"},
    {11022, "Matthew Gibson"},
    {11023, "Sheila Jackson"},
    {11024, "Morgan Richardson"},
    {11025, "Jason Harmon"},
    {11026, "Sydney Woods"},
    {11027, "Daniel Carter"},
    {11028, "Catherine Sullivan"},
    {11029, "Candice Knapp"},
    {11030, "Alexander Cole"},
    {11031, "Julie Garcia"},
    {11032, "Mark Little"},
    {11033, "Susan Mcdonald"},
    {11034, "Candice Richardson"},
    {11035, "Brendan Mills"},
    {11036, "Kenneth Park"},
    {11037, "Richard Garcia"},
    {11038, "Jonathan Roberts"},
    {11039, "Heidi Hayes"},
    {11040, "Sharon King"},
    {11041, "Charles Davis"},
    {11042, "Donald Moore"},
    {11043, "Brittney Cuevas"},
    {11044, "Randy Freeman"},
    {11045, "Ashley Turner"},
    {11046, "Kenneth Garcia"},
    {11047, "Jillian Jimenez"},
    {11048, "Katherine Brooks"},
    {11049, "Veronica Lyons"},
    {11050, "Ronald Davis"},
    {11051, "Charles Day"},
    {11052, "Jamie Gross"},
    {11053, "Dawn Holloway"},
    {11054, "Rebecca Johnson"},
    {11055, "Robert Harris"},
    {11056, "Brooke Parker"},
    {11057, "Kenneth Peters"},
    {11058, "Latasha Gomez"},
    {11059, "Mark Vang"},
    {11060, "Roger Ortega"},
    {11061, "Julie Matthews"},
    {11062, "Matthew Diaz"},
    {11063, "Pam Flores"},
    {11064, "Jason Myers"},
    {11065, "Pamela Oneill"},
    {11066, "Jeffery Marshall"},
    {11067, "Joseph Mays"},
    {11068, "Henry Parker"},
    {11069, "Sherri Stevens"},
    {11070, "Tonya Garcia"},
    {11071, "Raymond Frank"},
    {11072, "Gloria Hawkins"},
    {11073, "Andrew Leonard"},
    {11074, "Anthony Vincent"},
    {11075, "Sandra White"},
    {11076, "Charles Wilson"},
    {11077, "Michelle Silva"},
    {11078, "Lisa Greene"},
    {11079, "Laura Smith"},
    {11080, "Susan Walker"},
    {11081, "Alan Kelley"},
    {11082, "Eugene Ramirez"},
    {11083, "Antonio Saunders"},
    {11084, "Diane Bernard"},
    {11085, "Kelli Preston"},
    {11086, "Susan Bauer"},
    {11087, "Kendra Smith"},
    {11088, "Elizabeth Freeman"},
    {11089, "Kathy Medina"},
    {11090, "John Bryan"},
    {11091, "Justin Stuart"},
    {11092, "Christopher Martinez"},
    {11093, "Shane Hodges"},
    {11094, "Robert Horton"},
    {11095, "Lauren Aguirre"},
    {11096, "Erin Rice"},
    {11097, "Jacob Anderson"},
    {11098, "Michael Meyer"},
    {11099, "Justin Turner"},
};

// List all nurses
void Nurses::listNurses() {
    std::cout << "\nList of Nurses:\n";
    for (const auto& nurse : nurseList) {
        std::cout << "ID: " << nurse.id << ", Name: " << nurse.name 
                  << ", Hospital: " << nurse.hospitalName << "\n";
    }
}

// View nurse details
void Nurses::viewNurseDetails(int nurseId) {
    for (const auto& nurse : nurseList) {
        if (nurse.id == nurseId) {
            std::cout << "\nNurse Details:\n";
            std::cout << "ID: " << nurse.id << "\n";
            std::cout << "Name: " << nurse.name << "\n";
            std::cout << "Hospital: " << nurse.hospitalName << "\n";
            std::cout << "Assigned Patients: ";
            if (nurse.patientIds.empty()) {
                std::cout << "None";
            } else {
                for (int patientId : nurse.patientIds) {
                    std::cout << patientId << " ";
                }
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Nurse not found with ID: " << nurseId << "\n";
}

// Assign a nurse to a patient
void Nurses::assignNurseToPatient(int patientId, int nurseId) {
    for (auto& nurse : nurseList) {
        if (nurse.id == nurseId) {
            if (nurse.patientIds.size() < 2) { // Max 2 patients per nurse
                nurse.patientIds.push_back(patientId);
                std::cout << "Assigned Nurse ID " << nurseId 
                          << " to Patient ID " << patientId << "\n";
                return;
            } else {
                std::cout << "Nurse ID " << nurseId << " already has 2 patients.\n";
                return;
            }
        }
    }
    std::cout << "Nurse not found with ID: " << nurseId << "\n";
}

// View patient details
void Nurses::viewPatientDetails(int patientId) {
    for (const auto& patient : patientList) {
        if (patient.id == patientId) {
            std::cout << "\nPatient ID: " << patient.id 
                      << ", Name: " << patient.name << "\n";
            std::cout << "Assigned Nurse(s): ";
            bool found = false;
            for (const auto& nurse : nurseList) {
                for (int pId : nurse.patientIds) {
                    if (pId == patientId) {
                        std::cout << nurse.id << " ";
                        found = true;
                    }
                }
            }
            if (!found) {
                std::cout << "None";
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Patient with ID " << patientId << " not found.\n";
}
