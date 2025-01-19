#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceOccurrences(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();

    inputFile.close();

    std::string::size_type pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Erro ao criar o arquivo de saída." << std::endl;
        return;
    }
    outputFile << content;
    outputFile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Use: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    replaceOccurrences(argv[1], argv[2], argv[3]);
    return 0;
}
