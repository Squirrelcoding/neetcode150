from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        # Populate the hashmap
        for i, n in enumerate(nums):
            if n not in hashmap:
                hashmap[n] = [i]
            else:
                hashmap[n].append(i)

        print(hashmap)
        
        for i, n in enumerate(nums):
            # If we found a potential pair
            if target - n in hashmap:
                # Check whether it's the same one. That is, target == 2 * n
                if target == 2 * n:
                    if len(hashmap[n]) == 2:
                        return hashmap[n][:2]
                    else:
                        continue
                return [i, hashmap[target - n][0]]
        return [-1, -1]


s = Solution()

print(s.twoSum([3, 4, 5, 6], 7))
