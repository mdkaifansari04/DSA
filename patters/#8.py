

def printFullRightAngleTriangle (n):
    for i in range(n-1):
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