//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Please change the array in-place
  // void insertionSort(vector<int> &arr) {
  //   // code here
  //   int n = arr.size();
  //   for (int i = 0; i <= n - 1; i++) {
  //     int j = i;
  //     while ((j > 0) && (arr[j - 1] > arr[j])) {
  //       int temp = arr[j - 1];
  //       arr[j - 1] = arr[j];
  //       arr[j] = temp;
  //       j--;
  //     }
  //   }
  // }
  void insertionSort(vector<int> &arr, int n) {
    if (n == 1)
      return;
    int j = 6 - n;
    while ((j > 0) && arr[j - 1] > arr[j]) {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
    return insertionSort(arr, n - 1);
  }
};

//{ Driver Code Starts.

int main() {
  string ts;
  getline(cin, ts);
  int t = stoi(ts);
  while (t--) {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
      arr.push_back(number);
    }
    Solution obj;
    obj.insertionSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
