#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      map<char, int> s1_chars;
      map<char, int> window_chars;
      for (int i = 'a'; i <= 'z'; ++i) {
        window_chars[i] = 0;
        s1_chars[i] = 0;
      }

      for (char c : s1) {
        s1_chars[c]++;
      }
      
      for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        window_chars[s2[i]]++;
      }

      int p = min(s1.size(), s2.size());

      while (p <= s2.size()) {
        // Check if it's a permutation
        if (s1_chars == window_chars) return true;

        // Remove first character and add new character
        window_chars[p - s1.size() - 1]--;
        window_chars[p]++;
      }

      return false;
    }
};


int main() {
  Solution s;
  string s1 = "ab";
  string s2 = "eidbaooo";
  cout << s.checkInclusion(s1, s2) << endl;
  return 0;
}
