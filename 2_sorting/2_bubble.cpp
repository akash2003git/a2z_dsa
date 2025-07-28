#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void bubbleSort(vector<int> &arr) {
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

  void bubbleSortRecursive(vector<int> &arr, int n) {
    if (n == 1)
      return;
    int didSwap = 0;
    for (int i = 0; i <= n - 2; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        didSwap = 1;
      }
    }
    if (didSwap == 0)
      return;
    return bubbleSortRecursive(arr, n - 1);
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
