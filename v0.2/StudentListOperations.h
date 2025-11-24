#ifndef STUDENTLISTOPERATIONS_H
#define STUDENTLISTOPERATIONS_H

#include <vector>
#include <string>
#include "Person.h"

class StudentListOperations {
public:
    std::vector<Person> readFile(const std::string& path);
    void writeFile(const std::string& path, const std::vector<Person>& students);
    std::vector<Person> filterByGPA(const std::vector<Person>& students, double threshold);
    void splitByGPA(const std::vector<Person>& students, double threshold,
                    std::vector<Person>& above, std::vector<Person>& below);
};

#endif
