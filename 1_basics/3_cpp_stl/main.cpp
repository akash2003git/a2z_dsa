#include <bits/stdc++.h>

using namespace std;

void explainPair() {
  pair<int, int> p1 = {1, 3};
  cout << p1.first << " " << p1.second << endl;

  pair<int, pair<int, int>> p2 = {1, {3, 4}};
  cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  cout << arr[1].second;
}

void explainVector() {
  vector<int> v1;

  v1.push_back(1);
  v1.emplace_back(2);
  cout << v1[0] << " " << v1[1] << endl;

  // Use push_back when you already have an object.
  // Use emplace_back when you want to construct an object directly and avoid
  // extra copies/moves. For simple types (like int, double), there's no
  // significant difference, but for complex objects, emplace_back is generally
  // better for performance.

  vector<pair<int, int>> v2;
  v2.push_back({1, 2});
  v2.emplace_back(2, 3);
  cout << v2[0].second << " " << v2[1].second << endl;

  vector<int> v3(5, 100); // 5 times 100
  vector<int> v4(5);      // empty vector of size 5
  vector<int> v5(v3);     // copy v3 in v5

  vector<int> v;
  v.push_back(34);
  v.push_back(35);
  v.push_back(36);
  v.push_back(37);
  vector<int>::iterator it1 = v.begin();
  cout << *(it1) << " ";
  it1++;
  cout << *(it1) << endl;

  vector<int>::iterator it2 =
      v.end(); // pointing to address after the last element
  it2--;
  vector<int>::reverse_iterator it3 =
      v.rend(); // same here but ++ or -- is reversed
  it3--;
  vector<int>::reverse_iterator it4 =
      v.rbegin(); // points to first element but ++ or -- reversed

  cout << *(it2) << " " << *(it3) << " " << *(it4) << " " << endl;

  cout << v[0] << " " << v.at(1) << " " << *(it3 - 2) << " " << v.back()
       << endl;
  cout << endl;

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
  cout << endl;

  v.insert(v.begin(), 33);
  v.insert(v.begin() + 1, 2, 10);
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

  v.erase(v.begin() + 1);
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

  v.erase(v.begin() + 2, v.begin() + 4);
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
  cout << endl;

  vector<int> copy(2, 50);
  v.insert(v.begin(), copy.begin(), copy.end());
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

  cout << "Size of v: " << v.size() << endl;

  v.pop_back();
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
  cout << "Size of v: " << v.size() << endl;

  cout << endl;

  vector<int> vec1(3, 100);
  vector<int> vec2(5, 200);
  vec1.swap(vec2);
  cout << "vec1: ";
  for (auto it : vec1) {
    cout << it << " ";
  }
  cout << endl;
  cout << "vec2: ";
  for (auto it : vec2) {
    cout << it << " ";
  }
  cout << endl;
  cout << endl;

  v.clear();         // erases entire vector
  cout << v.empty(); // check if vector empty or not
}

void explainList() { // Doubly Linked List
  list<int> ls;
  ls.push_back(4);
  ls.emplace_back(5);
  ls.push_front(2);
  ls.emplace_front(1);
  for (auto it : ls) {
    cout << it << " ";
  }
  cout << endl;

  // rest functions same as vector
  // begin, end, rbegin, rend, clear, insert, erase, size, swap
}

void explainDeque() { // Double-ended queue
  deque<int> dq;
  // again same as list or vector
}

void explainStack() { // O(1)
  stack<int> st;      // LIFO (Last in First Out)
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.emplace(5); // similar to push
  cout << st.top() << endl;
  st.pop();
  cout << st.top() << endl;
  cout << st.size() << endl;
  cout << st.empty() << endl;
  stack<int> st1, st2;
  st1.swap(st2);
}

void explainQueue() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.emplace(3);
  q.back() += 5;
  cout << q.back() << endl;
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
}

void explainPQ() {
  priority_queue<int> pq; // for max heap
  pq.push(5);             // O(log(n))
  pq.push(2);
  pq.push(8); // largest element will be on top
  pq.emplace(1);
  cout << pq.top() << endl; // O(1)
  pq.pop();                 // O(log(n))
  cout << pq.top() << endl;
  // size, swap, empty functions same as others

  priority_queue<int, vector<int>, greater<int>> prq; // for min heap
  prq.push(5);
  prq.push(2);
  prq.push(8);
  prq.emplace(1); // smallest element will be on top
  cout << prq.top() << endl;
}

