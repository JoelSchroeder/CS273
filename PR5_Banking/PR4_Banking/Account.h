#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <sstream>
#include "Customer.h"
#include "Transaction.h"

/**
The Bank has Accounts and an Account belongs to a Customer.
Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.

@author: Ed Walker
*/

class Account {
protected:
	Customer *customer;		// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;		// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account

	/**
	Describe fees associated with the customer who owns this account.
	The fee will depend on the specific type of customer.
	@return string showing checking and overdraft fees
	*/
	std::string get_fees()
	{
		int overdraft, charge;

		// Polymorphism: calls the correct virtual methods from the specific customer type
	
		overdraft = customer->Get_OVERDREFT_PENELTY();
		charge = customer->Get_CHECK_CHARGE();

		std::stringstream ss;
		ss << "Check Charge: " << charge << " Overdraft Fee: " << overdraft;
		return ss.str();
	}

protected:
	/**
	Add interest based on a specified interest rate to account
	@param interest	The interest rate
	*/
	void add_interest(double interest) {
		double amt = balance*interest;
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(customer->getCustomer_number(), "interest" , amt, fees);
		transactions.push_back(tran);
	}

public:
	/**
	Constructor requires a customer to create an account
	Balance always starts with 0 when account is created.
	*/
	explicit Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}

	/**
	Generic accesser and setter methods for properties customer, balance, and account_number
	*/

	Customer *get_customer() {
		return customer;
	}

	std::string get_customer_name() {
		return customer->getName();
	}

	void set_customer(Customer *cust) {
		customer = cust;
	}

	int get_account() {
		return account_number;
	}

	void set_balance(double new_balance) {
		balance = new_balance;
	}

	void set_account(int account_number) {
		this->account_number = account_number;
	}

	double get_balance() {
		return balance;
	}

	/**
	Generic method describing the account information.
	Overridden version includes account type
	@return string describing generic information about the account
	*/
	virtual std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

		// Add information about the customer who owns this account.
		ss << "  Owner Name: " << customer->getName() << std::endl;
		ss << "  Owner Phone Number: " << customer->getTelephone_number() << std::endl;
		ss << "  Owner Age: " << customer->getAge() << std::endl;
		ss << "  Owner Adress: " << customer->getAddress() << std::endl;
		ss << "  Owner ID: " << customer->getCustomer_number() << std::endl;
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}

	/**
	Deposits amount into account
	@param amt The deposit amount
	*/
	virtual void deposit(double amt) {
		balance += amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(customer->getCustomer_number(), "deposit", amt, fees);
		transactions.push_back(tran);
	}

	/**
	Withdraws amount from account
	@param amt The withdrawal amount
	*/
	virtual void withdraw(double amt) {
		balance -= amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(customer->getCustomer_number(), "withdrow", amt, fees);
		transactions.push_back(tran);
	}

	// We want the Savings_Account and Checking_Account to implement this.
	virtual void add_interest() = 0;

};




///////////////////////////Savings account/////////////////////////////////////////

class Savings_Acount : public Account {
public:
	using Account::Account;

	std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

							  
		ss << "  Owner Name: " << customer->getName() << std::endl;
		ss << "  Owner Phone Number: " << customer->getTelephone_number() << std::endl;
		ss << "  Owner Age: " << customer->getAge() << std::endl;
		ss << "  Owner Adress: " << customer->getAddress() << std::endl;
		ss << "  Owner ID: " << customer->getCustomer_number() << std::endl;
		ss << "  Account Type: Savings" << std::endl;
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}


	void add_interest() {
		double amt = balance*customer->Get_SAVINGS_INTEREST();
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(customer->getCustomer_number(), "interest", amt, fees);
		transactions.push_back(tran);
	}
};




/////////////////////////////Checking Account//////////////////////////////////////////////

class Checking_Acount : public Account {
public:
	using Account::Account;

	std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

							
		ss << "  Owner Name: " << customer->getName() << std::endl;
		ss << "  Owner Phone Number: " << customer->getTelephone_number() << std::endl;
		ss << "  Owner Age: " << customer->getAge() << std::endl;
		ss << "  Owner Adress: " << customer->getAddress() << std::endl;
		ss << "  Owner ID: " << customer->getCustomer_number() << std::endl;
		ss << "  Account Type: Checking" << std::endl;
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}

	void add_interest() {
		double amt = balance*customer->Get_CHECK_INTEREST();
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(customer->getCustomer_number(), "interest", amt, fees);
		transactions.push_back(tran);
	}
};


#endif