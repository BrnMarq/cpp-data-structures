#include <iostream>
#include "dnode.hpp"

int main() {
  DNode<int> head = 3;
  DNode<int> test = 5;
  DNode<int> test2 = 8;
  DNode<int> test3 = 9;
  DNode<int> test4 = 10;

  head.insertPrev(&test);
  head.insertPrev(&test2);
  head.insertPrev(&test3);
  head.insertPrev(&test4);

  auto [left, right] = head.split();
  left->printList();
  right->printList();

  // DNode<int> head2 = 7;
  // DNode<int> tes3 = 1;
  // DNode<int> test4 = 2;

  // head2.insertNext(&tes3);
  // head2.insertNext(&test4);
  // head2.printList();

  // head.swap(&head2);
  // head.printList();
  // head2.printList();
  // head.concat(&head2);
  // head.printList();
};