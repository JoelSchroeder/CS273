#ifndef WAITING_ROOM_H_
#define WAITING_ROOM_H_
#include <iostream>
#include <cstdlib>
#include <queue>
#include "Resident.h"
#include <ctime>
#include "Random.h"
#include"Patient.h"
#include "ComparePriority.h"
#include "Emergency_Room.h"

extern Random random;


class Waiting_Room {
private:
	priority_queue<Patient, std::vector<Patient>, ComparePriority> patients;
	

	
public:
	friend class Emergency_Room;

	Waiting_Room() {}

	//add a patient the waiting room
	void update(std::string name, int clock) {
	Patient * new_pat = new Patient(name, clock, triage());


	patients.push(*new_pat);
		
	}


	//returns a priority number for the patient
	int triage(){
		int p = (random.next_int(10));
		if (p < 7) {
			int t = (random.next_int(9));
			return t + 1;
		}
		else if (p < 9) {
			int t = (random.next_int(4));
			return t + 11;
		}
		else {
			int t = (random.next_int(4));
			return t + 16;
		}

	}

};













#endif 

