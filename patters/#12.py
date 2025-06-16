

def printAlphabetTriangle(n):
    for i in range(n):
        for j in range(i+1):
            print(chr(ord("A")+ j), end=" ")
        print('\n')
        

printAlphabetTriangle(5)