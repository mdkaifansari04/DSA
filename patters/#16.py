

def printPattern(n):
    space = (n-2) *2
    rows= 2*n-1
    for i in range(1,rows+1):
        if(i < 2*n/2):
            print("*"*i, end="")
            print(" "*space, end="")
            print("*"*i, end="")
            space = space-2  if space > 0 else space+2
            print()
        else:
            print("*"*(2*n-i-2), end="")
            print(" "*space, end="")
            print("*"*(2*n-i-2), end="")
            space +=2
            print()

printPattern(5)