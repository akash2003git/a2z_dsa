#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
  // int n = a.size();
  // int maxLen = 0;
  // for (int i = 0; i < n; i++) {
  //   int sum = 0;
  //   int len = 0;
  //   for (int j = i; j < n; j++) {
  //     sum += a[j];
  //     len += 1;
  //     if (sum == 0) {
  //       maxLen = max(len, maxLen);
  //     }
  //   }
  // }
  // return maxLen;

  int n = a.size();
  int maxLen = 0;
  int sum = 0;
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum == 0) {
      maxLen = i + 1;
    } else {
      if (mpp.find(sum) != mpp.end()) {
        maxLen = max(maxLen, i - mpp[sum]);
      } else {
        mpp[sum] = i;
      }
    }
  }
  return maxLen;
}

int main() {
  vector<int> a = {9, -3, 3, -1, 6, -5};
  cout << solve(a) << endl;
  vector<int> b = {6, -2, 2, -8, 1, 7, 4, -10};
  cout << solve(b) << endl;
  vector<int> c = {1, 0, -5};
  cout << solve(c) << endl;
  vector<int> d = {1, 3, -5, 6, -2};
  cout << solve(d) << endl;

  return 0;
}
