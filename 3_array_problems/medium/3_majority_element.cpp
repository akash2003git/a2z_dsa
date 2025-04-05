//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // map<int, int> freq;
    // int max_val = INT_MIN;
    // int max_key = 0;
    // for (int num : nums) {
    //   freq[num]++;
    // }
    // for (auto it : freq) {
    //   if (it.second > max_val) {
    //     max_val = it.second;
    //     max_key = it.first;
    //   }
    // }
    // return max_key;

    // map<int, int> freq;
    // int max_val = INT_MIN;
    // int max_key = 0;
    // for (int num : nums) {
    //   freq[num]++;
    //   if (freq[num] > max_val) {
    //     max_val = freq[num];
    //     max_key = num;
    //   }
    // }
    // return max_key;

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
