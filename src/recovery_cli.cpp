#include <iostream>
#include <string>
#include <unordered_map>
#include "persistent.hpp"
#include "CLI11.hpp"

std::unordered_map<std::string, std::string> keywordToFilename;

int main(int argc, char** argv) {
    CLI::App app{"Recovery Code Grabber CLI"};

    auto set_cmd = app.add_subcommand("set", "Set a filepath + keyword");
    std::string keyword;
    std::string filename;

    set_cmd->add_option("-k,--keyword", keyword, "Keyword for this recovery file")->required();
    set_cmd->add_option("-f,--filename", filename, "Filename that has the recovery codes")->required();

    // auto get_cmd = app.add_subcommand("get", "Get a recovery code");
    // get_cmd->add_option("-u,--username", username, "Username for the recovery code")->required();

    CLI11_PARSE(app, argc, argv);

    if (*set_cmd) {
        saveRecoveryFile(keyword, filename);
        keywordToFilename[keyword] = filename;
        std::cout << "Recovery file set for " << keyword << "." << std::endl;
    }

    // if (*get_cmd) {
    //     if (recoveryCodes.find(username) != recoveryCodes.end()) {
    //         std::cout << "Recovery code for " << username << ": " << recoveryCodes[username] << std::endl;
    //     } else {
    //         std::cout << "No recovery code found for " << username << "." << std::endl;
    //     }
    // }

    return 0;
}
