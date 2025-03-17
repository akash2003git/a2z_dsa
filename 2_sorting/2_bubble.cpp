//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
public:
  // Function to sort the array using bubble sort algorithm.
  void bubbleSort(vector<int> &arr) {
    // Your code here
    int n = arr.size();
    for (int i = n - 1; i >= 1; i--) {
      int didSwap = 0;
      for (int j = 0; j <= i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          int temp = arr[j + 1];
          arr[j + 1] = arr[j];
          arr[j] = temp;
          didSwap = 1;
        }
      }
      if (didSwap == 0) {
        break;
      }
    }
  }
};

//{ Driver Code Starts.

// Driver program to test above functions
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

    ob.bubbleSort(arr);
    for (int e : arr) {
      cout << e << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
