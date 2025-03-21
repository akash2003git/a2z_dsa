//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
public:
  // Function to count the number of digits in n that evenly divide n
  int evenlyDivides(int n) {
    // code here
    int d;
    int count = 0;
    int num = n;
    while (n > 0) {
      d = n % 10;
      if (d != 0 && num % d == 0) {
        count++;
      }
      n = n / 10;
    }
    return count;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.evenlyDivides(N) << endl;
    cout << "~" << "\n";
  }
  return 0;
}
// } Driver Code End
