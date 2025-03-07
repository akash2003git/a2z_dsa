//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> lcmAndGcd(int a, int b) {
    // code here
    vector<int> lg;
    int lcm, gcd;
    int n1 = a, n2 = b;
    while (a > 0 && b > 0) {
      if (a > b)
        a = a % b;
      else
        b = b % a;
    }
    if (a == 0)
      gcd = b;
    else
      gcd = a;
    lcm = (n1 * n2) / gcd;
    lg.push_back(lcm);
    lg.push_back(gcd);
    return lg;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int A, B;

    cin >> A >> B;

    Solution ob;
    vector<int> ans = ob.lcmAndGcd(A, B);
    cout << ans[0] << " " << ans[1] << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
