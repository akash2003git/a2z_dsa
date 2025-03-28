// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();
    int maxCons = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        count++;
        maxCons = max(maxCons, count);
      } else {
        count = 0;
      }
    }
    return maxCons;
  }
};

// 4
// 6
// 1 1 0 1 1 1
// 5
// 1 0 1 1 0
// 10
// 0 1 1 1 1 0 1 1 0 1
// 11
// 1 1 0 1 1 1 1 0 1 1 1 0

// 3
// 2
// 4
// 4

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Size of the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i]; // Input array elements
    }
    Solution obj;
    cout << obj.findMaxConsecutiveOnes(nums)
         << endl; // Output max consecutive ones
  }
  return 0;
}
// { Driver Code Ends
