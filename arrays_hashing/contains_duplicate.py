from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        h = {}
        for n in nums:
            if n in h:
                return True
        return False
