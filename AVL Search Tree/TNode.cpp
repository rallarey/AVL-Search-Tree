/*
 * TNode.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string sarr[]) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
//	cout << "in constructor: "<<endl;
//	for (int i = 0; i < 5; i++) {
//		cout << sarr[i] << endl;
//	}
	student = new StudInf(sarr);//updated
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	string sarr[] = {"Adams","chocolate", "Alticia","I tried to decapitate my brother","fried tarantulas", "toothbrush that acidifies teeth"};
	student = new StudInf(sarr); // updated
}
TNode::~TNode(){
	cout <<"Deleting "<<student->first<<","<<student->last<<endl;
}
void TNode::printNode() {
	cout << "Height of node: " << height << endl;
	cout << "Name: ";
	cout << student->first << " "<<student->last << endl;
	cout << "Weirdest thing you ate: " << student->ate << endl;
	cout << "Unique thing: " << student->strange << endl;
	cout << "Favorite Dessert: " << student->dessert << endl;
	cout << "Invention: " << student->invent << endl;
	cout << "*************************************************************"<<endl;
}
