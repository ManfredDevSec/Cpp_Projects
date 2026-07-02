# LV100 C++ Projects

Small C++ projects from my LV100 coursework, covering core language
fundamentals, object-oriented programming, and data structures.

## Projects

| Project | Concepts | Description |
|---|---|---|
| [student-grade-manager](./student-grade-manager) | Structs, vectors, functions | Tracks students and grades, computes averages and letter grades |
| [library-management-system](./library-management-system) | Classes, inheritance, polymorphism | Console library catalog with `PrintedBook` and `EBook` item types |
| [linked-list-todo](./linked-list-todo) | Linked lists, pointers, manual memory management | To-do list built on a hand-written singly linked list |

Each project folder has its own `README.md` with build instructions and
sample output.

## Requirements
- A C++17-compatible compiler (e.g. `g++`, `clang++`)

## Build & run any project

```bash
cd <project-folder>
g++ -std=c++17 -o app main.cpp
./app
```

## About

Written while learning C++ in LV100. Kept intentionally small and readable
to focus on demonstrating specific concepts rather than building a full
application.
