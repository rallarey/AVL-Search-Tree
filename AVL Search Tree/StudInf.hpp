/*
 * StudInf.hpp
 *
 *  Created on: Oct 21, 2020
 *      Author: 13027
 */

#ifndef STUDINF_HPP_
#define STUDINF_HPP_

#include <stdlib.h>
#include <iostream>
using namespace std;

class StudInf {
	friend class TNode;
	friend class StudentTreeInfo;
	friend class BST;
	string first;
	string last;
	string ate;
	string strange;
	string dessert;
	string invent;
	int numstuff = 6;
public:
	StudInf();
	StudInf(string sarr[]);
};



#endif /* STUDINF_HPP_ */

