#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    // for (int i = 0; i < arr.size(); i++) {
    //   if (arr[i] <= k) {
    //     k++;
    //   } else {
    //     break;
    //   }
    // }
    // return k;

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int missing = arr[mid] - (mid + 1);
      if (missing < k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return k + high + 1; // or k + low
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    Solution sol;
    int result = sol.findKthPositive(arr, k);
    cout << result << endl;
  }
  return 0;
}
