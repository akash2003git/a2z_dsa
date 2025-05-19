#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;
    while (row <= n - 1 && col >= 0) {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] > target)
        col -= 1;
      else
        row += 1;
    }
    return false;
  }
};

// 2
// 5 5
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 5
// 5 5
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 20

// true
// false

int main() {
  int t;
  cin >> t;
  while (t--) {
    int rows, cols, target;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        cin >> matrix[i][j];
      }
    }
    cin >> target;
    Solution sol;
    if (sol.searchMatrix(matrix, target)) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
  return 0;
}
