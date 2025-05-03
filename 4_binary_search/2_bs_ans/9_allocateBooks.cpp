#include <bits/stdc++.h>

using namespace std;

int noOfStudents(vector<int> arr, int maxPages) {
  int stu = 1, noOfPages = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (noOfPages + arr[i] <= maxPages) {
      noOfPages += arr[i];
    } else {
      stu += 1;
      noOfPages = arr[i];
    }
  }
  return stu;
}

int findPages(vector<int> &arr, int n, int m) {
  int ans = -1;
  if (n < m)
    return ans;
  int low = *max_element(arr.begin(), arr.end());
  long long high = accumulate(arr.begin(), arr.end(), 0);
  // for (int i = low; i <= high; i++) {
  //   int students = noOfStudents(arr, i);
  //   if (students == m) {
  //     ans = i;
  //     return ans;
  //   }
  // }
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int students = noOfStudents(arr, mid);
    if (students <= m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  ans = low;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << findPages(arr, n, m) << endl;
  }
  return 0;
}
