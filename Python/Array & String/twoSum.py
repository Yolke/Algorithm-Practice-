def twoSum(nums: list[int],target:int)-> list[int]: #Brutforce solution O(N²)
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            x = nums[i]+nums[j]
            if x == target :
                return [i,j]
            
def twoSumOpti(nums: list[int],target:int) -> list[int]: #hashmap solution O(N)
    seen = {}
    for i,num in enumerate(nums):
        completion = target - num
        if completion in seen:
            return [seen[completion],i]
        seen[num] = i


            

print(twoSumOpti([2, 7, 11, 15], 27))  # ➞ [0, 1]