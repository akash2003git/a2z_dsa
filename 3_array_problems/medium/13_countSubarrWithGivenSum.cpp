#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    // int n = nums.size();
    // int cnt = 0;
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //   sum = 0;
    //   for (int j = i; j < n; j++) {
    //     sum += nums[j];
    //     if (sum == k) {
    //       cnt += 1;
    //     }
    //   }
    // }
    // return cnt;

    int preSum = 0, cnt = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (int num : nums) {
      preSum += num;
      int remove = preSum - k;
      cnt += mpp[remove];
      mpp[preSum] += 1;
    }
    return cnt;
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution obj;
    int result = obj.subarraySum(nums, k);

    cout << result << endl;
    cout << "~" << endl;
  }
  return 0;
}
