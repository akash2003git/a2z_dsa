#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    // int n = nums.size();
    // vector<int> ans;
    // map<int, int> mpp;
    // for (int i = 0; i < n; i++) {
    //   mpp[nums[i]]++;
    // }
    // for (auto it : mpp) {
    //   if (it.second > n / 3) {
    //     ans.push_back(it.first);
    //   }
    // }
    // return ans;

    // int n = nums.size();
    // vector<int> ans;
    // map<int, int> mpp;
    // int min = (n / 3) + 1;
    // for (int num : nums) {
    //   mpp[num]++;
    //   if (mpp[num] == min)
    //     ans.push_back(num);
    //   if (ans.size() == 2)
    //     break;
    // }
    // return ans;

    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (cnt1 == 0 && nums[i] != el2) {
        cnt1 = 1;
        el1 = nums[i];
      } else if (cnt2 == 0 && nums[i] != el1) {
        cnt2 = 1;
        el2 = nums[i];
      } else if (el1 == nums[i]) {
        cnt1 += 1;
      } else if (el2 == nums[i]) {
        cnt2 += 1;
      } else {
        cnt1 -= 1;
        cnt2 -= 1;
      }
    }

    int freq1 = 0, freq2 = 0;
    int min = (n / 3) + 1;
    for (int num : nums) {
      if (el1 == num)
        freq1++;
      if (el2 == num)
        freq2++;
    }
    if (freq1 >= min && el1 != el2) {
      ans.push_back(el1);
    }
    if (freq2 >= min && el1 != el2) {
      ans.push_back(el2);
    }

    return ans;
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

    Solution obj;
    vector<int> result = obj.majorityElement(nums);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
