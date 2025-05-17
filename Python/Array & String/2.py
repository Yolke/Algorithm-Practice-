from collections import Counter

#Ma solution C like
def isAnagram(s:str, t: str) -> bool:
    tab1,tab2 = [0] * 26
    for i in range(len(s)):
        s[i] = s[i].lower
        t[i] = t[i].lower
        index1 = ord(s[i]) - ord('a') #ord renvoie la valeur ascii est donc on peut avoir son ordre dans l'alphabet 
        index2 = ord(t[i]) - ord('a')
        tab1[index1] += 1
        tab2[index2] += 1
    
    for j in range(26) :
        if tab1[j] != tab2[j]:
            return False
    return True

#Meilleurs solution logique: 
def isAnagram2(s:str, t:str) -> bool:
    if len(s) != len(t):
        return False

    countS,countT =  {},{}

    for i in range(len(s)):
        countS[s[i]] = 1 + countS.get(s[i],0)
        countT[t[i]] = 1 + countT.get(t[i],0)
    for c in countS:
        if countS[c] != countT.get(c,0):
            return False
    return True

#best perf
def isAnagram3(s:str, t:str) -> bool:
    return Counter(s) == Counter(t)