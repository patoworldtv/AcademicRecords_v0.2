#include "StudentListGenerator.h"
#include <fstream>
#include <random>
#include <filesystem>
#include <vector>

void StudentListGenerator::generateFiles(int fileCount, int studentsPerFile, const std::string& folder) {
    std::vector<std::string> firstNames = {"John", "Jane", "Mary", "Alice", "Bob"};
    std::vector<std::string> lastNames = {"Smith", "Doe", "Black", "White", "Brown"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> idDist(1000000, 9999999);
    std::uniform_real_distribution<> gpaDist(0.0, 4.0);

    std::filesystem::create_directories(folder);

    for (int f = 0; f < fileCount; ++f) {
        std::string fileName = folder + "/students" + std::to_string(studentsPerFile * (f + 1)) + ".txt";
        std::ofstream out(fileName);
        if (!out.is_open()) continue;

        for (int i = 0; i < studentsPerFile; ++i) {
            std::string first = firstNames[gen() % firstNames.size()];
            std::string last = lastNames[gen() % lastNames.size()];
            int id = idDist(gen);
            double gpa = gpaDist(gen);
            out << first << " " << last << " " << id << " " << gpa << "\n";
        }
        out.close();
    }
}
