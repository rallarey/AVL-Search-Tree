/*
 * StudentTreeInfo.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: 13027
 */

#ifndef STUDENTTREEINFO_CPP_
#define STUDENTTREEINFO_CPP_
#include <iostream>
#include <stdlib.h>
#include "BST.hpp"
using namespace std;

class StudentTreeInfo {
	string fn;
public:
	BST *tree;
	StudentTreeInfo(string filename);
	void readFile();
	string strip(string s, string sarr[]);

	void Interface();
//	void addPhrases();
//	void deletePhrases();
//	void printPhrases();

};

#endif /* STUDENTTREEINFO_CPP_ */
