#include "hospitals.h"

//parametrized constructor called here
Hospitals::Hospitals(string hospitalid, string section, int cap) : Hospital_ID(hospitalid), Location(section), Capacity(cap) {}

void Hospitals::Admit(){
    //implementation of the admit patient will go here
}

void Hospitals::Pay(double x, string id){
    //implementation of the paying bill will go here
}