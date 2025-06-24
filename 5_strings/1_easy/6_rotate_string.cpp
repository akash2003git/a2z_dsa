#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n = s.length();
//         for(int i = 0; i < n; i++){
//             string shftWord = s.substr(i+1, n-i+1) + s.substr(0, i+1);
//             if(shftWord == goal){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
  bool rotateString(string A, string B) {
    return A.size() == B.size() && (A + A).find(B) != string::npos;
  }
};

// 3
// abcde
// cdeab
// abcde
// abced
// aa
// a

// true
// false
// false

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s, goal;
    getline(cin, s);    // Read string s
    getline(cin, goal); // Read string goal

    Solution sol;
    if (sol.rotateString(s, goal)) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
  return 0;
}
