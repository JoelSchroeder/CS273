#ifndef EMERGENCY_ROOM_H_
#define EMERGENCY_ROOM_H_
#include <iostream>
#include <cstdlib>
#include <queue>
#include "Resident.h"
#include "Waiting_Room.h"
#include "CompareTime.h"

extern Random random;

class Emergency_Room {
private:
	int num_doctors;
	int num_nurses;

	int busy_docs;
	int busy_nurses;

	priority_queue<Patient, std::vector<Patient>, CompareTime> patients;

	friend class Waiting_Room;
	Waiting_Room *the_waiting_room;

public:
	


	Emergency_Room(int docs, int nurs) {
		num_doctors = docs;
		num_nurses = nurs;
	
	}

	void set_waiting_room(Waiting_Room *the_waiting_room) {
		this->the_waiting_room = the_waiting_room;
	}

	void update(int clock) {
		if (!patients.empty())
		{
			//check if patient is ready to move on
			Patient pat = patients.top();
			if (pat.treatment_time + pat.start_treatment >= clock)
			{
				patients.pop();
			}
		}




		while (busy_docs < num_doctors || busy_nurses < num_nurses) {
			Patient pat = the_waiting_room->patients.top();
			if (pat.priority_number <= 10) {
				if (busy_nurses < num_nurses)
				{
					the_waiting_room->patients.pop();
					pat.set_wait_time(clock);
					pat.doc = false;
					busy_nurses++;

					//calculate treatment time
					pat.treatment_time = random.next_int(9) + 1;
					
					patients.push(pat);
				}
				else {
					the_waiting_room->patients.pop();
					pat.set_wait_time(clock);
					pat.doc = true;
					busy_docs++;

					//calculate treatment time
					pat.treatment_time = random.next_int(19) + 1;

					patients.push(pat);
				}
			}
			else if (busy_docs < num_doctors) {
				the_waiting_room->patients.pop();
				pat.set_wait_time(clock);
				pat.doc = true;
				busy_docs++;

				//calculate treatment time
				pat.treatment_time = random.next_int(19) + 1;

				patients.push(pat);
			}
			else {
				break;
			}


		}



	}


};













#endif 

