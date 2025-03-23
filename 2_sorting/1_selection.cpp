//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
public:
  template <class T> static void input(vector<T> &A, int n) {
    for (int i = 0; i < n; i++) {
      scanf("%d ", &A[i]);
    }
  }

  template <class T> static void print(vector<T> &A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends

class Solution {
public:
  // Function to perform selection sort on the given array.
  void selectionSort(vector<int> &arr) {
    // code here
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
      int min = i;
      for (int j = i + 1; j <= n - 1; j++) {
        if (arr[j] < arr[min])
          min = j;
      }
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
};

//{ Driver Code Starts.

// 5
// 12 4 3 0 1
// -2 4 23
// 39 31 32 32
// 49 1
// 23 1314 1 -234 1 -1

int main() {
  int t;
  scanf("%d ", &t);
  while (t--) {

    vector<int> a;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
      a.push_back(number);
    }

    Solution obj;
    obj.selectionSort(a);

    Array::print(a);
    cout << "~" << endl;
  }
}

// } Driver Code Ends
