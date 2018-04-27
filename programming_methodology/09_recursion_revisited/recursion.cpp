//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com	//
//	IDE: Microsoft Visual Studio Community 2015				//
//	CSC 340-01 | Assignment 7, General Tree					//
//															//
//	In this assignment, we are to create three recursion	//
//	methods that are assigned to us without using for or	//
//	while loops. Then we are to test these methods in the	//
//	main method.											//
//////////////////////////////////////////////////////////////


#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& input) {

	string s = input;
	s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	if (input.length() == 0) {
		return true;
	}

	if (input.length() == 1) {
		return true;
	}

	if (s[0] == s[s.length() - 1]) {
		s.erase(s.begin());
		s.erase(s.end() - 1);
		if (isPalindrome(s) == true) {
			return true;
		}
	}

	return false;

}

void palindromeTest(const string& str) {
	if (isPalindrome(str) == true) {
		cout << "\"" << str << "\"" << " is a palindrome. \n" << endl;
	}
	else {
		cout << "\"" << str << "\"" << " is not a palindrome. \n" << endl;
	}

}


int digitSum(int input) {
	int sum = input % 10;
	if (input == 0) {
		return sum;
	}
	input /= 10;
	sum += digitSum(input);
}


int waysToClimb(int numStairs) {
	if (numStairs == 0 || numStairs == 1) {
		return 1;
	}

	if (numStairs == 2) {
		return 2;
	}

	if (numStairs == 3) {
		return 3;
	}

	return (waysToClimb(numStairs - 1) + waysToClimb(numStairs - 2));
}


int main() {
	//PALINDROME TESTS
	cout << endl << "- PALINDROME TESTS -" << endl;
	cout << "_________________________\n" << endl;

	string pal1 = "racecar";
	string pal2 = "Was it a car or a cat I saw?";
	string pal3 = "This isn't a palindrome!";

	palindromeTest(pal1);	//true
	palindromeTest(pal2);	//true
	palindromeTest(pal3);	//false


	//DIGIT SUM TESTS
	cout << endl << "- DIGIT SUM TESTS -" << endl;
	cout << "_________________________\n" << endl;

	cout << "The digit sum of 10 is " << digitSum(10) << endl << endl;
	cout << "The digit sum of 101010 is " << digitSum(101010) << endl << endl;
	cout << "The digit sum of 1234567890 is " << digitSum(1234567890) << endl << endl;


	//STAIRCASE TESTS
	cout << endl << "- STAIRCASE TESTS -" << endl;
	cout << "_________________________\n" << endl;

	cout << "There are " << waysToClimb(4) << " ways to climb 4 steps" << endl << endl;
	cout << "There are " << waysToClimb(5) << " ways to climb 5 steps" << endl << endl;
	cout << "There are " << waysToClimb(10) << " ways to climb 10 steps" << endl << endl;
	cout << "There are " << waysToClimb(15) << " ways to climb 15 steps" << endl << endl;

	

}