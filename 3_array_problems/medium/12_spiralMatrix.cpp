#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
        ans.push_back(matrix[top][i]);
      }
      top++;
      for (int i = top; i <= bottom; i++) {
        ans.push_back(matrix[i][right]);
      }
      right--;
      if (top <= bottom) {
        for (int i = right; i >= left; i--) {
          ans.push_back(matrix[bottom][i]);
        }
        bottom--;
      }
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          ans.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return ans;
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
    vector<int> result = obj.spiralOrder(matrix);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
