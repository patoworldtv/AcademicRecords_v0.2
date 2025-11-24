#include "StudentListOperations.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Person> StudentListOperations::readFile(const std::string& path) {
    std::vector<Person> students;
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open file " << path << "\n";
        return students;
    }

    std::string line;
    Person temp;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> temp;
        students.push_back(temp);
    }
    return students;
}

void StudentListOperations::writeFile(const std::string& path, const std::vector<Person>& students) {
    std::ofstream out(path);
    if (!out.is_open()) {
        std::cerr << "ERROR: Cannot write to file " << path << "\n";
        return;
    }

    for (const auto& s : students) {
        out << s.getName() << " " << s.getSurname() << " " << s.getExam() << "\n";
    }
}

std::vector<Person> StudentListOperations::filterByGPA(const std::vector<Person>& students, double threshold) {
    std::vector<Person> result;
    for (const auto& s : students) {
        if (s.finalAvg() > threshold) result.push_back(s);
    }
    return result;
}

void StudentListOperations::splitByGPA(const std::vector<Person>& students, double threshold,
                                       std::vector<Person>& above, std::vector<Person>& below) {
    for (const auto& s : students) {
        if (s.finalAvg() > threshold)
            above.push_back(s);
        else
            below.push_back(s);
    }
}
