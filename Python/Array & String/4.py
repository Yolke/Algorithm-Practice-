def frequency(s:str)-> list[int]:
    tab = [0] * 26
    s = s.lower()
    for i in range(len(s)):
        index = ord(s[i]) - ord('a')
        tab[index] += 1
    return tab


def groupAnagrams(strs :list[str]) -> list[list[str]]:
    listFrequency = []
    stockMot = {}
    for i in range(len(strs)):
        listFrequency.append(frequency(strs[i]))

    for j in range(len(strs)):
        key = tuple(listFrequency[j])
        if key not in stockMot :
            stockMot[key] = []
        stockMot[key].append(strs[j])    
    return list(stockMot.values())
    



strs = ["act","pots","tops","cat","stop","hat"]
s = groupAnagrams(strs)
print(s)