#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void processFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string firstLine;
    std::vector<std::string> lines;
    int lineCount = 0;

    // parse through the data
    while (std::getline(infile, firstLine)) {
        if (lineCount == 0) {
            std::cout << firstLine << std::endl;
        } else {
            lines.push_back(firstLine);
        }
        lineCount++;
    }

    infile.close();

    if (lineCount == 0) {
        std::cout << "empty file! no codes left!" << std::endl;
        return;
    }

    std::cout << (lineCount - 1) << " codes left!" << std::endl;

    // write back
    std::ofstream outfile(filename);
    for (const auto& line : lines) {
        outfile << line << std::endl;
    }
    outfile.close();
}
