# Library Management System

A small console application modeling a library catalog using inheritance and
polymorphism.

## Concepts demonstrated
- Base class (`LibraryItem`) and derived classes (`PrintedBook`, `EBook`)
- Virtual functions and runtime polymorphism (`display()`)
- `std::unique_ptr` for ownership of heterogeneous objects
- Encapsulation (protected members, public interface)

## How it works
`Library` stores a collection of `LibraryItem` pointers. Even though the
collection holds different concrete types (`PrintedBook`, `EBook`), calling
`item->display()` runs the correct overridden version for each — a classic
polymorphism example.

## Build & run

```bash
g++ -std=c++17 -o library main.cpp
./library
```

## Sample output

```
--- Library Catalog (3 items) ---
"The Hobbit" by J.R.R. Tolkien [available] - Printed, 310 pages
"Clean Code" by Robert C. Martin [available] - Printed, 464 pages
"Effective C++" by Scott Meyers [available] - EBook, 4.2 MB

Checking out "The Hobbit"...

--- Library Catalog (3 items) ---
"The Hobbit" by J.R.R. Tolkien [checked out] - Printed, 310 pages
"Clean Code" by Robert C. Martin [available] - Printed, 464 pages
"Effective C++" by Scott Meyers [available] - EBook, 4.2 MB
```

## Possible extensions
- Add a `Member` class and track who has each item checked out
- Add due dates and overdue detection
- Persist the catalog to a file
