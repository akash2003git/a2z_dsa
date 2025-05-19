#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxIdx(vector<vector<int>> &mat, int col) {
    int n = mat.size();
    int max_element = -1;
    int max_idx = -1;
    for (int i = 0; i < n; i++) {
      if (mat[i][col] > max_element) {
        max_element = mat[i][col];
        max_idx = i;
      }
    }
    return max_idx;
  }
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int maxRowIdx = maxIdx(mat, mid);
      int curr = mat[maxRowIdx][mid];
      int left = mid - 1 > 0 ? mat[maxRowIdx][mid - 1] : -1;
      int right = mid + 1 < m ? mat[maxRowIdx][mid + 1] : -1;
      if (curr > left && curr > right) {
        return {maxRowIdx, mid};
      } else if (curr < left) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return {-1, -1};
  }
};

// 2
// 2 2
// 1 4
// 3 2
// 3 3
// 10 20 15
// 21 30 14
// 7 16 32

// 1 0
// 1 1

int main() {
  int t;
  cin >> t;
  while (t--) {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        cin >> mat[i][j];
      }
    }
    Solution sol;
    vector<int> peak = sol.findPeakGrid(mat);
    cout << peak[0] << " " << peak[1] << endl;
  }
  return 0;
}
