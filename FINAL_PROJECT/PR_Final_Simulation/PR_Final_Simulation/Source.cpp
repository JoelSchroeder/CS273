#include <iostream>
#include "Town.h"
using namespace std;



int main()
{
	
	//get values
	int arrival_rate = 61;
	int num_doctors = 0;
	int num_nurses = 0;

	while (arrival_rate > 60) {
		cout << "enter how many patients will arrive each hour (must be less than 60): ";
		cin >> arrival_rate;
	}
	cout << "enter the number of doctors: ";
	cin >> num_doctors;
	cout << "now enter the number of nurses: ";
	cin >> num_nurses;
	
	
	Town town_273ville(arrival_rate, num_doctors, num_nurses);
	town_273ville.run_simulation();


}