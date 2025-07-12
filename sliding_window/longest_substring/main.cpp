#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() <= 1) return s.size();
      int p1 = 0;
      int p2 = 1;
      int res = 1;

      while (p2 < s.size()) {
        if (s[p1] == s[p2]) {
          p1++;
          p2++;
          continue;
        }
        map<char, int> chars;
        chars.insert({s[p1], p1});
        chars.insert({s[p2], p2});
        while (true) {
          p2++;
          if (p2 == s.size() || chars.count(s[p2])) {
            res = max(res, p2 - p1);
            p1 = p2;
            p2 = p1 + 1;
            break;
          } else {
            chars.insert({s[p2], p2});
          }
        }
      }

      return res;        
    }
};


int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("au") << endl;

  return 0;
}
