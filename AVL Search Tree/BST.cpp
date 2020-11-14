/*
 * BST.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: Ryan
 */

#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


BST::BST() {
	root = NULL;
}

BST::BST(string sarr[]) {
	root = new TNode(sarr);
}

bool BST::insert(string sarr[]){


	TNode *n = new TNode(); // n new node
	if (root == NULL){
		root = new TNode(sarr);
		return true;

	} else {
		n = root; // set n to be root
		while (n != NULL){
			if (sarr[0] < n->student->last){
					if (n->left == NULL){
						n->left = new TNode(sarr); // set n's left child to be new node with data 's'
						n->left->parent = n; // set new node's parents to be n
						setHeight(n);
						return true;
					} else {
						n = n->left;
					}
			} else if (sarr[0] > n->student->last){ // sarr[0] is last
				if (n->right == NULL){
					n->right = new TNode(sarr); // set n's right child to be new node with data 's'
					n->right->parent= n; // set new node's parents to be n
					setHeight(n);
					return true;
				} else {
					n = n->right;
				}
			} else if (sarr[0] == n->student->last){  // if the last names are equal, then it does the same insert algorithm
				if (sarr[3] < n->student->first){ // but instead compares the first names (sarr[3] is first name)
					if (n->left == NULL){
						n->left = new TNode(sarr);
						n->left->parent = n;
						setHeight(n);
						return true;
					} else {
						n = n->left;
					}
				} else if (sarr[3] > n->student->first){
					if (n->right == NULL){
						n->right = new TNode(sarr);
						n->right->parent = n;
						setHeight(n);
						return true;
					} else {
						n = n->right;
					}
				} else if (sarr[3] == n->student->first){ // first and last are the same
					break;
				}
			} else {
				break;
			}
		}
	}
	return false; // x is in tree
}

// following pseudocode via slides

TNode *BST::find(string last, string first){
	int count = 0; // counting the comparisons
	TNode *tmp = root; // setting a new node tmp to the root
	while (tmp){
		if (tmp->student->last == last){ // if student field's last name is equal then compare first names
			count++; // updates count for each comparison
			if(tmp->student->first == first){
				count++;
				break; // just break out of loop if the phrase if tmps student first and last are both the same
			} else if (first < tmp->student->first){ // tmp now updates and points to left child if the first name is less than student's first
				count++;
				tmp = tmp->left;
			} else if (first > tmp->student->first){ // if student's first name is greater than tnodes student first
				count++;
				tmp = tmp->right; // tmp updates and now points to tmps right child
			}

		} else if (last < tmp->student->last){ // if string 's' is less than roots data, tmp points to left child
			count++;
			tmp = tmp->left;
		} else if (last > tmp->student->last){ // if string 's' is less than roots data, tmp points to right child
			count++;
			tmp = tmp->right;
		}
	}
	return tmp;
}


TNode *BST::remove(string last, string first){ // changed parameters to take in a first and last name

	TNode *tmp = find(last,first); // finding node
	if (tmp->right == NULL && tmp->left == NULL){ // checking to see if no kids
		removeNoKids(tmp);
	} else if (tmp->right == NULL){ // checking if it has a left child
		removeOneKid(tmp, true); // calls remove one kid with boolean set to true because it has left child
	} else if (tmp->left == NULL){ // checking right child
		removeOneKid(tmp, false);  // has right child
	} else if (tmp->right != NULL && tmp->left != NULL){ // 2 children
		TNode *temp = tmp;
		temp = temp->left;
		while(temp->right != NULL){
			temp = temp->right;
		}
		tmp->student = temp->student;
		if(temp->left == NULL){
			removeNoKids(temp);
		} else {
			removeOneKid(temp, true);
		}
	}
	return tmp;
}

TNode *BST::removeNoKids(TNode *tmp){

	if (root == tmp){
		root = NULL; // if node to be deleted is the root, then root is now NULL
	} else if (tmp->parent->left == tmp){ // if the parent of the node to be deleted's left is the node to be deleted
		tmp->parent->left = NULL; // set the parents left to null
		setHeight(tmp->parent); //adjust height of parent

	} else if (tmp->parent->right == tmp){ // similar to above, but with right
		tmp->parent->right = NULL;
		setHeight(tmp->parent);
	}
	free(tmp);
	return tmp;
}


