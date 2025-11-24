#include <iostream>
#include <vector>
#include <iomanip>
#include <exception>
#include "Person.h"
#include "StudentListGenerator.h"
#include "StudentListOperations.h"
#include "utils/helpers.h"

void printMenu() {
    std::cout << "\n===== Academic Records v0.2 =====\n";
    std::cout << "1. Generate random student files\n";
    std::cout << "2. Load students from file\n";
    std::cout << "3. Display students with GPA > 3.0\n";
    std::cout << "4. Split students by GPA threshold\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    StudentListGenerator generator;
    StudentListOperations operations;
    std::vector<Person> students;
    int choice;

    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    int fileCount, studentsPerFile;
                    std::cout << "How many files to generate? ";
                    std::cin >> fileCount;
                    std::cout << "How many students per file? ";
                    std::cin >> studentsPerFile;
                    generator.generateFiles(fileCount, studentsPerFile, "data");
                    std::cout << "SUCCESS: Files generated in ./data\n";
                    break;
                }
                case 2: {
                    std::string path;
                    std::cout << "Enter file path (example: data/students10000.txt): ";
                    std::cin >> path;
                    if (!fileExists(path)) throw std::runtime_error("File does not exist!");
                    students = operations.readFile(path);
                    std::cout << "Loaded " << students.size() << " students.\n";
                    break;
                }
                case 3: {
                    if (students.empty()) {
                        std::cout << "No students loaded. Load a file first.\n";
                        break;
                    }
                    auto filtered = operations.filterByGPA(students, 3.0);
                    std::cout << "\n--- Students with GPA > 3.0 ---\n";
                    for (const auto& s : filtered) {
                        std::cout << s << "\n";
                    }
                    break;
                }
                case 4: {
                    if (students.empty()) {
                        std::cout << "No students loaded. Load a file first.\n";
                        break;
                    }
                    double threshold;
                    std::cout << "Enter GPA threshold: ";
                    std::cin >> threshold;
                    std::vector<Person> above, below;
                    operations.splitByGPA(students, threshold, above, below);
                    operations.writeFile("data/students_above.txt", above);
                    operations.writeFile("data/students_below.txt", below);
                    std::cout << "Split complete. Results saved to data/students_above.txt and data/students_below.txt\n";
                    break;
                }
                case 5:
                    std::cout << "Goodbye!\n";
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "ERROR: " << e.what() << "\n";
        }
    }
}
