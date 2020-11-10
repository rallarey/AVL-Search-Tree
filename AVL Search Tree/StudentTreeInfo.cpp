/*
 * StudentTreeInfo.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: 13027
 */

#include "StudentTreeInfo.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


StudentTreeInfo::StudentTreeInfo(string name) {
	fn = name;
	tree = new BST();
	readFile();
}


void StudentTreeInfo::Interface() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"****************************************************"<<endl;
		cout <<"Choose Option:\n  a\tGet Student\n  b\tadd a student\n  c\tremove a student\n  d\tprint tree\n  q\tquit"<< endl;
		cin >> c;
		switch (c) {
		case 'a': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			TNode *t = tree->find(l,f);
			if (t == NULL) {
				char k;
				cout << f << " " << l <<" not found in database.  " << endl;
			}
			else {
				TNode *s = tree->find(l,f);
				s->printNode();
			}
			break;
		}
		case 'b':{
			string studarr[6];
			cout << "Enter Last: "<<endl;
			cin >> studarr[0];
			cout << "Enter First: " << endl;
			cin >> studarr[3];
			cout << "Enter Grossest thing you ever ate! " << endl;
			cin.ignore();
			getline(cin, studarr[2]);
			cout << endl << "Enter one unique thing about yourself: ";
			cin.ignore();
			getline(cin, studarr[1]);
			cout << endl << "Enter your favorite dessert: ";
			cin.ignore();
			getline(cin, studarr[4]);
			cout << endl << "If money/physics/time etc were not issues,what would you invent? "<<endl;
			cin.ignore();
			getline(cin, studarr[5]);

			if (tree->insert(studarr)) {
				cout << endl <<studarr[3] << "\t" << studarr[0]<< " inserted successfully "<<endl;
			}
			else {
				TNode *t = tree->find(studarr[0],studarr[3]);
				t->printNode();
				cout << "... already in tree with " << endl;
			}
			break;
		}
		case 'c': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			TNode *t = tree->remove(l,f);
			if (t == NULL) {
				cout << endl << f << " " << l << " not in tree " << endl;
			}
			else {
				t->printNode();
				cout << " ...has been removed. "<<endl;
			}
			break;
		}
		case 'd': {
			cout << "Choose a for pre, b for in, or c for post-order\t";
			char k;
			cin >> k;
			cout << endl;
			cout << "************************************************"<<endl;
			if (k == 'a') {
				cout << "*********** Printing Tree Pre Order ************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePre();
			}
			else if (k == 'b') {
				cout << "*********** Printing Tree In Order *************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreeIO();
			}
			if (k == 'c') {
				cout << "*********** Printing Tree Post Order ***********"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePost();
			}

			break;
		}
		}
	}
}

string StudentTreeInfo::strip(string s, string sarr[]) {
	const char* WhiteSpace = " \t\v\r\n";
	const char* EndChar = ":\t\n";
	for (int i = 0; i < 6; i++) {
		size_t start = s.find_first_not_of(WhiteSpace);
		int len = s.length();
		s = s.substr(start,len-start+1);
		size_t end = s.find_first_of(EndChar);
		if (end > 0){
			sarr[i] = s.substr(0,end);
			s = s.substr(end+1, len-end);
		}
		//cout << sarr[i] << endl;
		//cout << s << endl;

	}


	//cout << endl<< "************************************"<<endl;

	return sarr[5];

}
void StudentTreeInfo::readFile() {
	//tree = new BST();
	ifstream file(fn.c_str());
	string word;
	string phrase;
	string sarr[6];
	file >> word;
	while (!file.eof()) {
		//cout << word << " to be thrown out "<< endl;
		file >> word;
		//cout << word << " to be thrown out "<< endl;
		getline(file,phrase);
		phrase = strip(phrase, sarr);
//		cout << "in read file " << endl;
//		for (int i = 0; i < 5; i++) {
//				cout << sarr[i] << endl;
//		}
		//if (sarr[5] !=) {
			//cout << word << ", "<<phrase<<endl;
			tree->insert(sarr);
		//}
		file >> word;
	}
	tree->printTreeIO();
	return;
}

//	BST *tree;
//	string fn;
//public:
//	Abbr(string filename);

//	AddPhrases();
//	DeletePhrases();
//	PrintPhrases();
//};


