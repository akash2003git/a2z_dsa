//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // int maxSum = INT_MIN;
    // int n = nums.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i; j < n; j++) {
    //     sum = 0;
    //     for (int k = i; k <= j; k++) {
    //       sum += nums[k];
    //     }
    //     maxSum = max(sum, maxSum);
    //   }
    // }
    // return maxSum;

    // int maxSum = INT_MIN;
    // int n = nums.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //   sum = 0;
    //   for (int j = i; j < n; j++) {
    //     sum += nums[j];
    //     maxSum = max(sum, maxSum);
    //   }
    // }
    // return maxSum;

    // long long sum = 0, maxSum = LONG_MIN;
    // for (int num : nums) {
    //   sum += num;
    //   maxSum = max(sum, maxSum);
    //   if (sum < 0)
    //     sum = 0;
    // }
    // return maxSum;

    // If we want the array also
    long long sum = 0, maxSum = LONG_MIN;
    int start = 0, ansStart = 0, ansEnd = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (sum == 0)
        start = i;
      sum += nums[i];
      if (sum > maxSum) {
        maxSum = sum;
        ansStart = start;
        ansEnd = i;
      }
      if (sum < 0) {
        sum = 0;
      }
    }
    return maxSum;
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxSubArray(nums) << endl;
  }
  return 0;
}
//{ Driver Code Ends
