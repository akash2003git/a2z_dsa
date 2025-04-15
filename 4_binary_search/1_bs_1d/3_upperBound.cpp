#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> &arr, int n, int x) {
  int l = 0;
  int h = arr.size() - 1;
  int m = l + (h - l) / 2;
  int ans = arr.size();
  while (l <= h) {
    if (arr[m] > x) {
      ans = m;
      h = m - 1;
    } else {
      l = m + 1;
    }
    m = l + (h - l) / 2;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int result = upperBound(arr, n, x);
    cout << result << endl;
  }
  return 0;
}
