#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char, char> mp1, mp2;
//         for (int i = 0; i < s.length(); ++i) {
//             if (mp1[s[i]] && mp1[s[i]] != t[i]) return false;
//             if (mp2[t[i]] && mp2[t[i]] != s[i]) return false;
//             mp1[s[i]] = t[i];
//             mp2[t[i]] = s[i];
//         }
//         return true;
//     }
// };

// Time complexity: O(|str1|+|str2|)
// Space complexity: O(Number of different characters)

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length())
      return false;
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (m1[s[i]] != m2[t[i]])
        return false;
      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }
    return true;
  }
};

// 3
// egg
// add
// foo
// bar
// paper
// title

// true
// false
// true

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s, t;
    getline(cin, s); // Read string s
    getline(cin, t); // Read string t

    Solution sol;
    if (sol.isIsomorphic(s, t)) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
  return 0;
}
