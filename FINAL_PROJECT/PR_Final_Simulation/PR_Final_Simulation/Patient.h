#ifndef PATIENT_H_
#define PATIENT_H_
#include<string>
#include<iostream>
#include <fstream>
#include <stdexcept>
#include "Resident.h"
using namespace std;


class Patient: public Resident {
private:
	int arrival_time;
	int wait_time;
	
	

public:

	Patient() {}

	int start_treatment;
	int priority_number;
	int treatment_time;
	bool doc;
	Patient(std::string name, int ariv, int prio) : Resident(name)
	{
		arrival_time = ariv;
		wait_time = 0;
		treatment_time = 0;
		priority_number = prio;
		doc = NULL;

	}

	void set_wait_time(int clock) {
		wait_time = clock - arrival_time;
		start_treatment = wait_time + arrival_time;
	}


};



#endif