/*
 * lowestCommonInteger.cpp
 *
 *      Author: Anantha Yeshaswy
 *
 *	PROBLEM STATEMENT:
 *	Given 2 lists of integers, write a function solution(vector<int> &A, vector<int> &B)
 *	that returns the minimal integer value that is present in both the lists. Return -1
 *	if there is not common value in the lists.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
	int n = A.size();
	int m = B.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int k = 0; k < n; k++) {
        for (int i = 0;i < m && B[i] <= A[k]; i++) {
            if (A[k] == B[i])
            	return A[k];
        }
    }
    return -1;
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
	vector<int> A, B;

	cout<<"Enter integers of 1st list separated by space: ";
	getline(cin, inputstr);

	parseInput(inputstr, A);

	cout<<"Enter integers of 2nd list separated by space: ";
	getline(cin, inputstr);

	parseInput(inputstr, B);

	cout<<"Returned: "<< solution(A, B) <<endl;;
	return 0;
}
