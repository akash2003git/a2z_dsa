#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int myAtoi(string s) {
//         long long res = 0;
//         int n = s.length();
//         int sign = 1;
//         int i = 0;

//         while(i < n && s[i] == ' '){
//             i++;
//         }

//         if(i < n && (s[i] == '+' || s[i] == '-')){
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;
//         }

//         while(i < n && (s[i] >= '0' && s[i] <= '9')){
//             int digit = s[i] - '0';

//             if(sign == 1){
//                 if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit >
//                 INT_MAX % 10)){
//                     return INT_MAX;
//                 }
//             } else {
//                 long long abs_int_min_val = (long long)INT_MIN * -1;
//                 if (res > abs_int_min_val / 10) {
//                     return INT_MIN;
//                 }
//                 if (res == abs_int_min_val / 10 && digit > abs_int_min_val %
//                 10) {
//                     return INT_MIN;
//                 }
//             }

//             res = res * 10 + digit;
//             i++;
//         }

//         return static_cast<int>(res * sign);
//     }
// };

class Solution {
public:
  int myAtoi(string str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') {
      i++;
    }
    if (str[i] == '-' || str[i] == '+') {
      sign = 1 - 2 * (str[i++] == '-');
    }
    while (str[i] >= '0' && str[i] <= '9') {
      if (base > INT_MAX / 10 ||
          (base == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
        if (sign == 1)
          return INT_MAX;
        else
          return INT_MIN;
      }
      base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
  }
};

// 5
// 42
//    -42
// 4193 with words
// words and 987
// -91283472332

// 42
// -42
// 4193
// 0
// -2147483648

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.myAtoi(s) << endl;
  }
  return 0;
}
