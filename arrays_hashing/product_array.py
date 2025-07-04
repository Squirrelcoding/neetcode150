from typing import List

class Solution:
    def multiply(self, t: List[int], skip: int) -> int:
        prod = 1
        for i in range(61):
            if i == skip:
                print(t[i])
                prod *= pow(i - 30, t[i] - 1) 
                continue
            prod *= pow(i - 30, t[i])
        return prod

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total = [0 for _ in range(61)]
        for n in nums:
            total[n + 30] += 1
        result = []
        for i in range(len(nums)):
            result.append(self.multiply(total, nums[i] + 30))

        return result

s = Solution()

print(s.productExceptSelf([0, 0, 0]))
