#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // int n = nums.size();
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     for (int k = j + 1; k < n; k++) {
    //       if (nums[i] + nums[j] + nums[k] == 0) {
    //         vector<int> temp = {nums[i], nums[j], nums[k]};
    //         sort(temp.begin(), temp.end());
    //         st.insert(temp);
    //       }
    //     }
    //   }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // int n = nums.size();
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++) {
    //   set<int> hash;
    //   for (int j = i + 1; j < n; j++) {
    //     int third = -1 * (nums[i] + nums[j]);
    //     if (hash.find(third) != hash.end()) {
    //       vector<int> temp = {nums[i], nums[j], third};
    //       sort(temp.begin(), temp.end());
    //       st.insert(temp);
    //     }
    //     hash.insert(nums[j]);
    //   }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          ans.push_back(temp);
          j++;
          k--;
          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }
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
    vector<vector<int>> result = obj.threeSum(nums);

    for (const auto &triplet : result) {
      cout << "[";
      for (int i = 0; i < 3; i++) {
        cout << triplet[i] << (i == 2 ? "" : ",");
      }
      cout << "]";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
