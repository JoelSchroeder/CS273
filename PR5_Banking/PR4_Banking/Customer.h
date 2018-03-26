#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates, 
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer {
protected:
	std::string name;
	std::string adress;
	int age;
	std::string telephone_number;
	int customer_number;

public:
	virtual double Get_SAVINGS_INTEREST() = 0;
	virtual double Get_CHECK_INTEREST() = 0;
	virtual int Get_CHECK_CHARGE() = 0;
	virtual int Get_OVERDREFT_PENELTY() = 0;


	std::string getName() {
		return name;
	}

	void setName(std::string n) {
		name = n;
	}

	std::string getAdress() {
		return adress;
	}

	void setAdress(std::string a) {
		adress = a;
	}

	int getAge() {
		return age;
	}

	void setAge(int a) {
		age = a;
	}

	std::string getTelephone_number() {
		return telephone_number;
	}

	void setTelephone_number(std::string t) {
		telephone_number = t;
	}

	int getCustomer_number() {
		return customer_number;
	}

	void setCustomer_number(int c) {
		customer_number = c;
	}

};



class Senior : public Customer {
private:
	const double SAVINGS_INTEREST = 1 ;
	const double CHECK_INTEREST = 1.5;
	const int CHECK_CHARGE = 10;
	const int OVERDREFT_PENELTY = 15;
public:
	double Get_SAVINGS_INTEREST() {
		return SAVINGS_INTEREST;
	}

	double Get_CHECK_INTEREST() {
		return CHECK_INTEREST;
	}

	int Get_CHECK_CHARGE() {
		return CHECK_CHARGE;
	}

	int Get_OVERDREFT_PENELTY() {
		return OVERDREFT_PENELTY;
	}
};


class Student : public Customer {
private:
	const double SAVINGS_INTEREST = 2;
	const double CHECK_INTEREST = 2.5;
	const int CHECK_CHARGE = 20;
	const int OVERDREFT_PENELTY = 25;
public:
	double Get_SAVINGS_INTEREST() {
		return SAVINGS_INTEREST;
	}

	double Get_CHECK_INTEREST() {
		return CHECK_INTEREST;
	}

	int Get_CHECK_CHARGE() {
		return CHECK_CHARGE;
	}

	int Get_OVERDREFT_PENELTY() {
		return OVERDREFT_PENELTY;
	}
};


class Adult : public Customer {
private:
	const double SAVINGS_INTEREST = 3;
	const double CHECK_INTEREST = 3.5;
	const int CHECK_CHARGE = 30;
	const int OVERDREFT_PENELTY = 35;
public:
	double Get_SAVINGS_INTEREST() {
		return SAVINGS_INTEREST;
	}

	double Get_CHECK_INTEREST() {
		return CHECK_INTEREST;
	}

	int Get_CHECK_CHARGE() {
		return CHECK_CHARGE;
	}

	int Get_OVERDREFT_PENELTY() {
		return OVERDREFT_PENELTY;
	}
};

#endif