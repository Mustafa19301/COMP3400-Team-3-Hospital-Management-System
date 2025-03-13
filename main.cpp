#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
using namespace std;

void show_hospitals_window(Fl_Widget*, void*);
void show_main_window(Fl_Widget*, void*);

Fl_Window* main_win = nullptr;
Fl_Window* hospitals_win = nullptr;

//function for the hopsitals window
void show_hospitals_window(Fl_Widget*, void*) {
    main_win->hide();

    //window created for Hospitals section
    hospitals_win = new Fl_Window(500, 400, "Hospitals Section");

    //title of the window
    Fl_Box* title = new Fl_Box(100, 20, 300, 40, "Hospitals Locations (100 patients total)");
    title->labelsize(18);
    title->labelfont(FL_BOLD);

    //box for 5 different hospitals locations
    Fl_Button* location1 = new Fl_Button(50, 80, 400, 30, "Windsor Regional Hospital (20 Admissions)");
    Fl_Button* location2 = new Fl_Button(50, 120, 400, 30, "Erie Shore Regional Hospital (20 Admissions)");
    Fl_Button* location3 = new Fl_Button(50, 160, 400, 30, "Tecumseh Regional Hospital (20 Admissions)");
    Fl_Button* location4 = new Fl_Button(50, 200, 400, 30, "Kingsville Regional Hospital (20 Admissions)");
    Fl_Button* location5 = new Fl_Button(50, 240, 400, 30, "Amhertsburg Regional Hospital (20 Admissions)");

    //this serves as a back button to go back
    Fl_Button* back_btn = new Fl_Button(200, 320, 100, 40, "Back");
    back_btn->callback(show_main_window);

    hospitals_win->end();
    hospitals_win->show();
}

void show_main_window(Fl_Widget*, void*) {
    if (hospitals_win) {
        hospitals_win->hide();
        delete hospitals_win;
        hospitals_win = nullptr;
    }
    main_win->show();
}

int main() {
    //std::cout << "Loading Hospital Management System..." << "\n";
    //std::cout << "Welcome to the Hospital Management System! Developed by Team 3" << "\n";

    //using ftlk as the GUI base
    main_win = new Fl_Window(500, 400, "COMP3400 Team 3 Hospital Management System");

    //title for the Hospital Management System
    Fl_Box* title = new Fl_Box(50, 10, 300, 40, "Hospital Management System");
    title->labelsize(18);
    title->labelfont(FL_BOLD);
        
    //buttons for the selection (will discuss on layout)
    Fl_Button* but1 = new Fl_Button(150, 50, 100, 30, "Hospitals");
    but1->callback(show_hospitals_window);

    Fl_Button* but2 = new Fl_Button(150, 100, 100, 30, "Pharmacies");
    Fl_Button* but3 = new Fl_Button(150, 150, 100, 30, "Patients");
    Fl_Button* but4 = new Fl_Button(150, 200, 100, 30, "Doctors");
    Fl_Button* but5 = new Fl_Button(150, 250, 100, 30, "Nurses");

    main_win->end();
    main_win->show();
    return Fl::run();
    //here will call instance objects from the core classes
    //will have to implement the core classes before calling them
    //this is just a rough draft of the code and more implementation will come soon...
}
