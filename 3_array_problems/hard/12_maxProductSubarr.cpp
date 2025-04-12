#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    // int n = nums.size();
    // if (n == 1)
    //   return nums[0];
    // int max_product = 0;
    // for (int i = 0; i < n; i++) {
    //   int product = 1;
    //   for (int j = i; j < n; j++) {
    //     product *= nums[j];
    //     max_product = max(product, max_product);
    //   }
    // }
    // return max_product;

    int n = nums.size();
    int maxi = INT_MIN;
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++) {
      if (pre == 0)
        pre = 1;
      if (suf == 0)
        suf = 1;
      pre *= nums[i];
      suf *= nums[n - 1 - i];
      maxi = max(maxi, max(pre, suf));
    }
    return maxi;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxProduct(nums);
    cout << result << endl;
  }
  return 0;
}
