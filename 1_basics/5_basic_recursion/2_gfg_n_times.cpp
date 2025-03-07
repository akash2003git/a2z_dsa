//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void printGfg(int N, int cnt = 1) {
    // Code here

    // if (cnt > N)
    //   return;
    // cout << "GFG ";
    // printGfg(N, cnt + 1);

    if (N > 1)
      printGfg(N - 1);
    cout << "GFG ";
  }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
  int T;

  // taking testcases
  cin >> T;

  while (T--) {
    int N;

    // input N
    cin >> N;
    Solution ob;
    // calling printNos() function
    ob.printGfg(N);
    cout << "\n";

    cout << "~" << "\n";
  }
  return 0;
}

// } Driver Code Ends
