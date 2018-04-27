//	Emilio Quiambao | 915372476 | emilioquiambao@gmail.com	//
//	IDE: Microsoft Visual Studio Community 2015				//
//	CSC 340-01 | Assignment 7, General Tree					//
//															//
//	In this program, we are to implement a GeneralTree		//
//	class with each of its node value being a character 	//
//	and each node having any number of children.			//
//////////////////////////////////////////////////////////////



#include "GeneralTree.h"
#include <iostream>

using namespace std;

GeneralTree::GeneralTree() {
	start = NULL;
}

GeneralTree::GeneralTree(const GeneralTree& other) {
	start = NULL;
	copyOther(other);
}

GeneralTree::~GeneralTree() {
	clear();
}

GeneralTree& GeneralTree::operator=(const GeneralTree& other) {
	if (this != &other) {
		clear();
		copyOther(other);
	}

	return *this;
}

Node* GeneralTree::insert(char value, Node* parent) {
	try {

		Node* insert = new Node();
		insert->value = value;

		if (parent != NULL) {					//pushes into parent node's children vector
			parent->children.push_back(insert);
			return insert;
		}

		if (parent == NULL && start == NULL) {	//inserts root node
			start = insert;
			return start;
		}

		if (parent == NULL && start != NULL) {	//exception when parent is null, but start node already exists
			delete insert;
			throw NoParentException();
		}

	}

	catch (NoParentException& e) {
		cout << e.what() << endl;
	}
	

}

void GeneralTree::print() const {
	printFrom(start);
	cout << endl;
}

void GeneralTree::printFrom(Node* start) const {

	if (start == NULL) {
		return;
	}

	if (start->children.size() > 0) {							//if they have children, print paranthesis, then recursion
		cout << "(";

		for (int i = 0; i < start->children.size(); i++) {
			printFrom(start->children[i]);
		}

		cout << ")";
	}
	else {
		cout << start->value;									//if they have no children, print the value
	}
}

void GeneralTree::copyOther(const GeneralTree& other) {
	copyFrom(other.start, this->start);
}

void GeneralTree::copyFrom(Node* start, Node* parent) {
	
	if (start == NULL) {
		nodeTrack.clear();
		return;
	}
	
	if (start->children.size() > 0) {						//if they have children, keep track of current node, then recursion
		current = this->insert(start->value, parent);
		nodeTrack.push_back(current);
		for (int i = 0; i < start->children.size(); i++) {
			copyFrom(start->children[i], nodeTrack[nodeTrack.size() - 1]);
		}
		nodeTrack.pop_back();
	}
	else {
		this->insert(start->value, parent);					//if they dont have children, just insert without updating current node
	}
}

void GeneralTree::clear() {
	clearFrom(start);
}

void GeneralTree::clearFrom(Node* start) {

	if (start == NULL) {
		return;
	}

	if (start->children.size() > 0) {
		for (int i = start->children.size(); i < 0; i--) {
			clearFrom(start->children[i - 1]);
		}
			
	}

	delete start;
}