#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseListBrute(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    stack<int> st;
    ListNode *temp = head;
    while (temp != nullptr) {
      st.push(temp->val);
      temp = temp->next;
    }
    temp = head;
    while (temp != nullptr) {
      temp->val = st.top();
      st.pop();
      temp = temp->next;
    }

    return head;
  }

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *back = head;
    ListNode *temp = head->next;
    ListNode *front = temp->next;
    return head;
  }
};

// Helper function to create a linked list from a vector of integers
ListNode *createLinkedList(const std::vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(values[0]);
  ListNode *current = head;
  for (size_t i = 1; i < values.size(); ++i) {
    current->next = new ListNode(values[i]);
    current = current->next;
  }
  return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->val;
    if (head->next != nullptr) {
      std::cout << " -> ";
    }
    head = head->next;
  }
  std::cout << std::endl;
}

// Helper function to deallocate linked list memory
void deleteLinkedList(ListNode *head) {
  while (head != nullptr) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  int t;
  cin >> t;
  cin.ignore(); // Consume the newline character after reading t

  while (t--) {
    string line;
    getline(cin,
            line); // Read the entire line containing space-separated numbers

    stringstream ss(line);
    int val;
    vector<int> values;
    while (ss >> val) {
      values.push_back(val);
    }

    ListNode *head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    Solution sol;
    ListNode *reversed_head = sol.reverseList(head);

    cout << "Reversed list: ";
    printLinkedList(reversed_head);

    // Note: The original `head` now points to the last node of the reversed
    // list. `reversed_head` is the actual head. We should pass `reversed_head`
    // for cleanup.
    deleteLinkedList(reversed_head);
  }
  return 0;
}
