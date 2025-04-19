#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 0;
    if (nums[0] > nums[1]) {
      return 0;
    }
    if (nums[n - 1] > nums[n - 2]) {
      return n - 1;
    }
    int low = 1;
    int high = n - 2;
    int ans = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((nums[mid] > nums[mid - 1]) && nums[mid] > nums[mid + 1]) {
        ans = mid;
        break;
      } else if (nums[mid] > nums[mid - 1]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
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
    int peakIndex = sol.findPeakElement(nums);
    cout << peakIndex << endl;
  }
  return 0;
}
