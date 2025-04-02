# COMP3400-Team-3-Hospital-Management-System
Welcome to the COMP3400 Team 3 Hospital Management System developed by Mustafa, Murtaza and Spondon.

Here in this project, our group will be utilizing Object-Oriented Programming language C++ that uses core content from our lectures. You will notice content used such as constructors, overloading, OOP concepts like inheritance and many more to come.

## Before getting started on this Directory
This project is focused on using a text-based that will use the console terminal. Most of the work showcased will be on the console to provide a better structured Hospital Management System. Ensure that you have C++ version up to date and installed to be able to run this project.

## Core classes for this Hospital Management System
The management system will operate core classes such as Hospitals, Patients, Doctors, Pharmacies & Nurses. Each of these core classes have their own purpose and relationships that also connect with other core classes to functionally work together.

## Files in this Repository
- `res/PatientsRecords.txt`
- `res/PatientBillingRecords.txt`
- `res/ArchivedPatientRecords.txt`
- `.gitignore`
- `main.cpp`
- `hospitals.cpp`
- `hospitals.h`
- `pharmacies.cpp`
- `pharmacies.h`
- `patients.cpp`
- `patients.h`
- `doctors.cpp`
- `doctors.h`
- `nurses.cpp`
- `nurses.h`
- `PatientsRecords.txt`
- `pharmacybilling.txt`
- `README.md`

## Code Compilation Command
Do ensure you git clone this repository onto your own directory to have access to the coding files. Once you have git cloned the repository onto your directory, your pretty much ready to run the program. Before running ensure you C++ is up to date. To run this program simply type or copy and paste this command: g++ -std=c++23 -Wall -Wextra -Wold-style-cast -Werror -pedantic -O3 -march=native main.cpp hospitals.cpp pharmacies.cpp doctors.cpp nurses.cpp patients.cpp

## Code Compilation Command Cont..
Give it a few seconds for the system to compile the command. Once its ready, you will then type or copy and paste this command: ./a.out PatientsRecords.txt

## The Text-Based Console
Once you have it ready and have typed the command to run it, you should be able to see the Console Output that shows an option list for the Hospital Management System. Each of the options for the Hospital Management System have their own task in which you can explore the program.

## The Expected Text-Based Console Output
```cpp
Loading Hospital Management System...
Welcome to the Hospital Management System! Developed by Team 3

Hospital Management System
1. Hospital
2. Pharmacies
3. View Pharmacies Billing Records
4. Patients
5. Doctors
6. Nurses
7. Exit System
Enter your choice of option:
