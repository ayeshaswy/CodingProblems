# InterviewCodingProblems
Solutions to coding problems that I have come across in code challenges


PROBLEM STATEMENT 1

 ******************************calculatorStack
 
 Consider an input sequence containing 0-9, '*' and '+'. Write a function solution(string Input)
 to Read through the input sequence and push the character to a stack if it is a digit. If
 the character is '+' then take the pop the top to elements of stack, add them and push the
 result back to the stack. Similarly if the current character is '*', then pop the top 2 elements
 of stack, multiply them and push back to the stack.
 
 Return:
 > -1 if stack is empty or enough does not have enough elements to perform + 'or' *.
 > -1 if invalid character is entered in the input sequence.
 > -1 if input length is more than 200000.
 > The result of latest operation if end of input sequence is reached.
 
 
PROBLEM STATEMENT 2

 ************************************DecimalZip
 
 Given 2 non-negative integers, write a function solution(int A, int B) that returns their
 decimal zip i.e. a number which is made of alternate digits of the 2 input numbers.
 
 Example:
 		1)	input1 = 236, input2 = 743
   			output = 273463
 		2)	input1 = 203698, input2 = 743
   			output = 273463698 (last 3 digits of input1 are appended after exhausting digits of input2)
 		3) 	input1 = 236, input2 = 7434324
   			output = 2734634324 (last 3 digits of input2 are appended after exhausting digits of input1)
 		4)	input1 = 236, input2 = 0
   			output = 2036
 		5)	Return -1 if result is greater than 100000000


PROBLEM STATEMENT 3

 *****************************firstPositiveIntegerNotInList
 
 Given a list of integers, write a function solution(vector<int> A) that
 returns the lowest positive integer that is not part of the list.
 Example:	input = 1, 3, 4, 5, 7			    Output = 2 
  			     input = -2, 0, -3, -1, 2, 4		Output = 1
 	 		     input = -1, -3, -10, -5			  Output = 1
 
  
PROBLEM STATEMENT 4

 **********************************lowestCommonInteger
 
 Given 2 lists of integers, write a function solution(vector<int> &A, vector<int> &B)
 that returns the minimal integer value that is present in both the lists. Return -1
 if there is not common value in the lists.
