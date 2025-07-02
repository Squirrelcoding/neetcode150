from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        result = ""
        for string in strs:
            result += chr(0xC0)
            result += str(len(string))
            result += chr(0xC0)
            result += string
        return result
    def decode(self, s: str) -> List[str]:
        result = []
        i = 0
        while i < len(s):
            # If it's a number get the rest of the numbers
            num = ""
            if s[i] == chr(0xC0):
                i += 1
                # If we start with a 0, add empty string
                if int(s[i]) == 0:
                    result.append("")
                    i += 2
                    continue
                while s[i] != chr(0xC0):
                    num += s[i]
                    i += 1
                i += 1
                num = int(num)
                result.append(s[i: i + num])
            i += 1

        return result

s = Solution()

# DONT MIX NUMBERS AND THE INFO
encoded = s.encode(["","44","","[]"])
print(encoded)
decoded = s.decode(encoded)
print(decoded)

# 1100011110111111001001100101
