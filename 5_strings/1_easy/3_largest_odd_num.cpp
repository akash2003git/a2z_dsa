#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
      if ((num[i] - '0') % 2 != 0) {
        return num.substr(0, i + 1);
      }
    }
    return "";
  }
};

// 3
// 52
// 4206
// 35427

// 5
//
// 35427

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string num;
    getline(cin, num); // Read the entire line for the string
    Solution sol;
    cout << sol.largestOddNumber(num) << endl;
  }
  return 0;
}
