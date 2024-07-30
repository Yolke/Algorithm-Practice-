class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0

        idx = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[idx]:
                idx += 1
                nums[idx] = nums[i]
        
        return idx + 1

solution = Solution()
test = [1, 1, 1, 2, 2, 3, 4, 5]
x= solution.removeDuplicates(test)
print("Résultat:", x)
print(test[:x])
