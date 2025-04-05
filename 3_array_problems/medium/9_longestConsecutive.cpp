#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // if (nums.size() == 0)
    //   return 0;
    // int n = nums.size();
    // int count = 0;
    // int lastSmaller = INT_MIN;
    // int longest = 1;
    // sort(nums.begin(), nums.end());
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] - 1 == lastSmaller) {
    //     lastSmaller = nums[i];
    //     count++;
    //   } else if (nums[i] != lastSmaller) {
    //     lastSmaller = nums[i];
    //     count = 1;
    //   }
    //   longest = max(count, longest);
    // }
    // return longest;

    if (nums.size() == 0)
      return 0;
    int longest = 1;
    unordered_set<int> st(nums.begin(), nums.end());
    int n = st.size();
    for (auto it : st) {
      if (st.find(it - 1) == st.end()) {
        int cnt = 1;
        int x = it;
        while (st.find(x + 1) != st.end()) {
          x += 1;
          cnt += 1;
        }
        longest = max(longest, cnt);
      }
    }
    return longest;
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
    int result = obj.longestConsecutive(nums);

    cout << result << endl;
    cout << "~" << endl;
  }
  return 0;
}
