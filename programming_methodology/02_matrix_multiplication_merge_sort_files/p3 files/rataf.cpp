//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com	//
//	IDE: Microsoft Visual Studio Community 2015				//
//	CSC 340-01 | Assignment 2, Random Accesses to a File	//
//															//
//	This program will insert the numbers 7777 through 7781	//
//	between the 6000th and 60001st integer in the assigned	//
//	input file ("file1.txt").								//
//__________________________________________________________//


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

fstream fs;
vector<int> nums;	//this vector will be used to save the numbers beyond the 6000th integer.

//inserts the numbers 7777 - 7781 and the numbers after using the saved vector.
void insert() {
	fs.clear();
	fs.seekp(6000 * 5);

	for (int i = 7777; i <= 7781; i++) {		//inserts numbers 7777 through 7781.
		fs << i << endl;
	}

	for (int j = 0; j < 3999; j++) {			//inserts the saved numbers beyond the 6000th integer.
		fs.width(4);							//width and fill are used to keep the uniform
		fs.fill('0');							//look of the text file by keeping the leading zeroes.
		fs << nums[j] << endl;
	}

}


//saves the numbers beyond the 6000th integer into a vector.
void saveNum() {					
	fs.seekg(6000 * 5);

	while (true) {		//stores the numbers in a vector.
		int data;
		fs >> data;
		if (fs.fail()) { break; }
		nums.push_back(data);
	}

}

int main() {
	fs.open("file1.txt");
	saveNum();
	insert();
	cout << "Numbers inserted. Check file.\n" << endl;
}