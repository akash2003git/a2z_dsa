#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findRotations(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    int mini = INT_MAX;
    int idx = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[low] <= nums[high]) {
        if (nums[low] < mini) {
          mini = nums[low];
          idx = low;
        }
        break;
      }
      if (nums[low] <= nums[mid]) {
        if (nums[low] < mini) {
          mini = nums[low];
          idx = low;
        }
        low = mid + 1;
      } else {
        if (nums[mid] < mini) {
          mini = nums[mid];
          idx = mid;
        }
        high = mid - 1;
      }
    }
    return idx;
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
    int minVal = sol.findRotations(nums);
    cout << minVal << endl;
  }
  return 0;
}
