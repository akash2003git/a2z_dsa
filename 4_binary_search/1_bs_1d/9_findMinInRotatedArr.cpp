#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    int mini = INT_MAX;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[low] <= nums[high]) {
        mini = min(mini, nums[low]);
        break;
      }
      if (nums[low] <= nums[mid]) {
        mini = min(mini, nums[low]);
        low = mid + 1;
      } else {
        mini = min(mini, nums[mid]);
        high = mid - 1;
      }
    }
    return mini;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution sol;
    int minVal = sol.findMin(nums);
    cout << minVal << endl;
  }
  return 0;
}
