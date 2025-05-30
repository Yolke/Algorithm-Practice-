#Brut force solution
def threeSum(nums: list[int]) -> list[list[int]]:
    l = []

    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for w in range(j + 1, len(nums)):
                x = nums[i]+nums[j]+nums[w]
                if x == 0:
                    l.append([nums[i],nums[j],nums[w]])

    seen = set()
    result = []

    for triplet in l:
        sorted_triplet = tuple(sorted(triplet))
        if sorted_triplet not in seen:
            seen.add(sorted_triplet)
            result.append(triplet)
    
    return result









nums = [-1,0,1,2,-1,-4]
print(threeSum(nums))