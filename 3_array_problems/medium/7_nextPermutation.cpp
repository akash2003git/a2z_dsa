#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int idx = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      return reverse(nums.begin(), nums.end());
    }
    for (int i = n - 1; i > idx; i--) {
      if (nums[i] > nums[idx]) {
        swap(nums[i], nums[idx]);
        break;
      }
    }
    return reverse(nums.begin() + idx + 1, nums.end());
  }
};

// 3
// 3
// 1 2 3
// 3
// 3 2 1
// 4
// 1 3 2 4

// 1 3 2
// ~
// 1 2 3
// ~
// 1 3 4 2
// ~

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution obj;
    obj.nextPermutation(nums);

    for (int i = 0; i < n; i++) {
      cout << nums[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl << "~" << endl;
  }
  return 0;
}
