#include <cmath>
#include <iostream>

using namespace std;

int floorSqrt(int n) {
  int low = 1, high = n;
  int ans = 0;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long val = mid * mid;
    if (val <= n) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int result = floorSqrt(n);
    cout << result << endl;
  }
  return 0;
}
