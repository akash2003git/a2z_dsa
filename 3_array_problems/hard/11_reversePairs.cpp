#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int merge(vector<int> &arr, int l, int m, int h) {
    vector<int> temp;
    int left = l;
    int right = m + 1;

    int cnt = 0;
    int j = m + 1;
    for (int i = l; i <= m; i++) {
      while (j <= h && (long long)arr[i] > 2LL * (long long)arr[j]) {
        j++;
      }
      cnt += (j - (m + 1));
    }

    while (left <= m && right <= h) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
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
  int mergeSort(vector<int> &arr, int l, int h) {
    // code here
    int cnt = 0;
    if (l >= h)
      return cnt;
    int m = (l + h) / 2;
    cnt += mergeSort(arr, l, m);
    cnt += mergeSort(arr, m + 1, h);
    cnt += merge(arr, l, m, h);
    return cnt;
  }

  int reversePairs(vector<int> &nums) {
    // int n = nums.size();
    // int cnt = 0;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     long long a = nums[i];
    //     long long b = 2LL * (long long)nums[j];
    //     if (a > b) {
    //       cnt++;
    //     }
    //   }
    // }

    return mergeSort(nums, 0, nums.size() - 1);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution sol;
    int result = sol.reversePairs(nums);
    cout << result << endl;
  }
  return 0;
}
