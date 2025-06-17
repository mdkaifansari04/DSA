import math
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -2**31
        INT_MAX = 2**31 -1
        SIGNED = False
        
        reverseDigitString = "" 
        if(x<0):
            SIGNED = True
            x=abs(x)


        while(x > 0):
            lastDigit = int(x%10)
            reverseDigitString += str(lastDigit)
            x = int(x /10)
            
        reversedNum = 0 if reverseDigitString == "" else int(reverseDigitString)
        if (reversedNum < INT_MIN or reversedNum > INT_MAX ):
            return 0
        
        if(SIGNED): 
            return -1 * reversedNum
        return reversedNum
            
            
    


# Local test runner
if __name__ == "__main__":
    sol = Solution()

    test_cases = [
        (123, 321),
        (-123, -321),
        (120, 21),
        (0, 0),
        (1534236469, 0),  # this causes overflow
    ]

    for inp, expected in test_cases:
        result = sol.reverse(inp)
        print(f"Input: {inp}, Output: {result}, Expected: {expected}, ✅ {result == expected}")
