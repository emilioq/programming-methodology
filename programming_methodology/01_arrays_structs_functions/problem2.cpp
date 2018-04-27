//Emilio Quiambao | 915372476 | emilioquiambao@gmail.com
//IDE: Microsoft Visual Studio Community 2015
//CSC 340-01 | Assignment 1, Problem 2
//
//This program sorts user-inputted integers by a selection sort algorithm.
//				  
/* _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ * _ */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

vector<int> numsCopy;	//A copy of the original inputted integers.
vector<int> sortedNums;	//Where the sorted integers will be stored.

//reads and stores user input
vector<int> readData(vector<int> nums) {
	string temp;
	stringstream ss;

	getline(cin, temp);
	ss << temp;

	while (true) {
		int next_num;
		ss >> next_num;

		if (ss.fail()) { break; }

		nums.push_back(next_num);
	}
	numsCopy = nums;
	return nums;
}

//sorts the user input in a vector from least to greatest
vector<int> selectionSort(vector<int> nums) {
	int leastNum;
	int eraseNum;	//saves the location of the number to erase in the original vector.

	for (unsigned int i = 0; i < nums.size(); i++) {
		leastNum = nums[i];
		eraseNum = i;
		for (unsigned int j = 0; j < nums.size(); j++) {
			if (leastNum > nums[j]) {
				leastNum = nums[j];					//if the number being compared is lower, leastNum will be that number
				eraseNum = j;						//also saves location of said number in the original vector.
			}

			if (j == nums.size() - 1) {					//once we reach the end of the nested for loop, 
				sortedNums.push_back(leastNum);			//push back the value of leastNum in sortedNums vector
				nums.erase(nums.begin() + eraseNum);	//and erase the number in the original vector.
				i--;
			}
		}
	}
	return sortedNums;
}

//prints the vector
void printVector(vector<int> nums) {
	cout << "\n" << "Sorted: " << endl;
	for (unsigned int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << "\n" << "__________________________________________________" << "\n" << endl;

	cout << "Original: " << endl;
	for (unsigned int i = 0; i < nums.size(); i++) {
		cout << numsCopy[i] << " ";
	}
	cout << "\n" << "__________________________________________________" << "\n" << endl;


}

int main()
{
	vector<int> input;
	cout << "Enter numbers: ";
	printVector(selectionSort(readData(input)));
}