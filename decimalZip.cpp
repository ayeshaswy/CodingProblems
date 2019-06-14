/*
 * decimalZip.cpp
 *
 *      Author: Anantha Yeshaswy
 *
 * PROBLEM STATEMENT:
 * Given 2 non-negative integers, write a function solution(int A, int B) that returns their
 * decimal zip i.e. a number which is made of alternate digits of the 2 input numbers.
 *
 * Example:
 * 		1)	input1 = 236, input2 = 743
 * 			output = 273463
 * 		2)	input1 = 203698, input2 = 743
 * 			output = 273463698 (last 3 digits of input1 are appended after exhausting digits of input2)
 * 		3) 	input1 = 236, input2 = 7434324
 * 			output = 2734634324 (last 3 digits of input2 are appended after exhausting digits of input1)
 * 		4)	input1 = 236, input2 = 0
 * 			output = 2036
 * 		5)	Return -1 if result is greater than 100000000
 */

#include <iostream>
#include <vector>

using namespace std;

void getDigitsInNum(int num, vector<int> &digits){
    int divider = 10;
    for (; num>=10;) {
        int reminder = num%divider;
        digits.insert(digits.begin(), reminder);
        num = num/divider;
    }

    digits.insert(digits.begin(),num);
    return;
}

int solution(int A, int B) {
	vector<int> digitsA, digitsB;
	int decimalzip=0;

	getDigitsInNum(A, digitsA);
	getDigitsInNum(B, digitsB);

	int m = digitsA.size();
	int n = digitsB.size();
	int i;

	for (i = 0; i<m && i< n; i++) {
		decimalzip = (decimalzip*10) + digitsA[i];
		decimalzip = (decimalzip*10) + digitsB[i];
	}

	if (i == m) {
		for (;i<n; i++) {
			decimalzip = (decimalzip*10) + digitsB[i];
		}
	} else if (i == n) {
		for (;i<m; i++) {
			decimalzip = (decimalzip*10) + digitsA[i];
		}
	}

	if (decimalzip > 100000000)
		return -1;
	else
		return decimalzip;
}
int main() {
	int A, B;

	cout<<"Enter 1st integer: ";
	cin>>A;

	cout<<"Enter 2nd integer: ";
	cin>>B;

	cout<<"Returned: "<< solution(A, B)<<endl;;
	return 0;
}

