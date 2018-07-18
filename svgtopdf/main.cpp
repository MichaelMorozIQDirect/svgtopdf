#include "stdafx.h"
#include <iostream>
#include "SvgConverter.h"

int main(int argc, char ** argv) {

	if (argc != 3) {
		std::cout << "Invalid run arguments." << std::endl << "The correct usage is: svgtopdf infile.svg outfile.pdf" << std::endl;
		return 1;
	}
	
	std::string fileInput = argv[1];
	std::string fileOutput = argv[2];

	SvgConverter converter; 

	if (!converter.loadFromFile(fileInput)) { // load svg image to inner buffer
		std::cout << "Error loading inout file" << fileInput << std::endl;
		return 1;
	}
	
	std::cout << "input file " << fileInput << " loaded" << std::endl;
	
	if (!converter.convertToPDF(fileOutput)) { // parse and write image from buffer to pdf format
		std::cout << "Error converting " << fileOutput << std::endl;
		return 1;
	}
	
	std::cout << "Converted. Please see " << fileOutput  << std::endl;


	//getchar();
	return 0;
}