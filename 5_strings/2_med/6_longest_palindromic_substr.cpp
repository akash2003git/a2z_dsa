#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string res = "";
//         int len = 0;
//         int maxLen = 0;
//         int n = s.length();
//         for(int i = 0; i < s.length(); i++){
//             for(int j = i; j < s.length(); j++){
//                 string str = s.substr(i, j - i + 1);
//                 string rev = str;
//                 reverse(rev.begin(), rev.end());
//                 if(str == rev){
//                     len = str.length();
//                     if(len > maxLen){
//                         res = str;
//                         maxLen = max(len, maxLen);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1)
      return s;

    auto expand = [&](int left, int right) {
      while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
      }
      return s.substr(left + 1, right - left - 1);
    };

    string max_str = s.substr(0, 1);

    for (int i = 0; i < n; i++) {
      string odd = expand(i, i);
      string even = expand(i, i + 1);
      if (odd.length() > max_str.length()) {
        max_str = odd;
      }
      if (even.length() > max_str.length()) {
        max_str = even;
      }
    }

    return max_str;
  }
};

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
  }
  return 0;
}
