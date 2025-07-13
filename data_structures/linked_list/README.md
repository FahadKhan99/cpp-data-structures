# Doubly Linked List in C++

This project is a simple implementation of a **doubly linked list** in C++.  
It demonstrates how to manage a dynamic list with nodes that have both `next` and `prev` pointers.

---

## 🚀 **Features**

✅ Add elements to the end of the list  
✅ Insert an element at a specific index  
✅ Remove all occurrences of a given value  
✅ Find the index of the first occurrence of a value  
✅ Display the list in forward and reverse order  
✅ Reverse the list in place  
✅ Clear the entire list  
✅ Destructor to free memory automatically

---

## 🧩 **Files**

- `DoublyLinkedList.cpp` — Contains the full implementation with a test `main()` function.

---

## 🗂️ **How it works**

Each `Node` stores:
- `data` — an integer value
- `next` — pointer to the next node
- `prev` — pointer to the previous node

The `LinkedList` class keeps track of:
- `first` — pointer to the first node
- `last` — pointer to the last node
- `size` — total number of elements

---

## 🛠️ **How to compile and run**

```bash
# Compile
g++ DoublyLinkedList.cpp -o linkedlist

# Run
./linkedlist
