
# 📚 C++ Data Structures

This repository contains clear, beginner-friendly implementations of **Core Data Structures** in modern C++. It’s a **work in progress** — the goal is to expand this with more data structures and eventually core algorithms as well.



---

## 📂 Folder Structure

```
C++/
├── .vscode/                         # Local editor settings (optional, git-ignored)
├── build/                           # Compiled binaries (git-ignored)
├── data_structures/
│   ├── binary_tree/
│   │   └── binary_tree.h            # Binary Tree / Binary Search Tree implementation
│   ├── linked_list/
│   │   ├── singly_linked_list.h     # Singly Linked List
│   │   ├── doubly_linked_list.h     # Doubly Linked List
│   │   ├── circular_doubly_linked_list.h  # Circular Doubly Linked List
│   │   └── README.md                # Linked List notes and explanations
│   ├── priority_queue/
│   │   ├── priority_queue_heap.h    # Priority Queue using Heap
│   │   └── priority_queue_list.h    # Priority Queue using Linked List
│   ├── queue/
│   │   ├── array_queue.h            # Queue using array
│   │   ├── linked_list_queue.h      # Queue using linked list
│   │   └── deque.h                  # Double-ended queue
│   └── stack/
│       ├── array_stack.h            # Stack using array
│       └── linked_list_stack.h      # Stack using linked list
├── main.cpp                         # Example usage and testing
├── Makefile                         # Simple build script
├── .gitignore                       # Ignore build output & local configs

```

---

## ✅ Implementations (in progress)

### Singly Linked List
- `add(data)` – Append to end
- `insertAt(index, data)` – Insert at specific index
- `remove(data)` – Remove all occurrences
- `find(data)` – Get index of first match
- `reverse()` – Reverse the list in-place
- `clear()` – Delete all nodes
- `printList()` – Print the list

### Doubly Linked List
- All Singly Linked List methods
- `displayReverse()` – Print list backward

---

## ⚙️ How to Build & Run

```bash
# Build using Makefile
make

# Or compile manually
g++ main.cpp -o build/main

# Run
./build/main
```

---

## 📌 Notes

- `build/` is git-ignored to keep compiled binaries out of your repo.
- `.vscode/` is git-ignored to keep your editor settings personal.
- No external libraries — fully self-contained C++.
- Clean and tested for edge cases like inserting/removing at head/tail.

---

## 🚀 To Do Next

- [ ] Add more data structures (Stacks, Queues, Trees)
- [ ] Add unit tests
- [ ] Document Big-O complexities
- [ ] Automate builds with CI

---

## 🤝 Contributions

Open to pull requests for bug fixes, improvements, or new structures!  
Feel free to fork, modify, and use as you like.

---

## 📜 License

MIT — free for personal or educational use.  
Credit appreciated but not required.
