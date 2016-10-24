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

using namespace std;

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
//TEST REVERSE ITERATOR
   std::cout << ("\nTESING REVERSE ITERATOR\n");
   DoublyLinkedList<std::string> BW_sentence = {"backwards!", "are", "words", "These"};
   for (auto iter = BW_sentence.rbegin(), iter_end = BW_sentence.rend(); iter != iter_end; ++iter){
      std::cout << *iter << " ";
   }
   std::cout << "\nsize is: " << BW_sentence.size() << "\n";
//TEST REMOVE FUNCTION
   std::cout << "\nTESTING REMOVE\n";
   for (const std::string& word : words) std::cout << word << " ";
   std::cout << "\nremoving lists\n";
   words.remove("lists");
   for (const std::string& word : words) std::cout << word << " ";
   std::cout << "\nremoving syntax\n";
   words.remove("syntax");
   for (const std::string& word : words) std::cout << word << " ";
   std::cout << "\nremoving initalizer\n";
   words.remove("initializer");
   for (const std::string& word : words) std::cout << word << " "; std::cout << "\nsize is: " << words.size() << "\n";
//TEST HIS REMOVE
   cout << "\nTESTING FISH REMOVE\n";
   DoublyLinkedList<std::string> fish = {"fish", "red", "fish", "blue", "fish", "big", "fish", "small", "fish"};
   for (const std::string& word : fish) { cout << word << " "; }
   cout << "\nsize is: " << fish.size() << "\n"; fish.remove("blue");
   for (const std::string& word : fish) { cout << word << " "; }
   cout << "\nsize is now: " << fish.size() << "\n"; fish.remove("fish");
   for (const std::string& word : fish) { cout << word << " "; }
   cout << "\nsize is finally: " << fish.size() << "\n";

//TEST REMOVE ONE
   cout << "\nTESTING REMOVE ONE\n";
   DoublyLinkedList<std::string> uno = {"oneThing"};
   for (const std::string& word : uno) { cout << word << " "; }
   std::cout << "\nremoving oneThing\n";
   uno.remove("oneThing"); cout << "\nsize is now: " << uno.size() << "\n";

//TEST INSERT ONE
   cout << "\nTESTING INSERT ONE";
   for (const std::string& word : uno) { cout << word << " "; }
   std::cout << "\ninsterting otherThing\n";
   uno.insert(uno.begin(), "otherThing");
   for (const std::string& word : uno) { cout << word << " "; }
   cout << "\nsize is finally: " << uno.size() << "\n";
//TEST INSERT MANY
   cout << "\nTESTING INSERT MANY\n";
   DoublyLinkedList<std::string> subject = {"the", "trees"};
   for (const std::string& word : subject) { cout << word << " "; }
   subject.insert(subject.end(), "flow");
   subject.insert(subject.end(), "in");
   subject.insert(subject.end(), "the");
   subject.insert(subject.end(), "wind");
   subject.insert(subject.end(), "wistfully");
   cout << endl;
   for (const std::string& word : subject) { cout << word << " "; }
   cout << "\nsize is finally: " << subject.size() << "\n";
   return 0;
}


