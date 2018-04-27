//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com				//
//	IDE: Microsoft Visual Studio Community 2015							//
//	CSC 340-01 | Assignment 2, Matrix Multiplication					//
//																		//
//	This program allows the user to provide the dimensions of two		//
//	matrices and their contents. The program will return the product	//
//	of the two matrices.												//
//______________________________________________________________________//


#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

vector< vector < int > > m1;
vector< vector < int > > m2;
vector< vector < int > > m3;

int m1rows, m1columns, m2rows, m2columns, m3rows, m3columns;
int mnum = 0;

//User enters size of matrix
void sizeInput(){
	while (true) {
		cout << "\nEnter number of ROWS in matrix 1 : " << endl;
		cin >> m1rows;
		cout << "\nEnter number of COLUMNS in matrix 1 : " << endl;
		cin >> m1columns;

		cout << "\nEnter number of ROWS in matrix 2 : " << endl;
		cin >> m2rows;
		cout << "\nEnter number of COLUMNS in matrix 2 : " << endl;
		cin >> m2columns;

		if (m1columns == m2rows) {				//checks if the matrices are able to multiply.
			cin.ignore();
			break;
		}

		else {
			cout << "\n1st matrix's COLUMNS does not match 2nd matrix's ROWS." << endl;
			cout << "Try again." << endl;
		}
	}
}

//User enter contents of matrix
void matrixInput(vector<vector < int > > m, int mrows, int mcolumns) {
	while (true) {
		vector< vector < int > > mCopy;						//mCopy is a temporary matrix which will be copied later
		string temp;										//mnum keeps count on which matrix this will be stored in
		stringstream ss;
		mnum++;

		for (int row = 0; row < mrows; row++) {
			mCopy.push_back(vector<int>());
			cout << "\n[Matrix " << mnum << "] Enter numbers in row " << row + 1 << " : " << endl;
			ss.str("");
			ss.clear();
			getline(cin, temp);								//input is read by getline then into a stringstream which then stores into 
			ss << temp;										//a temporary int then put into the matrix.

			while (true) {
				int num;
				ss >> num;

				if (ss.fail()) {
					if (mCopy[row].size() == mcolumns) { break; }					//if the user put too little or too much numbers,
					else {															//the user will have to re-enter the row input.
						cout << "\nNumbers do not match column size." << endl;
						mCopy.pop_back();
						row--;
						break;
					}
				}

				mCopy[row].push_back(num);

			}
		}
		
		if (mnum == 1) {				//stores data to matrix
			m1 = mCopy;
		}

		if (mnum == 2) {
			m2 = mCopy;
		}

		break;
	}

}

//Multiplies matrices 1 & 2 and stores result in matrix 3
void multiply_matrices() {
	m3rows = m1rows;
	m3columns = m2columns;
	int sum;

	for (int row = 0; row < m1rows; row++) {
		m3.push_back(vector<int>());
		for (int col = 0; col < m2columns; col++) {
			sum = 0;
			for (int pos = 0; pos < m2rows; pos++) {
				sum += (m1[row][pos] * m2[pos][col]);
			}
			m3[row].push_back(sum);
		}
	}

}

//Prints matrix
void printMatrix(vector<vector < int > > m, int mrows, int mcolumns) {
	cout << endl;
	cout << setw(5);
	for (int row = 0; row < mrows; row++) {
		for (int column = 0; column < mcolumns; column++) {
			cout << m[row][column] << setw(5);
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	sizeInput();
	matrixInput(m1, m1rows, m1columns);
	matrixInput(m2, m2rows, m2columns);

	cout << endl;
	cout << "[Matrix 1]" << endl;
	printMatrix(m1, m1rows, m1columns);

	cout << "[Matrix 2]" << endl;
	printMatrix(m2, m2rows, m2columns);

	multiply_matrices();

	cout << "[Matrix 1 x Matrix 2]" << endl;
	printMatrix(m3, m3rows, m3columns);
}