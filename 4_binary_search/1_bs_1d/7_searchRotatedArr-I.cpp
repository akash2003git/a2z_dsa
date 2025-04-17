#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // Left Sorted
      if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target <= nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      // Right Sorted
      if (nums[mid] <= nums[high]) {
        if (nums[mid] <= target && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
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
