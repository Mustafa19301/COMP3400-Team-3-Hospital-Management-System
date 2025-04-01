#include <iostream>
#include <vector>
#include <fstream>
#include "hospitals.h"
#include "pharmacies.h"
#include "doctors.h"
#include "nurses.h"
#include "patients.h"
using namespace std;

/*
Auth: Spondon
Reason: stuff like "20/" will cause the program to loop like infinitly and spaz out so this will make it so only number will be accepted and not spaz out
        Also at the top so it will be in the scope
*/
int getSafeIntInput(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();                                         // clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a valid number.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard leftover input
            return value;
        }
    }
}

// object instances declared for the Hospitals section
Hospitals Windsor("H001", "Windsor Regional Hospital", 20);
Hospitals Erie("H002", "Erie Shore Regional Hospital", 20);
Hospitals Tecumseh("H003", "Tecumseh Regional Hospital", 20);
Hospitals Kingsville("H004", "Kingsville Regional Hospital", 20);
Hospitals Amherstburg("H005", "Amherstburg Regional Hospital", 20);

// function for the hopsitals window
void hospitalsection()
{
    std::cout << "\nHospitals Locations" << "\n";
    int choicev1;
    do
    {
        // std::cout << "1. Windsor Regional Hospital" << ""<< "\n";
        // std::cout << "2. Erie Shore Regional Hospital" << "\n";
        // std::cout << "3. Tecumseh Regional Hospital" << "\n";
        // std::cout << "4. Kingsville Regional Hospital" << "\n";
        // std::cout << "5. Amherstburg Regional Hospital" << "\n";
        Patients::Show_Hospital_Occupancy();
        std::cout << "6. Return" << "\n";
        // std::cout << "Enter your choice of option: ";
        // std::cin >> choicev1;

        choicev1 = getSafeIntInput("Enter your choice of option: ");
        switch (choicev1)
        {
        case 1:
            std::cout << "Selected Windsor Regional Hospital" << "\n";
            Windsor.listpatients();
            break;
        case 2:
            std::cout << "Selected Erie Shore Regional Hospital" << "\n";
            Erie.listpatients();
            break;
        case 3:
            std::cout << "Selected Tecumseh Regional Hospital" << "\n";
            Tecumseh.listpatients();
            break;
        case 4:
            std::cout << "Selected Kingsville Regional Hospital" << "\n";
            Kingsville.listpatients();
            break;
        case 5:
            std::cout << "Selected Amherstburg Regional Hospital" << "\n";
            Amherstburg.listpatients();
            break;
        case 6:
            std::cout << "Returning to Hospital Management System..." << "\n";
            return;
            break;
        default:
            std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choicev1 != 6);
}

// function to relocate patient
void relocatepatientsection()
{
    std::cout << "\nSelect Hospital to Relocate Patient" << "\n";
    int choicev2;
    do
    {
        std::cout << "1. Windsor Regional Hospital" << "\n";
        std::cout << "2. Erie Shore Regional Hospital" << "\n";
        std::cout << "3. Tecumseh Regional Hospital" << "\n";
        std::cout << "4. Kingsville Regional Hospital" << "\n";
        std::cout << "5. Amherstburg Regional Hospital" << "\n";
        std::cout << "6. Return" << "\n";
        // std::cout << "Enter your choice of option: ";
        // std::cin >> choicev2;

        choicev2 = getSafeIntInput("Enter your choice of option: ");
        switch (choicev2)
        {
        case 1:
            std::cout << "Selected Windsor Regional Hospital" << "\n";
            Windsor.relocatepatient();
            break;
        case 2:
            std::cout << "Selected Erie Shore Regional Hospital" << "\n";
            Erie.relocatepatient();
            break;
        case 3:
            std::cout << "Selected Tecumseh Regional Hospital" << "\n";
            Tecumseh.relocatepatient();
            break;
        case 4:
            std::cout << "Selected Kingsville Regional Hospital" << "\n";
            Kingsville.relocatepatient();
            break;
        case 5:
            std::cout << "Selected Amherstburg Regional Hospital" << "\n";
            Amherstburg.relocatepatient();
            break;
        case 6:
            std::cout << "Returning to Hospital Management System..." << "\n";
            return;
            break;
        default:
            std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choicev2 != 6);
}

void pharmaciessection()
{
    int hospitalchoice, pharmacychoice, drugchoice;

    Pharmacies::createpharmacies();

    std::cout << "\nSelect Hospital in which the prescription drug will be delivered to:" << "\n";
    std::cout << "1. Windsor Regional Hospital" << "\n";
    std::cout << "2. Erie Shore Regional Hospital" << "\n";
    std::cout << "3. Tecumseh Regional Hospital" << "\n";
    std::cout << "4. Kingsville Regional Hospital" << "\n";
    std::cout << "5. Amherstburg Regional Hospital" << "\n";
    std::cout << "6. Return" << "\n";
    // std::cout << "Enter your choice of option: ";
    // std::cin >> hospitalchoice;
    hospitalchoice = getSafeIntInput("Enter your choice of option: ");
    if (hospitalchoice == 6)
    {
        return;
    }

    string hospitalName;
    switch (hospitalchoice)
    {
    case 1:
        hospitalName = "Windsor Regional Hospital";
        break;
    case 2:
        hospitalName = "Erie Shore Regional Hospital";
        break;
    case 3:
        hospitalName = "Tecumseh Regional Hospital";
        break;
    case 4:
        hospitalName = "Kingsville Regional Hospital";
        break;
    case 5:
        hospitalName = "Amherstburg Regional Hospital";
        break;
    default:
        std::cout << "Invalid selection, returning to main menu" << "\n";
        return;
    }

    std::cout << "\nSelect any of the 20 Pharmacies:" << "\n";
    for (size_t i = 0; i < Pharmacies::pharmacieslist.size(); i++)
    {
        std::cout << i + 1 << ". " << Pharmacies::pharmacieslist[i] << "\n";
    }
    // std::cout << "Enter your choice of Pharmacy: ";
    // std::cin >> pharmacychoice;
    pharmacychoice = getSafeIntInput("Enter your choice of option: ");

    if (pharmacychoice < 1 || pharmacychoice > 20)
    {
        std::cout << "Invalid choice, returning to main menu" << "\n";
        return;
    }

    string pharmacyName = Pharmacies::pharmacieslist[pharmacychoice - 1];

    std::cout << "\nSelect a Prescription Drug that will be delievered:" << "\n";
    for (size_t i = 0; i < Pharmacies::prescriptiondruglist.size(); i++)
    {
        std::cout << i + 1 << ". " << Pharmacies::prescriptiondruglist[i] << "\n";
    }
    // std::cout << "Enter your choice of Prescription Drug: ";
    // std::cin >> drugchoice;
    drugchoice = getSafeIntInput("Enter your choice of option: ");

    if (drugchoice < 1 || drugchoice > 10)
    {
        std::cout << "Invalid choice, returning to main menu" << "\n";
        return;
    }

    string drugName = Pharmacies::prescriptiondruglist[drugchoice - 1];

    Pharmacies::Deliver_Meds(hospitalName, pharmacyName, drugName);
    Pharmacies::Bill_Hosp(hospitalName, pharmacyName, drugName);
}

// prints the pharmacybill records that were placed in the pharmacy section
void pharmacybillrecords()
{
    ifstream inputfile("pharmacybilling.txt");
    if (!inputfile)
    {
        std::cout << "No pharmacy billing records found at the moment..." << "\n";
        return;
    }

    if (inputfile.peek() == ifstream::traits_type::eof())
    {
        std::cout << "No pharmacy billing records found at the momment..." << "\n";
        inputfile.close();
        return;
    }

    string line;
    std::cout << "\nPharmacy Billing Records" << "\n";
    while (getline(inputfile, line))
    {
        std::cout << line << "\n";
    }
    inputfile.close();
}
/*
Auth: Spondon
Reason: handles user input for paients
*/
void patientssection()
{
    int choice;
    do
    {
        cout << "\nPatient Management\n";
        cout << "------------------------------\n";
        cout << "1. Update a Patient Information\n";
        cout << "2. View Attending Doctor(s)\n";
        cout << "3. View Primary Doctor\n";
        cout << "4. Discharge a Patient\n";
        cout << "5. Admit a Patient\n";
        cout << "6. Search for a Patient\n";
        cout << "7. List All Patients\n";
        cout << "8. Relocate a Paitent\n";
        cout << "9. Return\n";

        cout << "Enter your choice of option: ";

        choice = getSafeIntInput("");

        switch (choice)
        {
        case 1:
            Patients::Update_Patient_Info();
            break;
        case 2:
            Patients::Find_Attending_Doctor();
            break;
        case 3:
            Patients::Find_Primary_Doctor();
            break;
        case 4:
            Patients::Discharge_Patient();
            break;
        case 5:
            Patients::Admit_Patient();
            break;
        case 6:
            Patients::Search_Patient();
            break;
        case 7:
            Patients::List_All_Patients();
            break;
        case 8:
            Patients::Relocate_Patient();
            break;
        case 9:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice, please enter a valid option.\n";
        }

    } while (choice != 9);
}

void doctorsection()
{
    std::cout << "\nDoctor Management Section" << "\n";
    int choice;
    do {
        std::cout << "1. List all doctors" << "\n";
        std::cout << "2. View doctor details" << "\n";
        std::cout << "3. Assign doctor to a patient" << "\n";
        std::cout << "4. Assign primary doctor to a patient" << "\n";
        std::cout << "5. Assign attending doctor to a patient" << "\n";
        std::cout << "6. View patient details" << "\n";
        std::cout << "7. Return to main menu" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Call the method to list all doctors
                Doctors::listDoctors();
                break;
            case 2:
                // View doctor details
                int doctorId;
                std::cout << "Enter Doctor ID: ";
                std::cin >> doctorId;
                Doctors::viewDoctorDetails(doctorId);
                break;
            case 3:
                // Assign doctor to a patient
                int patientId;
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cout << "Enter Doctor ID: ";
                std::cin >> doctorId;
                Doctors::assignDoctorToPatient(patientId, doctorId);
                break;
            case 4:
                // Assign primary doctor to a patient
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cout << "Enter Doctor ID: ";
                std::cin >> doctorId;
                Doctors::assignPrimaryDoctor(patientId, doctorId);
                break;
            case 5:
                // Assign attending doctor to a patient
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cout << "Enter Doctor ID: ";
                std::cin >> doctorId;
                Doctors::assignAttendingDoctor(patientId, doctorId);
                break;
            case 6:
                // View patient details
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                Doctors::viewPatientDetails(patientId);
                break;
            case 7:
                std::cout << "Returning to main menu..." << "\n";
                return;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choice != 7);
}

void nursesection()
{
    std::cout << "\nNurse Management Section" << "\n";
    int choice;
    do {
        std::cout << "1. List all nurses" << "\n";
        std::cout << "2. View nurse details" << "\n";
        std::cout << "3. Assign nurse to a patient" << "\n";
        std::cout << "4. View patient details" << "\n";
        std::cout << "5. Return to main menu" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Call the method to list all nurses
                Nurses::listNurses();
                break;
            case 2:
                // View nurse details
                int nurseId;
                std::cout << "Enter Nurse ID: ";
                std::cin >> nurseId;
                Nurses::viewNurseDetails(nurseId);
                break;
            case 3:
                // Assign nurse to a patient
                int patientId;
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cout << "Enter Nurse ID: ";
                std::cin >> nurseId;
                Nurses::assignNurseToPatient(patientId, nurseId);
                break;
            case 4:
                // View patient details
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                Nurses::viewPatientDetails(patientId);
                break;
            case 5:
                std::cout << "Returning to main menu..." << "\n";
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
                break;
        }
    } while (choice != 5);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: please provide a txt file" << "\n";
        return 1;
    }

    string filename = argv[1];

    std::cout << "Loading Hospital Management System..." << "\n";
    std::cout << "Welcome to the Hospital Management System! Developed by Team 3" << "\n";

    Windsor.loadpatients(filename);
    Erie.loadpatients(filename);
    Tecumseh.loadpatients(filename);
    Kingsville.loadpatients(filename);
    Amherstburg.loadpatients(filename);

    int choice;
    do
    {
        std::cout << "\nHospital Management System" << "\n";
        std::cout << "1. Hospital" << "\n";
        // std::cout << "2. Relocate Patient" << "\n";
        std::cout << "2. Pharmacies" << "\n";
        std::cout << "3. Pharmacies Billing Records" << "\n";
        std::cout << "4. Patients" << "\n";
        std::cout << "5. Doctors" << "\n";
        std::cout << "6. Nurses" << "\n";
        std::cout << "7. Exit System" << "\n";
        // std::cout << "Enter your choice of option: ";
        // std::cin >> choice;

        choice = getSafeIntInput("Enter your choice of option: ");

        switch (choice)
        {
        case 1:
            hospitalsection();
            break;
        // case 2:
        //     relocatepatientsection();
        //     break;
        case 2:
            pharmaciessection();
            break;
        case 3:
            pharmacybillrecords();
            break;
        case 4:
            patientssection();
            break;
        case 5:
            doctorsection();
            break;
        case 6:
            nursesection();
            break;
        case 7:
            std::cout << "Exiting Hospital Management System..." << "\n";
            break;
        default:
            std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choice != 7);

    return 0;
}
