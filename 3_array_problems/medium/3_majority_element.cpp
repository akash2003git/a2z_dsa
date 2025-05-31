//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // map<int, int> freq;
    // for (int num : nums) {
    //   freq[num]++;
    // }
    // for (auto it : freq) {
    //   if (it.second > nums.size() / 2) {
    //     return it.first;
    //   }
    // }
    // return -1;

    int count = 0;
    int element;
    for (int num : nums) {
      if (count == 0) {
        count = 1;
        element = num;
      } else if (element == num) {
        count++;
      } else {
        count--;
      }
    }
    int freq = 0;
    for (int num : nums) {
      if (element == num)
        freq++;
    }
    if (freq > nums.size() / 2)
      return element;
    return -1;
  }
};

// 3
// 3
// 3 2 3
// 7
// 2 2 1 1 1 2 2
// 8
// 1 2 2 1 1 2 1 2

// 3
// ~
// 2
// ~
// -1
// ~

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    Solution obj;
    cout << obj.majorityElement(nums) << endl;
  }
  return 0;
}
//{ Driver Code Ends
