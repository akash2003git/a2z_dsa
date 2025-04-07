#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> generateRows(int n) {
    vector<int> row;
    int num = 1;
    row.push_back(num);
    for (int i = 1; i < n; i++) {
      num = num * (n - i);
      num = num / i;
      row.push_back(num);
    }
    return row;
  }

  vector<vector<int>> generate(int numRows) {
    // int n = numRows;
    // vector<vector<int>> ans(n);
    // for (int i = 0; i < n; i++) {
    //   ans[i].resize(i + 1);
    //   ans[i][0] = 1;
    //   ans[i][i] = 1;
    //   if (n >= 2) {
    //     for (int j = 1; j < i; j++) {
    //       ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
    //     }
    //   }
    // }
    // return ans;
    vector<vector<int>> pascaleTriangle;
    for (int i = 1; i <= numRows; i++) {
      pascaleTriangle.push_back(generateRows(i));
    }
    return pascaleTriangle;
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int numRows;
    cin >> numRows;

    Solution obj;
    vector<vector<int>> result = obj.generate(numRows);

    for (const auto &row : result) {
      for (int val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
    cout << "~" << endl;
  }
  return 0;
}
