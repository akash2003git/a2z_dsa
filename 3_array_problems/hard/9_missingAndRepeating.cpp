#include <bits/stdc++.h>

using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
  // map<int, int> mpp;
  // pair<int, int> ans;
  // for (int i = 1; i <= n; i++) {
  //   mpp[i] = 0;
  // }
  // for (int num : arr) {
  //   mpp[num]++;
  // }
  // for (auto it : mpp) {
  //   if (it.second == 2) {
  //     ans.second = it.first;
  //   } else if (it.second == 0) {
  //     ans.first = it.first;
  //   }
  // }
  // return ans;

  // vector<int> hash(n + 1, 0);
  // pair<int, int> ans = {-1, -1};
  // for (int i = 0; i < n; i++) {
  //   hash[arr[i]]++;
  // }
  // for (int i = 1; i <= n; i++) {
  //   if (hash[i] == 0) {
  //     ans.first = i;
  //   } else if (hash[i] == 2) {
  //     ans.second = i;
  //   }
  //   if (ans.first != -1 and ans.second != -1)
  //     break;
  // }
  // return ans;

  // long long S1N = (n * (n + 1)) / 2;
  // long long S2N = (n * (n + 1) * ((2 * n) + 1)) / 6;
  // long long S1 = 0, S2 = 0;
  // for (int i = 0; i < n; i++) {
  //   S1 += arr[i];
  //   S2 += (long long)arr[i] * (long long)arr[i];
  // }
  // long long val1 = S1 - S1N; // x - y
  // long long val2 = S2 - S2N;
  // val2 = val2 / val1; // x + y
  // long long x = (val1 + val2) / 2;
  // long long y = x - val1;
  // return {(int)x, (int)y};

  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= arr[i];
    xr ^= (i + 1);
  }
  // int bitNo = 0;
  // while (1) {
  //   if ((xr & (1 << bitNo)) != 0) {
  //     break;
  //   }
  //   bitNo++;
  // }
  // int number = 1 << bitNo
  int number = xr & ~(xr - 1); // shortcut to get the number

  int zero = 0;
  int one = 0;
  for (int i = 0; i < n; i++) {
    if ((arr[i] & number)) {
      one ^= arr[i];
    } else {
      zero ^= arr[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    if ((i & number)) {
      one ^= i;
    } else {
      zero ^= i;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == zero)
      cnt++;
  }
  if (cnt == 2)
    return {zero, one};
  return {one, zero};
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    pair<int, int> result = missingAndRepeating(arr, n);
    cout << result.first << " " << result.second << endl;
  }
  return 0;
}
