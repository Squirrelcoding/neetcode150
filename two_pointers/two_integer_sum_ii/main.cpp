#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int p1 = 0;
    int p2 = numbers.size() - 1;
    while (true) {
      int sum = numbers[p1] + numbers[p2];
      if (sum < target) {
        p1++;
      }
      else if (sum > target) {
        p2--;
      } else {
        return {p1 + 1, p2 + 1};
      }
   }
    return {-1, -1};
}
};


int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  int target = 3;
  vector<int> result = s.twoSum(nums, target);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
