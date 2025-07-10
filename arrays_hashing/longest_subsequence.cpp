#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if (nums.size() == 0) return 0;

      map<int, int> frequency_table;
      for (int i = 0; i < nums.size(); ++i) {
        if (frequency_table.count(nums[i]) > 0) {
          frequency_table[nums[i]]++;
        } else {
          frequency_table.insert({nums[i], 1});
        }
      }

      vector<int> keys;
      for (auto p : frequency_table) {
        keys.push_back(p.first);
      }

      int longest_subsequence = 1;
      int temp = 1;

      // Apply a sliding window approach
      for (int i = 0; i < keys.size() - 1; ++i) {
        while (i < keys.size() - 1 && keys[i] + 1 == keys[i + 1]) {
          temp += 1; 
          i++;
        } 
        longest_subsequence = max(longest_subsequence, temp);
        temp = 1;
      }

      return longest_subsequence;
    }
};


int main (){
  Solution s;

  vector<int> v = {5, 6, 7};

  cout << s.longestConsecutive(v) << endl;

  return 0;
}
