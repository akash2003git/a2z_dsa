#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2; // +1 to take care of even
    int n = n1 + n2;
    while (low <= high) {
      int mid1 = low + (high - low) / 2;
      int mid2 = left - mid1;
      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;
      if (mid1 < n1)
        r1 = nums1[mid1];
      if (mid2 < n2)
        r2 = nums2[mid2];
      if (mid1 - 1 >= 0)
        l1 = nums1[mid1 - 1];
      if (mid2 - 1 >= 0)
        l2 = nums2[mid2 - 1];
      if (l1 <= r2 && l2 <= r1) {
        if (n % 2 == 1)
          return max(l1, l2);
        return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
      } else if (l1 > r2) {
        high = mid1 - 1;
      } else {
        low = mid1 + 1;
      }
    }
    return 0.0;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; ++i) {
      cin >> nums1[i];
    }
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; ++i) {
      cin >> nums2[i];
    }
    Solution sol;
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(6) << result << endl;
  }
  return 0;
}
