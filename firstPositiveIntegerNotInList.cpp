/*
 * firstPositiveIntegerNotInList.cpp
 *
 *      Author: Anantha Yeshaswy C A
 *
 *	PROBLEM STATEMENT:
 *	Given a list of integers, write a function solution(vector<int> A) that
 *	returns the lowest positive integer that is not part of the list.
 *	Example:	input = 1, 3, 4, 5, 7			Output = 2
 *				input = -2, 0, -3, -1, 2, 4		Output = 1
 *				input = -1, -3, -10, -5			Output = 1
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<int> A) {
    std::sort(A.begin(), A.end());

    unsigned int i=0;
    bool firstPositive = false;
    if (A.front() > 0)
        A.insert(A.begin(),0);
    for (i=0; i<(A.size() - 1); ++i) {
        if (A[i]<0)
        	continue;
        if (!firstPositive) {
        	firstPositive = true;
            if (A[i]>1)
            	return 1;
        }
        int difference = A[i+1] - A[i];
        if (difference > 1) {
            return (A[i]+1);
        }
    }
    int ret = A[i] + 1;
    while(ret <= 0)
        ret = ret + 1;

    return ret;
}

void parseInput(string inputstr, vector<int> &inputlist) {
	size_t pos=0, previousPos=0;
	string delimiter = " ";
	int value;

	//There's not much input validation is done here.
	while ((pos = inputstr.find(delimiter, previousPos)) != string::npos) {
		stringstream ss(inputstr.substr(previousPos, pos));
		ss>>value;
		inputlist.push_back(value);
		previousPos = pos + delimiter.length();
	}
	stringstream ss(inputstr.substr(previousPos));
	ss>>value;
	inputlist.push_back(value);
	return;
}

int main() {
	string inputstr;
	vector<int> inputlist;

	cout<<"Enter integers separated by space: ";
	getline(cin, inputstr);

	parseInput(inputstr, inputlist);

	cout<<"Returned: "<< solution(inputlist) <<endl;;
	return 0;
}
