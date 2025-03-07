#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<int, int> maxMinFrequency(vector<int> &arr) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++) {
      mpp[arr[i]]++;
    }

    int maxFreq = 0, minFreq = arr.size();
    int maxEle = mpp.begin()->first, minEle = mpp.begin()->first;

    for (auto &[element, count] : mpp) {
      if (count > maxFreq) {
        maxEle = element;
        maxFreq = count;
      }
      if (count < minFreq) {
        minEle = element;
        minFreq = count;
      }
    }

    return {maxEle, minEle};
  }
};

// Driver Code
int main() {
  int t;
  cin >> t; // Number of test cases

  while (t--) {
    int n;
    cin >> n; // Size of array

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i]; // Read array elements
    }

    Solution obj;
    pair<int, int> result = obj.maxMinFrequency(arr);
    cout << result.first << " " << result.second << endl;
  }

  return 0;
}
