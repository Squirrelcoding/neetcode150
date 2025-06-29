class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_chars = {}
        for c in s:
            if c not in s_chars:
                s_chars[c] = 1
            else:
                s_chars[c] += 1
        print(s_chars)
        for c in t:
            if c not in s_chars:
                return False
            else:
                s_chars[c] -= 1

        for v in s_chars.values():
            if v != 0:
                return False
        
        return True
s = Solution()

print(s.isAnagram("racecar", "carrace"))
