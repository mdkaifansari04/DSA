

def printAlphabet_triangle(n):
    ch = 'A'
    for i in range(n):
        for j in range(i+1):
            print(ch, end= " ")
        print("\n")
        ch = chr(ord(ch)+1)

printAlphabet_triangle(5)