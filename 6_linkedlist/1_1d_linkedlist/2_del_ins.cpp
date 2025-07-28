#include <bits/stdc++.h>
using namespace std;

// Node Definition
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

// Function to convert Array to LinkedList
Node *arrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

// Function for length of LinkedList
void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Function to remove head
Node *removeHead(Node *head) {
  if (head == NULL)
    return head;
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

// Function to remove tail
Node *removeTail(Node *head) {
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}

// Function to remove Kth element
Node *removeK(Node *head, int k) {
  if (head == NULL)
    return head;
  if (k == 1) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  int cnt = 0;
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL) {
    cnt++;
    if (cnt == k) {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

// Function to remove a particular element
Node *removeEl(Node *head, int el) {
  if (head == NULL)
    return head;
  if (head->data == el) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL) {
    if (temp->data == el) {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

// Function to insert at head
Node *insertHead(Node *head, int val) { return new Node(val, head); }

// Function to insert at tail
Node *insertTail(Node *head, int val) {
  if (head == NULL) {
    return new Node(val, head);
  }
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newNode = new Node(val);
  temp->next = newNode;
  return head;
}

// Function to insert at Kth position
Node *insertK(Node *head, int val, int k) {
  if (head == NULL) {
    if (k == 1) {
      return new Node(val);
    } else {
      return NULL;
    }
  }
  if (k == 1) {
    return new Node(val, head);
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL) {
    cnt++;
    if (cnt == k - 1) {
      Node *newNode = new Node(val, temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}

// Function to insert an element before a value
Node *insertBeforeVal(Node *head, int el, int val) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == val) {
    return new Node(el, head);
  }
  Node *temp = head;
  bool found = false;
  while (temp->next != NULL) {
    if (temp->next->data == val) {
      Node *newNode = new Node(el, temp->next);
      temp->next = newNode;
      found = true;
      break;
    }
    temp = temp->next;
  }
  if (!found) {
    cout << "Element not found!" << endl;
  }
  return head;
}

int main() {
  cout << "----------------------------------------" << endl;
  vector<int> arr = {12, 34, 4, 15, 56, 94, 80, 23};
  Node *head = arrToLL(arr);
  cout << "Original LL: ";
  printLL(head);
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "Removed head: ";
  head = removeHead(head);
  printLL(head);
  cout << endl;
  cout << "Removed tail: ";
  head = removeTail(head);
  printLL(head);
  cout << endl;
  cout << "Removed 3rd element: ";
  head = removeK(head, 3);
  printLL(head);
  cout << endl;
  cout << "Removed 56: ";
  head = removeEl(head, 56);
  printLL(head);
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "Inserted 71 at head: ";
  head = insertHead(head, 71);
  printLL(head);
  cout << endl;
  cout << "Inserted 66 at tail: ";
  head = insertTail(head, 66);
  printLL(head);
  cout << endl;
  cout << "Inserted at 2nd position: ";
  head = insertK(head, 123, 2);
  printLL(head);
  cout << endl;
  cout << "Inserted before 4: ";
  head = insertBeforeVal(head, 58, 4);
  printLL(head);
  cout << endl;

  return 0;
}
