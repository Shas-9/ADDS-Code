#include<iostream>
using namespace std;

class Node {
  public:
  int value;
  Node* next;
};

// can i store the pointers to each node in an array and then use that to sort a linked list?????
// BIG BRAIN TIME

// inserts a new node at the beginning of the linked list
void insertBeginning(Node** head, int newValue) {
  // create new node
  Node* newHead = new Node();
  newHead->value = newValue;
  // new node should point to head
  newHead->next = *head;
  // new node is the new head
  *head = newHead;
}

// inserts a new node at end of linked list
void insertEnd(Node** head, int newValue) {
  // create new node
  Node* newNode = new Node();
  newNode->value = newValue;
  newNode->next = NULL;

  // assign pointer to first node
  Node* pointer = *head;
  while(pointer->next != NULL) {
    // if not last node, move on to next node
    pointer = pointer->next;
  }
  // make last node point to new node
  pointer->next = newNode;
}

// creates a linked list with n nodes
Node* createLinkedList(int n) {
  Node* head = new Node();
  head->value = 1;
  Node* x = new Node();
  head->next = x;

  for(int i = 2; i<n; i++) {
    x->value = i;
    x->next = new Node;
    x = x->next;
  }
  x->value = n;
  x->next = NULL;
  return head;
}

// prints a linked list
void printList(Node* pointer) {
  while (pointer != NULL) {
    cout << pointer->value << " ";
    pointer = pointer->next;
  }
  cout<<endl;
}