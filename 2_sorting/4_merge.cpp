//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void merge(vector<int> &arr, int l, int m, int h) {
    vector<int> temp;
    int left = l;
    int right = m + 1;

    while (left <= m && right <= h) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        right++;
      }
    }

    while (left <= m) {
      temp.push_back(arr[left]);
      left++;
    }

    while (right <= h) {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = l; i <= h; i++) {
      arr[i] = temp[i - l];
    }
  }
  void mergeSort(vector<int> &arr, int l, int h) {
    // code here
    if (l >= h)
      return;
    int m = (l + h) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);
    merge(arr, l, m, h);
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
    obj.mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
