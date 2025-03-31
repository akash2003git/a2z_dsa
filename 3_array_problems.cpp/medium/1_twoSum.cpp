#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if (i == j)
    //       continue;
    //     if (nums[i] + nums[j] == target)
    //       return {i, j};
    //   }
    // }
    // return {};

    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     if (nums[i] + nums[j] == target)
    //       return {i, j};
    //   }
    // }
    // return {};

    int n = nums.size();
    map<int, int> hash;
    for (int i = 0; i < n; i++) {
      int secondNum = target - nums[i];
      if (hash.find(secondNum) != hash.end()) {
        return {i, hash[secondNum]};
      }
      hash[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  // { Driver Code Starts
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    // { Driver Code Ends

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    // { Driver Code Starts
    if (!result.empty()) {
      cout << result[0] << " " << result[1] << endl;
      cout << "~" << endl;
    } else {
      cout << "No valid pair found" << endl;
      cout << "~" << endl;
    }
    // { Driver Code Ends
  }
  return 0;
}
