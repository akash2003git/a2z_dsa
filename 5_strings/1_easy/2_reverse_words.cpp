#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         vector<string> words;
//         string word;
//         string result;
//         while(ss >> word){
//           words.push_back(word);
//         }
//         for(int i = words.size() - 1; i >= 0; i--){
//           result += words[i];
//           if(i != 0){
//             result += " ";
//           }
//         }
//         return result;
//     }
// };

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int left = 0, right = 0;
    int n = s.size();
    int i = 0;
    while (i < n) {
      while (i < n && s[i] == ' ') {
        i++;
      }
      if (i >= n) {
        break;
      }
      while (i < n && s[i] != ' ') {
        s[right++] = s[i++];
      }
      reverse(s.begin() + left, s.begin() + right);
      s[right++] = ' ';
      left = right;
      i++;
    }
    s.resize(right - 1);
    return s;
  }
};

// Time complexity: O(n)
// Space complexity: O(1)

// 3
// the sky is blue
//   hello world
// a good   example

// 'blue is sky the'
// 'world hello'
// 'example good a'

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    // Using getline to read the entire line including spaces
    getline(cin, s);
    Solution sol;
    cout << "'" << sol.reverseWords(s) << "'"
         << endl; // Enclose output in quotes to show exact string
  }
  return 0;
}