TNode *BST::removeOneKid(TNode *tmp, bool leftFlag){

	TNode *temp = tmp->right; // initialize new TNode to be nodes right

	if(leftFlag){ // if it has left child, initialize to nodes left
		temp = tmp->left;
	} // basically getting nodes child

	if (root == tmp){ // if root is the node
		root = temp; // root now equals nodes child
		setHeight(root); // adjusting height

	} else if (tmp->parent->right == tmp){ // if nodes parents right is the node, then adjust and make childs parent now be nodes parent
		temp->parent = tmp->parent;
		temp->parent->right = temp; // childs parent's right now points to child itself
		setHeight(tmp->parent);

	} else if (tmp->parent->left == tmp){ // if nodes parents left is the node, then adjust and make childs parent now be nodes parent
		temp->parent = tmp->parent;
		temp->parent->left = temp; // child's parent's left now points to child itself
		setHeight(tmp->parent);
	}
	free(tmp);
	return tmp;
}

void BST::setHeight(TNode *n){

//	bool pass = false; // boolean variable to keep track of heights if each node has a valid height
//	if (n->left == NULL && n->right == NULL){ // if it's a leaf
//		if(n->height == 1){
//			pass = true;
//		}
//		n->height = 1; // set height to 1
//
//	} else if (n->right == NULL){ // checking if it has a left child
//		if (n->height == n->left->height + 1){ //nodes height should be child's height + 1
//			pass = true;
//		}
//		n->height = n->left->height + 1; // height calculation
//
//	} else if (n->left == NULL){ // checking if it has a right child
//		if (n->height == n->right->height + 1){ // nodes height should be child's height + 1
//			pass = true;
//		}
//		n->height = n->right->height + 1;
//
//	} else { // it has both children
//		int t = n->left->height; // new variable t that is equal to the height of n nodes child
//		if (n->right->height > t){ // if the right child's height is greater than left nodes child
//			t = n->right->height; // left nodes child is now equal to right nodes child
//		}
//		if (n->height == t + 1){ // if height of node = child's height + 1
//			pass = true;
//		}
//		n->height = t + 1; //nodes height should be child's height + 1
//	}
//	// recursive call back to setHeight
//	if(n->parent && !pass){ // if everything has valid height, adjust height of parent
//		n = n->parent;
//		setHeight(n); // setting the height of the parent
//	}


// change from recursive to iterative

	int heightBefore = 0;
	int heightAfter = 1;
	while (n != NULL && (heightBefore != heightAfter || heightBefore ==1 )){
		heightBefore = n->height;
		if(n->right == NULL && n->left == NULL){
			n->height = 1;
		} else if (n->right == NULL){
			n->height = n->left->height + 1;
		} else if (n->left == NULL){
			n->height = n->right->height + 1;
		} else {
			if (n->right->height > n->left->height){
				n->height = n->right->height + 1;
			} else {
				n->height = n->left->height + 1;
			}
		}
		heightAfter = n->height;

		if (getBalance(n) == 2){
			if(getBalance(n->left) == -1){
				rotateLeft(n->left);
			}
			rotateRight(n);
			if(n == root){
				root = n->parent;
			}
		} else if (getBalance(n) == -2){
			if (getBalance(n->right) == 1){
				rotateRight(n->right);
			}
			rotateLeft(n);
			if(n == root){
				root = n->parent;
			}
		}
		n = n->parent;
	}
}


int BST::getBalance(TNode *tmp){

	if (tmp->left != NULL && tmp->right != NULL){
		return tmp->left->height - tmp->right->height;
	} else if (tmp->right != NULL){
		return -tmp->right->height;
	} else if (tmp->left != NULL){
		return tmp->left->height;
	} else {
		return 0;
	}
}

