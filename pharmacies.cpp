#include "pharmacies.h"
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

//create the vectors to hold string lists
vector<string> Pharmacies::pharmacieslist;
vector<string> Pharmacies::prescriptiondruglist;

//parametrized constructor called here
Pharmacies::Pharmacies(string id, double salary) : Pharmacies_ID(id), Pharm_Salary(salary) {
    this->Pharmacies_ID = id;
    this->Pharm_Salary = salary;
}

//createpharmacies that will initalize the pharamacieslist and prescriptiondruglist
void Pharmacies::createpharmacies() {
    pharmacieslist = {
        "Rexall", "West Tecumseh Pharmacy", "Medica Pharmacy", "Hunter's Pharmacy", "Ziter Pharmacy",
        "Shoppers Drug Mart", "Trinity Pharmacy", "Loblaw Pharmacy", "Walmart Pharmacy", "Amherstburg Pharmacy",
        "Old Town Pharmacy", "Guardian Pharmacy", "Beachside Pharmacy", "Oasis Pharmacy", "Sunshine Drug Pharmacy",
        "Leamington Wellness Pharmacy", "Thompson Guardian Pharmacy", "Grand Marais Pharmacy", "Dougall Pharmacy", "Totten Pharmacy"
    };

    prescriptiondruglist = {
        "Antibiotics", "Ibuprofen", "Amoxcillin", "Inhaler Treatment", "Chemotherapy Drugs",
        "Insulin", "Aspirin", "Diuretics", "Intravenous (IV) Drug", "Antivirals"
    };
}

//function for delivering prescription drugs to hopsital (connection to hospital)
void Pharmacies::Deliver_Meds(string hospitalName, string pharmaciesname, string prescriptiondrugname) {
    std::cout << "\n" << pharmaciesname << " is preparing " << prescriptiondrugname << " for delivery" << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\n" << pharmaciesname << " is delivering " << prescriptiondrugname << " to " << hospitalName << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\n" << "Delivery of the prescription drug was successful!" << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

//function for pharmacy to bill hospital, hospital then pays back to pharmacy
void Pharmacies::Bill_Hosp(string hospitalName, string pharmaciesname, string prescriptiondrugname) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(250, 500);

    int billamount = dist(gen);
    string billmessage = "\n" + pharmaciesname + " billed " + hospitalName + " $" + to_string(billamount) + " for " + prescriptiondrugname + "\n";

    int hospitalpayment = dist(gen);
    string paymessage = hospitalName + " paid $" + to_string(hospitalpayment) + " to " + pharmaciesname + "\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << billmessage;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << paymessage;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    ofstream output ("pharmacybilling.txt", ios::app); 
        if (output) {
            output << billmessage;
            output << paymessage;
        }
        output.close();
}