#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<long long> &arr, int l, int m, int h) {
  vector<long long> temp;
  int left = l;
  int right = m + 1;

  long long cnt = 0;

  while (left <= m && right <= h) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      cnt += m - left + 1;
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= m) {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= h) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = l; i <= h; i++) {
    arr[i] = temp[i - l];
  }

  return cnt;
}

long long mergeSort(vector<long long> &arr, int l, int h) {
  long long cnt = 0;
  if (l >= h)
    return cnt;
  int m = (l + h) / 2;
  cnt += mergeSort(arr, l, m);
  cnt += mergeSort(arr, m + 1, h);
  cnt += merge(arr, l, m, h);
  return cnt;
}

long long getInversions(vector<long long> &arr, int n) {
  return mergeSort(arr, 0, n - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    long long result = getInversions(arr, n);
    cout << result << endl;
  }
  return 0;
}