void explainSet() { // sorted and unique
  set<int> st;      // O(log(n))
  st.insert(1);     // 1
  st.emplace(2);    // 1 2
  st.insert(2);     // 1 2
  st.insert(4);     // 1 2 4
  st.insert(3);     // 1 2 3 4

  // Functionality of insert in vector can be used also, that only increases
  // efficiency

  // begin(), end(), rbegin(), rend(), size(), empty() and swap() available

  auto it1 = st.find(3);
  cout << *(it1) << endl;
  auto it2 = st.find(6); // if element not in set st.find() returns st.end()
                         // i.e. largest element of the set
  cout << *(it2) << endl;

  st.erase(5); // O(log(n))

  cout << st.count(1)
       << endl; // only one occurrence of "1" hence the count is 1

  auto it = st.find(3);
  st.erase(it); // O(1)

  set<int> st2 = {1, 2, 3, 4, 5};
  auto it3 = st.find(2);
  auto it4 = st.find(4);
  st.erase(it3, it4); // 1 4 5

  set<int> st3 = {1, 2, 3, 4, 5, 6};
  auto it5 = st3.lower_bound(2);
  // Returns an iterator pointing to the first element in the set which is
  // greater than or equal to x.
  cout << *(it5) << endl;
  auto it6 = st3.upper_bound(3);
  // Returns an iterator pointing to the first element in the set which is
  // strictly greater than x.
  cout << *(it6) << endl;
}

void explainMultiSet() {
  // Same as but stores duplicate elements also
  multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  cout << ms.count(1) << endl;
  ms.erase(1);
  cout << ms.count(1) << endl;

  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  cout << ms.count(1) << endl;
  ms.erase(ms.find(1)); // only single "1" is erased
  cout << ms.count(1) << endl;
  auto it1 = ms.find(1);
  auto it2 = next(it1, 2);
  ms.erase(it1, it2);
  cout << ms.count(1) << endl;

  // rest all functions same as set
}

void explainUSet() {     // random order but unique elements
  unordered_set<int> st; // O(1)
  // lower_bound and upper_bound functions not available
  // rest all functions same
  // worst case which is rare: O(N)
}

void explainMap() { // key value pairs
                    // all keys unique
                    // sorted order of keys
  map<int, int> mpp;
  map<int, pair<int, int>> mpp2;
  map<pair<int, int>, int> mpp3;

  mpp[1] = 2;          // {1, 2}
  mpp.emplace(3, 1);   // {3, 1}
  mpp.insert({2, 4});  // {2, 4}
  mpp.insert({5, 21}); // {5, 21}

  mpp3[{2, 3}] = 10; // {{2, 3}, 10}

  for (auto it : mpp) {
    cout << it.first << " " << it.second << endl;
  }

  cout << mpp[1] << endl;
  cout << mpp[6] << endl;

  auto it = mpp.find(5);
  cout << (*it).second << endl;

  auto it2 = mpp.find(6);
  cout << (*it2).second << endl;

  auto it3 = mpp.lower_bound(2);
  cout << (*it3).second << endl;
  auto it4 = mpp.upper_bound(3);
  cout << (*it4).second << endl;

  // erase, swap, size, empty
}

void explainMultiMap() {
  // same as map but can store duplicate keys
  // only mpp[key] cannot be used here
}

void explainUnorderedMap() {
  // random order of elements and will have unique keys
}

// map is O(log(n)) and unordered_map is O(1) with O(N) in worst case (rare)

bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second < p2.second)
    return true;
  if (p1.second > p2.second)
    return false;
  if (p1.first > p2.first)
    return true;
  return false;
}

void explainExtra() {
  // sort(a, a + n);
  // sort(v.begin, v.end());
  // sort(a + 2, a + 4);
  // sort(a, a + n, greater<int>);

  // custom sorting example
  pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
  // sort it according to second element
  // if second element is same, then sort it according to the first element but
  // in descending order
  // sort(a, a + n, comp); // 4 1, 2 1, 1 2

  // popcount returns the no. of set bits of the binary represenation of i/p
  int num = 7;
  cout << __builtin_popcount(num) << endl;
  long long num2 = 123141234312314;
  cout << __builtin_popcountll(num2) << endl;

  string s = "123";
  sort(s.begin(), s.end()); // sort before permautaions to get all of them

  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  // int maxi = *max_element(a, a+n); // max element of array, min also
  // available
}

int main() {
  // explainPair();
  // explainVector();
  // explainList();
  // explainDeque();
  // explainStack();
  // explainQueue();
  // explainPQ();
  // explainSet();
  // explainMultiSet();
  // explainMap();
  explainExtra();
  return 0;
}
