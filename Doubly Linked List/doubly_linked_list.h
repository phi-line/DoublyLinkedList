// checklist
// node          [X]
// iterator class[X]
//    ++ [X]
//    -- [X]
//    +  [X]
//    += [X]
// push_back     [X]
// remove        [X]
// erase         [/]
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
         for (iterator iter = begin(); iter != iter_end; ++iter) {
            erase(iter);
         }
      };
      DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {};
      DoublyLinkedList(const DoublyLinkedList& other) {
         for (const T& iter : other) {
            push_back(iter);
         }
      };
      DoublyLinkedList(std::initializer_list<T> dll) : DoublyLinkedList() {
         for (auto iter : dll) {
            push_back(iter);
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
//COMPLETED!
   void remove(const T& value) {
      for (iterator iter = begin(); iter != end(); ++iter) {
         if (*iter == value) {
            erase(iter);
            //--iter;
         } else {
            //++iter;
         }
      }
   };
//COMPLETED! (seg fault)
   void erase(iterator pos) {
      if (pos.cur == nullptr){
         return;
      }
      if (list_size == 1){
         pos.cur = head;
         head = nullptr;
         tail = head;
         --list_size;
      }
      else if (pos.cur == head){
         pos.cur->next->prev = nullptr;
         head = pos.cur->next;
         --list_size;
      }
      else if (pos.cur == tail){
         pos.cur->prev->next = nullptr;
         tail = pos.cur->prev;
         --list_size;
      }
      else {
         pos.cur->prev->next = pos.cur->next;
         pos.cur->next->prev = pos.cur->prev;
         --list_size;
      }
      //return pos;
   };

   iterator insert(iterator pos, const T& value) {
      if (list_size == 0){
         push_back(value);
         pos.cur = head;
         pos.prev = nullptr;
         return pos;
      }
      if (pos.cur == head){
         DLLnode *new_head = new DLLnode(value, head, nullptr);
         pos.cur->prev = new_head;
         head = new_head;
         pos.cur = head;
         pos.prev = nullptr;
      } else if (pos.cur == tail){
         DLLnode *new_tail = new DLLnode(value, nullptr, tail);
         pos.cur->next = new_tail;
         tail = new_tail;
         pos.cur = tail;
         pos.prev = tail->prev;
      }
      //default
      else {
         DLLnode *insert_head = pos.cur->prev;
         DLLnode *insert_tail = pos.cur;
         DLLnode *temp_node= new DLLnode (value, insert_tail, insert_head);
         pos.cur->prev->next = temp_node;
         pos.cur->next->prev = temp_node;
         pos.cur = temp_node;
         pos.prev = temp_node->prev;
//         push_back(value);
//         pos.cur = head;
//         pos.prev = nullptr;
      }
      ++list_size;
      return pos;
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
      //reserve(list_size + 1);
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

//if (pos.cur == nullptr){
//   return;
//}
//if (list_size == 1){
//   head = nullptr;
//   tail = nullptr;
//   --list_size;
//}
//else if (pos.cur == head){
//   pos.cur->next->prev = nullptr;
//   head = pos.cur->next;
//   --list_size;
//}
//else if (pos.cur == tail){
//   pos.cur->prev->next = nullptr;
//   tail = pos.cur->prev;
//   --list_size;
//}
//else {
//   pos.cur->prev->next = pos.cur->next;
//   pos.cur->next->prev = pos.cur->prev;
//   --list_size;
//}
#endif /* doubly_linked_list_h */
