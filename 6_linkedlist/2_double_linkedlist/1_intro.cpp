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

Node *deleteHead(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;
  delete prev;
  return head;
}

Node *deleteTail(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  Node *tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;
  delete tail;
  return head;
}

Node *deleteKthElement(Node *head, int k) {
  if (head == nullptr) {
    return nullptr;
  }

  int cnt = 0;
  Node *kNode = head;
  while (kNode != nullptr) {
    cnt++;
    if (cnt == k)
      break;
    kNode = kNode->next;
  }

  Node *prev = kNode->back;
  Node *front = kNode->next;
  if (prev == nullptr && front == nullptr) {
    return nullptr;
  } else if (prev == nullptr) {
    return deleteHead(head);
  } else if (front == nullptr) {
    return deleteTail(head);
  }
  prev->next = front;
  front->back = prev;
  kNode->next = nullptr;
  kNode->back = nullptr;
  delete kNode;
  return head;
}

Node *deleteVal(Node *head, int val) {
  if (head == nullptr) {
    return nullptr;
  }

  Node *kNode = head;
  while (kNode != nullptr) {
    if (kNode->data == val)
      break;
    kNode = kNode->next;
  }

  Node *prev = kNode->back;
  Node *front = kNode->next;
  if (prev == nullptr && front == nullptr) {
    return nullptr;
  } else if (prev == nullptr) {
    return deleteHead(head);
  } else if (front == nullptr) {
    return deleteTail(head);
  }
  prev->next = front;
  front->back = prev;
  kNode->next = nullptr;
  kNode->back = nullptr;
  delete kNode;
  return head;
}

// assume temp is anything but head
void deleteNode(Node *temp) {
  Node *prev = temp->back;
  Node *front = temp->next;

  if (front == nullptr) {
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return;
  }

  prev->next = front;
  front->back = prev;
  temp->back = temp->next = nullptr;
  delete temp;
}

Node *insertBeforeHead(Node *head, int val) {
  Node *newHead = new Node(val, head, nullptr);
  head->back = newHead;
  return newHead;
}

Node *insertBeforeTail(Node *head, int val) {
  if (head->next == nullptr)
    return insertBeforeHead(head, val);
  Node *tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  Node *prev = tail->back;
  Node *newNode = new Node(val, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}

Node *insertBeforeKthElement(Node *head, int k, int val) {
  if (k == 1)
    return insertBeforeHead(head, val);
  int cnt = 0;
  Node *kNode = head;
  while (kNode != nullptr) {
    cnt++;
    if (cnt == k)
      break;
    kNode = kNode->next;
  }
  Node *prev = kNode->back;
  Node *newNode = new Node(val, kNode, prev);
  prev->next = newNode;
  kNode->back = newNode;
  return head;
}

void insertBeforeNode(Node *node, int val) {
  Node *prev = node->back;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->back = newNode;
}

int main() {
  cout << "----------------------------------------" << endl;
  vector<int> arr = {12, 34, 4, 15, 56, 94, 80, 23};
  Node *head = arrToDLL(arr);
  cout << "Original DLL: ";
  printDLL(head);
  cout << endl;
  cout << "----------------------------------------" << endl;
  head = deleteHead(head);
  cout << "Deleted head: ";
  printDLL(head);
  cout << endl;
  head = deleteTail(head);
  cout << "Deleted tail: ";
  printDLL(head);
  cout << endl;
  head = deleteKthElement(head, 2);
  cout << "Deleted 2nd element(4): ";
  printDLL(head);
  cout << endl;
  head = deleteVal(head, 94);
  cout << "Deleted 94: ";
  printDLL(head);
  cout << endl;
  deleteNode(head->next->next);
  cout << "Deleted 3rd Node(56): ";
  printDLL(head);
  cout << endl;
  cout << "----------------------------------------" << endl;
  head = insertBeforeHead(head, 100);
  cout << "Inserted 100 before head: ";
  printDLL(head);
  cout << endl;
  head = insertBeforeTail(head, 99);
  cout << "Inserted 99 before tail: ";
  printDLL(head);
  cout << endl;
  head = insertBeforeKthElement(head, 3, 66);
  cout << "Inserted 66 before 3rd element(15): ";
  printDLL(head);
  cout << endl;
  insertBeforeNode(head->next, 72);
  cout << "Inserted 72 before 2nd node(34): ";
  printDLL(head);
  cout << endl;

  return 0;
}
