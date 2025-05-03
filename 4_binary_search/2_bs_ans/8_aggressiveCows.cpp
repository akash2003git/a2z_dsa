#include <bits/stdc++.h>

using namespace std;

bool canPlace(vector<int> &stalls, int numCows, int minDist) {
  int countCows = 1;
  int lastCowPos = stalls[0];
  for (int i = 1; i < stalls.size(); i++) {
    if ((stalls[i] - lastCowPos >= minDist)) {
      countCows += 1;
      lastCowPos = stalls[i];
      if (countCows >= numCows) {
        return true;
      }
    } else {
      continue;
    }
  }
  return false;
}

int aggressiveCows(vector<int> &stalls, int numCows) {
  sort(stalls.begin(), stalls.end());
  int maxDist = 0;
  int low = 1;
  int high = stalls.back() - stalls[0];
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (canPlace(stalls, numCows, mid)) {
      maxDist = mid;
      low = mid + 1; // Possible but try for a larger distance
    } else {
      high = mid - 1; // Not possible so try a smaller distance
    }
  }
  // for (int i = 1; i <= stalls.back() - stalls[0]; i++) {
  //   if (canPlace(stalls, numCows, i) == true) {
  //     maxDist = i;
  //   } else {
  //     break;
  //   }
  // }
  return maxDist;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
      cin >> stalls[i];
    }
    cout << aggressiveCows(stalls, c) << endl;
  }
  return 0;
}
