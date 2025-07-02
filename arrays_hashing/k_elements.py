from typing import List

class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        hashmap = {}
        for num in nums:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                hashmap[num] += 1

        result = dict(zip([i for i in range(n + 1)], [[] for _ in range(n + 1)]))

        for num, frequency in hashmap.items():
            result[frequency].append(num)

        top_k = []

        i = n
        while i >= 0:
            for num in result[i]:
                if len(top_k) < k:
                    top_k.append(num)
            i -= 1

        return top_k

s = Solution()

print(s.topKFrequent([1, 2, 2, 3, 3, 3], 2))
