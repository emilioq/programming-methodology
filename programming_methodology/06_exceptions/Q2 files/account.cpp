#include "account.h"

Account::Account() : balance(0) {}

Account::Account(double initialDeposit) : balance(initialDeposit) {}

double Account::getBalance() {
	return balance;
}

double Account::deposit(double amount) {

	if (amount < 0) { throw Exception_Negative_Deposit(); }

	if (amount > 0) { balance += amount; }

	else { throw Exception_Amount(); }

	return balance;
}

double Account::withdraw(double amount) {
	if (amount > balance) {
		throw Exception_Overdraw();
	}

	if (amount < 0) {
		throw Exception_Negative_Withdraw();
	}

	if ((amount <= balance) && (amount > 0)) {
		balance -= amount;
	}

	else {
		throw Exception_Amount();

	}

	return balance;
}