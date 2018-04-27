//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com					//
//	IDE: Microsoft Visual Studio Community 2015								//
//	CSC 340-01 | Assignment 4, ADT Design									//
//																			//
//	This program implements a polynomial ADT that manipulates polynomials	//
//	in a single variable x. Main uses all the functions in the polynomial	//
//	class.																	//
//__________________________________________________________________________//


#include "polynomial.h"
#include <iostream>

int main() {

	Polynomial myPolynomial;
	myPolynomial.readFromUser();

	Polynomial myPolynomial2;
	myPolynomial2.readFromUser();

	myPolynomial.printPoly();
	myPolynomial2.printPoly();

	std::cout << "\nSum : " << std::endl;
	Polynomial myPolynomial3;
	myPolynomial3 = myPolynomial.addPoly(myPolynomial2);
	myPolynomial3.printPoly();

	std::cout << "\nNegation : " << std::endl;
	-myPolynomial3;
	myPolynomial3.printPoly();


	std::cout << "\nThe degree of the polynomial is " << myPolynomial3.degree() << std::endl;
	std::cout << "The coefficient of X^2 is " << myPolynomial3.coefficient(2) << std::endl;

	std::cout << "\nChanging Coefficient : ";
	myPolynomial3.changeCoefficient(3000, 2);
	std::cout << std::endl;
	myPolynomial3.printPoly();
	std::cout << "The coefficient of X^2 is now " << myPolynomial3.coefficient(2) << std::endl << std::endl;

}

	
