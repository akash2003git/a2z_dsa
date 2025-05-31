#include <bits/stdc++.h>
using namespace std;

// Do not use the stdc++ sort function.
class Solution {
public:
  void sortColors(vector<int> &nums) {
    // int n = nums.size();
    // int hash[] = {0, 0, 0};
    // for (int i = 0; i < n; i++) {
    //   hash[nums[i]]++;
    // }
    // nums = {};
    // for (int i = 0; i < 3; i++) {
    //   while (hash[i] > 0) {
    //     nums.push_back(i);
    //     hash[i]--;
    //   }
    // }

    // int n = nums.size();
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;
    // for (int num : nums) {
    //   if (num == 0)
    //     count0++;
    //   if (num == 1)
    //     count1++;
    //   if (num == 2)
    //     count2++;
    // }
    // for (int i = 0; i < count0; i++) {
    //   nums[i] = 0;
    // }
    // for (int i = count0; i < count0 + count1; i++) {
    //   nums[i] = 1;
    // }
    // for (int i = count0 + count1; i < n; i++) {
    //   nums[i] = 2;
    // }

    int n = nums.size();
    int low = 0, mid = 0;
    int high = n - 1;
    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};

// 1
// 6
// 2 0 2 1 1 0

// 0 0 1 1 2 2

int main() {
  // { Driver Code Starts
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    // { Driver Code Ends

    Solution obj;
    obj.sortColors(nums);

    // { Driver Code Starts
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
    // { Driver Code Ends
  }
  return 0;
}
