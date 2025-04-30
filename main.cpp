#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

// Evaluate simple conditions like: when user_age < 18
bool evaluateCondition(const std::string &varName, const std::string &op, const std::string &valueStr, const std::unordered_map<std::string, std::string> &vars) {
    if (vars.find(varName) == vars.end()) return false;

    int varVal;
    try {
        varVal = std::stoi(vars.at(varName));  // Convert to integer
    } catch (std::invalid_argument&) {
        return false;  // Handle invalid input
    }

    int cmpVal;
    try {
        cmpVal = std::stoi(valueStr);  // Convert to integer
    } catch (std::invalid_argument&) {
        return false;  // Handle invalid input
    }

    if (op == "<") return varVal < cmpVal;
    if (op == "<=") return varVal <= cmpVal;
    if (op == "==") return varVal == cmpVal;
    if (op == "!=") return varVal != cmpVal;
    if (op == ">=") return varVal >= cmpVal;
    if (op == ">") return varVal > cmpVal;

    return false;
}

// Handle say statements, including string + variable support
void processSayLine(const std::string &line, const std::unordered_map<std::string, std::string> &variables) {
    std::string toSay = line.substr(4); // skip "say "
    std::string output;

    std::istringstream ss(toSay);
    std::string token;
    while (std::getline(ss, token, '+')) {
        token.erase(remove(token.begin(), token.end(), ' '), token.end()); // trim spaces

        if (token.front() == '"' && token.back() == '"') {
            output += token.substr(1, token.size() - 2); // remove quotes
        } else if (variables.count(token)) {
            output += variables.at(token);
        } else {
            output += "[undefined]";
        }
    }

    std::cout << output << std::endl;
}

// Main execution function
void executeHumanLang(std::ifstream &file) {
    std::string line;
    std::unordered_map<std::string, std::string> variables;

    while (std::getline(file, line)) {
        // Trim leading/trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.find("say") == 0) {
            processSayLine(line, variables);
        }
        else if (line.find("wait for the user to type something") != std::string::npos) {
            size_t pos = line.find("call it");
            if (pos != std::string::npos) {
                std::string varName = line.substr(pos + 7);
                varName.erase(0, varName.find_first_not_of(" \t"));
                std::cout << "Please enter a value for " << varName << ": ";
                std::string userInput;
                std::getline(std::cin, userInput);
                variables[varName] = userInput;
            }
        }
        else if (line.find("when") == 0 && line.find(":") != std::string::npos) {
            std::istringstream iss(line.substr(4)); // skip "when "
            std::string varName, op, value;
            iss >> varName >> op >> value;

            bool result = evaluateCondition(varName, op, value, variables);

            std::getline(file, line); // line under "when"
            line.erase(0, line.find_first_not_of(" \t"));
            if (result && line.find("say") == 0) {
                processSayLine(line, variables);
                std::getline(file, line); // skip "otherwise" line
            } else {
                std::getline(file, line); // skip current block
                line.erase(0, line.find_first_not_of(" \t"));
                if (line.find("say") == 0) {
                    processSayLine(line, variables);
                }
            }
        }
        else if (line.find("otherwise") == 0 && line.find(":") != std::string::npos) {
            std::getline(file, line); // line after "otherwise:"
            line.erase(0, line.find_first_not_of(" \t"));
            if (line.find("say") == 0) {
                processSayLine(line, variables);
            }
        }
    }
}

int main() {
    std::ifstream file("program.hl");
    if (!file.is_open()) {
        std::cerr << "Failed to open program.hl!" << std::endl;
        return 1;
    }

    executeHumanLang(file);
    return 0;
}
