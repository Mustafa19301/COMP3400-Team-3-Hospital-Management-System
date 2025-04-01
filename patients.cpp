/*
    Auth:Spondon
*/

#include "patients.h"
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

Patients::Patients(string id, string first, string last, string dob, string address, string phone,
                   string illness, string treatment, double paymentInfo, bool checkedin, int daysAdmmited, string hospital)
    : Patient_ID(id), P_Fname(first), P_Lname(last), P_DOB(dob), P_Address(address), P_Phone(phone),
      P_Disease(illness), P_Treatment(treatment), P_Billed(paymentInfo), P_Checkin(checkedin),
      P_DaysAdmmited(daysAdmmited), P_Hospital(hospital) {}

/*
    Auth:Spondon
    reason : fancy stuff and shows how many paitents are there dyanmicly
*/
void Patients::Show_Hospital_Occupancy()
{
    ifstream file("res/PatientsRecords.txt");
    if (!file)
    {
        cerr << "Error: Could not open res/PatientsRecords.txt\n";
        return;
    }
    map<string, int> hospitalCounts;
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string temp;
        vector<string> tokens;

        while (iss >> std::quoted(temp))
        {
            tokens.push_back(temp);
        }

        if (tokens.size() >= 12)
        {
            string hospital = tokens.back();
            hospitalCounts[hospital]++;
        }
    }
    file.close();
    cout << "\nHospitals Location (Patients total)\n";
    vector<string> orderedHospitals = {
        "Windsor Regional Hospital",
        "Erie Shore Regional Hospital",
        "Tecumseh Regional Hospital",
        "Kingsville Regional Hospital",
        "Amherstburg Regional Hospital"};
    int index = 1;
    for (const string &name : orderedHospitals)
    {
        int count = hospitalCounts[name];
        int remaining = 20 - count;
        cout << index++ << ". " << left << setw(30) << name
             << ": " << setw(2) << count << " patients"
             << " (" << remaining << " slots remaining)" << "\n";
    }
}
/*
    Auth:Spondon
    reason : text gui && to update info
*/
void Patients::Update_Patient_Info()
{
    string id;
    cout << "Enter Patient ID to update: ";
    cin >> id;
    cin.ignore();

    ifstream file("res/PatientsRecords.txt");
    if (!file)
    {
        cerr << "Error: Cannot open patient file.\n";
        return;
    }

    vector<string> updatedLines;
    string line;
    bool found = false;

    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> quoted(token))
            tokens.push_back(token);

        if (tokens.size() >= 12 && tokens[0] == id)
        {
            found = true;
            Patients temp(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], stod(tokens[8]), tokens[9] == "True", stoi(tokens[10]), tokens[11]);
            cout << "\nSelect field to update:\n"
                 << "1. First Name\n"
                 << "2. Last Name\n"
                 << "3. Date of Birth\n"
                 << "4. Address\n"
                 << "5. Phone\n"
                 << "6. Disease\n"
                 << "7. Treatment\n"
                 << "8. Billed Amount\n"
                 << "9. Check - in Status\n"
                 << "10. Days Admitted\n"
                 << "11. Hospital\n"
                 << "Enter choice : ";
            int choice;
            cin >> choice;
            cin.ignore();

            string newValue;
            double dblValue;
            bool boolValue;

            switch (choice)
            {
            case 1:
                cout << "Enter new First Name: ";
                getline(cin, newValue);
                temp.Update_Fname(newValue);
                break;
            case 2:
                cout << "Enter new Last Name: ";
                getline(cin, newValue);
                temp.Update_Lname(newValue);
                break;
            case 3:
                cout << "Enter new Date of Birth: ";
                getline(cin, newValue);
                temp.Update_DOB(newValue);
                break;
            case 4:
                cout << "Enter new Address: ";
                getline(cin, newValue);
                temp.Update_Address(newValue);
                break;
            case 5:
                cout << "Enter new Phone: ";
                getline(cin, newValue);
                temp.Update_Phone(newValue);
                break;
            case 6:
                cout << "Enter new Disease: ";
                getline(cin, newValue);
                temp.Update_Disease(newValue);
                break;
            case 7:
                cout << "Enter new Treatment: ";
                getline(cin, newValue);
                temp.Update_Treatment(newValue);
                break;
            case 8:
                cout << "Enter new Billed Amount: ";
                cin >> dblValue;
                temp.Update_Payment_Info(dblValue);
                break;
            case 9:
                cout << "Enter new Check-in status (1 = True, 0 = False): ";
                cin >> boolValue;
                temp.Update_Checkin(boolValue);
                break;
            case 10:
                cout << "Enter new Days Admitted: ";
                cin >> newValue;
                temp.Update_DaysAdmmited(stoi(newValue));
                break;
            case 11:
                cout << "Enter new Hospital: ";
                cin.ignore();
                getline(cin, newValue);
                temp.Update_Hospital(newValue);
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }

            ostringstream oss;
            oss << quoted(temp.getID()) << " "
                << quoted(temp.getFname()) << " "
                << quoted(temp.getLname()) << " "
                << quoted(temp.getDOB()) << " "
                << quoted(temp.getAddress()) << " "
                << quoted(temp.getPhone()) << " "
                << quoted(temp.getDisease()) << " "
                << quoted(temp.getTreatment()) << " "
                << temp.getBilled() << " "
                << (temp.getCheckin() ? "True" : "False") << " "
                << temp.getDaysAdmmited() << " "
                << quoted(temp.getHospital());

            updatedLines.push_back(oss.str());
        }
        else
        {
            updatedLines.push_back(line);
        }
    }
    file.close();

    if (!found)
    {
        cout << "Patient not found.\n";
        return;
    }

    ofstream out("res/PatientsRecords.txt");
    for (const auto &l : updatedLines)
        out << l << "\n";

    cout << "Patient info updated.\n";
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::Find_Attending_Doctor()
{
    string id;
    cout << "Enter Patient ID to find attending doctor(s): ";
    cin >> id;

    // 🔧 Placeholder logic
    // You would eventually pull this from a real doctor-patient assignment
    cout << "Attending doctors for patient " << id << ":\n";
    cout << "- Dr. Amanda Jones\n";
    cout << "- Dr. Kevin Lee\n";
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::Find_Primary_Doctor()
{
    string id;
    cout << "Enter Patient ID to find primary doctor: ";
    cin >> id;

    // 🔧 Placeholder logic
    cout << "Primary doctor for patient " << id << ": Dr. Amanda Jones\n";
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::Discharge_Patient()
{
    string id;
    cout << "Enter Patient ID to discharge: ";
    cin >> id;
    ifstream infile("res/PatientsRecords.txt");
    ofstream archive("res/ArchivedPatientRecords.txt", ios::app);
    if (!infile || !archive)
    {
        cerr << "Error: Cannot open required file(s).\n";
        return;
    }
    vector<string> keptPatients;
    string line;
    bool found = false;
    while (getline(infile, line))
    {
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> std::ws)
        {
            if (iss.peek() == '"')
                iss >> quoted(token);
            else
                iss >> token;
            tokens.push_back(token);
        }
        if (tokens.size() >= 12 && tokens[0] == id)
        {
            tokens[9] = "False";
            found = true;
            // Rebuild discharged line for archive
            ostringstream oss;
            for (int i = 0; i < tokens.size(); ++i)
            {
                if (i > 0)
                    oss << " ";
                if (i == 8 || i == 9 || i == 10)
                    oss << tokens[i];
                else
                    oss << quoted(tokens[i]);
            }
            archive << oss.str() << "\n";
            // ----- Write to PatientBillingRecords.txt -----
            ofstream billing("res/PatientBillingRecords.txt", ios::app);
            if (billing)
            {
                string fullName = tokens[1] + " " + tokens[2];
                string hospital = tokens[11];
                int days = stoi(tokens[10]);
                double billedAmount = stod(tokens[8]);
                double multiplier = 1 + (days / 90.0);
                double hospitalCharge = multiplier * billedAmount;

                billing << "Patient: " << fullName << " | ID: " << tokens[0]
                        << " | Hospital: " << hospital << " | Days Admitted: " << days << "\n";
                billing << "Calculated Hospital Charge: $" << fixed << setprecision(2) << hospitalCharge;
                billing << " (" << fixed << setprecision(2) << multiplier << "x of billed amount)\n\n";

                billing.close();
            }
            else
            {
                cerr << "Warning: Could not write to PatientBillingRecords.txt\n";
            }
        }
        else
        {
            keptPatients.push_back(line);
        }
    }

    infile.close();
    archive.close();

    if (!found)
    {
        cout << "Patient ID not found.\n";
        return;
    }

    ofstream out("res/PatientsRecords.txt");
    for (const auto &l : keptPatients)
        out << l << "\n";

    cout << "Patient " << id << " has been discharged, marked as not checked in, archived, and billing recorded.\n";
}
/*
    Auth:Spondon
    reason : string formating for name
*/
string FormatName(const string &name)
{
    string formatted = name;
    bool capitalize = true;

    for (char &c : formatted)
    {
        if (capitalize && isalpha(c))
        {
            c = toupper(c);
            capitalize = false;
        }
        else
        {
            c = tolower(c);
        }

        if (c == ' ')
            capitalize = true;
    }

    return formatted;
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::Search_Patient()
{
    int choice;
    cout << "\nSearch By:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Disease\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    string query;
    cout << "Enter search value: ";
    getline(cin, query);

    ifstream file("res/PatientsRecords.txt");
    if (!file)
    {
        cerr << "Error: Cannot open file.\n";
        return;
    }

    if (choice == 2)
        query = FormatName(query); // Capitalize if searching by name

    string line;
    bool found = false;

    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> quoted(token))
            tokens.push_back(token);

        if (tokens.size() < 12)
            continue;

        string fullName = tokens[1] + " " + tokens[2];

        if ((choice == 1 && tokens[0] == query) ||
            (choice == 2 && fullName.find(query) != string::npos) ||
            (choice == 3 && tokens[6].find(query) != string::npos))
        {
            found = true;
            cout << line << "\n";
        }
    }

    if (!found)
        cout << "No matching patient found.\n";
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::List_All_Patients()
{
    ifstream file("res/PatientsRecords.txt");
    if (!file)
    {
        cerr << "Error: Cannot open file.\n";
        return;
    }

    string line;
    cout << "\nAll Patients:\n";

    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> tokens;
        string token;

        while (iss >> quoted(token) || iss >> token)
        {
            tokens.push_back(token);
        }

        if (tokens.size() < 12)
            continue;

        string id = tokens[0];
        string fname = tokens[1];
        string lname = tokens[2];
        string dob = tokens[3];
        string address = tokens[4];
        string phone = tokens[5];
        string disease = tokens[6];
        string treatment = tokens[7];
        double billed = stod(tokens[8]);
        bool checkin = (tokens[9] == "True");
        int daysAdmitted = stoi(tokens[10]);
        string hospitalName = tokens[11];

        cout << left
             << "ID: " << setw(10) << id
             << "Name: " << setw(20) << (fname + " " + lname)
             << "DOB: " << setw(15) << dob
             << "Address: " << setw(35) << address
             << "Phone: " << setw(25) << phone
             << "Disease: " << setw(15) << disease
             << "Treatment: " << setw(30) << treatment
             << "Billed:$" << setw(10) << fixed << setprecision(2) << billed
             << "Checkin: " << setw(10) << ("True")
             << "Days Admitted: " << daysAdmitted
             << "\n";
    }
}
/*
    Auth:Spondon
    reason : in name
*/
void Patients::Admit_Patient()
{
    string fname, lname, dob, address, phone, disease, treatment, hospital;
    double billed;
    bool checkin = true;
    int daysAdmitted;

    // -- Auto-generate Patient ID --
    ifstream checkFile("res/PatientsRecords.txt");
    string existingLine;
    int maxID = 11000;

    while (getline(checkFile, existingLine))
    {
        istringstream iss(existingLine);
        string existingID;
        iss >> quoted(existingID);

        if (!existingID.empty())
        {
            try
            {
                int idNum = stoi(existingID);
                maxID = max(maxID, idNum);
            }
            catch (...)
            {
            }
        }
    }
    checkFile.close();

    string id = to_string(maxID + 1);
    cout << "Generated Patient ID: " << id << "\n";
    // -- Get Patient Info --
    cout << "Enter First Name: ";
    getline(cin, fname);
    cout << "Enter Last Name: ";
    getline(cin, lname);
    cout << "Enter Date of Birth: ";
    getline(cin, dob);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Disease: ";
    getline(cin, disease);
    cout << "Enter Treatment: ";
    getline(cin, treatment);
    cout << "Enter Billed Amount: ";
    while (!(cin >> billed) || billed < 0)
    {
        cout << "Invalid input. Please enter a valid positive number for the billed amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Days Admitted: ";
    while (!(cin >> daysAdmitted) || daysAdmitted < 0)
    {
        cout << "Invalid input. Please enter a valid number of days admitted: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // -- Determine hospital with lowest load --
    map<string, int> hospitalCounts;
    ifstream infile("res/PatientsRecords.txt");
    string line;

    while (getline(infile, line))
    {
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> quoted(token) || iss >> token)
            tokens.push_back(token);

        if (tokens.size() >= 12 && tokens[9] == "True")
            hospitalCounts[tokens[11]]++;
    }
    infile.close();

    vector<string> hospitals = {
        "Windsor Regional Hospital",
        "Erie Shore Regional Hospital",
        "Tecumseh Regional Hospital",
        "Kingsville Regional Hospital",
        "Amherstburg Regional Hospital"};

    string selectedHospital = hospitals[0];
    int minCount = hospitalCounts[selectedHospital];

    for (const string &h : hospitals)
    {
        if (hospitalCounts[h] < minCount)
        {
            minCount = hospitalCounts[h];
            selectedHospital = h;
        }
    }

    if (minCount >= 20)
    {
        cout << "All hospitals are at full capacity!\n";
        return;
    }

    // -- Save to file --
    ofstream out("res/PatientsRecords.txt", ios::app);
    out << quoted(id) << " "
        << quoted(fname) << " "
        << quoted(lname) << " "
        << quoted(dob) << " "
        << quoted(address) << " "
        << quoted(phone) << " "
        << quoted(disease) << " "
        << quoted(treatment) << " "
        << billed << " "
        << (checkin ? "True" : "False") << " "
        << daysAdmitted << " "
        << quoted(selectedHospital) << "\n";
    out.close();

    cout << "Patient " << fname << " " << lname << " successfully admitted to " << selectedHospital << ".\n";
}
/*
    Auth: Spondon
    Reason: Reads from file instead of memory
            makes it so changes are reflected in file
                so when next instance of program is made it isnt reset to orgin hospital
*/
void Patients::Relocate_Patient()
{
    string patientID;
    cout << "Enter Patient ID: ";
    cin >> patientID;

    vector<string> hospitals = {
        "Windsor Regional Hospital",
        "Erie Shore Regional Hospital",
        "Tecumseh Regional Hospital",
        "Kingsville Regional Hospital",
        "Amherstburg Regional Hospital"};

    // Show available hospital options
    cout << "\nAvailable Hospitals:\n";
    for (size_t i = 0; i < hospitals.size(); ++i)
    {
        cout << " " << (i + 1) << ". " << hospitals[i] << "\n";
    }

    string newHospital;
    cin.ignore();
    while (true)
    {
        cout << "\nEnter the name of the new hospital to relocate to: ";
        getline(cin, newHospital);
        newHospital = FormatName(newHospital);

        if (find(hospitals.begin(), hospitals.end(), newHospital) != hospitals.end())
            break;

        cout << "Invalid hospital name. Please enter one exactly from the list.\n";
    }

    ifstream infile("res/PatientsRecords.txt");
    if (!infile)
    {
        cerr << "Error: Cannot open res/PatientsRecords.txt for reading.\n";
        return;
    }

    vector<string> updatedLines;
    string line;
    bool found = false;
    int newHospitalCount = 0;

    // First pass: count patients in newHospital
    while (getline(infile, line))
    {
        istringstream iss(line);
        string id, fname, lname, dob, address, phone, disease, treatment, checkinStr, hospitalName;
        double billed;
        int daysAdmitted;

        iss >> quoted(id) >> quoted(fname) >> quoted(lname) >> quoted(dob) >> quoted(address) >> quoted(phone) >> quoted(disease) >> quoted(treatment) >> billed >> checkinStr >> daysAdmitted >> quoted(hospitalName);

        if (hospitalName == newHospital)
            newHospitalCount++;
    }

    infile.clear();
    infile.seekg(0);

    if (newHospitalCount >= 20)
    {
        cout << "The destination hospital is at full capacity. Cannot relocate.\n";
        return;
    }

    // Second pass: update patient hospital if matched
    while (getline(infile, line))
    {
        istringstream iss(line);
        string id, fname, lname, dob, address, phone, disease, treatment, checkinStr, hospitalName;
        double billed;
        int daysAdmitted;

        iss >> quoted(id) >> quoted(fname) >> quoted(lname) >> quoted(dob) >> quoted(address) >> quoted(phone) >> quoted(disease) >> quoted(treatment) >> billed >> checkinStr >> daysAdmitted >> quoted(hospitalName);

        if (id == patientID)
        {
            hospitalName = newHospital;
            found = true;
        }

        ostringstream updated;
        updated << quoted(id) << " " << quoted(fname) << " " << quoted(lname) << " " << quoted(dob) << " "
                << quoted(address) << " " << quoted(phone) << " " << quoted(disease) << " " << quoted(treatment) << " "
                << billed << " " << checkinStr << " " << daysAdmitted << " " << quoted(hospitalName);

        updatedLines.push_back(updated.str());
    }
    infile.close();

    if (!found)
    {
        cout << "Patient ID not found.\n";
        return;
    }

    ofstream outfile("res/PatientsRecords.txt");
    if (!outfile)
    {
        cerr << "Error: Cannot open PatientsRecords.txt for writing.\n";
        return;
    }

    for (const auto &updatedLine : updatedLines)
    {
        outfile << updatedLine << "\n";
    }

    cout << "Patient ID " << patientID << " successfully relocated to " << newHospital << ".\n";
}