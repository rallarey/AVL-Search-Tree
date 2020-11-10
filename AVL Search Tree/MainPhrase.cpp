/*
 * MainPhrase.cpp
 *
 *  Created on: Apr 19, 2020
 *      Author: 13027
 */

#include <iostream>
#include "StudentTreeInfo.hpp"
using namespace std;

int main() {
/************Part 1 - before you've added in the balancing and rotations *****/
//	StudentTreeInfo *studtree = new StudentTreeInfo("TestRightLeft.txt");
//	cout << "************************************" << endl;
/************End of Part 1*********************/


/************Part 2 - for testing left rotations *****/
/* Please comment out part 1 before testing this part */
//	StudentTreeInfo *studtree = new StudentTreeInfo("Testleft.txt");
//	cout << "************************************" << endl;
//	studtree->tree->clearTree();
//
//	delete studtree;
/**********End of Part 2 *************************/


/***** Part 3 testing the right-right rotations *****/
//	cout << "********* Testing right ************" << endl;
//	studtree = new StudentTreeInfo("TestRight.txt");
//	cout << "************************************" << endl;
//	studtree->tree->clearTree();
//
//	delete studtree;
/************End of Part 3 **********************/

/***** Part 4 testing the right-left rotations *****/
//	cout << "********* Testing rightleft ************" << endl;
//	studtree = new StudentTreeInfo("TestRightLeft.txt");
//	cout << "************************************" << endl;
//	studtree->tree->clearTree();
//
//	delete studtree;
/****************End of Part 4 **************************/



/***** Part 5 testing the left-right rotations *****/
//	cout << "********* Testing leftright ************" << endl;
//	studtree = new StudentTreeInfo("TestLeftRight.txt");
//	cout << "************************************" << endl;

/*********End of Part 5 ***********************/


//
/***** Part 6 now testing the removing part *******/
/* Note: make sure you leave Part 5 in so you have a tree to remove from */

//	cout <<endl<<endl<< "********* Testing Removing ************" << endl;
//
//	/***** Removing student with no kids *******/
//	cout << "Removing No Children (Arachnea Adams)"<<endl;
//	studtree->tree->remove("Adams","Arachnea");
//	studtree->tree->printTreeIO();
//	cout << "************************************" << endl;
//

	///***** Removing student with one kid *******/
//		cout << "Removing Node with One Kid (Fabian Fearful)"<<endl;
//		studtree->tree->remove("Fearful","Fabian");
//		studtree->tree->printTreeIO();
//		cout << "************************************" << endl;

///***** Removing student with two kids *******/
//		cout << "Removing Node with two kids (Jason Jinx)"<<endl;
//		studtree->tree->remove("Jinx","Jason");
//		studtree->tree->printTreeIO();
//		cout << "************************************" << endl;
//	cout << "Ready to Delete?"<< endl;
//	string ans;
//	cin >> ans;
//	studtree->tree->clearTree();
//	delete studtree;

/*****And now for the big tree!!!  Part 7 *************/
	StudentTreeInfo *studtree = new StudentTreeInfo("StudentAnswers.txt");
	studtree->Interface();
	return 0;
}


