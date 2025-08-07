def isPowerOfTwo(n:int ) -> bool:
    if n == 1 or n == 0: return True
    x = 2
    num = 2
    while True:
        if n == num: return True
        if num > n:return False
        num = 2 ** x
        x += 2

print(isPowerOfTwo(1023))