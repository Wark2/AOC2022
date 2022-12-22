//============================================================================
// Name        : AoC2022.cpp
// Author      : William Coombs
// Version     :
// Copyright   : Your copyright notice
// Description : Yer
//============================================================================
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

bool contains(list<char> listchars, char element) {
	auto result = find(listchars.begin(), listchars.end(), element);
	return (result != listchars.end());
}

bool containsThree(list<char> listchars, list<char> listchars2, char element) {
	auto result = find(listchars.begin(), listchars.end(), element);
	auto result2 = find(listchars2.begin(), listchars2.end(), element);
	return (result != listchars.end()) && (result2 != listchars2.end());
}

int main() {
	ifstream ifs("Day3.txt");
	string l;
	int num = 0;
	while (getline(ifs, l)) {
		int current = 0;
		list<char> letters1;
		list<char> letters2;
		for (int i = 0; i < l.length() / 2; i++) { //add to lists 
			letters1.push_back(l[i]);
		}
		for (int j = l.length() / 2; j < l.length(); j++) {
			letters2.push_back(l[j]);
		}
		list<char>::iterator it;
		for (it = letters2.begin(); it != letters2.end(); it++) {
			if (contains(letters1, *it)) { //function that returns if *it in list 
				int asc = int(*it);
				asc -= 65;
				if (asc > 26) {
					asc -= 31;
				} else {
					asc += 27;
				}
				if (asc > current) {
					current = asc;
				}
			}
		}
		num += current;
	}

	cout << "Output P1: " << num << endl;

	ifstream ifs2("Day3.txt");
	int total = 0;
	string l2;
	string l3;
	string l4;

	while (getline(ifs2, l2)) {
		int cur = 0;
		list<char> let1;
		list<char> let2;
		list<char> let3;
		getline(ifs2, l3);
		getline(ifs2, l4);
		for (int i = 0; i < l2.length(); i++) { //add to lists 
			let1.push_back(l2[i]);
		}
		for (int i = 0; i < l3.length(); i++) {
			let2.push_back(l3[i]);
		}
		for (int i = 0; i < l4.length(); i++) {
			let3.push_back(l4[i]);
		}
		list<char>::iterator its;
		for (its = let1.begin(); its != let1.end(); its++) {
			if (containsThree(let2, let3, *its)) {//function that returns if *it in all list 
				int asc = int(*its);
				asc -= 65; //changing ascii to correct nums 
				if (asc > 26) {
					asc -= 31;
				} else {
					asc += 27;
				}
				if (asc > cur) {
					cur = asc;
				}
			}
		}
		total += cur;
	}
	cout << "Day 3 P2: " << total << endl;
}

