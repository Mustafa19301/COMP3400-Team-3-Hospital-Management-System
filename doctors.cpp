#include "doctors.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

std::vector<Doctors::Doctor> Doctors::doctorList = {
    {29789, "Dr. Smith", "Oncology", {11000, 11001}},
    {22578, "Dr. Johnson", "General Surgery", {11002, 11003}},
    {28713, "Dr. Williams", "Rheumatology", {11004, 11005}},
    {25741, "Dr. Brown", "Radiology", {11006, 11007}},
    {21956, "Dr. Jones", "Pediatrics", {11008, 11009}},
    {27169, "Dr. Miller", "Cardiology", {11010, 11011}},
    {28902, "Dr. Davis", "Neurology", {11012, 11013}},
    {29234, "Dr. Garcia", "Orthopedics", {11014, 11015}},
    {26098, "Dr. Rodriguez", "Dermatology", {11016, 11017}},
    {24352, "Dr. Wilson", "Endocrinology", {11018, 11019}},
    {29641, "Dr. Martinez", "Oncology", {11020, 11021}},
    {20431, "Dr. Anderson", "General Surgery", {11022, 11023}},
    {29902, "Dr. Taylor", "Rheumatology", {11024, 11025}},
    {21157, "Dr. Thomas", "Radiology", {11026, 11027}},
    {23286, "Dr. Hernandez", "Pediatrics", {11028, 11029}},
    {22298, "Dr. Moore", "Cardiology", {11030, 11031}},
    {29110, "Dr. Martin", "Neurology", {11032, 11033}},
    {25548, "Dr. Jackson", "Orthopedics", {11034, 11035}},
    {29037, "Dr. Thompson", "Dermatology", {11036, 11037}},
    {28809, "Dr. White", "Endocrinology", {11038, 11039}},
    {20748, "Dr. Lopez", "Oncology", {11040, 11041}},
    {24457, "Dr. Lee", "General Surgery", {11042, 11043}},
    {29765, "Dr. Gonzalez", "Rheumatology", {11044, 11045}},
    {28694, "Dr. Harris", "Radiology", {11046, 11047}},
    {20986, "Dr. Clark", "Pediatrics", {11048, 11049}},
    {20315, "Dr. Lewis", "Cardiology", {11050, 11051}},
    {21209, "Dr. Robinson", "Neurology", {11052, 11053}},
    {27819, "Dr. Walker", "Orthopedics", {11054, 11055}},
    {29571, "Dr. Perez", "Dermatology", {11056, 11057}},
    {27065, "Dr. Hall", "Endocrinology", {11058, 11059}},
    {22241, "Dr. Young", "Oncology", {11060, 11061}},
    {21907, "Dr. Allen", "General Surgery", {11062, 11063}},
    {20965, "Dr. Sanchez", "Rheumatology", {11064, 11065}},
    {28514, "Dr. Wright", "Radiology", {11066, 11067}},
    {23689, "Dr. King", "Pediatrics", {11068, 11069}},
    {26879, "Dr. Scott", "Cardiology", {11070, 11071}},
    {21138, "Dr. Green", "Neurology", {11072, 11073}},
    {29620, "Dr. Baker", "Orthopedics", {11074, 11075}},
    {24890, "Dr. Adams", "Dermatology", {11076, 11077}},
    {24132, "Dr. Nelson", "Endocrinology", {11078, 11079}},
    {28751, "Dr. Carter", "Oncology", {11080, 11081}},
    {22784, "Dr. Mitchell", "General Surgery", {11082, 11083}},
    {25947, "Dr. Roberts", "Rheumatology", {11084, 11085}},
    {23364, "Dr. Phillips", "Radiology", {11086, 11087}},
    {20641, "Dr. Evans", "Pediatrics", {11088, 11089}},
    {29476, "Dr. Campbell", "Cardiology", {11090, 11091}},
    {20058, "Dr. Parker", "Neurology", {11092, 11093}},
    {22347, "Dr. Edwards", "Orthopedics", {11094, 11095}},
    {29001, "Dr. Collins", "Dermatology", {11096, 11097}},
};


