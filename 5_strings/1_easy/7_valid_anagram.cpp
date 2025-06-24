#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()) return false;
//         int n = s.length();
//         unordered_map<char, int> mp1, mp2;
//         for(int i = 0; i < n; i++){
//             mp1[s[i]]++;
//             mp2[t[i]]++;
//         }
//         return mp1 == mp2;
//     }
// };

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()) return false;
//         int n = s.length();
//         unordered_map<char, int> mp;
//         for(char c : s){
//             mp[c]++;
//         }
//         for(char c : t){
//             mp[c]--;
//             if(mp[c] < 0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;
    int n = s.length();
    vector<int> mp(26, 0);
    for (char c : s) {
      mp[c - 'a']++;
    }
    for (char c : t) {
      mp[c - 'a']--;
      if (mp[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

// 3
// anagram
// nagaram
// rat
// car
// hello
// world

// true
// false
// false

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s, t;
    getline(cin, s); // Read string s
    getline(cin, t); // Read string t

    Solution sol;
    // Using the frequency array approach
    if (sol.isAnagram(s, t)) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }

    // Uncomment the lines below to test the sorting approach
    // if (sol.isAnagram_sorting(s, t)) {
    //     cout << "true (sorting)" << endl;
    // } else {
    //     cout << "false (sorting)" << endl;
    // }
  }
  return 0;
}
