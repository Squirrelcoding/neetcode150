#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() <= 1) return s.size();
      int max_length = 1;
      int l = 0;
      int r = 0;
      set<char> characters;
      characters.insert(s[l]);
      while (r < s.size()) {
        r++;
        while (characters.count(s[r])) {
          max_length = max(max_length, r - l);
          characters.erase(s[l]);
          l++;
        }
        characters.insert(s[r]);
        max_length = max(max_length, r - l);
      }
      return max_length;
    }
};


int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << " " << 3 << endl;
  cout << s.lengthOfLongestSubstring("bbbbb") << " " << 1 << endl;
  cout << s.lengthOfLongestSubstring("pwwkew") << " " << 3 << endl;
  cout << s.lengthOfLongestSubstring("au") << " "  << 2 << endl;
  cout << s.lengthOfLongestSubstring("zxyzxyz") << " "  <<  3 <<endl;
  cout << s.lengthOfLongestSubstring("xxxx") << " "  << 1 << endl;

  return 0;
}
