def duplicate(list1):
    dict = {}
    for num in list1:
        if num in dict:
            return False
        else:
            dict[num] = 1
    return True

print(duplicate([1, 2, 3]))     # ✅ True (pas de doublons)
print(duplicate([1, 2, 2, 3]))  # ❌ False (2 est en double)

def intersect(l1, l2):
    return list(set(l1) & set(l2))  # intersection entre deux ensembles


def intersect(l1, l2):
    l1.sort()
    l2.sort()
    res = []
    sizel1 = len(l1)
    sizel2 = len(l2)
    i = 0
    j = 0
    while(i < sizel1 and j < sizel2):
        if l1[i] == l2[j]:
            if not res or res[-1] != l1[i]:
                res.append(l1[i])
            i += 1
            j += 1
        elif l1[i] > l2[j]:
            j += 1
        elif l1[i] < l2[j]:
            i += 1
    return res
            

print(intersect([1, 2, 2, 3], [2, 2, 3]))  # [2, 3]
print(intersect([4, 5, 6], [1, 2]))        # []

def max(nums:list):
    x = nums[0]
    for i in range(len(nums)):
        if x < nums[i]:
            x = nums[i]
    return x

def majority_element(nums: list[int]) -> int:
    freq = {}
    max = 0
    index = 0
    for num in  nums:
        freq[num] = freq.get(num, 0) + 1  # initialise à 0 si la clé n'existe pas encore
        if max < freq[num]:
            max = freq[num]
            index = num
    return index
print(majority_element([2,2,1,1,1,2,2]))  # ✅ 2
