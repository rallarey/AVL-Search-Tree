/*
 * TNode.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#ifndef TNODE_HPP_
#define TNODE_HPP_
#include <iostream>
#include "StudInf.hpp"
using namespace std;

class TNode{
	friend class BST;
	TNode *left;
	TNode *right;
	TNode *parent;
	StudInf *student;  //updated
	int height;
public:
	TNode(string sarr[]);//updated
	TNode();
	~TNode();
	void printNode();
};



#endif /* TNODE_HPP_ */
