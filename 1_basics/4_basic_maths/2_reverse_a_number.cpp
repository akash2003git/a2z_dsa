#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long rev = 0;
    int d;
    while (x != 0) {
      d = x % 10;
      x = x / 10;
      rev = (rev * 10) + d;
    }
    return (rev > INT_MAX || rev < INT_MIN) ? 0 : rev;
  }
};

// 3
// 123
// -123
// 120

// Time Complexity: O(log(x)). There are roughly log10(x) digits in x.
// Space Complexity: O(1).

int main() {
  int t; // Number of test cases
  cin >> t;
  while (t--) {
    int x;
    cin >> x; // Read input integer
    Solution obj;
    cout << obj.reverse(x) << endl; // Call function and print result
  }
  return 0;
}
