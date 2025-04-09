#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    // long long t = target; // to avoid runtime error
    // int n = nums.size();
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     for (int k = j + 1; k < n; k++) {
    //       for (int l = k + 1; l < n; l++) {
    //         long long sum = 0;
    //         sum += nums[i];
    //         sum += nums[j];
    //         sum += nums[k];
    //         sum += nums[l];
    //         if (sum == t) {
    //           vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
    //           sort(temp.begin(), temp.end());
    //           st.insert(temp);
    //         }
    //       }
    //     }
    //   }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // int n = nums.size();
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     set<long long> hash;
    //     for (int k = j + 1; k < n; k++) {
    //       long long sum = (long long)nums[i] + nums[j] + nums[k];
    //       long long fourth = (long long)target - sum;
    //       if (hash.find(fourth) != hash.end()) {
    //         vector<int> temp = {nums[i], nums[j], nums[k],
    //                             static_cast<int>(fourth)};
    //         sort(temp.begin(), temp.end());
    //         st.insert(temp);
    //       }
    //       hash.insert(nums[k]);
    //     }
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
      for (int j = i + 1; j < n; j++) {
        if (j > (i + 1) && nums[j] == nums[j - 1])
          continue;
        int k = j + 1;
        int l = n - 1;
        while (k < l) {
          long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
          if (sum < target) {
            k++;
          } else if (sum > target) {
            l--;
          } else {
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
            ans.push_back(temp);
            k++;
            l--;
            while (k < l && nums[k] == nums[k - 1])
              k++;
            while (k < l && nums[l] == nums[l + 1])
              l--;
          }
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
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.fourSum(nums, target);

    for (const auto &quadruplet : result) {
      cout << "[";
      for (int i = 0; i < 4; i++) {
        cout << quadruplet[i] << (i == 3 ? "" : ",");
      }
      cout << "]";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
