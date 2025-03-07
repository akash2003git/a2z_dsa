#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isArmstrong(int n) {
    int temp = n;
    int d;
    int sum = 0;
    int count = log10(n) + 1;
    while (n) {
      d = n % 10;
      sum += pow(d, count);
      n = n / 10;
    }
    return (sum == temp);
  }
};

int main() {
  int t; // Number of test cases
  cin >> t;
  while (t--) {
    int n;
    cin >> n; // Read input integer
    Solution obj;
    cout << (obj.isArmstrong(n) ? "true" : "false") << endl;
  }
  return 0;
}
