#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // int n = prices.size();
    // int maxProfit = 0;
    // int profit = 0;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     if (prices[i] < prices[j]) {
    //       profit = prices[j] - prices[i];
    //       maxProfit = max(profit, maxProfit);
    //     }
    //   }
    // }
    // return maxProfit;

    int cost = 0, mini = prices[0], maxProfit = 0;
    for (int price : prices) {
      cost = price - mini;
      maxProfit = max(maxProfit, cost);
      mini = min(mini, price);
    }
    return maxProfit;
  }
};

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Number of days
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
      cin >> prices[i]; // Input stock prices
    }

    Solution obj;
    int result = obj.maxProfit(prices);

    cout << result << endl;
    cout << "~" << endl;
  }
  return 0;
}
