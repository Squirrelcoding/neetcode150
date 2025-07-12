#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int p1 = prices.size() - 1;        
      int p2 = p1 - 1;
      int max_profit = 0;
      while (p2 >= 0) {
        if (prices[p2] > prices[p1]) {
          p1 = p2;
          p2--;
          continue;
        }
        max_profit = max(max_profit, prices[p1] - prices[p2]);
        p2--;
      }
      return max_profit;
    }
};

int main() {
  Solution s;
  vector<int> prices = {10,8,7,5,2};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
