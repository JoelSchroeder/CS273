#ifndef _TICKET_H_
#define _TICKET_H_

/**
* Abstract Base Class for PartyTicket
* This class just defines the methods that need to be implemented by its derived classes
*/
class PartyTicket
{
public:

	/**
	* Allows a party goer to leave a party
	*/
	virtual void leave() = 0;
};
#endif