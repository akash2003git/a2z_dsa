#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // int n = intervals.size();
    // vector<vector<int>> ans;
    // sort(intervals.begin(), intervals.end());
    // for (int i = 0; i < n; i++) {
    //   int start = intervals[i][0];
    //   int end = intervals[i][1];
    //   if (!ans.empty() && end <= ans.back()[1]) {
    //     continue;
    //   }
    //   for (int j = i + 1; j < n; j++) {
    //     if (intervals[j][0] <= end) {
    //       end = max(end, intervals[j][1]);
    //     } else {
    //       break;
    //     }
    //   }
    //   ans.push_back({start, end});
    // }
    // return ans;

    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++) {
      if (ans.empty() || ans.back()[1] < intervals[i][0]) {
        ans.push_back(intervals[i]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
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
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;
    vector<vector<int>> merged = obj.merge(intervals);

    for (const auto &interval : merged) {
      cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
  }
  return 0;
}
