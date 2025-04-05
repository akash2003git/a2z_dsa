#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }

    Solution obj;
    obj.rotate(matrix);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << (j == n - 1 ? "" : " ");
      }
      cout << endl;
    }
    cout << "~" << endl;
  }
  return 0;
}
