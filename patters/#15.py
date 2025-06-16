

def printSquarePattern(n):
    initSpace = 0
    for i in range(0,n):
        #star
        for j in range (1,n-i):
            print("* ", end="")
        #spaces 
        for j in range(initSpace):
            print("  ", end="")
        #stars
        for j in range (1,n-i):
            print("* ", end="")
        print()
        initSpace +=2
    initSpace-=2
    for i in range(0,n):
        if n - i == 0:
            continue
        for j in range(i):
            print("* ", end="")
        for j in range(initSpace):
            print("  ", end="")
        for j in range(i):
            print("* ", end="")
        print()
        initSpace-=2

printSquarePattern(5)
