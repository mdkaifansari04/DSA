
# print number box 
def printNumberSquare(n):
    row = 2*n-1
    for i in range(row):
        for j in range(row):
            top = i
            left = j
            right = row -1 - j
            bottom = row -1 -i
            minimum = min(min(top, bottom),min(left, right))
            print(n-minimum, end="")
        print()

printNumberSquare(9)