#ifndef DOCTORS_H
#define DOCTORS_H

#include <iostream>
#include <vector>
#include <string>

class Doctors {
public:
    // Define the Doctor struct
    struct Doctor {
        int id;
        std::string name;
        std::string specialty;
        std::string hospitalName;
        std::vector<int> patientIds;
    };

    // Define the Patient struct
    struct Patient {
        int id;
        std::string name;
        int primaryDoctorId = -1;
        std::vector<int> attendingDoctors;
    };

    static std::vector<Doctor> doctorList;
    static std::vector<Patient> patientList;

    // Function to list all doctors
    static void listDoctors();

    // Function to view doctor details based on doctor ID
    static void viewDoctorDetails(int doctorId);

    // Function to assign a doctor to a patient
    static void assignDoctorToPatient(int patientId, int doctorId);

    // Function to assign a primary doctor to a patient
    static void assignPrimaryDoctor(int patientId, int doctorId);

    // Function to assign an attending doctor to a patient
    static void assignAttendingDoctor(int patientId, int doctorId);

    // Function to view patient details
    static void viewPatientDetails(int patientId);
};

#endif
