



def printReversePyramid(n):
    for i in  range(n,0, -1):
        space = " " * (n-i)
        output = "*" * (2*i-1)
        print(space + output)
            
printReversePyramid(5)

# *********
#  ******* 
#   *****  
#    ***   
#     *    