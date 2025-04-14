#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int bs(vector<int> &nums, int target, int low, int high) {
    if (low > high)
      return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      return bs(nums, target, low, mid - 1);
    } else {
      return bs(nums, target, mid + 1, high);
    }
  }

  int search(vector<int> &nums, int target) {
    // int left = 0;
    // int right = nums.size() - 1;
    // while (left <= right) {
    //   int mid = left + (right - left) / 2; // Prevent potential overflow
    //
    //   if (nums[mid] == target) {
    //     return mid;
    //   } else if (nums[mid] < target) {
    //     left = mid + 1;
    //   } else {
    //     right = mid - 1;
    //   }
    // }
    // return -1; // Target not found

    return bs(nums, target, 0, nums.size() - 1);
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
    int result = sol.search(nums, target);
    cout << result << endl;
  }
  return 0;
}
