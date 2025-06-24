#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    string result;
    int balance = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        if (balance > 0) {
          result += s[i];
        }
        balance++;
      } else {
        balance--;
        if (balance > 0) {
          result += s[i];
        }
      }
    }
    return result;
  }
};

// 3
// (()())(())
// (()())(())(()(()))
// ()()

// ()()()
// ()()()()(())
//

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.removeOuterParentheses(s) << endl;
  }
  return 0;
}
