#include <iostream>
#include <cstdlib>
#include "tag.h"

int main(int argc, char * argv[]) {
	char op;
	
	do {

		std::cout << "r: Read and process tag file\n";
		std::cout << "p: Print all tags\n";
		std::cout << "d: Dump/write tags and data to tag.txt\n";
		std::cout << "l: List/Dump tag data for given tag\n";
		std::cout << "q: Quit\n";
		std::cout << "Enter an option (r,p,d,l) or q to quit, and press the Enter key..." << std::endl;
		
		std::cin >> op;
		system("clear"); //clear the shell command to improve visibility
		
		switch (op) {
			case 'r':
				std::cout << "r entered" << std::endl;
				readFile("tag.txt");
				break;
			case 'p':
				std::cout << "p entered" << std::endl;
				break;
			case 'd':
				std::cout << "d entered" << std::endl;
				break;
			case 'l':
				std::cout << "l entered" << std::endl;
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
