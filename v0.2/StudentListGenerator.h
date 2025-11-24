#ifndef STUDENTLISTGENERATOR_H
#define STUDENTLISTGENERATOR_H

#include <string>

class StudentListGenerator {
public:
    void generateFiles(int fileCount, int studentsPerFile, const std::string& folder);
};

#endif
