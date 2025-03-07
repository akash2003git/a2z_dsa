//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {}
};

// 3
// 3 5
// 1 2 4
// 4 5
// 1 4 8 13
// 3 2
// 3 9 6

// 3
// ~
// 2
// ~
// 1
// ~

//{ Driver Code Starts.
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

    Solution ob;
    int ans = ob.maxFrequency(nums, k);
    cout << ans << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
