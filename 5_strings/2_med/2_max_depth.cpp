#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int n = s.size();
    int balance = 0;
    int maxBalance = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        balance++;
        maxBalance = max(balance, maxBalance);
      } else if (s[i] == ')') {
        balance--;
      }
    }
    return maxBalance;
  }
};

// 3
// (1+(2*3)+((8)/4))+1
// (1)+((2))+(((3)))
// 1+(2*3)/(2-1)

// 3
// 3
// 1

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.maxDepth(s) << endl;
  }
  return 0;
}
