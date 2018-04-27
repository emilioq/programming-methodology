//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com	//
//	IDE: Microsoft Visual Studio Community 2015				//
//	CSC 340-01 | Assignment 6, Question 1					//
//															//
//	In this program, we are to create and use an exception	//
//	that detects if an ID of a product is not found			//
//															//
//////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

class Exception_ID_Not_Found : public exception
{
	public:
		const char* what() const throw()
		{
			return "ID Not Found.";
		}
};

int getProductID(int ids[], string names[], int numProducts, string target)

{

	for (int i = 0; i < numProducts; i++)

	{

		if (names[i] == target)

				return ids[i];
			
	}

	throw Exception_ID_Not_Found();

}

int main() // Sample code to test the getProductID function

{

	int productIds[] = { 4, 5, 8, 10, 13 };

	string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };

	try {
		cout << getProductID(productIds, products, 5, "mouse") << endl;
	} catch (Exception_ID_Not_Found& e) {
		cout << "Product ID Exception : " << e.what() << endl;
	}
	
	try {
		cout << getProductID(productIds, products, 5, "camera") << endl;
	} catch (Exception_ID_Not_Found& e) {
		cout << "Product ID Exception : " << e.what() << endl;
	}

	try {
		cout << getProductID(productIds, products, 5, "laptop") << endl;
	} catch (Exception_ID_Not_Found& e) {
		cout << "Product ID Exception : " << e.what() << endl;
	}

	return 0;

}