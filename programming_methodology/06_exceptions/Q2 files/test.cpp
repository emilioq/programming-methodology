//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com	//
//	IDE: Microsoft Visual Studio Community 2015				//
//	CSC 340-01 | Assignment 6, Question 2					//
//															//
//////////////////////////////////////////////////////////////

#include <iostream>
#include "account.h"
using namespace std;

int main() {
	Account myAcc(500);
	cout << myAcc.getBalance() << endl;

	//DEPOSIT EXCEPTION TESTS

		//depositing a negative amount
	try {
		myAcc.deposit(-100);
	} catch (Exception_Negative_Deposit& e) {
		cout << "Amount Exception : " << e.what() << endl;
	} catch (Exception_Amount& e2) {
		cout << "Amount Exception : " << e2.what() << endl;
	}

		//depositing nothing
	try {
		myAcc.deposit(0);
	} catch (Exception_Negative_Deposit& e) {
		cout << "Amount Exception : " << e.what() << endl;
	} catch (Exception_Amount& e2) {
		cout << "Amount Exception : " << e2.what() << endl;
	}



	//WITHDRAW EXCEPTION TESTS	

		//withdrawing a negative amount
	try {
		myAcc.withdraw(-100);
	} catch (Exception_Overdraw& e) {
		cout << "Amount Exception : " << e.what() << endl;
	} catch (Exception_Negative_Withdraw& e2) {
		cout << "Amount Exception : " << e2.what() << endl;
	} catch (Exception_Amount& e3) {
		cout << "Amount Exception : " << e3.what() << endl;
	}

		//overdrawing
	try {
		myAcc.withdraw(1000);
	} catch (Exception_Overdraw& e) {
		cout << "Amount Exception : " << e.what() << endl;
	} catch (Exception_Negative_Withdraw& e2) {
		cout << "Amount Exception : " << e2.what() << endl;
	} catch (Exception_Amount& e3) {
		cout << "Amount Exception : " << e3.what() << endl;
	}

		//withdrawing nothing
	try {
		myAcc.withdraw(0);
	} catch (Exception_Overdraw& e) {
		cout << "Amount Exception : " << e.what() << endl;
	} catch (Exception_Negative_Withdraw& e2) {
		cout << "Amount Exception : " << e2.what() << endl;
	} catch (Exception_Amount& e3) {
		cout << "Amount Exception : " << e3.what() << endl;
	}

}