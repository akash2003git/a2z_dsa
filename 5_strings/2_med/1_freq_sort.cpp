#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    int n = s.length();
    string res = "";
    unordered_map<char, int> freq;
    vector<string> bucket(n + 1, "");

    // frequency map of all characters
    for (char c : s)
      freq[c]++;

    // put characters in freq bucket
    for (auto it : freq) {
      char c = it.first;
      int f = it.second;
      bucket[f].append(f, c);
    }

    // iterate through the bucket in descending order
    for (int i = n; i > 0; i--) {
      if (!bucket[i].empty()) {
        res.append(bucket[i]);
      }
    }

    return res;
  }
};

// 3
// tree
// cccaaa
// Aabb

// eert
// aaaccc
// bbaA

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.frequencySort(s) << endl;
  }
  return 0;
}
