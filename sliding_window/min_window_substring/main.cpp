#include<string>
#include<map>
#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
      set<char> t_freq;
      for (char c : t) t_freq.insert(c);
      vector<char> chars;
      vector<int> indices;

      for (int i = 0; i < s.size(); ++i) {
        if (t_freq.count(s[i])) {
          chars.push_back(s[i]);
          indices.push_back(i);
        }
      }

      

      map<char, int> t_chars;
      for (char c : t) {
        if (t_chars.count(c)) {
          t_chars[c]++;
        } else {
          t_chars[c] = 1;
        }
      }

      map<char, int> window_chars;
      for (char c : t) {
        window_chars[c] = 0;
      }

      if (chars.size() < t.size()) return "";
      int a = 0;
      int b = t.size() - 1;

      for (int i = a; i <= b; ++i) {
        window_chars[chars[i]]++;
      }

      int start = -3000;
      int end = 3000;

      while (b < chars.size()) {
        if (window_chars == t_chars) {
          if (indices[b] - indices[a] < end - start) {
            start = indices[a];
            end = indices[b];
          }
        }
        window_chars[chars[a]]--;
        a++;
        b++;
        if (b < chars.size()) window_chars[chars[b]]++;
      }

      if (end == 3000 && start == -3000) return "";
      return s.substr(start, 1 + end - start);
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
