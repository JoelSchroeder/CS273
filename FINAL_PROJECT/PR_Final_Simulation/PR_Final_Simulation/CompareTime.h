#ifndef COMPARETIME_H_
#define COMPARETIME_H_
#include "Patient.h"

struct CompareTime
{
	bool operator()(const Patient& lhs, const Patient& rhs) const
	{
		return lhs.treatment_time > rhs.treatment_time;
	}
};



#endif 
