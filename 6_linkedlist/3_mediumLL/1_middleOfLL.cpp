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
  int lengthLL(ListNode *head) {
    int len = 0;
    ListNode *temp = head;
    while (temp != nullptr) {
      len += 1;
      temp = temp->next;
    }
    return len;
  }

  // ListNode *middleNode(ListNode *head) {
  //   if (head == nullptr)
  //     return head;
  //   int len = lengthLL(head);
  //   if (len == 1)
  //     return head;
  //   int cnt = 0;
  //   ListNode *temp = head;
  //   while (temp != nullptr) {
  //     cnt += 1;
  //     if (cnt == len / 2) {
  //       break;
  //     }
  //     temp = temp->next;
  //   }
  //   return temp->next;
  // }

  // Tortoise and Hare algorithm.
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
      // Move slow one step.
      slow = slow->next;
      // Move fast two steps.
      fast = fast->next->next;
    }
    // Return the slow pointer, which is now at the middle node.
    return slow;
  }
};

// 2
// 1 2 3 4 5
// 1 2 3 4 5 6

// Middle of the list: 3 -> 4 -> 5
// Middle of the list: 4 -> 5 -> 6

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

// Helper function to print a linked list (from a given node to the end)
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

    Solution sol;
    ListNode *middle = sol.middleNode(head);

    // Output the linked list starting from the middle node
    cout << "Middle of the list: ";
    printLinkedList(middle);

    // Clean up memory
    deleteLinkedList(head);
  }
  return 0;
}
