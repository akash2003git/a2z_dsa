#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lower_bound(vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= x) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
  int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max_cnt = 0;
    int row_index = -1;
    for (int i = 0; i < n; i++) {
      int curr_cnt = m - lower_bound(matrix[i], 1);
      if (curr_cnt > max_cnt) {
        max_cnt = curr_cnt;
        row_index = i;
      }
    }
    return row_index;
  }
};

// 4
// 3 3
// 0 1 1
// 1 1 1
// 0 0 0
// 2 2
// 1 1
// 1 1
// 3 3
// 0 0 0
// 0 0 0
// 0 0 0
// 2 1
// 0
// 0

// 1
// 0
// -1
// -1

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    Solution sol;
    cout << sol.rowWithMax1s(arr, n, m) << endl;
  }
  return 0;
}
