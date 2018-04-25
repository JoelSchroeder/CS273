#include "DinnerPartyTicket.h"
#include "DinnerParty.h"

/**
* Implements the leave method
*/
void DinnerPartyTicket::leave() {
	DinnerParty * actual_party = dynamic_cast<DinnerParty *>(the_party); // down-cast base class to derived class
	actual_party->remove(me); // call remove DinnerParty remove method to erase party goes identified by "me"
}