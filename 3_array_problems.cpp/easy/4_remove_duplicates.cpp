//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    // int n = nums.size();
    // int uniqueNum = nums[0];
    // vector<int> newNums;
    // int k = 1;
    // newNums.push_back(uniqueNum);
    // for (int i = 1; i < n; i++) {
    //   if (nums[i] != uniqueNum) {
    //     uniqueNum = nums[i];
    //     newNums.push_back(uniqueNum);
    //     k++;
    //   }
    // }
    // nums = newNums;
    // return k;

    int n = nums.size();
    int i = 0;
    for (int j = 0; j < n; j++) {
      if (nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    Solution obj;
    int newSize = obj.removeDuplicates(nums);

    // Printing the modified array
    for (int i = 0; i < newSize; i++) {
      cout << nums[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
//} Driver Code Ends
