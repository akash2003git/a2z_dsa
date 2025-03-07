#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    long long rev = 0, temp = x;
    int d;
    while (x) {
      d = x % 10;
      x = x / 10;
      rev = (rev * 10) + d;
    }
    return (rev == temp);
  }
};

// 4
// 121
// -121
// 10
// 0

int main() {
  int t; // Number of test cases
  cin >> t;
  while (t--) {
    int x;
    cin >> x; // Read input integer
    Solution obj;
    cout << (obj.isPalindrome(x) ? "true" : "false") << endl;
  }
  return 0;
}
