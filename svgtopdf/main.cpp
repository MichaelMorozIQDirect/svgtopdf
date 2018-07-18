#include <iostream>
#include "DrawSvg.h"

int main(int argc, char ** argv) {

	if (argc != 3) {
		std::cout << "Invalid run arguments" << std::endl;
		return 1;
	}
	std::string fileInput = argv[1];
	std::string fileOutput = argv[2];

	SVGManager manager; 

	if (!manager.loadFromFile(fileInput)) { // load svg image to inner buffer
		std::cout << "Error loading file" << std::endl; 
		return 1;
	}
	else std::cout << "Loaded" << std::endl;


	if (!manager.convertToPDF(fileOutput)) { // parse and write image from buffer to pdf format
		std::cout << "Error converting file" << std::endl;
		return 1;
	}
	else std::cout << "Converted" << std::endl;


	//getchar();
	return 0;
}