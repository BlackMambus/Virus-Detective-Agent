#include <iostream>
#include <fstream>
#include <string>

bool scanFileForVirus(const std::string& filename, const std::string& virusSignature) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    std::string content;
    while (std::getline(file, content)) {
        if (content.find(virusSignature) != std::string::npos) {
            return true; // Virus signature found
        }
    }

    file.close();
    return false; // Virus signature not found
}

int main() {
    std::string filename = "example.txt";
    std::string virusSignature = "malicious_code";

    if (scanFileForVirus(filename, virusSignature)) {
        std::cout << "Virus detected in " << filename << std::endl;
    } else {
        std::cout << "No virus found in " << filename << std::endl;
    }

    return 0;
}





