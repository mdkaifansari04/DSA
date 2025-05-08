def printWholePyramid(n):
    for i in range(n):
        space = " " * (n-i-1)
        stars = "*" *(2*i + 1)
        space = " " * (n-i-1)
        print( space + stars + space)
    for i in range(n,0, -1):
        space = " " * (n-i)
        stars = "*" *(2*i - 1)
        space = " " * (n-i)
        print( space + stars + space)
        
printWholePyramid(5)
#     *    
#    ***   
#   *****  
#  ******* 
# *********
# *********
#  ******* 
#   *****  
#    ***   
#     *    