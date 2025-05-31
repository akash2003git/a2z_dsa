#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // int n = matrix.size();
    // int m = matrix[0].size();
    // vector<int> rows(n, 0);
    // vector<int> cols(m, 0);
    //
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     if (matrix[i][j] == 0) {
    //       rows[i] = 1;
    //       cols[j] = 1;
    //     }
    //   }
    // }
    //
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     if (rows[i] || cols[j]) {
    //       matrix[i][j] = 0;
    //     }
    //   }
    // }

    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    // marking rows and cols
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          // mark the i-th row
          matrix[i][0] = 0;
          // mark the j-th row
          if (j != 0) {
            matrix[0][j] = 0;
          } else {
            col0 = 0;
          }
        }
      }
    }

    // zeroing out the inner portion
    // (porition excluding the row and col used for marking)
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] != 0) {
          // check for col and row
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }
    }

    // zeroing out the marking row
    if (matrix[0][0] == 0) {
      for (int j = 1; j < m; j++) {
        matrix[0][j] = 0;
      }
    }

    // zeroing out the marking col
    if (col0 == 0) {
      for (int i = 0; i < n; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
      }
    }

    Solution obj;
    obj.setZeroes(matrix);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << matrix[i][j] << (j == cols - 1 ? "" : " ");
      }
      cout << endl;
    }
    cout << "~" << endl;
  }
  return 0;
}
