//============================================================================
// Name        : AoC2022.cpp
// Author      : William Coombs
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ifstream ifs("CalorieList.txt");
	int count[] = {0,0,0}; //top 3 
	int current = 0;
	string s;
	while (getline(ifs, s)) {
		if (s.empty()) {
	        if(current > count[0])
	        {
	        	count[0] = current; //insert in first location
	        	sort(count, count+3); //then sort 
	        }
			current = 0;
		} else {
			int n = stoi(s);
			current += n;
		}
	}
    if(current > count[0]) //account for the last grouping 
    {
    	count[0] = current;
    	sort(count, count+3);
    }
	ifs.close();
	cout << "Output Day 1 P1: " << count[2] << endl;
	cout << "Output Day 1 P2: " << accumulate(count, count+3, 0) << endl;
	return 0;
}


