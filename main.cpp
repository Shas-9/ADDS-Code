#include<iostream>
using namespace std;
#include "linkedlist.h"


int main() {
  Node* head = createLinkedList(21);
  printList(head);
  insertBeginning(&head, 0);
  printList(head);
  insertEnd(&head, 22);
  printList(head);

  Node* meow = new Node();
  for(int i = 1; i < 11; i++) {
    insertEnd(&meow, i);
  }
  printList(meow);

  return 0;
}