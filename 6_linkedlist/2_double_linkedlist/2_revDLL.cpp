#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *back;
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *arrToDLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp; // or prev = prev->next;
  }
  return head;
}

void printDLL(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Node *reverseDLL(Node *head) {
//   Node *temp = head;
//   stack<int> st;
//   while (temp != nullptr) {
//     st.push(temp->data);
//     temp = temp->next;
//   }
//   temp = head;
//   while (temp != nullptr) {
//     temp->data = st.top();
//     st.pop();
//     temp = temp->next;
//   }
//   return head;
// }
// TC: O(2*N);
// SC: O(N);

Node *reverseDLL(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *current = head;
  Node *prev = nullptr;
  while (current != nullptr) {
    prev = current->back;
    current->back = current->next;
    current->next = prev;
    current = current->back;
  }
  return prev->back;
}
// TC: O(N);
// SC: O(1);

int main() {
  vector<int> arr = {12, 34, 4, 15, 56, 94, 80, 23};
  Node *head = arrToDLL(arr);
  printDLL(head);
  head = reverseDLL(head);
  cout << endl;
  printDLL(head);
  return 0;
}
