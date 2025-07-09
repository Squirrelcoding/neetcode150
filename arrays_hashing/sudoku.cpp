#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int n = board.size();

      // Form a hashset for each of the rows to check for duplicates
      for (int row = 0; row < n; ++row) {
        map<char, int> m;
        for (int col = 0; col < n; ++col) {
          char c = board[row][col];
          if (c != '.') {
            if (m.count(c) > 0) {
              return false;
            } else {
              m.insert({c, 1});
            }
          }
        }

      for (int col = 0; col < n; ++col) {
        map<char, int> m;
        for (int row = 0; row < n; ++row) {
          char c = board[row][col];
          if (c != '.') {
            if (m.count(c) > 0) {
              return false;
            } else {
              m.insert({c, 1});
            }
          }
        }
      }

      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          map<char, int> m;
          for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
              char c = board[3  * i + k][3 * j + l];
                
              if (c != '.') {
                if (m.count(c) > 0) {
                  return false;
                } else {
                  m.insert({c, 1});
                }
              }
            } 
          }
        }
      }
    }

      return true;        
    }
};


int main() {
  Solution s;
  vector<vector<char>> input = {{'1','2','.','.','3','.','.','.','.'},
 {'4','.','.','5','.','.','.','.','.'},
 {'.','9','1','.','.','.','.','.','3'},
 {'5','.','.','.','6','.','.','.','4'},
 {'.','.','.','8','.','3','.','.','5'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','.','.','.','.','.','2','.','.'},
 {'.','.','.','4','1','9','.','.','8'},
 {'.','.','.','.','8','.','.','7','9'}};
  bool res = s.isValidSudoku(input);
  cout << res << endl;
  return 0;
}
