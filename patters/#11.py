

def numberTriangle(n):
    number = 1
    for i in range(1,n+1):
        for j in range(0,i):
            print(number,end="\t")
            number+=1
        print("\n")


numberTriangle(5)