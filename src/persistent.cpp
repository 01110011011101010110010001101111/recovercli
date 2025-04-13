#include <fstream>
#include <unordered_map>
#include <iostream>

#define FILENAME "recovery_codes.txt"

void loadRecoveryFile(std::unordered_map<std::string, std::string>& keywordToFilename) 
{
    std::ifstream infile(FILENAME);
    std::string keyword, filename;

    while (infile >> keyword >> filename) {
        keywordToFilename[keyword] = filename;
    }
}

void saveRecoveryFile(std::string keyword, std::string filename)
{
    // append mode
    std::ofstream outfile(FILENAME, std::ios::app);

    if (outfile.is_open()) {
        outfile << keyword << " " << filename << std::endl;
    } else {
        std::cerr << "Error opening file " << filename << " for writing!" << std::endl;
    }
}
