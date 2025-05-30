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


x  = isPalindrome("TettheT")
print(x)