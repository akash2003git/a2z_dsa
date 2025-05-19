#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (arr[mid] > x) {
        ans = mid;
        high = mid - 1; // Look for a smaller index on the left
      } else {
        low = mid + 1; // Look on the right
      }
    }
    return ans;
  }

  int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += upperBound(matrix[i], x, m);
    }
    return cnt;
  }

  int findMedian(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < n; i++) {
      low = min(low, matrix[i][0]);
      high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m + 1) / 2;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int smallEqual = countSmallEqual(matrix, m, n, mid);
      if (smallEqual < req)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }
};

// 2
// 5 5
// 1 5 7 9 11
// 2 3 4 8 9
// 4 11 14 19 20
// 6 10 22 99 100
// 7 15 17 24 28
// 3 5
// 1 2 3 4 5
// 8 9 11 12 13
// 21 23 25 27 29

// 10
// 11

int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> matrix[i][j];
      }
    }
    Solution sol;
    cout << sol.findMedian(matrix) << endl;
  }
  return 0;
}
