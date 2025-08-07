a="1010"
b="1011"



def addBinary(a: str,b: str) -> str:
    differenceLenght = abs(len(a) - len(b))
    if len(a) > len(b):
        b = differenceLenght*"0"+b
    else:
        a = differenceLenght*"0"+a
    revA = a[::-1]
    revB = b[::-1]

    result = ""
    retenu = 0
    for i in range(len(a)):
        sum = int(revA[i]) + int(revB[i]) + retenu
        retenu = 0
        if sum + retenu > 1:
            retenu = 1
            result = result + str(sum-2)
        else:
            result = result + str(sum)
        
    if retenu == 1:
        result = result + "1"
    result = result[::-1]
    return result

print(addBinary(a,b))




