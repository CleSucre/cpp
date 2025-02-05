#include "colors.h"
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, const char *argv[]) {
	if (argc != 4) {
		std::cout << RED << "Usage: " << RESET << argv[0]
				  << " " << BOLD << "<filename> <find> <replace>" << RESET << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string find = argv[2];
	std::string replace = argv[3];

	if (find.empty()) {
		std::cout << RED << "Error: " << RESET << "Find string cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		std::cout << RED << "Error: " << RESET << "Could not open file '" << filename
				  << "' - " << strerror(errno) << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	size_t pos = 0;
	while ((pos = content.find(find, pos)) != std::string::npos) {
		content = content.substr(0, pos) + replace + content.substr(pos + find.length());
		pos += replace.length();
	}

	std::string out_filename = filename + ".replace";
	std::ofstream outputFile(out_filename.c_str());
	if (!outputFile) {
		std::cout << RED << "Error: " << RESET << "Could not create output file '" << out_filename
				  << "' - " << strerror(errno) << std::endl;
		return 1;
	}

	outputFile << content;
	outputFile.close();

	std::cout << GREEN << "Success: " << RESET << "File '" << filename
			  << "' has been processed. Output saved in '" << out_filename << "'" << std::endl;

	return 0;
}
