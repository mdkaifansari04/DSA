
a = -321
signed = False
if(a<0):
    a =abs(a)
    signed = True

print(a%10)

if(signed):
    a = -1*a

print(a)