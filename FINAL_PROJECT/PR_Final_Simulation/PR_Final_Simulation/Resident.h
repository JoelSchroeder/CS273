#ifndef RESIDENT_H_
#define RESIDENT_H_
#include<string>
#include<iostream>
#include <fstream>
#include <stdexcept>
using namespace std;


class Resident {
private:
	std::string name;
	

public:
	Resident() {};

	Resident(std::string new_name) 
	{
		name = new_name;
	
	}

	std::string get_name() {
		return name;
	}
	

};



























#endif 

