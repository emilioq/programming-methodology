#include "polynomial.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Polynomial::Polynomial() {};

//Enables the user to type in a polynomial
void Polynomial::readFromUser() {
	int currentCoefficient;
	string input;
	
	while (true) {										//Only allows ints. Anything else inputted is looped back to try again
		cout << "\nEnter degree of polynomial : ";
		getline(cin, input);
		stringstream ss(input);
		ss >> power;
		if (!ss.fail()) {
			break;
		}
		cout << "\nError! Please enter a valid integer." << endl;
	}

	for (int i = 0; i <= power; i++) {					//Same thing, but for inputting the coefficients.
		while (true) {
			cout << "\nEnter coefficient of X^" << power - i << " : ";
			getline(cin, input);
			stringstream ss(input);
			ss >> currentCoefficient;
			if (!ss.fail()) {
				coefficients.push_back(currentCoefficient);
				break;
			}
			cout << "\nError! Please enter a valid integer." << endl;
		}
	}
}

//Prints the Polynomial
void Polynomial::printPoly() {
	for (int i = 0; i < coefficients.size(); i++) {		//Goes through the polynomials coefficient vector to print. 
														//If it's the last element, it doesnt print the "X^0". 
		while (true) {									
			if (i == 0) {
				if (coefficients[i] == 0) {
					cout << "\n0";
					break;
				}
				else {
					cout << "\n" << coefficients[0] << "X^" << coefficients.size() - 1;
					break;
				}
			}

			if (i == coefficients.size() - 1) {
				if (coefficients[i] == 0) {
					break;
				}
				else {
					cout << " + " << coefficients[i];
					break;
				}
			}

			if (coefficients[i] == 0) {
				break;
			}

			cout << " + " << coefficients[i] << "X^" << coefficients.size() - 1 - i;
			break;

		}
		
	}

	cout << endl;

}

//Returns the degree of the polynomial
int Polynomial::degree() {
	return power;
}

//Returns the coefficients of the said power
int Polynomial::coefficient(int power) {
	return coefficients[coefficients.size() - 1 - power];
}

//Changes the coefficient of the said power
void Polynomial::changeCoefficient(int newCoefficient, int power) {
	coefficients[coefficients.size() - 1 - power] = newCoefficient;
}

//Multiplies the polynomial by said integer
void Polynomial::scalePoly(int scaler) {
	for (int i = 0; i < coefficients.size(); i++) {
		coefficients[0] *= scaler;
	}
}

//Returns a polynomial by the sum of two polynomials
Polynomial Polynomial::addPoly(Polynomial poly) {			//If one coefficient vector is larger than the other, 
	Polynomial result;										//then store the coefficients of the larger one into the
	int off;												//resulting vector until both coefficient vectors are at the same power.
															//Then start adding the two coefficients vectors and store into resulting vector.
	if (coefficients.size() > poly.coefficients.size()) {
		result.power = coefficients.size() - 1;
		off = coefficients.size() - poly.coefficients.size();

		for (int i = 0; i < off; i++) {
			result.coefficients.push_back(coefficients[i]);
		}
		for (int j = off; j < coefficients.size(); j++) {
			result.coefficients.push_back(coefficients[j] + poly.coefficients[j - off]);
		}
	}

	if (coefficients.size() < poly.coefficients.size()) {
		result.power = poly.coefficients.size() - 1;
		off = poly.coefficients.size() - coefficients.size();

		for (int i = 0; i < off; i++) {
			result.coefficients.push_back(poly.coefficients[i]);
		}
		for (int j = off; j < poly.coefficients.size(); j++) {
			result.coefficients.push_back(poly.coefficients[j] + coefficients[j - off]);
		}
	}

	if (coefficients.size() == poly.coefficients.size()) {
		result.power = coefficients.size() - 1;
		for (int i = 0; i < coefficients.size(); i++) {
			result.coefficients.push_back(coefficients[i] + poly.coefficients[i]);
		}
	}

	return result;
}

//Negates a polynomial
void Polynomial::operator-() {
	for (int i = 0; i < coefficients.size(); i++) {
		coefficients[i] *= -1;
	}
}