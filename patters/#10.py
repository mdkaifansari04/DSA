# number pattern


def printNumberPattern(n):

    for row in range(1,n+1):
        for i in range(1,n+1):
            print(i, end="\t") if (i<=row) else print(' ', end="\t")
        for j in range(n,0,-1):
             print(j, end="\t") if (j<=row) else print(' ', end="\t")
        print("\n")

printNumberPattern(4)