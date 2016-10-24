//
//  main.cpp
//  Doubly Linked List
//
//  Created by admin on 10/9/16.
//  Copyright © 2016 admin. All rights reserved.
//

#include <iostream>
#include <string>

#include "doubly_linked_list.h"

// Simple main program that tests that the following methods work:
// DoublyLinkedList();  // default constructor
// DoublyLinkedList::push_back;
// DoublyLinkedList::begin();
// const T&amp; iterator::operator*() const;
int main() {
   DoublyLinkedList<std::string> words = {"initializer", "lists", "have", "nice", "syntax"};
//TEST PUSH BACK
   std::cout << "TESTING PUSH BACK\n";
   for (const std::string& word : words) std::cout << word << " "; std::cout << "\nsize is: " << words.size() << "\n";
//TEST REMOVE FUNCTION
   std::cout << "\nTESTING REMOVE\n";
   words.remove("lists");
   words.remove("syntax");
   words.remove("initalizer");
   for (const std::string& word : words) std::cout << word << " "; std::cout << "\nsize is: " << words.size() << "\n";
//TEST REVERSE ITERATOR
   std::cout << ("\nTESING REVERSE ITERATOR\n");
   DoublyLinkedList<std::string> BW_sentence = {"backwards!", "are", "words", "These"};
   for (auto iter = BW_sentence.rbegin(), iter_end = BW_sentence.rend(); iter != iter_end; ++iter){
      std::cout << *iter << " ";
   }
   std::cout << "\nsize is: " << BW_sentence.size() << "\n";

   return 0;
}


