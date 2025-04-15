#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
  int low = 0, high = n - 1;
  int floor = -1, ceil = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == x) {
      return {x, x};
    } else if (a[mid] < x) {
      low = mid + 1;
      floor = mid;
    } else {
      high = mid - 1;
      ceil = mid;
    }
  }

  if (floor == -1) {
    return {-1, a[ceil]};
  } else if (ceil == -1) {
    return {a[floor], -1};
  }

  return {a[floor], a[ceil]};
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    pair<int, int> result = getFloorAndCeil(a, n, x);
    cout << result.first << " " << result.second << endl;
  }
  return 0;
}
