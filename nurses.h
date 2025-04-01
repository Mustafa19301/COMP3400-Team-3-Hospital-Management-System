#ifndef NURSES_H
#define NURSES_H

#include <string>
#include <vector>

class Nurses {
public:
    // Structure to represent a Nurse
    struct Nurse {
        int id;
        std::string name;
        std::string hospitalName;
        std::vector<int> patientIds;
    };

    // Structure to represent a Patient
    struct Patient {
        int id;
        std::string name;
    };

    // Static lists to hold nurse and patient data
    static std::vector<Nurse> nurseList;
    static std::vector<Patient> patientList;

    // Function to list all nurses
    static void listNurses();

    // Function to view details of a specific nurse
    static void viewNurseDetails(int nurseId);

    // Function to assign a nurse to a patient
    static void assignNurseToPatient(int patientId, int nurseId);

    // Function to view patient details
    static void viewPatientDetails(int patientId);
};

#endif
