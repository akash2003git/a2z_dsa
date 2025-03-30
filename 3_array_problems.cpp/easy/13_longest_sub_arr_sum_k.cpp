// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarrayWithSumK(vector<int> &nums, long long k) {
    // int n = nums.size();
    // int l = 0;
    // long long s = 0;
    // for (int i = 0; i < n; i++) {
    //   s = 0;
    //   for (int j = i; j < n; j++) {
    //     s += nums[j];
    //     if (s == k) {
    //       l = max(l, j - i + 1);
    //     }
    //   }
    // }
    // return l;

    // this solution is optimal for negative + positive
    // int n = nums.size();
    // map<long long, int> preSum;
    // long long sum = 0;
    // int maxLen = 0;
    // for (int i = 0; i < n; i++) {
    //   sum += nums[i];
    //   if (sum == k) {
    //     maxLen = max(maxLen, i + 1);
    //   }
    //   int rem = sum - k;
    //   if (preSum.find(rem) != preSum.end()) { // check if rem exists
    //     // preSum.end() is a special iterator which indicated "not found"
    //     // preSum.find() returns preSum.end() when an element is not found
    //     int len = i - preSum[rem];
    //     maxLen = max(maxLen, len);
    //   }
    //   if (preSum.find(sum) == preSum.end()) {
    //     // only map the sum if it is NOT present in the map already
    //     preSum[sum] = i;
    //   }
    // }
    // return maxLen;

    int n = nums.size();
    int left = 0, right = 0;
    long long sum = nums[0];
    int maxLen = 0;
    while (right < n) {
      while (left <= right && sum > k) {
        sum -= nums[left];
        left++;
      }
      if (sum == k) {
        maxLen = max(maxLen, right - left + 1);
      }
      right++;
      if (right < n)
        sum += nums[right];
    }
    return maxLen;
  }
};

// 5
// 5 5
// 1 2 3 2 1
// 6 10
// 1 2 3 4 5 6
// 5 2
// 2 2 4 1 2
// 7 3
// 1 2 3 1 1 1 1
// 4 2
// 1 2 1 3
//
// 2
// 4
// 1
// 3
// 1

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    Solution obj;
    cout << obj.longestSubarrayWithSumK(nums, k) << endl;
  }
  return 0;
}
// { Driver Code Ends
