#Contains duplicate :
#My Solution
def hasDuplicate(nums: list[int]) -> bool:
    for i in range(len(nums)):
        for j in range(i + 1,len(nums)):
            if nums[i] == nums[j]:
                return True
    return False

#The best solution
def hasDuplicate2(nums: list[int]) -> bool:
    hashset = set()

    for n in nums:
        if n in hashset:
            return True
        hashset.add(n)
    return False