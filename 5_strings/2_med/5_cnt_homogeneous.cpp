#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     int countHomogenous(std::string s) {
//         long long total_homogenous_substrings = 0;
//         int n = s.length();

//         if (n == 0) {
//             return 0;
//         }

//         int i = 0;
//         int j = 0;

//         while (j < n) {
//             if (s[j] == s[i]) {
//                 j++;
//             } else {
//                 long long segment_length = j - i;
//                 long long combinations = (segment_length * (segment_length +
//                 1) / 2) % MOD; total_homogenous_substrings =
//                 (total_homogenous_substrings + combinations) % MOD; i = j;

//             }
//         }

//         long long last_segment_length = j - i;
//         long long last_combinations = (last_segment_length *
//         (last_segment_length + 1) / 2) % MOD; total_homogenous_substrings =
//         (total_homogenous_substrings + last_combinations) % MOD;

//         return static_cast<int>(total_homogenous_substrings);
//     }
// };

class Solution {
public:
  int countHomogenous(string s) {
    int left = 0;
    long long res = 0;

    for (int right = 0; right < s.length(); right++) {
      if (s[left] == s[right]) {
        res += right - left + 1;
      } else {
        res += 1;
        left = right;
      }
    }

    return (int)(res % (1000000007));
  }
};

// 1 --- 1
// 2 --- 2 + 1
// 3 --- 3 + 2 + 1
// 4 --- 4 + 3 + 2 + 1
// 5 --- 5 + 4 + 3 + 2 + 1

// 3
// abbcccaa
// zzzaac
// x

// 13
// 10
// 1

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string s;
    getline(cin, s); // Read the entire line for the string
    Solution sol;
    cout << sol.countHomogenous(s) << endl;
  }
  return 0;
}
