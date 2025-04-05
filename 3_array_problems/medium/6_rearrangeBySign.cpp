#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    // int n = nums.size();
    // int i = 0, j = 0;
    // vector<int> result;
    // while (i < n || j < n) {
    //   while (i < n) {
    //     if (nums[i] > 0) {
    //       result.push_back(nums[i]);
    //       i++;
    //       break;
    //     }
    //     i++;
    //   }
    //   while (j < n) {
    //     if (nums[j] < 0) {
    //       result.push_back(nums[j]);
    //       j++;
    //       break;
    //     }
    //     j++;
    //   }
    // }
    // return result;

    int n = nums.size();
    vector<int> result(n);
    int pos = 0, neg = 1;

    for (int num : nums) {
      if (num > 0) {
        result[pos] = num;
        pos += 2;
      } else {
        result[neg] = num;
        neg += 2;
      }
    }
    return result;
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
    vector<int> result = obj.rearrangeArray(nums);

    for (int i = 0; i < n; i++) {
      cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl << "~" << endl;
  }
  return 0;
}
