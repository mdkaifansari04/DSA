

def printFullRightAngleTriangle (n):
    for i in range(1,n-1):
        print("*"*i)
    print("*"*n)
    for j in range(n-1, 0, -1):
        print("*"*j)
        
printFullRightAngleTriangle(5)
# *
# **
# ***
# *****
# ****
# ***
# **
# *

# 10 -1-5
def printTriangle(n):
    for i in range(2*n - 1):
        stars = i+1 if i < n else 2*n - 1 - i
        print("*" * stars)


printTriangle(5)