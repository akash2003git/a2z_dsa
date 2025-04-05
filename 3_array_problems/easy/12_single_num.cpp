// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int s = 0;
    int n = nums.size();
    for (int num : nums) {
      s ^= num;
    }
    return s;
  }
};

// 2
// 5
// 4 1 2 1 2
// 3
// 7 3 3

// 4
// 7

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
    cout << obj.singleNumber(nums) << endl; // Output single number
  }
  return 0;
}
// { Driver Code Ends
