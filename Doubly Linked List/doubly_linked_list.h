// checklist
// node          [X]
// iterator class[X]
//    ++ [X]
//    -- [X]
//    +  [X]
//    += [X]
// push_back     [X]
// remove        [ ]
// erase         [ ]
// insert        [ ]
// iterator func [X]


#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include <initializer_list>

// DLLnode is the core of the LinkedList class.
// It holds the data and actually points to the next element.
// The only reason it couldn't be used to represent the entire class, is that
// it doesn't contain a pointer to the last node.
template <typename T>
class DoublyLinkedList {
   private:
      class DLLnode {
      public:
         DLLnode() : value(nullptr), next(nullptr), prev(nullptr) {};
         DLLnode(const T& value, DLLnode *next, DLLnode *prev)
         : value(value), next(next), prev(prev) {}
         T value;
         DLLnode *next;
         DLLnode *prev;
         friend class DoublyLinkedList;
      };
      DLLnode *head, *tail;
      int list_size;
   public:
      class iterator {
         DLLnode *cur;
         DLLnode *prev;
         bool reversed;
      public:
         iterator(DLLnode* cur, DLLnode* prev, bool reversed = false)
            : cur(cur), prev(prev), reversed(reversed) {}
         iterator & operator++(){
            if (!reversed)
               cur = cur->next;
            else
               cur = cur->prev;
            return *this;
         };
         iterator & operator--(){
            if (!reversed)
               cur = cur->prev;
            else
               cur = cur->next;
            return *this;
         };
         const T& operator*() const {
            return cur->value;
         }
         bool operator!=(const iterator& other) {  // myiter != other_iter
            return cur != other.cur;
         }
         friend class DoublyLinkedList;
      };

      ~DoublyLinkedList() {
         auto iter_end = end();
         for (iterator itr = begin(); itr != iter_end; ++itr) {
            erase(itr);
         }
      };
      DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {};
      DoublyLinkedList(const DoublyLinkedList& other) {
         for (const T& itr : other) {
            push_back(itr);
         }
      };
      DoublyLinkedList(std::initializer_list<T> dll) : DoublyLinkedList() {
         for (auto itr : dll) {
            push_back(itr);
         }
      };

   //noexcept wont throw and exception
   int size() const noexcept {return list_size;};
//COMPLETED!
   void push_back(const T& value) {
      //if empty list make a new node with value and assign head and tail
      if (list_size == 0){
         head = new DLLnode(value, nullptr, nullptr);
         tail = head;
      }
      else {
         DLLnode *new_tail = new DLLnode(value, nullptr, tail);
         tail -> next = new_tail;
         tail = new_tail;
      }
      ++list_size;
   }
//      void test_push_back(){
//         for (DLLnode<T> *cur = head; cur != nullptr; cur = cur->next){}
//      }

   void remove(const T& value) {
      iterator iter_end = end();
      for (iterator itr = begin(); itr != iter_end;) {
         if (*itr == value) {
            itr = erase(itr);
            --itr;
         } else {
            ++itr;
         }
      }
   };

   iterator erase(iterator cur) {
      if (list_size == 0) {
         return end();
      }
      else if (list_size == 1){
         cur = end();
         --list_size;
      }
      //if cur head or end
      else if (cur.prev == begin()){

      }
      else if (cur->tail == end()){
         return;
      }
      //default case
      else {

      }
      return cur;
   };

   iterator insert(iterator cur, const T& value) {
      return cur;
   }
//COMPLETED!
   //iterator (current, previous, isReversed);
   iterator begin() {
      return iterator(head, nullptr, false);
   }
   iterator end() {
      return iterator(nullptr, nullptr, false);
   }
   iterator rbegin(){
      return iterator(tail, nullptr, true);
   }
   iterator rend()  {
      return iterator(nullptr, nullptr, true);
   };
//from VECTOR CLASS
/*
iterator erase(iterator position) {
   iterator iter_end = end();
   iterator cur = position, next = position;
   // Erase this value at position by copying everything over it.
   for (++next; next != iter_end; ++next, ++cur) {
      *cur = *next;
   }
   return position;
}
*/
//from VECTOR CLASS
/*
void remove(const T& val) {
   iterator iter_end = end();
   for (iterator iter = begin(); iter != iter_end;) {
      if (*iter == val) {
         iter = erase(iter);
      } else {
         ++iter;
      }
   }
}
*/
//from VECTOR CLASS
//should work exactly like this!!
/*
   iterator insert(iterator cur, const T& value) {
      //reserve(list_size_ + 1);
      cur = end();
      iterator prev = cur;
      // Copy everything over to make room to insert value at position.
      for (--prev; cur != cur; --cur, --prev) {
         *cur = *prev;
      }
      *cur = value;
      ++cur;
      return cur;
   }
*/
};

#endif /* doubly_linked_list_h */