TNode *BST::rotateLeft(TNode *tmp){
	TNode *parent = tmp->parent; // new node for parent

	TNode *x = tmp->right;
//	tmp->right = x->left;
//	x->left = tmp;

	if(x->left != NULL){
		tmp->right = x->left;
		x->left->parent = tmp;
	} else {
		tmp->right = NULL;
	}

	// parents

	if (parent == NULL){
		x->parent = NULL;
		root = x;
	} else {
		x->parent = tmp->parent;
		if(tmp->parent->right == tmp){
			tmp->parent->right = x;
		} else {
			tmp->parent->left = x;
		}
	}
	x->left = tmp;
	tmp->parent = x;

	// heights

	if (tmp->left == NULL && tmp->right == NULL){
		tmp->height = 1;
	} else if (tmp->left == NULL && tmp->right != NULL){ // has a right child
		tmp->height = tmp->right->height + 1;
	} else if (tmp->left != NULL && tmp->right == NULL){ // has a left child
		tmp->height = tmp->left->height + 1;
	} else { // it has both children
		int t = tmp->left->height; // new variable t that is equal to the height of n nodes child
		if (t > tmp->right->height){
			tmp->height = tmp->left->height + 1;
		} else {
			tmp->height = tmp->right->height + 1;
		}
	}

	if (x->left == NULL && x->right == NULL){
		x->height = 1;
	} else if (x->left == NULL && x->right != NULL){ // has a right child
		x->height = x->right->height + 1;
	} else if (x->left != NULL && x->right == NULL){ // has a left child
		x->height = x->left->height + 1;
	} else { // it has both children
		int t = x->left->height; // new variable t that is equal to the height of n nodes child
		if (t > x->right->height){ // if the right child's height is greater than left nodes child
			x->height = x->left->height + 1; // left nodes child is now equal to right nodes child
		} else {

		} x->height = x->right->height + 1; //nodes height should be child's height + 1
	}

	return x;
}

TNode *BST::rotateRight(TNode *tmp){
	TNode *parent = tmp->parent;

	TNode *x = tmp->left;
//	tmp->left = x->right;
//	x->right = tmp;

	if (x->right != NULL){
		tmp->left = x->right;
		x->right->parent = tmp;
	} else {
		tmp->left = NULL;
	}

	// parents

	if (parent == NULL){
		x->parent = NULL;
		root = x;
	} else {
		x->parent = tmp->parent;
		if (tmp->parent->left == tmp){
			tmp->parent->left = x;
		} else {
			tmp->parent->right = x;
		}
	}

	x->right = tmp;
	tmp->parent = x;

	// updating heights

	if (tmp->left == NULL && tmp->right == NULL){
		tmp->height = 1;
	} else if (tmp->left == NULL && tmp->right != NULL){ // has a right child
		tmp->height = tmp->right->height + 1;
	} else if (tmp->left != NULL && tmp->right == NULL){ // has a left child
		tmp->height = tmp->left->height + 1;
	} else { // it has both children
		int t = tmp->left->height; // new variable t that is equal to the height of n nodes child
		if (t > tmp->right->height){
			tmp->height = tmp->left->height + 1;
		} else {
			tmp->height = tmp->right->height + 1;
		}
	}

	if (x->left == NULL && x->right == NULL){
		x->height = 1;
	} else if (x->left == NULL && x->right != NULL){ // has a right child
		x->height = x->right->height + 1;
	} else if (x->left != NULL && x->right == NULL){ // has a left child
		x->height = x->left->height + 1;
	} else { // it has both children
		int t = x->left->height; // new variable t that is equal to the height of n nodes child
		if (t > x->right->height){ // if the right child's height is greater than left nodes child
			x->height = x->left->height + 1; // left nodes child is now equal to right nodes child
		} else {

		} x->height = x->right->height + 1; //nodes height should be child's height + 1
	}

	return x;
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void BST::printTreeIO(TNode *n) {
	if (n == NULL){
		return;
	} else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreePre(TNode *n){
	if (n == NULL){
		return;
	} else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePost(TNode *n){
	if (n == NULL){
		return;
	} else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}

void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}
