#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> superiorElements(vector<int> &a) {
    // int n = a.size();
    // vector<int> result;
    // result.push_back(a[n - 1]);
    // int isSuperior = 1;
    // for (int i = 0; i < n - 1; i++) {
    //   isSuperior = 1;
    //   for (int j = i + 1; j < n; j++) {
    //     if (a[i] < a[j]) {
    //       isSuperior = 0;
    //       break;
    //     }
    //   }
    //   if (isSuperior == 1) {
    //     if (find(result.begin(), result.end(), a[i]) == result.end()) {
    //       result.push_back(a[i]);
    //     }
    //   }
    // }
    // sort(result.begin(), result.end());
    // return result;

    int n = a.size();
    vector<int> res;
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > max) {
        res.push_back(a[i]);
        max = a[i];
      }
    }
    return res;
  }
};

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
    vector<int> result = obj.superiorElements(arr);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl << "~" << endl;
  }
  return 0;
}
