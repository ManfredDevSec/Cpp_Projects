# Linked List To-Do App

A console to-do list backed by a hand-built singly linked list — no
`std::vector` or `std::list` used, so the data structure mechanics are fully
visible.

## Concepts demonstrated
- Manual node-based linked list (`struct Task` with a `next` pointer)
- Raw pointers and manual memory management (`new` / `delete`)
- Class-managed resource cleanup (destructor frees every node)
- Classic list operations: insert at tail, delete by index, traverse

## How it works
Each `Task` is a node holding a description, a done flag, and a pointer to
the next task. `TaskList` keeps a `head` pointer and implements add, remove,
mark-done, and print by walking the list — the same way `std::list` works
internally, just exposed directly.

## Build & run

```bash
g++ -std=c++17 -o todo main.cpp
./todo
```

## Sample session

```
1. Add task
2. Mark done
3. Remove task
4. Show list
5. Exit
Choice: 1
Task description: Finish LV100 assignment

Choice: 1
Task description: Push sample projects to GitHub

Choice: 2
Index to mark done: 0

Choice: 4

--- To-Do List ---
0. [x] Finish LV100 assignment
1. [ ] Push sample projects to GitHub
```

## Possible extensions
- Convert to a doubly linked list for backward traversal
- Add priority levels and sort by priority
- Persist tasks to a file between runs
