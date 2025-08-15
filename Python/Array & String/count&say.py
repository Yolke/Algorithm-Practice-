#https://fr.wikipedia.org/wiki/Codage_par_plages

def rle(s:str) -> str:
    cpt = 0
    newStr = ""
    for l in range(1,len(s)):
        cpt += 1
        if not s[l] == s[l-1]:
            newStr += str(cpt)+s[l-1]
            cpt = 0
    newStr += str(cpt+1)+s[-1]
    return newStr

def countAndSay(n: int) -> str:
    start = "1"
    for i in range(n-1):
        start = rle(start)
    return start
    

