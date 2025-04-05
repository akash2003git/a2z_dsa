//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<int, int> getSecondOrderElements(int n, vector<int> &a) {
    int large = INT_MIN;
    int small = INT_MAX;
    int slarge = INT_MAX;
    int ssmall = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (a[i] > large) {
        slarge = large;
        large = a[i];
      } else if (a[i] > slarge && a[i] != large) {
        slarge = a[i];
      }
      if (a[i] < small) {
        ssmall = small;
        small = a[i];
      } else if (a[i] < ssmall && a[i] != small) {
        ssmall = a[i];
      }
    }
    return {slarge, ssmall};
  }
};

// 4
// 5
// 3 1 4 5 2
// 4
// 3 4 5 2
// 5
// 2 31 1 245 41
// 5
// 4 5 3 6 7

// 4 2
// 4 3
// 41 2
// 6 4

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
    pair<int, int> result = obj.getSecondOrderElements(n, arr);
    cout << result.first << " " << result.second << endl;
  }
  return 0;
}
//} Driver Code Ends
