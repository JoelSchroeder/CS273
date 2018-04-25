#include "BirthdayPartyTicket.h"
#include "BirthdayParty.h"

/**
* Implements the leave method
*/
void BirthdayPartyTicket::leave() {
	//4: Implement leave for birthday parties
	BirthdayParty * actual_party = dynamic_cast<BirthdayParty *>(the_party); // down-cast base class to derived class
	actual_party->remove(me); // call remove DinnerParty remove method to erase party goes identified by "me"
}
