#include "GeneralTree.h"
#include <sstream>
using namespace std;

void parseRecursive(stringstream& ss, GeneralTree& gt, Node* parent)
{
	char nextChar;
	while (true) {
		ss >> nextChar;
		if (ss.fail())
			return;

		if (nextChar == ')')
			return;

		if (nextChar == '(') {
			Node* newNode = gt.insert(' ', parent);
			parseRecursive(ss, gt, newNode);
		} else {
			gt.insert(nextChar, parent);
		}
	}
}

void parseExpression(const string& expr, GeneralTree& gt)
{
	stringstream ss;
	ss << expr;

	parseRecursive(ss, gt, NULL);
}

int main()
{
	// This should print:
	// (c(ab))
	GeneralTree gt;
	Node* grandparent = gt.insert('.', NULL);
	Node* parent1 = gt.insert('c', grandparent);
	Node* parent2 = gt.insert('.', grandparent);
	Node* kid1 = gt.insert('a', parent2);
	Node* kid2 = gt.insert('b', parent2);
	gt.print();

	// This should print:
	// (abab(cd)d(ef(g(h))))
	GeneralTree gt2;
	parseExpression("(abab(cd)d(ef(g(h))))", gt2);
	gt2.print();

	// This should print:
	// (c(ab))
	GeneralTree gt3 = gt;
	gt3.print();

	// This should print:
	// (abab(cd)d(ef(g(h))))
	GeneralTree gt4(gt2);
	gt4.print();



	//Exception Test
	GeneralTree x;
	Node* n1 = x.insert('.', NULL);
	Node* n2 = x.insert('e', NULL);

	return 0;
}

