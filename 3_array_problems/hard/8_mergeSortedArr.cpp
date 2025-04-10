#include <bits/stdc++.h>

using namespace std;

void swapIfGreater(vector<long long> &arr1, vector<long long> &arr2, int ind1,
                   int ind2) {
  if (arr1[ind1] > arr2[ind2]) {
    swap(arr1[ind1], arr2[ind2]);
  }
}

void mergeArrays(vector<long long> &arr1, vector<long long> &arr2, int n,
                 int m) {
  // int i = n - 1;
  // int j = 0;
  // while (i >= 0 && j < m) {
  //   if (arr1[i] > arr2[j]) {
  //     swap(arr1[i], arr2[j]);
  //     i--;
  //     j++;
  //   } else {
  //     break;
  //   }
  // }
  // sort(arr1.begin(), arr1.end());
  // sort(arr2.begin(), arr2.end());

  int len = n + m;
  int gap = (len / 2) + (len % 2);
  while (gap > 0) {
    int left = 0;
    int right = left + gap;
    while (right < len) {
      if (left < n && right >= n) {
        swapIfGreater(arr1, arr2, left, right - n);
      } else if (left >= n) {
        swapIfGreater(arr2, arr2, left - n, right - n);
      } else {
        swapIfGreater(arr1, arr1, left, right);
      }
      left++;
      right++;
    }
    if (gap == 1)
      break;
    gap = (gap / 2) + (gap % 2);
  }
}

// 2
// 4 5
// 1 3 5 7
// 0 2 6 8 9
// 2 2
// 10 12
// 5 18
//
// 0 1 2 3 5 6 7 8 9
// 5 10 12 18

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> arr1(n);
    vector<long long> arr2(m);
    for (int i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> arr2[i];
    }
    mergeArrays(arr1, arr2, n, m);
    for (int i = 0; i < n; i++) {
      cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++) {
      cout << arr2[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
