#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();

    // vector<int> temp;
    // int count = 0;
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] != 0) {
    //     temp.push_back(nums[i]);
    //   } else {
    //     count++;
    //   }
    // }
    // while (count > 0) {
    //   temp.push_back(0);
    //   count--;
    // }
    // nums = temp;

    int j = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        j = i;
        break;
      }
    }
    if (j == -1)
      return;

    for (int i = j + 1; i < n; i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[j]);
        j++;
      }
    }
  }
};

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
    obj.moveZeroes(nums);

    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
