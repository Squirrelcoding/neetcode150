#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

      set<int> frequency_table;
      for (int i = 0; i < nums.size(); ++i) {
        frequency_table.insert(nums[i]);
      }       

      int longest_subsequence = nums.size();

      return longest_subsequence;
    }
};


int main (){
  Solution s;

  vector<int> v = {5, 6, 7};

  cout << s.longestConsecutive(v) << endl;

  return 0;
}
