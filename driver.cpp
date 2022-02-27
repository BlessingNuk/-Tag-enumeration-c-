#include <iostream>
#include <cstdlib>
#include <string>
#include "tag.h"

using namespace NKRBLE001;
int main(int argc, char * argv[]) {
	char op;
	
	do {
		system("clear"); //clear the shell command to improve visibility
		std::cout << "Enter an option (r,p,d,l) or q to quit, and press the Enter key...\n\n";
		std::cout << "r: Read and process tag file\n";
		std::cout << "p: Print all tags\n";
		std::cout << "d: Dump/write tags and data to tag.txt\n";
		std::cout << "l: List/Dump tag data for given tag\n";
		std::cout << "q: Quit\n\n";
		
		std::cin >> op;
		system("clear"); 
		std::string filename, tagName;
		switch (op) {
			case 'r':
				std::cout << "Enter the file name (if nested, include the word 'nested' e.g x_nested.txt)" << std::endl;
				std::cin >> filename;
				readFile(filename);
				break;
			case 'p':
				std::cout << "The Tags are: " << std::endl;
				printTags();
				break;
			case 'd':
				writeFile("tag.txt");
				std::cout << "Tags written in tag.txt file" << std::endl;
				break;
			case 'l':
				std::cout << "Enter the tag name:" << std::endl;
				std::cin >> tagName;
				printTagInfo(tagName);
				break;
			default:
				if (op != 'q') 
					std::cout << "Incorrect option entered" << std::endl;
			}
			
		if (op !='q') {
			std::cout << "\nPress any letter to display the menu or 'q' to close the program\n";
			std::cin >> op; 
		}
		
		system("clear");
	} while (op != 'q');
	return 0;
}
