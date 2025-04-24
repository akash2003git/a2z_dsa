#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &bloomDay, int day, int m, int k) {
    int noOfBouq = 0, flowerCount = 0;
    for (int bloom : bloomDay) {
      if (bloom <= day) {
        flowerCount += 1;
      } else {
        noOfBouq += flowerCount / k;
        flowerCount = 0;
      }
    }
    noOfBouq += flowerCount / k;
    if (noOfBouq >= m)
      return true;
    return false;
  }

  int minDays(vector<int> &bloomDay, int m, int k) {
    int ans = -1;
    if (bloomDay.size() < m * k)
      return ans;
    int low = 1;
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (isPossible(bloomDay, mid, m, k)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++) {
      cin >> bloomDay[i];
    }

    Solution sol;
    int result = sol.minDays(bloomDay, m, k);
    cout << result << endl;
  }
  return 0;
}
