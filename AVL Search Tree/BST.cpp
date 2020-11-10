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
				if (sarr[3] < n->student->last){ // but instead compares the first names (sarr[3] is first name)
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
				}
			} else {
				return false;
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
	TNode *tmp = find(last, first); // finding the node with the proper first and last name, setting tmp to that node
	if (tmp->left == NULL && tmp->right == NULL){ // no kids
		removeNoKids(tmp);
	} else if (tmp->right == NULL){
		removeOneKid(tmp, true); // calls remove one kid with boolean set to true because it has left child
	} else if (tmp->left == NULL){
		removeOneKid(tmp, false);  // has right child
	} else {
		TNode *temp = tmp->left; // new node set equal to the node with the parameter 's'' left child

		while (temp->right != NULL){ // goes through the right branch, finds the node to replace
			temp = temp->right;
		}
		StudInf *value = temp->data; // getting the phrase from temp

		if (temp->left == NULL){ // checks if temp has a left child
			removeNoKids(temp);
		} else {
			removeOneKid(temp, true);
		}

		if (root == tmp){  // if the node with data s is tmp
			root = new TNode(value->phrase); // make root a new node with the value from above
			root->left = tmp->left; //
			root->right = tmp->right;
			if (tmp->left){
				tmp->left->parent = root;
			} else if (tmp->right){
				tmp->right->parent = root;
			}
			setHeight(root);
		} else if (tmp->parent->left == tmp){
			tmp->parent->left = new TNode(value->phrase);
			if(tmp->left){
				tmp->left->parent = tmp->parent;
				tmp->parent->left->left = tmp->left;
			} else if (tmp->right){
				tmp->right->parent = tmp->parent;
				tmp->parent->left->right = tmp->right;
			}
			setHeight(tmp->parent->left); // adjusting height
		}
		free(tmp);
		return tmp;
	}
	return NULL;
}

TNode *BST::removeNoKids(TNode *tmp){
//	if (tmp->left == NULL && tmp->right == NULL){ //i think they check this in remove method
//		if (tmp->data->phrase > tmp->parent->data->phrase){ // if data in tmp is greater than parents data, tmp is in the right branch
//			tmp->parent->right = NULL; // therefore, parents right child points to NULL
//			return tmp;
//		} else {
//			tmp->parent->left = NULL; // if data in tpm is less than, tmp is in the left branch
//			return tmp; // parents left child should now point to NULL;
//		}
//	}
//	return tmp;
//}

// remove no kids and remove one kid arent working D:

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
//	if(leftFlag){ // the one child is to the left of tmp
//		if(tmp->data->phrase > tmp->parent->data->phrase){ // if tmps data is greater than the parents data, it will be in the right branch
//			tmp->parent->right = tmp->left; // parents right child will now point to tmps left
//			return tmp;
//		} else {
//			tmp->parent->left = tmp->left; // parents left child points to tmps left
//			return tmp;
//		}
//	} else { // child of node to be removed is to the right
//		if(tmp->data->phrase > tmp->parent->data->phrase){ // tmp is in right branch of parent
//			tmp->parent->right = tmp->right; // parent right points to tmps right
//			return tmp;
//		} else {
//			tmp->parent->left = tmp->right; // parents left points to tmps left
//			return tmp;
//		}
//	}
//}

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
//	int height = 1;
//	n->height = height;
//
//	if (n == NULL){
//		n->height = 0;
//	}
//	if (insert(n->data->phrase) && n->left == NULL && n->right == NULL){ // if insert is true and node is leaf
//		n->height = 1;
//	}
//
//
	// actual height algorithm
//	while (n->parent != NULL){ // stops when you hit the root and parent becomes null
//		n = n->parent; // sets n to be parent
//		height++;
//		if (height > n->height){
//			n->height = height;
//		}
//	}

// for some reason when i use above ^^, code terminates and gives no output

// will re write code

	bool pass = false; // boolean variable to keep track of heights if each node has a valid height
	if (n->left == NULL && n->right == NULL){ // if it's a leaf
		if(n->height == 1){
			pass = true;
		}
		n->height = 1; // set height to 1

	} else if (n->right == NULL){ // checking if it has a left child
		if (n->height == n->left->height + 1){ //nodes height should be child's height + 1
			pass = true;
		}
		n->height = n->left->height + 1; // height calculation

	} else if (n->left == NULL){ // checking if it has a right child
		if (n->height == n->right->height + 1){ // nodes height should be child's height + 1
			pass = true;
		}
		n->height = n->right->height + 1;

	} else { // if it doesn't have a child
		int t = n->left->height; // new variable t that is equal to the height of n nodes child
		if (n->right->height > t){ // if the right child's height is greater than left nodes child
			t = n->right->height; // left nodes child is now equal to right nodes child
		}
		if (n->height == t + 1){ // if height of node = child's height + 1
			pass = true;
		}
		n->height = t + 1; //nodes height should be child's height + 1
	}

	if(n->parent && !pass){ // if everything has valid height, adjust height of parent
		setHeight(n->parent); // setting the height of the parent
	}

}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root->left);
		cout << root->student << " ";
		printTreeIO(root->right);
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
