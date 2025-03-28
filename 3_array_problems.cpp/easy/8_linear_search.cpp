//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to find element in sorted array
  // arr: input array
  // k: element to be searched
  bool searchInSorted(vector<int> &arr, int k) {
    // Your code here
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (arr[i] == k) {
        return true;
      }
    }
    return false;
  }
};

// 2
// 1 2 3 4 5
// 3
// 10 20 30 40 50
// 25

//{ Driver Code Starts.

int main(void) {

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

    int k;
    cin >> k;
    cin.ignore();
    Solution ob;
    cout << (ob.searchInSorted(arr, k) ? "true" : "false") << endl;
    cout << "~" << endl;
  }

  return 0;
}

// } Driver Code Ends
