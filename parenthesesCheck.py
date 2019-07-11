#!/usr/bin/python


class Solution:
    str = ''
    def __init__(self):
        self.curlyParenthesis = 0
        self.squareParenthesis = 0
        self.lastOpenParenthesis = []

    def checkParenthesis(self):
        for ch in Solution.str:
            if(ch == '['):
                self.squareParenthesis = self.squareParenthesis +1
                self.lastOpenParenthesis.append(ch)
            elif(ch == ']'):
                if (self.squareParenthesis >0):
                    if (self.lastOpenParenthesis[-1] == '{'):
                        break
                    self.squareParenthesis = self.squareParenthesis -1
                    del self.lastOpenParenthesis[-1]
                else:
                    self.squareParenthesis = 1
                    break
            elif(ch == '{'):
                self.curlyParenthesis = self.curlyParenthesis +1
                self.lastOpenParenthesis.append(ch)
            else:
                if (self.curlyParenthesis>0):
                    if (self.lastOpenParenthesis[-1] == '['):
                        break
                    self.curlyParenthesis = self.curlyParenthesis - 1
                    del self.lastOpenParenthesis[-1]
                else:
                    self.curlyParenthesis = 1
                    break

        if ((self.curlyParenthesis ==0) and (self.squareParenthesis == 0)):
            return 0
        else:
            return 1

    def getInput(self):
        Solution.str = input("Enter input\n")



solObj = Solution()
solObj.getInput()
print(type(solObj.lastOpenParenthesis))
if (solObj.checkParenthesis()):
    print ("incorrect")
else:
    print ("correct")
