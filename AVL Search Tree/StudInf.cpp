/*
 * StudInf.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: 13027
 */


//	friend class StudentTreeInfo;
//	string first;
//	string last;
//	string ate;
//	string strange;
//	string dessert;
#include "StudInf.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

StudInf::StudInf() {
	first = "Wendy";
	last = "Adams";
	ate = "I have eaten salad";
	strange = "My hobby is plotting a gruesome death for my brother";
	dessert = "Fried tarantulas with snake eggs";
	invent = "a toothbrush that acidifies your teeth";
}
StudInf::StudInf(string sarr[]){
	first = sarr[3];
	last = sarr[0];//
	ate = sarr[2];//
	strange = sarr[1];//
	dessert = sarr[4];
	invent = sarr[5];
}

