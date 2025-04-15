#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    int x = target;
    int l = 0;
    int h = n - 1;
    int m = l + (h - l) / 2;
    int ans = n;
    while (l <= h) {
      if (nums[m] >= x) {
        ans = m;
        h = m - 1;
      } else {
        l = m + 1;
      }
      m = l + (h - l) / 2;
    }
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution sol;
    int result = sol.searchInsert(nums, target);
    cout << result << endl;
  }
  return 0;
}
