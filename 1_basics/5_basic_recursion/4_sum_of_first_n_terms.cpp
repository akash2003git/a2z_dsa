//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
public:
  int sumOfSeries(int n, int sum = 0) {
    // // code here
    // if (n < 1) {
    //   return sum;
    // }
    // return sumOfSeries(n - 1, sum + n * n * n);
    if (n == 0) {
      return n;
    }
    return (n * n * n + sumOfSeries(n - 1));
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
    cout << ob.sumOfSeries(N) << "\n";

    cout << "~"
         << "\n";
  }
}
// } Driver Code Ends
