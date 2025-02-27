#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
using namespace std;

int main() {
    std::cout << "Loading Hospital Management System..." << "\n";
    std::cout << "Welcome to the Hospital Management System! Developed by Team 3" << "\n";

    //using ftlk as the GUI base
    Fl_Window win(400, 350, "COMP3400 Team 3 Hospital Management System");

    //title for the Hospital Management System
    Fl_Box title(50, 10, 300, 40, "Hospital Management System");
    title.labelsize(18);
    title.labelfont(FL_BOLD);
        
    //buttons for the selection (will discuss on layout)
    Fl_Button but1(150, 50, 100, 30, "Hospitals");
    Fl_Button but2(150, 100, 100, 30, "Pharmacies");
    Fl_Button but3(150, 150, 100, 30, "Patients");
    Fl_Button but4(150, 200, 100, 30, "Doctors");
    Fl_Button but5(150, 250, 100, 30, "Nurses");

    win.end();
    win.show();
    return Fl::run();
    //here will call instance objects from the core classes
    //will have to implement the core classes before calling them
    //this is just a rough draft of the code and more implementation will come soon...
}
