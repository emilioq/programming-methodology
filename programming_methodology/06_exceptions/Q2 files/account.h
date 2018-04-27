#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <exception>

class Exception_Amount : public std::exception {
public:
	virtual const char* what() throw() {
		return "Invalid amount.";
	}
};

class Exception_Negative_Deposit : public std::exception {
public:
	virtual const char* what() throw() {
		return "Cannot deposit a negative amount.";
	}
};

class Exception_Overdraw : public std::exception {
public:
	virtual const char* what() throw() {
		return "Overdraw";
	}
};

class Exception_Negative_Withdraw : public std::exception {
public:
	virtual const char* what() throw() {
		return "Cannot withdraw a negative amount.";
	}
};

class Account {

private:

	double balance;

public:

	Account();

	Account(double initialDeposit);

	double getBalance();

	double deposit(double amount);

	double withdraw(double amount);

};


#endif