#ifndef _PARTY_H_
#define _PARTY_H_
#include <string>
#include "PartyTicket.h"

/**
* Abstract Base Class for Party.  
* This class just defines the methods that need to be implemented in its derived classes.
*/
class Party
{
public:

	/**
	* Adds a person to the party, and returns a party ticket
	*/
	virtual PartyTicket * add(std::string name) = 0;

	/**
	* List the people currently in the party
	*/
	virtual void list() = 0;
};

#endif