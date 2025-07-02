from typing import List

class Solution:
    def id(self, a: str) -> tuple:
        result = [0 for _ in range(26)]
        for char in a:
            result[ord(char) - 97] += 1
        return tuple(result)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}

        for string in strs:
            if self.id(string) not in hashmap:
                hashmap[self.id(string)] = [string]
            else:
                hashmap[self.id(string)].append(string)

        result = []
        for key in hashmap:
            result.append(hashmap[key])
        return result


s = Solution()

print(s.groupAnagrams(["hhhhu","tttti","tttit","hhhuh","hhuhh","tittt"]))
