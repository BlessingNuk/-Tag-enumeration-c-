#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "tag.h"

using namespace NKRBLE001;
std::vector<TagStruct> tagsVector; //tagsVector.push_back(x); 

void NKRBLE001::readFile(std::string filename){
	std::string s;
	std::ifstream infile;
	std::ofstream outfile;
	
	infile.open(filename);
	outfile.open("out.txt");
	
	while (getline(infile, s)) {
		//getline(infile, s); //read from file
		std::cout << s << std::endl;
		outfile << s << std::endl;
		processLine(s);
	}
	
	infile.close();
	outfile.close();
	printVector(tagsVector);
}

void NKRBLE001::processLine(std::string line) {
	TagStruct tagData;
	std::string tName;
	std::string tText;
	
	int pos = line.find('>');
	
	tName = line.substr(1, pos - 1);
	tText = line.substr(pos+1, line.rfind('<') - (pos+1));
	
	//std::cout << tName << ' ' << tText << std::endl;
	
	tagData.tagName = tName;
	tagData.tagText = tText;
	//std::cout << tagData.tagName << ':' << tagData.tagText << std::endl;
	
	tagsVector.push_back(tagData);
}

void NKRBLE001::printVector(std::vector<TagStruct> tagvec) {
	for (int i = 0; i < tagvec.size(); i++) {
		std::cout << tagvec[i].tagName << ' ' << tagvec[i].tagText << std::endl;
	}
}

