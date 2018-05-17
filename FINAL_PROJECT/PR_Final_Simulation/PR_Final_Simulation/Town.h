#ifndef TOWN_H_
#define TOWN_H_

#include <vector>
#include "Resident.h"
#include <iterator>
#include <set>
#include <stack>
#include "Waiting_Room.h"
#include "Emergency_Room.h"
#include "Random.h"

Random random;

class Town
{
private:
	std::vector<Resident> residents;
	int size;
	int arrival_rate;

	Emergency_Room *the_emergency_room;
	Waiting_Room *the_waiting_room;
	

public:

	Town(int rate, int docs, int nurs)//constructor for the town
	{
		size = 2000;
		arrival_rate = rate;
		std::set<string> names = initialize_names();

		for (set<string>::iterator it = names.begin(); it != names.end(); ++it)
		{

			Resident new_res(*it);
			residents.push_back(new_res);
		}

		the_waiting_room = new Waiting_Room();
		the_emergency_room = new Emergency_Room(docs, nurs);

	}


	//reads the names form the files
	std::set<string> initialize_names() {

		std::set<string> names;
		
		std::ifstream file("residents_of_273ville.txt");
		std::ifstream file2("surnames_of_273ville.txt");
		std::string line;
		std::string line2;

		for (int i = 0; i < 2000; i++) {
			std::getline(file, line);
			std::getline(file2, line2);

			
			names.insert((line + " ") + line2);
		}
		
		file.close();
		file2.close();

		return names;
	}




	void run_simulation()
	{
		// run the simulation
		for (int clock = 0; clock < 10080; ++clock)
		{
			//decide if a resident gets sick this round
			if (random.next_int(60) < arrival_rate)
			{
				//find a random resident to become a patient
				int sr = random.next_int(2000);
				std::string name = residents[sr].get_name();
				the_waiting_room->update(name, clock);
			}

			//update the ER

			the_emergency_room->update(clock);

			

		}
	}


	
};












#endif