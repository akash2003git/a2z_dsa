#include <bits/stdc++.h>

using namespace std;

int countSubarraysWithGivenXor(vector<int> &arr, int k) {
  // int n = arr.size();
  // int count = 0;
  // for (int i = 0; i < n; i++) {
  //   int x = 0;
  //   for (int j = i; j < n; j++) {
  //     x ^= arr[j];
  //     if (x == k) {
  //       count++;
  //     }
  //   }
  // }
  // return count;

  // Imp: A^B = C ⟹ A^C = B
  int n = arr.size();
  int xR = 0;
  int cnt = 0;
  unordered_map<int, int> mpp;
  mpp[xR]++; //{0, 1}
  for (int i = 0; i < n; i++) {
    xR ^= arr[i];
    int x = xR ^ k;
    cnt += mpp[x];
    mpp[xR]++;
  }
  return cnt;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int result = countSubarraysWithGivenXor(arr, k);
    cout << result << endl << "~" << endl;
  }
  return 0;
}
