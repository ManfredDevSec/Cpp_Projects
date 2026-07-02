
#include <iostream>
#include <string>

struct Task {
    std::string description;
    bool done;
    Task* next;

    Task(std::string desc) : description(std::move(desc)), done(false), next(nullptr) {}
};

class TaskList {
    Task* head;

public:
    TaskList() : head(nullptr) {}

    ~TaskList() {
        Task* current = head;
        while (current != nullptr) {
            Task* next = current->next;
            delete current;
            current = next;
        }
    }

    void addTask(const std::string& description) {
        Task* newTask = new Task(description);
        if (head == nullptr) {
            head = newTask;
            return;
        }
        Task* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTask;
    }

    bool markDone(int index) {
        Task* current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                current->done = true;
                return true;
            }
            current = current->next;
            i++;
        }
        return false;
    }

    bool removeTask(int index) {
        if (head == nullptr) return false;

        if (index == 0) {
            Task* toDelete = head;
            head = head->next;
            delete toDelete;
            return true;
        }

        Task* prev = head;
        int i = 0;
        while (prev->next != nullptr && i < index - 1) {
            prev = prev->next;
            i++;
        }

        if (prev->next == nullptr) return false;

        Task* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        return true;
    }

    void print() const {
        std::cout << "\n--- To-Do List ---\n";
        Task* current = head;
        int i = 0;
        if (current == nullptr) {
            std::cout << "(empty)\n";
        }
        while (current != nullptr) {
            std::cout << i << ". [" << (current->done ? "x" : " ") << "] "
                       << current->description << "\n";
            current = current->next;
            i++;
        }
    }
};

int main() {
    TaskList tasks;
    int choice;

    do {
        std::cout << "\n1. Add task\n2. Mark done\n3. Remove task\n4. Show list\n5. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();
            std::cout << "Task description: ";
            std::string desc;
            std::getline(std::cin, desc);
            tasks.addTask(desc);
        } else if (choice == 2) {
            std::cout << "Index to mark done: ";
            int idx;
            std::cin >> idx;
            if (!tasks.markDone(idx)) std::cout << "Invalid index.\n";
        } else if (choice == 3) {
            std::cout << "Index to remove: ";
            int idx;
            std::cin >> idx;
            if (!tasks.removeTask(idx)) std::cout << "Invalid index.\n";
        } else if (choice == 4) {
            tasks.print();
        }
    } while (choice != 5);

    std::cout << "Goodbye!\n";
    return 0;
}
