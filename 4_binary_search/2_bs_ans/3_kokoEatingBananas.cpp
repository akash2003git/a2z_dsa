#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long calTotalHours(vector<int> &piles, int k) {
    long long totalHours = 0;
    for (int i = 0; i < piles.size(); ++i) {
      totalHours += ceil((double)piles[i] / (double)k);
    }
    return totalHours;
  }

  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    long long high = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      long long totalHours = calTotalHours(piles, mid);
      if (totalHours <= h) {
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
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
      cin >> piles[i];
    }

    Solution sol;
    int result = sol.minEatingSpeed(piles, h);
    cout << result << endl;
  }
  return 0;
}
