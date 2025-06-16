
def isEvenLine(lineNumber):
    return True if(lineNumber % 2 == 0) else False

def printBinaryTriangle(n):
    for i in range(n):
        if(isEvenLine(i)):
            for j in range(i):
                print("0\t", end="") if(j%2 ==0) else print("1\t", end="")
        else:
            for j in range(i):
                  print("1\t", end="") if(j%2 ==0) else  print("0\t", end="")
        print('\n')


printBinaryTriangle(10)