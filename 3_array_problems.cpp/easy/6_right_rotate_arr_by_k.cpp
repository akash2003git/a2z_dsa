//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;

    // vector<int> temp;
    // for (int i = n - k; i < n; i++) {
    //   temp.push_back(nums[i]);
    // }
    // for (int i = 0; i < n - k; i++) {
    //   temp.push_back(nums[i]);
    // }
    // nums = temp;

    reverse(nums.begin(), nums.begin() + (n - k));
    reverse(nums.begin() + (n - k), nums.end());
    reverse(nums.begin(), nums.end());
  }
};

// 2
// 7 3
// 1 2 3 4 5 6 7
// 6 2
// 10 20 30 40 50 60

// 5 6 7 1 2 3 4
// 50 60 10 20 30 40

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution obj;
    obj.rotate(nums, k);

    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
//} Driver Code Ends
