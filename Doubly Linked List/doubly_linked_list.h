// checklist
// node          [X]
// iterator class[ ]
//    ++ [ ]
//    -- [ ]
//    +  [X]
//    += [X]
// push_back     [X]
// remove        [ ]
// erase         [ ]
// insert        [ ]
// iterators     [X]


#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include <initializer_list>

// DLLnode is the core of the LinkedList class.
// It holds the data and actually points to the next element.
// The only reason it couldn't be used to represent the entire class, is that
// it doesn't contain a pointer to the last node.
template <typename T>
class DLLnode {
public:
   DLLnode() : value(nullptr), next(nullptr), prev(nullptr) {};
   DLLnode(const T& value, DLLnode *next, DLLnode *prev)
      : value(value), next(next), prev(prev) {}
   T value;
   DLLnode *next;
   DLLnode *prev;
};

template <typename T>
class DoublyLinkedList {
         DLLnode<T> *head, *tail;
         int list_size;
   public:
      class iterator {
         DLLnode<T> *cur;
         DLLnode<T> *prev;
         bool reversed;
      public:
         iterator(DLLnode<T>* cur, DLLnode<T>* prev, bool reversed = false)
            : cur(cur), prev(prev), reversed(reversed) {}
         iterator& operator++(){
            if (!reversed)
               cur = cur->next;
            else
               cur = cur->prev;
            return *this;
         };
         iterator& operator--(){
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

      DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {};
      DoublyLinkedList(const DoublyLinkedList& other);
      DoublyLinkedList(std::initializer_list<T>);
   //~DoublyLinkedList();

      //noexcept wont throw and exception
      int size() const noexcept {return list_size;};
//COMPLETED!
      void push_back(const T& value) {
         //empty list
         if (list_size == 0){
            head = new DLLnode<T>(value, nullptr, nullptr);
            tail = head;
         }
         else {
            DLLnode<T> *new_tail = new DLLnode<T>(value, nullptr, tail);
            tail -> next = new_tail;
            tail = new_tail;
         }
      }
//      void test_push_back(){
//         for (DLLnode<T> *cur = head; cur != nullptr; cur = cur->next){}
//      }
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
      void remove(const T& value) {
         for (iterator itr = begin(); itr != end();) {
            if (*itr == value) {
               erase(itr);
               itr = begin();
            } else {
               ++itr;
            }
         }
      };

      iterator erase(iterator pos) {
         DLLnode<T> *temp = pos.cur;
         if (pos.cur){
            DLLnode<T> *head = pos.cur->prev;
            DLLnode<T> *prev = pos.cur->next;
         } else {
            DLLnode<T> *head = nullptr;
            DLLnode<T> *prev = nullptr;
         }
         head && (head->next = tail);
         tail && (tail->prev = head);

         if (!pos.reversed) {
            pos.cur = tail;
            pos.prev = head;
         } else {
            pos.cur = head;
            pos.cur = tail;
         }

         if (!pos.prev && pos.cur) {
            head = pos.cur;
         } else if (!pos.cur && pos.prev){
            tail = pos.cur;
         }

         delete temp;
         list_size--;
         return pos;
      };
//from VECTOR CLASS
//should work exactly like this!!
/*
      iterator insert(iterator cur, const T& value) {
         //reserve(size_ + 1);
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
//COMPLETED!
      iterator begin() {
         return iterator(head, nullptr, false);
      }
      iterator end() {
         return iterator(tail, nullptr, false);
      }
      //from LINKED LIST CLASS
      iterator rbegin(){
         return iterator(nullptr, tail, true);
      }
      iterator rend()  {
         return iterator(nullptr, head, true);
      };
};

#endif /* doubly_linked_list_h */
