#ifndef _GENERALTREE_H
#define _GENERALTREE_H

#include <cstdlib>
#include <vector>

class NoParentException : public std::exception {
public:
	const char *what() const throw () {
		return "Parent does not exist.";
	}
};

struct Node {

	char value;
	std::vector<Node*> children;

};


class GeneralTree {

public:

	GeneralTree();

	GeneralTree(const GeneralTree& other);

	~GeneralTree();

	GeneralTree& operator=(const GeneralTree& other);

	Node* insert(char value, Node* parent);

	void print() const;

private:
	Node* start;

	Node* current; //used in copyOther to keep track of parent node

	std::vector<Node*> nodeTrack; //used with current to keep track where we are in the tree;

	void copyOther(const GeneralTree& other);
	
	void clear();

	void printFrom(Node* start) const;

	void copyFrom(Node* start, Node* parent);

	void clearFrom(Node* start);


};


#endif