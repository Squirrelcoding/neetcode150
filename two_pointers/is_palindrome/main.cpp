#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
      int i = 0;
      int j = s.size() - 1;

      while (i != j) {
        while (i < s.size() && !isalnum(s[i])) i++;
        while (j >= 0 && !isalnum(s[j])) j--;
        if (i > s.size() - 1 || j < 0) break;
        if (char(tolower(s[i])) != char(tolower(s[j]))) return false;
        i++;
        j--;
      }

      return true;        
    }
};


int main() {
  Solution s;

  string str = "aa";


  cout << s.isPalindrome(str) << endl;

  return 0;
}
