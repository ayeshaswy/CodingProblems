#!/usr/bin/python

def printClosest(list):
    closest = list[0]
    for i in range(1, len(list)-1) :
        if (abs(list[i]) < abs(closest)) :
            closest = list[i]
        elif (abs(list[i]) > abs(closest)):
            pass
        else :
            if (list[i]>closest):
                closest = list[i]

    print (closest)

list=[]
inputList = input("Enter list of integers separated by space\n")
inputList = inputList.lstrip()
inputList = inputList.rstrip()
inputList = inputList.split(' ')
for element in inputList:
    list.append(int(element))
printClosest(list)
