//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool isPalindrome(string s) {
    // if (i == 0) {
    //   string result = "";
    //   for (char c : s) {
    //     if (isalnum(c)) {
    //       result += tolower(c);
    //     }
    //   }
    //   s = result;
    // }
    // if (i >= s.size() / 2) {
    //   return true;
    // }
    // if (s[i] != s[s.size() - 1 - i]) {
    //   return false;
    // }
    // return isPalindrome(s, i + 1);
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalnum(s[l]))
        l++;
      while (l < r && !isalnum(s[r]))
        r--;
      if (tolower(s[l]) != tolower(s[r]))
        return false;
      l++;
      r--;
    }
    return true;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  cin.ignore(); // To handle newline after integer input
  while (t--) {
    string s;
    getline(cin, s);

    Solution ob;
    bool ans = ob.isPalindrome(s);
    cout << (ans ? "true" : "false") << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
