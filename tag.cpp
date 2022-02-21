#include <fstream>
#include <iostream>
#include <string>
#include "tag.h"


void readFile(std::string filename){
	std::string s;
	std::ifstream infile;
	std::ofstream outfile;
	
	infile.open(filename);
	outfile.open("out.txt");
	
	while (getline(infile, s)) {
		//getline(infile, s); //read from file
		std::cout << s << std::endl;
		outfile << s << std::endl;
		//processLine(s);
	}
	
	infile.close();
	outfile.close();
}


