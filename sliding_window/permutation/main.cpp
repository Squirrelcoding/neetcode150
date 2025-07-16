#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s2.size() < s1.size()) return false;
      int n = s1.size();
      int s1_dist[26] = { 0 };
      int window_dist[26] = { 0 };

      // Populate s1_dist and window_dist
      for (char c : s1) { s1_dist[c - 97]++; }
      for (int i = 0; i < n; ++i) { window_dist[s2[i] - 97]++; }

      int p = 0;
      while (p + n <= s2.size()) {
        int i = 0;
        while (i < 26) {
          if (s1_dist[i] != window_dist[i]) break; ++i;
        }
        if (i == 26) return true;
        window_dist[s2[p]]--;
        window_dist[s2[p + n]]++;
        p++;
      }
      return false;
    }
};


int main() {
  Solution s;
  string s1 = "eebaacel";
  string s2 = "c";
  cout << s.checkInclusion(s1, s2) << endl;
  return 0;
}
