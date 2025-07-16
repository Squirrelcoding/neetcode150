#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool b_at_least_a(map<char, int> a, map<char, int> b) {
      for (auto p : a) {
        if (b[p.first] < p.second) return false;
      }
      return true;
    }
    string minWindow(string s, string t) {
      map<char, int> t_freq;
      map<char, int> s_freq;

      

      return "";
    }
};


int main() {
  freopen("input", "r", stdin);
  Solution s;
  string ss;
  cin >> ss;
  string tt;
  cin >> tt;
  cout<< s.minWindow(ss, tt) << endl;
  
  return 0;
}
