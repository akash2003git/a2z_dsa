#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    // int low = 0;
    // int high = nums.size() - 1;
    // int first = -1, last = -1;
    // vector<int> ans;
    // while (low <= high) {
    //   int mid = low + (high - low) / 2;
    //   if (nums[mid] == target) {
    //     first = mid;
    //     high = mid - 1;
    //   } else if (nums[mid] > target) {
    //     high = mid - 1;
    //   } else {
    //     low = mid + 1;
    //   }
    // }
    // low = 0;
    // high = nums.size() - 1;
    // while (low <= high) {
    //   int mid = low + (high - low) / 2;
    //   if (nums[mid] == target) {
    //     last = mid;
    //     low = mid + 1;
    //   } else if (nums[mid] > target) {
    //     high = mid - 1;
    //   } else {
    //     low = mid + 1;
    //   }
    // }
    // return {first, last};

    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    int first = -1, last = -1;
    if (!(lb == nums.size() || nums[lb] != target)) {
      first = lb;
      last = ub - 1;
    }
    return {first, last};
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
    vector<int> result = sol.searchRange(nums, target);
    cout << result[0] << " " << result[1] << endl;
  }
  return 0;
}
