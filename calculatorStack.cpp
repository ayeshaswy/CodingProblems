/*
 * calculatorStack.cpp
 *
 *      Author: Anantha Yeshaswy
 *
 * PROBLEM STATEMENT:
 * Consider an input sequence containing 0-9, '*' and '+'. write a function solution(string Input)
 * to Read through the input sequence and push the character to a stack if it is a digit. If
 * the character is '+' then take the pop the top to elements of stack, add them and push the
 * result back to the stack. Similarly if the current character is '*', then pop the top 2 elements
 * of stack, multiply them and push back to the stack.
 *
 * Return:
 * > -1 if stack is empty or enough does not have enough elements to perform + 'or' *.
 * > -1 if invalid character is entered in the input sequence.
 * > -1 if input length is more than 200000.
 * > The result of latest operation if end of input sequence is reached.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int solution(string input) {
	vector<int> digits;
	int inputLen = input.length();
	if (inputLen > 200000)
		return -1;

	char c[inputLen];
	int result=0;

	strcpy(c ,input.c_str());

	for (int i = 0; i<inputLen; i++) {
		if (isdigit(c[i])) {
			digits.push_back((int)(c[i]-'0'));
		}
		else if (c[i] == '+'){
			cout<<"Stack contents: ";
			for (auto i: digits) {
				cout<<i<<" ";
			}
			cout<<endl;
			if ((digits.size() < 2))
				return -1;
			int var1 = digits.back();
			digits.pop_back();
			int var2 = digits.back();
			digits.pop_back();
			result = var1 + var2;
			digits.push_back(result);
		} else if (c[i] == '*'){
			cout<<"Stack contents: ";
			for (auto i: digits) {
				cout<<i<<" ";
			}
			cout<<endl;
			if ((digits.size() < 2))
				return -1;
			int var1 = digits.back();
			digits.pop_back();
			int var2 = digits.back();
			digits.pop_back();
			result = var1 * var2;
			digits.push_back(result);
		} else
			return -1;
	}
	return result;

}


int main() {
	string inputstr;
	vector<int> inputlist;

	cout<<"Enter input sequence: ";
	getline(cin, inputstr);

	int retcode = solution(inputstr);
	cout<<"Returned: "<< retcode <<endl;;
	return 0;
}



