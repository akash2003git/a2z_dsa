//{ Driver Code Starts
#include <bits/stdc++.h>
#include <climits>

using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution {
public:
  // Function returns the second
  // largest elements

  // int getSecondLargest(vector<int> &arr) {
  //   // Code Here
  //   sort(arr.begin(), arr.end());
  //   int largest = arr[arr.size() - 1];
  //   for (int i = arr.size() - 2; i >= 0; i--) {
  //     if (arr[i] != largest) {
  //       return arr[i];
  //     }
  //   }
  //   return largest;
  // }
  // TC: O(NlogN) + O(N)

  // int getSecondLargest(vector<int> &arr) {
  //   int n = arr.size();
  //   int largest = arr[0];
  //   int secondLargest = INT_MIN;
  //   // if only positive integers then u can take this as -1 instead
  //   for (int i = 0; i < n; i++) {
  //     if (arr[i] > largest) {
  //       largest = arr[i];
  //     }
  //   }
  //   for (int i = 0; i < n; i++) {
  //     if (arr[i] > secondLargest && arr[i] != largest) {
  //       secondLargest = arr[i];
  //     }
  //   }
  //   if (secondLargest == INT_MIN)
  //     return largest;
  //   return secondLargest;
  // }
  // TC: 2*O(N)

  // this solution is for +ve int only so we will use secondLargest = -1
  int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i] > largest) {
        secondLargest = largest;
        largest = arr[i];
      }
      if (arr[i] < largest && arr[i] > secondLargest) {
        secondLargest = arr[i];
      }
    }
    if (secondLargest == -1)
      return largest;
    return secondLargest;
  }
  // TC: O(N)
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
    int ans = ob.getSecondLargest(arr);
    cout << ans << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
