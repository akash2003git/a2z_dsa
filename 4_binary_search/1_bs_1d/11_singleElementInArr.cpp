#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    else if (nums[0] != nums[1])
      return nums[0];
    else if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];
    int ans = 0;
    int low = 1, high = n - 2;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1])) {
        ans = nums[mid];
        break;
      }
      // Right half
      if (((mid % 2) == 0 && nums[mid] == nums[mid + 1]) or
          ((mid % 2) == 1 && nums[mid] == nums[mid - 1])) {
        low = mid + 1;
      }
      // Left half
      else {
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
    int result = sol.singleNonDuplicate(nums);
    cout << result << endl;
  }
  return 0;
}