std::vector<Doctors::Patient> Doctors::patientList = {
    {11000, "Emily Soto", -1, {}},
    {11001, "Dustin Coleman", -1, {}},
    {11002, "Amanda Rosario", -1, {}},
    {11003, "Douglas Ryan", -1, {}},
    {11004, "Angela Smith", -1, {}},
    {11005, "Christina Farmer", -1, {}},
    {11006, "Ray Riley", -1, {}},
    {11007, "Katherine Valenzuela", -1, {}},
    {11008, "Rebecca Johnson", -1, {}},
    {11009, "Edward Moyer", -1, {}},
    {11010, "Amanda Caldwell", -1, {}},
    {11011, "Mark Moore", -1, {}},
    {11012, "Monique Hill", -1, {}},
    {11013, "Jacob Hanna", -1, {}},
    {11014, "Sean Young", -1, {}},
    {11015, "Summer Diaz", -1, {}},
    {11016, "Beverly Hendricks", -1, {}},
    {11017, "Valerie Spears", -1, {}},
    {11018, "Richard Martin", -1, {}},
    {11019, "John Pitts", -1, {}},
    {11020, "Jason Gallegos", -1, {}},
    {11021, "Sandra Williams", -1, {}},
    {11022, "Matthew Gibson", -1, {}},
    {11023, "Sheila Jackson", -1, {}},
    {11024, "Morgan Richardson", -1, {}},
    {11025, "Jason Harmon", -1, {}},
    {11026, "Sydney Woods", -1, {}},
    {11027, "Daniel Carter", -1, {}},
    {11028, "Catherine Sullivan", -1, {}},
    {11029, "Candice Knapp", -1, {}},
    {11030, "Alexander Cole", -1, {}},
    {11031, "Julie Garcia", -1, {}},
    {11032, "Mark Little", -1, {}},
    {11033, "Susan Mcdonald", -1, {}},
    {11034, "Candice Richardson", -1, {}},
    {11035, "Brendan Mills", -1, {}},
    {11036, "Kenneth Park", -1, {}},
    {11037, "Richard Garcia", -1, {}},
    {11038, "Jonathan Roberts", -1, {}},
    {11039, "Heidi Hayes", -1, {}},
    {11040, "Sharon King", -1, {}},
    {11041, "Charles Davis", -1, {}},
    {11042, "Donald Moore", -1, {}},
    {11043, "Brittney Cuevas", -1, {}},
    {11044, "Randy Freeman", -1, {}},
    {11045, "Ashley Turner", -1, {}},
    {11046, "Kenneth Garcia", -1, {}},
    {11047, "Jillian Jimenez", -1, {}},
    {11048, "Katherine Brooks", -1, {}},
    {11049, "Veronica Lyons", -1, {}},
    {11050, "Ronald Davis", -1, {}},
    {11051, "Charles Day", -1, {}},
    {11052, "Jamie Gross", -1, {}},
    {11053, "Dawn Holloway", -1, {}},
    {11054, "Rebecca Johnson", -1, {}},
    {11055, "Robert Harris", -1, {}},
    {11056, "Brooke Parker", -1, {}},
    {11057, "Kenneth Peters", -1, {}},
    {11058, "Latasha Gomez", -1, {}},
    {11059, "Mark Vang", -1, {}},
    {11060, "Roger Ortega", -1, {}},
    {11061, "Julie Matthews", -1, {}},
    {11062, "Matthew Diaz", -1, {}},
    {11063, "Pam Flores", -1, {}},
    {11064, "Jason Myers", -1, {}},
    {11065, "Pamela Oneill", -1, {}},
    {11066, "Jeffery Marshall", -1, {}},
    {11067, "Joseph Mays", -1, {}},
    {11068, "Henry Parker", -1, {}},
    {11069, "Sherri Stevens", -1, {}},
    {11070, "Tonya Garcia", -1, {}},
    {11071, "Raymond Frank", -1, {}},
    {11072, "Gloria Hawkins", -1, {}},
    {11073, "Andrew Leonard", -1, {}},
    {11074, "Anthony Vincent", -1, {}},
    {11075, "Sandra White", -1, {}},
    {11076, "Charles Wilson", -1, {}},
    {11077, "Michelle Silva", -1, {}},
    {11078, "Lisa Greene", -1, {}},
    {11079, "Laura Smith", -1, {}},
    {11080, "Susan Walker", -1, {}},
    {11081, "Alan Kelley", -1, {}},
    {11082, "Eugene Ramirez", -1, {}},
    {11083, "Antonio Saunders", -1, {}},
    {11084, "Diane Bernard", -1, {}},
    {11085, "Kelli Preston", -1, {}},
    {11086, "Susan Bauer", -1, {}},
    {11087, "Kendra Smith", -1, {}},
    {11088, "Elizabeth Freeman", -1, {}},
    {11089, "Kathy Medina", -1, {}},
    {11090, "John Bryan", -1, {}},
    {11091, "Justin Stuart", -1, {}},
    {11092, "Christopher Martinez", -1, {}},
    {11093, "Shane Hodges", -1, {}},
    {11094, "Robert Horton", -1, {}},
    {11095, "Lauren Aguirre", -1, {}},
    {11096, "Erin Rice", -1, {}},
    {11097, "Jacob Anderson", -1, {}},
    {11098, "Michael Meyer", -1, {}},
    {11099, "Justin Turner", -1, {}},
};


