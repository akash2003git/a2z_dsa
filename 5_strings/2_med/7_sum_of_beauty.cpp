#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int beautySum(string s) {
    int n = s.length();
    int sum = 0;

    for (int i = 0; i < n; i++) {
      unordered_map<char, int> mpp;
      // a vector can also be used here
      for (int j = i; j < n; j++) {
        mpp[s[j]]++;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (auto const &[key, val] : mpp) {
          mini = min(mini, val);
          maxi = max(maxi, val);
        }
        sum += (maxi - mini);
      }
    }

    return sum;
  }
};

// Time Complexity: O(26 * n^2);
// Space Complexity: O(26);

// 2
// aabcb
// aabcbaa

// 5
// 17

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.beautySum(s) << endl;
  }
  return 0;
}
