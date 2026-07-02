
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<int> grades;
};

double calculateAverage(const Student& s) {
    if (s.grades.empty()) return 0.0;
    int sum = std::accumulate(s.grades.begin(), s.grades.end(), 0);
    return static_cast<double>(sum) / s.grades.size();
}

char letterGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

int findHighest(const std::vector<Student>& students) {
    int maxIndex = 0;
    double maxAvg = -1;
    for (size_t i = 0; i < students.size(); i++) {
        double avg = calculateAverage(students[i]);
        if (avg > maxAvg) {
            maxAvg = avg;
            maxIndex = static_cast<int>(i);
        }
    }
    return maxIndex;
}

void printReport(const std::vector<Student>& students) {
    std::cout << "\n----- Class Report -----\n";
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(10) << "Average"
              << "Grade\n";
    std::cout << "-------------------------------\n";

    for (const auto& s : students) {
        double avg = calculateAverage(s);
        std::cout << std::left << std::setw(15) << s.name
                   << std::setw(10) << std::fixed << std::setprecision(2) << avg
                   << letterGrade(avg) << "\n";
    }

    if (!students.empty()) {
        int topIndex = findHighest(students);
        std::cout << "\nTop student: " << students[topIndex].name
                   << " (" << std::fixed << std::setprecision(2)
                   << calculateAverage(students[topIndex]) << ")\n";
    }
}

Student inputStudent() {
    Student s;
    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, s.name);

    std::cout << "How many grades for " << s.name << "? ";
    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        int grade;
        std::cout << "  Grade " << (i + 1) << ": ";
        std::cin >> grade;
        s.grades.push_back(grade);
    }
    return s;
}

int main() {
    std::vector<Student> students;
    int choice;

    do {
        std::cout << "\n=== Student Grade Manager ===\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Show report\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                students.push_back(inputStudent());
                break;
            case 2:
                printReport(students);
                break;
            case 3:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 3);

    return 0;
}
