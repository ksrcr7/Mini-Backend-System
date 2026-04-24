#include "TaskController.h"
#include <stdexcept>

backend::TaskController::TaskController(backend::TaskService &sv) : service(sv){}

backend::TaskController::Command backend::TaskController::pars(const std::string &input) {

    std::vector<std::string> tokens;
    std::string current;
    bool inQuotes = false;

    for (char c : input) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ' ' && !inQuotes) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }
        else {
            current += c;
        }
    }


    if (inQuotes) {
        throw std::runtime_error("Unclosed quote in input");
    }


    if (!current.empty()) {
        tokens.push_back(current);
    }


    if (tokens.size() < 2) {
        throw std::runtime_error("Invalid command");
    }


    if (tokens[0] != "task") {
        throw std::runtime_error("Command must start with 'task'");
    }

    Command cmd;
    cmd.action = tokens[1];


    for (size_t i = 2; i < tokens.size(); ++i) {
        cmd.args.push_back(tokens[i]);
    }

    return cmd;


}

