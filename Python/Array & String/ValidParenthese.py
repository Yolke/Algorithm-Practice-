def validParenthese(s: str) -> bool:
    stack = []
    pairs = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in pairs.values():  # si c'est une ouvrante
            stack.append(char)
        elif char in pairs:
            if not stack or stack[-1] != pairs[char]:
                return False
            stack.pop()
        else:
            return False  # caractère inattendu

    return not stack  # True si la pile est vide à la fin


print(validParenthese("{(())}"))

print(7//2)