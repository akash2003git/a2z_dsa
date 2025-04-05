//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void leftRotateByOne(int n, vector<int> &arr) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
      arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
  }
};

// 2
// 5
// 1 2 3 4 5
// 3
// 10 20 30

// 2 3 4 5 1
// 20 30 10

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
    obj.leftRotateByOne(n, arr);

    for (int num : arr) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
//} Driver Code Ends
