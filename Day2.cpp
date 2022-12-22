//============================================================================
// Name        : AoC2022.cpp
// Author      : William Coombs
// Version     :
// Copyright   : Your copyright notice
// Description : Yur
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs("Day2List.txt", std::ifstream::in);
	int sum = 0;
	while (!ifs.eof()) {
		char first;
		char second;
		ifs >> first >> second; //this updates the eof, must recheck after
		if (ifs.eof()) //check to make sure the current line isn't eof
			break;
		int asc1 = int(first); //put into ASCII
		int asc2 = int(second);
		if (asc2 - asc1 == 22) //different cases
			sum += (asc2 - 87);
		if (asc2 - asc1 == 21)
			sum += (6 + asc2 - 87);
		if (asc2 - asc1 == 23)
			sum += (3 + asc2 - 87);
		if (asc2 - asc1 == 24)
			sum += (6 + asc2 - 87);
		if (asc2 - asc1 == 25)
			sum += (asc2 - 87);
	}
	cout << "Output: " << sum << endl;

	ifstream ifs2("Day2List.txt", std::ifstream::in);
	int sum2 = 0;
	while (!ifs2.eof()) {
		int initial = sum2;
		char first2;
		char second2;
		ifs2 >> first2 >> second2; //this updates the eof, must recheck after
		if (ifs2.eof()) //check to make sure the current line isn't eof
			break;
		int asc3 = int(first2); //put into ASCII
		int asc4 = int(second2);
		if (asc4 - 88 == 1) {  //for a draw
			sum2 += (3 + asc3 - 64);
		}
		if (asc4 - 88 == 2) { //for a win
			if (asc3 - 63 == 4)
				sum2 += (6 + 1);
			else
				sum2 += (6 + asc3 - 63);
		}
		if (asc4 - 88 == 0) {
			if (asc3 - 65 == 0)
				sum2 += (0 + 3);
			else
				sum2 += (0 + asc3 - 65);
		}
		cout << asc3 << " " << asc4 << " " << sum2-initial << endl;
	}
	cout << "Output2: " << sum2 << endl;
}
