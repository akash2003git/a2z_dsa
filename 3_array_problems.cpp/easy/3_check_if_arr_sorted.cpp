//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isSorted(int n, vector<int> &arr) {
    for (int i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) {
        return false;
      }
    }
    return true;
  }
};

// 5
// 4
// 123 4 1 45
// 4
// 2 2 2 2
// 5
// 1 2 3 4 5
// 4
// 23 45 124 2355
// 6
// 9 8 11 11 2 1

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution obj;
    cout << (obj.isSorted(n, arr) ? "true" : "false") << endl;
  }
  return 0;
}
//} Driver Code Ends
