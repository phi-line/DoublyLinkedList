//
//  main.cpp
//  Doubly Linked List
//
//  Created by admin on 10/9/16.
//  Copyright © 2016 admin. All rights reserved.
//

#include <iostream>

#include "doubly_linked_list.h"

// Simple main program that tests that the following methods work:
// DoublyLinkedList();  // default constructor
// DoublyLinkedList::push_back;
// DoublyLinkedList::begin();
// const T&amp; iterator::operator*() const;
int main() {
   DoublyLinkedList<std::string> mylist;
   mylist.push_back("first");
   mylist.push_back("second");
   DoublyLinkedList<std::string>::iterator myiterator = mylist.begin();
   if (*myiterator != "first") {
      std::cout << "Oh no!  Expected *myiterator == \"first\", "
      << "but actually *myiterator == " << *myiterator << std::endl;
   }
   return 0;
}
