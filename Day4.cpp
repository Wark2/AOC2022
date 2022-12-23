//============================================================================
// Name        : AoC2022.cpp
// Author      : William Coombs
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

bool inRange(int start, int end, int num)
{
  return (start <= num && num <= end); 
}
int main() {
	ifstream ifs("Day4.txt");
	int count = 0;
	int count2 = 0; 
	string l;
	int numbers[4] = {0,0,0,0};
	while(getline(ifs, l))
	{
	  int initial = count2; 
	  string numberStrings[4] = {"","","",""};
	  int index = 0;
	  string num1;
	  string num2;
	  string num3;
	  string num4;
	  for(int i = 0; i < 4; i++)
	   {
	      while(l[index] != '-' && l[index] != ',' && l[index] != ' ')
		 {
		   numberStrings[i] += l[index];
		   index++;
		   if(index >= l.length())
		     break; 
		 }
	      index++;
	   }
	  for(int j = 0; j < 4; j++)
	   {
	      numbers[j] = stoi(numberStrings[j].c_str());
	   }
	  if(numbers[0] <= numbers[2] && numbers[1] >= numbers[3]) //part 1 
	    {
	    count++;
	    }
	  else
	    {
	      if(numbers[2] <= numbers[0] && numbers[3] >= numbers[1]) //part 1 
		count++; 
	    }
	  if(inRange(numbers[0],numbers[1],numbers[2])) //part 2
	    {
	    count2++;
	    }
	  else
	    {
	      if(inRange(numbers[0],numbers[1],numbers[3])) //part2
		{
		count2++;
		}
	      else
		{
		  if(inRange(numbers[2],numbers[3],numbers[0])) //account for case of num=num, num-num 
		    count2++; 
		}
	    }
	  
	  cout << count2-initial << endl; 
	    
	}
	cout << "Day4 P1 Output: " << count << endl;
	cout << "Day4 P2 Output: " << count2 << endl; 
}

