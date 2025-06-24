#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";

    for (int i = 0; i < strs[0].length(); i++) {
      char currChar = strs[0][i];
      for (int j = 1; j < strs.size(); j++) {
        if (i == strs[j].length() || currChar != strs[j][i]) {
          return strs[0].substr(0, i);
        }
      }
    }

    return strs[0];
  }
};

// 3
// 3
// flower
// flow
// flight
// 3
// dog
// racecar
// car
// 2
// apple
// apricot

// fl
//
// ap

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    int n;
    cin >> n;
    cin.ignore(); // Consume the newline after reading n

    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, strs[i]); // Read each string, handles spaces if any
    }

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
  }
  return 0;
}
