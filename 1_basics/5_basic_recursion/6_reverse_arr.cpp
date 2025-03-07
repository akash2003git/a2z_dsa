//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void reverseArray(vector<int> &arr, int l = 0) {
    // code here
    int r = arr.size() - 1 - l;
    if (l >= r)
      return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
      arr.push_back(number);
    }

    Solution ob;
    ob.reverseArray(arr);
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
