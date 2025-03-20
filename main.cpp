#include <iostream>
#include <vector>
using namespace std;


//function for the hopsitals window
void hospitalsection() {
    std::cout << "\nHospitals Location (100 Patients total)" << "\n";
    int choicev1;
    do {
        std::cout << "1. Windsor Regional Hospital" << "\n";
        std::cout << "2. Erie Shore Regional Hospital" << "\n";
        std::cout << "3. Tecumseh Regional Hospital" << "\n";
        std::cout << "4. Kingsville Regional Hospital" << "\n";
        std::cout << "5. Amherstburg Regional Hospital" << "\n";
        std::cout << "6. Return" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choicev1;

        switch (choicev1) {
            case 1:
                std::cout << "To be implemented" << "\n";
                break;
            case 2:
                std::cout << "To be implemented" << "\n";
                break;
            case 3:
                std::cout << "To be implemented" << "\n";
                break;
            case 4:
                std::cout << "To be implemented" << "\n";
                break;
            case 5:
                std::cout << "To be implemented" << "\n";
                break;
            case 6:
                std::cout << "Returning to Hospital Management System..." << "\n";
                return;
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choicev1 !=6);
}

void pharmaciessection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

void patientssection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

void doctorsection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

void nursesection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

int main() {
    std::cout << "Loading Hospital Management System..." << "\n";
    std::cout << "Welcome to the Hospital Management System! Developed by Team 3" << "\n";

    int choice;
    do {
        std::cout << "\nHospital Management System" << "\n";
        std::cout << "1. Hospital" << "\n";
        std::cout << "2. Pharmacies" << "\n";
        std::cout << "3. Patients" << "\n";
        std::cout << "4. Doctors" << "\n";
        std::cout << "5. Nurses" << "\n";
        std::cout << "6. Exit System" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                hospitalsection();
                break;
            case 2:
                pharmaciessection();
                break;
            case 3:
                patientssection();
                break;
            case 4:
                doctorsection();
                break;
            case 5:
                nursesection();
                break;
            case 6:
                std::cout << "Exiting Hospital Management System..." << "\n";
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choice !=6);
    
    return 0;
}