def isPalindrome( s:str ) -> bool :
    s=s.lower()
    list = []
    for i in range(len(s)):
        if s[i].isalpha():
            list.append(s[i])
    if len(list) < 2:
        return False
    for j in range(len(list)):
        if list[j] != list[len(list)-j-1]:
            return False

    return True


# x  = isPalindrome("TettheT")
# print(x)



x = 1122332211
def isPalindromeInt(x:int) -> bool:
    numStr = str(x)
    size_divided = len(numStr)//2
    for i in range(size_divided):
        if numStr[i] != numStr[len(numStr)-i-1]:
            return False
    return True
        

print(isPalindromeInt(x))