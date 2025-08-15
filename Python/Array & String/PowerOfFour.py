


def isPowerOfFour(n:int):
    if n == 0: 
        return False
    x = 0
    num = 0
    while num < n:
        num = 4**x
        x += 1
    if num == n:
        return True
    return False


print(isPowerOfFour(0))