#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int noOfSplits(vector<int> &nums, int maxSum) {
    int splitCount = 1;
    long long currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (currSum + nums[i] <= maxSum) {
        currSum += nums[i];
      } else {
        splitCount += 1;
        currSum = nums[i];
      }
    }
    return splitCount;
  }

  int splitArray(vector<int> &nums, int k) {
    int ans = -1;
    if (k > nums.size())
      return ans;
    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int splitCount = noOfSplits(nums, mid);
      if (splitCount <= k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    ans = low;
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }
    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << result << endl;
  }
  return 0;
}
