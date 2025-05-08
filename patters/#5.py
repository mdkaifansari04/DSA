

def printPyramid(n):
    for i in  range(n):
        space = " "
        output = ""
        for s1 in range(n-i):
            output+=space
        for j in range(2*i+1):
            output+="*"
        for s1 in range(n-i):
            output+=space
        print(output)
            
printPyramid(5)

#      *     
#     ***    
#    *****   
#   *******  
#  ********* 