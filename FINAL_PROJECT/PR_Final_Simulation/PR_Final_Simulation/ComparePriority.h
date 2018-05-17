#ifndef COMPAREPRIORITY_H_
#define COMPAREPRIORITY_H_
#include "Patient.h"

struct ComparePriority
{
	bool operator()(const Patient& lhs, const Patient& rhs) const
	{
		return lhs.priority_number < rhs.priority_number;
	}
};



#endif 

