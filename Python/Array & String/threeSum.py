
from typing import List

def remove_duplicates(triplets: List[List[int]]) -> List[List[int]]:
    unique = set(tuple(sorted(t)) for t in triplets)  # tuples triés pour comparaison
    return [list(t) for t in unique]  

def twoSum(nums: list[int],target:int) -> list[int]: #hashmap solution O(N)
    seen = {}
    for i,num in enumerate(nums):
        completion = target - num
        if completion in seen:
            return [seen[completion],i]
        seen[num] = i

def threeSum(nums: List[int]) -> List[List[int]]:

    l = []
    for num in nums:
        l_sorted = sorted(l)
        res = twoSum(nums,-num)
        if res and not any(sorted(existing) == l_sorted for existing in l):
            l.append([num,nums[res[0]],nums[res[1]]])
    result = remove_duplicates(l)
    
    return result    

print(threeSum([-1,0,1,2,-1,-4]))