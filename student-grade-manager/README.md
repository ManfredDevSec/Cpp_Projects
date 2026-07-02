# Student Grade Manager

A console-based C++ program that tracks students and their grades, computes
averages, and generates a simple class report.

## Concepts demonstrated
- Structs (`Student`)
- `std::vector` for dynamic collections
- Functions with pass-by-reference (`const Student&`)
- Loops and conditional logic
- `<algorithm>` / `<numeric>` usage (`std::accumulate`)
- Formatted console output (`<iomanip>`)

## How it works
1. Add one or more students, each with a name and a list of numeric grades.
2. View a report showing each student's average and letter grade (A–F).
3. The report also highlights the top-performing student.

## Build & run

```bash
g++ -std=c++17 -o grade_manager main.cpp
./grade_manager
```

## Sample session

```
=== Student Grade Manager ===
1. Add student
2. Show report
3. Exit
Choice: 1
Enter student name: Ama
How many grades for Ama? 3
  Grade 1: 88
  Grade 2: 92
  Grade 3: 79

Choice: 2

----- Class Report -----
Name           Average   Grade
-------------------------------
Ama            86.33     B

Top student: Ama (86.33)
```

## Possible extensions
- Save/load students from a file
- Support weighted grades (assignments vs exams)
- Sort students by average
