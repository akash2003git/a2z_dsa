#include <bits/stdc++.h>

using namespace std;

int noOfPainters(vector<int> &boards, int minTime) {
  int painterCount = 1;
  long long currTime = boards[0];
  for (int i = 1; i < boards.size(); i++) {
    if (currTime + boards[i] <= minTime) {
      currTime += boards[i];
    } else {
      painterCount += 1;
      currTime = boards[i];
    }
  }
  return painterCount;
}

long long findLargestMinDistance(vector<int> &boards, int k) {
  int ans = -1;
  if (k > boards.size()) {
    return ans;
  }
  long long low = *max_element(boards.begin(), boards.end());
  long long high = accumulate(boards.begin(), boards.end(), 0);
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    int painterCount = noOfPainters(boards, mid);
    if (painterCount <= k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  ans = low;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
      cin >> boards[i];
    }
    cout << findLargestMinDistance(boards, k) << endl;
  }
  return 0;
}
