//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
public:
  vector<long long> factorialNumbers(long long n) {
    // Write Your Code here
    vector<long long> facts;
    long long fact = 1, i = 1;
    while (fact <= n) {
      facts.push_back(fact);
      i++;
      fact *= i;
    }
    return facts;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    Solution ob;
    vector<long long> ans = ob.factorialNumbers(N);
    for (auto num : ans) {
      cout << num << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
