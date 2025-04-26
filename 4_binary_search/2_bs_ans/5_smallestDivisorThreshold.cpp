#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int sumOfDiv(vector<int> &nums, int divisor) {
    int sum = 0;
    for (int num : nums) {
      sum += ceil((double)num / (double)divisor);
    }
    return sum;
  }
  int smallestDivisor(vector<int> &nums, int threshold) {
    int ans = -1;
    int low = 1, high = *max_element(nums.begin(), nums.end());
    // for (int i = 1; i <= maxi; i++) {
    //   if (sumOfDiv(nums, i) <= threshold) {
    //     ans = i;
    //     break;
    //   }
    // }
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (sumOfDiv(nums, mid) <= threshold) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, threshold;
    cin >> n >> threshold;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution sol;
    int result = sol.smallestDivisor(nums, threshold);
    cout << result << endl;
    cout << "~" << endl;
  }
  return 0;
}
