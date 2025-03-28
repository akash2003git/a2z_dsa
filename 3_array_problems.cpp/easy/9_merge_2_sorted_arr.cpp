// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortedArray(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();

    // set<int> s;
    // for (int num : a)
    //   s.insert(num);
    // for (int num : b)
    //   s.insert(num);
    // return vector<int>(s.begin(), s.end());

    // map<int, int> freq;
    // vector<int> ans;
    // for (int i = 0; i < n; i++) {
    //   freq[a[i]]++;
    // }
    // for (int i = 0; i < m; i++) {
    //   freq[b[i]]++;
    // }
    // for (auto &it : freq) {
    //   ans.push_back(it.first);
    // }
    // return ans;

    vector<int> unionArr;
    int i = 0;
    int j = 0;

    while (i < n && j < m) {
      if (a[i] <= b[j]) {
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
          unionArr.push_back(a[i]);
        }
        i++;
      } else {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
          unionArr.push_back(b[j]);
        }
        j++;
      }
    }

    while (i < n) {
      if (unionArr.size() == 0 || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      i++;
    }

    while (j < m) {
      if (unionArr.size() == 0 || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      }
      j++;
    }

    return unionArr;
  }
};

// 2
// 5 3
// 1 2 3 4 6
// 2 3 5
// 4 3
// 1 2 3 3
// 2 2 4

// 1 2 3 4 5 6
// 1 2 3 4

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

    Solution obj;
    vector<int> result = obj.sortedArray(a, b);

    for (int num : result) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
// { Driver Code Ends
