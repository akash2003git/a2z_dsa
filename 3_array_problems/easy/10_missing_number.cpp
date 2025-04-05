// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    // int n = nums.size();
    // int missingNumber = -1;
    // sort(nums.begin(), nums.end());
    // if (n != nums[n - 1]) {
    //   return n;
    // }
    // for (int i = 0; i < n; i++) {
    //   if (i != nums[i]) {
    //     missingNumber = i;
    //     break;
    //   }
    // }
    // return missingNumber;

    // int n = nums.size();
    // int sum1 = (n * (n + 1)) / 2;
    // int sum2 = accumulate(nums.begin(), nums.end(), 0);
    // return sum1 - sum2;

    int xor1 = 0, xor2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      xor2 ^= nums[i];
      xor1 ^= i + 1;
    }
    return xor1 ^ xor2;
  }
};

// 3
// 5
// 0 1 3 4
// 4
// 1 2 3
// 5
// 0 1 2 3
//
//
// 2
// 0
// 4

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Input the size of array (n-1 elements expected)
    vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> nums[i]; // Input array elements
    }
    Solution obj;
    cout << obj.missingNumber(nums) << endl; // Output missing number
  }
  return 0;
}
// { Driver Code Ends
