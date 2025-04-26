#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool canShip(vector<int> &weights, int days, int capacity) {
    int noOfDays = 1; // Start with one day
    int currentWeight = 0;
    for (int weight : weights) {
      if (currentWeight + weight > capacity) {
        noOfDays++;             // Move to the next day
        currentWeight = weight; // Start the new day with the current item
      } else {
        currentWeight += weight; // Add to the current day's load
      }
    }
    return noOfDays <= days;
  }

  int shipWithinDays(vector<int> &weights, int days) {
    int ans = -1;
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (canShip(weights, days, mid)) {
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
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
      cin >> weights[i];
    }

    Solution sol;
    int result = sol.shipWithinDays(weights, days);
    cout << result << endl;
    cout << "~" << endl;
  }
  return 0;
}
