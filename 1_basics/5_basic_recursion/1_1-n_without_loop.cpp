//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Complete this function
  // void printNos(int n, int cnt = 1) {
  //   // Your code here
  //   if (cnt > n)
  //     return;
  //   cout << cnt << " ";
  //   printNos(n, cnt + 1);
  // }
  void printNos(int N) {
    if (N > 1)
      printNos(N - 1);
    cout << N << ' ';
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
    ob.printNos(N);
    cout << "\n";

    cout << "~"
         << "\n";
  }
  return 0;
}

// } Driver Code Ends
