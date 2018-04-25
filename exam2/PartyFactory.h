#ifndef _PARTY_FACTORY_H_
#define _PARTY_FACTORY_H_

#include <stdexcept>
#include <string>
#include "DinnerParty.h"
#include "BirthdayParty.h"

/**
* The Party Factory
* This class is used for making parties!
*/
class PartyFactory
{
public:
	friend class BirthdayParty;

	/**
	* The factory method is the only way of making a party
	* Please see the main() function to understand how it works!
	*/
	static Party *factory(std::string type) {
		if (type == "dinner") {
			return new DinnerParty(); // Creates a dinner party
		} 
		else if (type == "birthday") { // Create a birthday party?
			return new BirthdayParty();
		} 
		else
			throw std::invalid_argument("unknown type of party");
	}
};
#endif