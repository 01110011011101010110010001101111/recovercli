#include <iostream>
#include <string>
#include <unordered_map>
#include "persistent.hpp"
#include "parse_code.hpp"
#include "CLI11.hpp"

std::unordered_map<std::string, std::string> keywordToFilename;

int main(int argc, char** argv) {
    CLI::App app{"Recovery Code Grabber CLI"};

    auto set_cmd = app.add_subcommand("set", "Set a filepath + keyword");
    std::string keyword_set, filename;
    set_cmd->add_option("-k,--keyword", keyword_set, "Keyword for this recovery file")->required();
    set_cmd->add_option("-f,--filename", filename, "Filename that has the recovery codes")->required();

    auto get_cmd = app.add_subcommand("get", "Get a recovery code");
    std::string keyword_get;
    get_cmd->add_option("-k,--keyword", keyword_get, "Keyword to retrieve the recovery code")->required();


    CLI11_PARSE(app, argc, argv);

    if (*set_cmd) {
        saveRecoveryFile(keyword_set, filename);
        keywordToFilename[keyword_set] = filename;
        std::cout << "Recovery file set for " << keyword_set << "." << std::endl;
    }

    if (*get_cmd) {
        // TODO: make this not run every file
        loadRecoveryFile(keywordToFilename);
        if (keywordToFilename.find(keyword_get) != keywordToFilename.end()) {
            filename = keywordToFilename[keyword_get];
            processFile(filename);
        } else {
            std::cout << "No recovery code found for " << keyword_get << "." << std::endl;
        }
    }

    return 0;
}
