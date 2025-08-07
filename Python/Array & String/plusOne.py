from typing import List


def plusOne(digits: List[int]) -> List[int]:
    n = len(digits)
    for idx, val in enumerate(reversed(digits)):
        real_idx = n - 1 - idx  # convertit l’index inversé vers l’index réel
        if val == 9:
            digits[real_idx] = 0
        else:
            digits[real_idx] += 1
            return digits
    # Si on n’a jamais break → tous des 9
    return [1] + [0] * n
