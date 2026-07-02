
#include <iostream>
#include <string>
#include <vector>

struct ProjectInfo {
    std::string name;
    std::string folder;
    std::string concepts;
};

void printProjects(const std::vector<ProjectInfo>& projects) {
    std::cout << "=== LV100 C++ Projects ===\n\n";
    for (size_t i = 0; i < projects.size(); i++) {
        std::cout << i + 1 << ". " << projects[i].name << "\n";
        std::cout << "   Folder:   " << projects[i].folder << "\n";
        std::cout << "   Concepts: " << projects[i].concepts << "\n\n";
    }
    std::cout << "To build and run any project:\n";
    std::cout << "  cd <folder>\n";
    std::cout << "  g++ -std=c++17 -o app main.cpp\n";
    std::cout << "  ./app\n";
}

int main() {
    std::vector<ProjectInfo> projects = {
        {"Student Grade Manager", "student-grade-manager",
         "structs, vectors, functions"},
        {"Library Management System", "library-management-system",
         "classes, inheritance, polymorphism"},
        {"Linked List To-Do App", "linked-list-todo",
         "linked lists, pointers, manual memory management"}
    };

    printProjects(projects);
    return 0;
}
