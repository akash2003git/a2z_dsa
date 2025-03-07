//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
public:
  bool isPrime(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        count++;
        if (n / i != i) {
          count++;
        }
      }
    }
    return (count == 2);
  }
  bool isPrimeOptimal(int n) {
    if (n < 2)
      return false; // 0 and 1 are not prime numbers
    if (n == 2 || n == 3)
      return true; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0)
      return false; // Handle even numbers and multiples of 3

    for (int i = 5; i * i <= n; i += 6) { // Start from 5 and check `6k ± 1`
      if (n % i == 0 || n % (i + 2) == 0) // Check both `6k - 1` and `6k + 1`
        return false;
    }
    return true;
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
    bool ans = ob.isPrimeOptimal(N);
    cout << (ans ? "true" : "false") << endl;

    cout << "~"
         << "\n";
  }
  return 0;
}
// } Driver Code Ends
