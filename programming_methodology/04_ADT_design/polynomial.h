#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <vector>

class Polynomial {
public:
	Polynomial();
	void readFromUser();
	void printPoly();
	int degree();
	int coefficient(int power);
	void changeCoefficient(int newCoefficient, int power);
	void scalePoly(int scaler);
	Polynomial addPoly(Polynomial poly);
	void operator-();


private:
	int power;
	std::vector<int> coefficients;
};


#endif