#ifndef PERSISTENT
#define PERSISTENT_H

void loadRecoveryFile(std::unordered_map<std::string, std::string>& keywordToFilename);

void saveRecoveryFile(std::string keyword, std::string filename);

#endif // PERSISTENT_H
