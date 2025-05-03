#include <bits/stdc++.h>
#include <queue>

using namespace std;

// double minimiseMaxDistance(vector<int> &arr, int k) {
//   int n = arr.size();
//   vector<int> howMany(n - 1, 0);
//   for (int gasStation = 1; gasStation <= k; gasStation++) {
//     long double maxSection = -1;
//     int maxIdx = -1;
//     for (int i = 0; i < n - 1; i++) {
//       long double diff = arr[i + 1] - arr[i];
//       long double sectionLen = diff / (long double)(howMany[i] + 1);
//       if (sectionLen > maxSection) {
//         maxSection = sectionLen;
//         maxIdx = i;
//       }
//     }
//     howMany[maxIdx] += 1;
//   }
//   long double maxSection = -1;
//   for (int i = 0; i < n - 1; i++) {
//     long double diff = arr[i + 1] - arr[i];
//     long double sectionLen = diff / (long double)(howMany[i] + 1);
//     maxSection = max(sectionLen, maxSection);
//   }
//   return maxSection;
// }

// double minimiseMaxDistance(vector<int> &arr, int k) {
//   int n = arr.size();
//   vector<int> howMany(n - 1, 0);
//   priority_queue<pair<long double, int>> pq;
//   for (int i = 0; i < n - 1; i++) {
//     pq.push({arr[i + 1] - arr[i], i});
//   }
//   for (int gasStation = 1; gasStation <= k; gasStation++) {
//     auto tp = pq.top();
//     pq.pop();
//     int sectionIdx = tp.second;
//     howMany[sectionIdx] += 1;
//     long double diff = arr[sectionIdx + 1] - arr[sectionIdx];
//     long double sectionLen = diff / (long double)(howMany[sectionIdx] + 1);
//     pq.push({sectionLen, sectionIdx});
//   }
//   return pq.top().first;
// }

int numberOfGasStations(long double dist, vector<int> &arr) {
  int cnt = 0;
  for (int i = 1; i < arr.size(); i++) {
    int stationsInBetween = ((arr[i] - arr[i - 1]) / dist);
    if ((arr[i] - arr[i - 1]) == stationsInBetween * dist) {
      stationsInBetween -= 1; // in case of a perfect division
    }
    cnt += stationsInBetween;
  }
  return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k) {
  int n = arr.size();
  long double low = 0;
  long double high = 0;
  for (int i = 0; i < n - 1; i++) {
    high = max(high, (long double)arr[i + 1] - arr[i]);
  }
  long double diff = 1e-6;
  while (high - low > diff) {
    long double mid = low + (high - low) / 2.0;
    int cnt = numberOfGasStations(mid, arr);
    if (cnt > k) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high; // or we can return low
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << fixed << setprecision(6) << minimiseMaxDistance(a, k) << endl;
  }
  return 0;
}
