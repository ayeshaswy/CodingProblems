#!/usr/bin/python

def solution(num, pos) :
    mask = 2**(pos - 1)
    return(num & mask)

while (1) :
    num = int(input("Enter the number\n"))
    pos = int(input("Enter the position of bit to be checked\n"))
    if (solution(num, pos)):
        print("true")
    else:
        print("false")
    choice = input("Print Y to try another number\nPrint N to exit\n")
    if (choice.lower() == 'y') :
        continue
    elif (choice.lower() == 'n') :
        break

