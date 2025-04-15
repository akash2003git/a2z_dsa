#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr, int n, int x) {
  // if (x == 0)
  //   return 0;
  // for (int i = 0; i < n; i++) {
  //   if (arr[i] >= x) {
  //     return i;
  //   }
  // }
  // return n;

  int l = 0;
  int h = n - 1;
  int m = l + (h - l) / 2;
  int ans = n;
  while (l <= h) {
    if (arr[m] >= x) {
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

    int result = lowerBound(arr, n, x);
    cout << result << endl;
  }
  return 0;
}
