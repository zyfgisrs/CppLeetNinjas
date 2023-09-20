#include <iostream>

struct Node {
  Node* next;
  int val;

  Node() : val(0), next(nullptr) {}
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node* next) : val(val), next(next) {}
};

class MyLinkedList {
 private:
  Node* head;
  int size;

 public:
  MyLinkedList() {
    head = nullptr;
    size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= size || size == 0) {
      return -1;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
      temp = temp->next;
    }
    return temp->val;
  }

  void addAtHead(int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
      newNode->next = head;
      head = newNode;
    } else {
      head = newNode;
    }
    size++;
  }

  void addAtTail(int val) {
    if (size == 0) {
      addAtHead(val);
    } else {
      Node* temp = head;
      Node* newNode = new Node(val);
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
      size++;
    }
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }
    if (index == size) {
      addAtTail(val);
    } else if (index == 0) {
      addAtHead(val);
    } else {
      Node* newNode = new Node(val);
      Node* temp = head;
      for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
      }
      Node* next = temp->next;
      temp->next = newNode;
      newNode->next = next;
      size++;
    }
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    Node* dummy = new Node();
    dummy->next = head;
    Node* temp = dummy;
    for (int i = 0; i < index; ++i) {
      temp = temp->next;
    }
    Node* toDeleteNode = temp->next;
    temp->next = temp->next->next;
    head = dummy->next;
    delete toDeleteNode;
    size--;
  }
};