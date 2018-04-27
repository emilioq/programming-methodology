//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com			//
//	IDE: Microsoft Visual Studio Community 2015						//
//	CSC 340-01 | Assignment 2, File I/Os							//
//																	//
//	This program reads in two text files which both contain a		//
//	sorted list of integers (one int per line) in non-decreasing	//
//	order. It then merges the two files into a third file which		//
//	contains the data from both files sorted.						//
//__________________________________________________________________//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

string if1, if2;
ifstream ifs, ifs2;
ofstream ofs;

//merges two files into a third file sorted
void merge(string& f1, string& f2) {
	string str1, str2;
	stringstream ss1, ss2;
	int num1, num2;

	ifs.open(f1);
	ifs2.open(f2);
	ofs.open("merged_file.txt");

	getline(ifs, str1);				//gets first line on both txt files, stores in int.
	getline(ifs2, str2);
	ss1 << str1;
	ss2 << str2;
	ss1 >> num1;
	ss2 >> num2;

	while (true) {

		if ( (num1 < num2) || (num1 == num2) ) {		//if first file num is smaller than second file num (or equal),
			ofs << num1 << endl;						//then write it in the merged txt file and get next num
			ss1.clear();								//on first txt file.
			ss1.str("");
			getline(ifs, str1);

			if ( (str1 == "" && str2 != "") || (ifs.fail() && !ifs2.fail()) )  {	//if we reached the end of the first txt file,
				while (true) {														//then write the rest of the second txt file to	
					ofs << num2 << endl;											//the merged txt file.
					ss2.clear();
					ss2.str("");
					getline(ifs2, str2);
					if (str2 == "" || ifs2.fail()) { break; }
					ss2 << str2;
					ss2 >> num2;
				}
				break;
			}

			ss1 << str1;
			ss1 >> num1;
		}

		if (num1 > num2) {					//if second file num is smaller than first file num,
			ofs << num2 << endl;			//then write it in the merged txt file and get next
			ss2.clear();					//num on second txt file.
			ss2.str("");
			getline(ifs2, str2);

			if ( (str1 != "" && str2 == "") && (!ifs.fail() && ifs2.fail()) ) {		//if we reached the end of the second txt file,
				while (true) {														//then write the rest of the first txt file to
					ofs << num1 << endl;											//the merged txt file.
					ss1.clear();
					ss1.str("");
					getline(ifs, str1);
					if (str1 == "" || ifs.fail()) { break; }
					ss1 << str1;
					ss1 >> num1;
				}
				break;
			}

			ss2 << str2;
			ss2 >> num2;
		}

	}

	ifs.close();
	ifs2.close();
	ofs.close();
}

//tests if file can open
bool failLoadTest(string& file) {
	bool check = false;
	
	ifs.open(file);
	if (ifs.fail()) { check = true; }
	ifs.close();

	return check;
}

//tests if file has numbers only
bool hasNonNumTest(string& file) {
	ifs.open(file);
	string str;

	int count = 0;
	while (true) {				//if anything that's not a number appears, the test returns true.
		getline(ifs, str);
		if (ifs.fail()) { break; }
		if (str.find_first_not_of("1234567890") != string::npos) { count++; }
	}

	ifs.close();
	return count > 0;
}

//tests if file contains numbers in non-decreasing order
bool isNumOrderTest(string& file) {
	ifs.open(file);
	string str;
	stringstream ss;
	int num, next_num;
	bool check = true;

	while (true) {
		ss.clear();
		ss.str("");

		getline(ifs, str);
		if (ifs.fail()) break;
		ss << str;
		ss >> num;

		ss.clear();
		ss.str("");

		getline(ifs, str);
		if (ifs.fail()) {
			if (num < next_num) {	//if we reached the end of the txt file, this will do the final comparison.
				check = false;
			}
			break;
		}
		ss << str;
		ss >> next_num;

		if (num > next_num) {		//compares the two numbers. If the number before 
			check = false;			//the next numberis larger, the test will return false. 
			break;
		}
	}

	ifs.close();
	return check;
}

//tests the file using the three tests
bool fileTest(string& file1, string& file2) {
	int count = 0;

	if (failLoadTest(file1) == true) {
		cout << "\nFailed to load File 1." << endl;;
		count++;
	}

	if (failLoadTest(file2) == true) {
		cout << "\nFailed to load File 2." << endl;
		count++;
	}

	if (hasNonNumTest(file1) == true) {
		cout << "\nFile 1 contains non-numeric character(s)." << endl;
		count++;
	}

	if (hasNonNumTest(file2) == true) {
		cout << "\nFile 2 contains non-numeric character(s)." << endl;
		count++;
	}

	if (isNumOrderTest(file1) == false) {
		cout << "\nFile 1 is not sorted in non-decreasing order." << endl;
		count++;
	}

	if (isNumOrderTest(file2) == false) {
		cout << "\nFile 2 is not sorted in non-decreasing order." << endl;
		count++;
	}

	cout << "___________________________________________________________" << endl << "\n";

	return count == 0;	//The count will increase if any of the tests go off. 
}

int main() {

	while (true) {
		cout << "Type in the name of input File 1 : ";
		getline(cin, if1);
		cout << "Type in the name of input File 2 : ";
		getline(cin, if2);

		if (fileTest(if1, if2)) { 
			cout << "Success!\n" << endl;
			break; 
		}
	}

	merge(if1, if2);
	cout << "\"merged_file.txt\" created.\n" << endl;
}