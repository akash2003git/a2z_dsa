#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) {
      return false;
    }
    int cols = matrix[0].size();
    if (cols == 0) {
      return false;
    }

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int row = mid / cols;
      int col = mid % cols;

      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};

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
