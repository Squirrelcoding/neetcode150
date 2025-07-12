#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      if (height.size() <= 2) return 0;
      int total = 0;
      int p1 = 0;
      int p2 = 1;

      // Find the index of the max element
      int left_max_index = 0;
      for (int i = 0; i < height.size(); ++i) {
        if (height[i] > height[left_max_index]) left_max_index = i;
      }

      // Find the index of the max element
      int right_max_index = 0;
      for (int i = height.size() - 1; i >= 0; --i) {
        if (height[i] > height[right_max_index]) right_max_index = i;
      }

      while (p2 < left_max_index) {
        // Keep moving until we find an anchor
        if (height[p1] == 0) {
          p1++;
          p2++;
          continue;
        }

        if (height[p2] >= height[p1]) {
          p1 = p2;
          p2++;
          continue;
        }

        total += height[p1] - height[p2];
        p2++;
      }

      // Add together all the area between the two max_heights
      /*total += (right_max_index - left_max_index) * height[left_max_index];*/
      for (int i = left_max_index; i <= right_max_index; ++i) {
        total += height[left_max_index] - height[i];
      }

      p1 = height.size() - 1;
      p2 = p1 - 1;

      while (p2 > right_max_index) {
        // Keep moving until we find an anchor
        if (height[p1] == 0) {
          p1--;
          p2--;
          continue;
        }

        if (height[p2] >= height[p1]) {
          p1 = p2;
          p2--;
          continue;
        }

        total += height[p1] - height[p2];
        p2--;
      }

      return total;
    }
};


int main() {
  Solution s;
  vector<int> v = {0,2,0,3,1,0,1,3,2,1};
  cout << s.trap(v) << endl;
  return 0;
}