// List all doctors
void Doctors::listDoctors() {
    std::cout << "\nList of Doctors:\n";
    for (const auto& doctor : doctorList) {
        std::cout << "ID: " << doctor.id << ", Name: " << doctor.name << ", Specialty: " << doctor.specialty << "\n";
    }
}

// View doctor details based on doctor ID
void Doctors::viewDoctorDetails(int doctorId) {
    for (const auto& doctor : doctorList) {
        if (doctor.id == doctorId) {
            std::cout << "\nDoctor Details:\n";
            std::cout << "ID: " << doctor.id << "\n";
            std::cout << "Name: " << doctor.name << "\n";
            std::cout << "Specialty: " << doctor.specialty << "\n";
            std::cout << "Assigned Patients: ";
            for (int patientId : doctor.patientIds) {
                std::cout << patientId << " ";
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Doctor not found with ID: " << doctorId << "\n";
}

// Assign a doctor to a patient
void Doctors::assignDoctorToPatient(int patientId, int doctorId) {
    for (auto& doctor : doctorList) {
        if (doctor.id == doctorId) {
            doctor.patientIds.push_back(patientId);
            std::cout << "Assigned Doctor ID " << doctorId << " to Patient ID " << patientId << "\n";
            return;
        }
    }
    std::cout << "Doctor not found with ID: " << doctorId << "\n";
}

// Assign a primary doctor to a patient
void Doctors::assignPrimaryDoctor(int patientId, int doctorId) {
    // Find the patient
    for (auto& patient : patientList) {
        if (patient.id == patientId) {
            if (patient.primaryDoctorId == -1) {
                // Assign the primary doctor if no primary doctor is assigned yet
                patient.primaryDoctorId = doctorId;
                std::cout << "Assigned Doctor ID " << doctorId << " as the primary doctor for Patient ID " << patientId << "\n";
            } else {
                std::cout << "Patient ID " << patientId << " already has a primary doctor (ID " << patient.primaryDoctorId << ").\n";
            }
            return;
        }
    }
    std::cout << "Patient with ID " << patientId << " not found.\n";
}

// Assign an attending doctor to a patient
void Doctors::assignAttendingDoctor(int patientId, int doctorId) {
    for (auto& patient : patientList) {
        if (patient.id == patientId) {
            // Add the doctor to the attending doctors list
            patient.attendingDoctors.push_back(doctorId);
            std::cout << "Assigned Doctor ID " << doctorId << " as an attending doctor for Patient ID " << patientId << "\n";
            return;
        }
    }
    std::cout << "Patient with ID " << patientId << " not found.\n";
}

// View patient details, including primary doctor and attending doctors
void Doctors::viewPatientDetails(int patientId) {
    for (const auto& patient : patientList) {
        if (patient.id == patientId) {
            std::cout << "\nPatient ID: " << patient.id << ", Name: " << patient.name << "\n";
            std::cout << "Primary Doctor ID: " << patient.primaryDoctorId << "\n";
            std::cout << "Attending Doctors: ";
            for (const auto& doctorId : patient.attendingDoctors) {
                std::cout << doctorId << " ";
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Patient with ID " << patientId << " not found.\n";
} 