#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *arrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

int lengthOfLL(Node *head) {
  int cnt = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

int isPresent(Node *head, int val) {
  Node *temp = head;
  while (temp) {
    if (temp->data == val)
      return 1;
    temp = temp->next;
  }
  return 0;
}

int main() {
  vector<int> arr = {2, 5, 8, 7};
  Node *y = new Node(arr[0], nullptr);
  cout << y->data << endl;
  cout << y->next << endl;
  cout << y << endl;

  Node z = Node(arr[1]);
  cout << z.data << endl;
  cout << z.next << endl;

  cout << "-------------------------" << endl;

  Node *head = arrToLL(arr);
  cout << head->data << " ";
  cout << head->next->data << " ";
  cout << head->next->next->data << " ";
  cout << head->next->next->next->data << " " << endl;

  cout << "-------------------------" << endl;

  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
  cout << "Length of the LL is: " << lengthOfLL(head) << endl;
  cout << "Is 2 present? " << isPresent(head, 2) << endl;
  cout << "Is 3 present? " << isPresent(head, 3) << endl;

  return 0;
}
