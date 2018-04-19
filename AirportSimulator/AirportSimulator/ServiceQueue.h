#ifndef SERVICE_Q_H_
#define SERVICE_Q_H_

#include <queue>
#include <vector>
#include "Plane.h"
#include "LandingQueue.h"
#include "DepartureQueue.h"
#include "Random.h"

extern Random my_random; // Enables us to access the global variable declared in Simulator.h

/** The service queue takes a plane from the landing queue and adds it to its queue.
    When a plane in service queue has finished being serviced, it will be placed in the departure queue.
*/
class ServiceQueue
{
private:
	int min_service_time, max_service_time;  // range of service times
	LandingQueue *landing_queue;             // pointer to the landing queue
	DepartureQueue *departure_queue;         // pointer to the departure queue
	std::vector<Plane *> the_queue;           // vector of planes in the service queue
	int gates;
public:
	ServiceQueue() {}

	void set_service_times(int min_service_time, int max_service_time) {
		this->min_service_time = min_service_time;
		this->max_service_time = max_service_time;
	}

	void set_landing_queue(LandingQueue *landing_queue) {
		this->landing_queue = landing_queue;
	}

	void set_departure_queue(DepartureQueue *departure_queue) {
		this->departure_queue = departure_queue;
	}

	void set_gates(int gates) {
		this->gates = gates;
	}

	void update(int clock) 
	{
		//there are planes in the queue
		if (!the_queue.empty()) {

			for(int i = 0; i < the_queue.size(); i++){

				Plane *plane = the_queue[i];

				// check if a plane is ready to move from the service queue to the departure queue
				if ((clock - plane->start_service_time) > plane->service_time) {
					//remove plane from the service queue
					the_queue.erase(the_queue.begin() + i);

					//update the enter_departure_time attribute for the plane
					plane->enter_departure_time = clock;

					departure_queue->the_queue.push(plane);
				}
			}
		}
		

			// there are open gates - ready to serve!
		while (the_queue.size() < gates && !landing_queue->the_queue.empty()) {

			// move a plane from the landing queue to the service queue
			Plane *plane = landing_queue->the_queue.front();
			landing_queue->the_queue.pop();

			//calculate the wait time of the plane in the landing queue
			int wait = clock - plane->arrival_time;

			//update total_wait and num_served for the landing queue
			landing_queue->num_served++;
			landing_queue->total_wait += wait;


			//update the start_service_time attribute for the plane
			plane->start_service_time = clock;

			//compute a random service time for the plane between min_service_time and max_service_time
			plane->service_time = (min_service_time + my_random.next_int(max_service_time - min_service_time));


			//add the plane to the service queue
			the_queue.push_back(plane);


		}
	}

};

#endif