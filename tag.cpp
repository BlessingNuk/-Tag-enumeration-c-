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
		std::cout << s << std::endl; //print out
		outfile << s << std::endl; //print to output file
		processLine(s);
	}
	
	infile.close();
	outfile.close();
	printVector(tagsVector); //print out
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
	
	//tagsVector.push_back(tagData);
	insertTag(tagData);
}

void NKRBLE001::printVector(std::vector<TagStruct> tagvec) {
	for (int i = 0; i < tagvec.size(); i++) {
		std::cout << '\"'<< tagvec[i].tagName << "\"," << tagvec[i].totalNum << ",\"" << tagvec[i].tagText<<"\"\n";
	}
}

void NKRBLE001::insertTag(TagStruct tag) {
	bool found = false;
	for (int i = 0; i < tagsVector.size(); i++) {
		if (tagsVector[i].tagName == tag.tagName) { //if tag is already in vector, then increment the total number of that tag, and concatinate text
				found = true;
				tagsVector[i].totalNum++;
				tagsVector[i].tagText = tagsVector[i].tagText + ':' + tag.tagText;
				break;
			}
	}
	if (found == false) { // if the tag is not in the vector, then add tag in the vector
		tag.totalNum = 1;
		tagsVector.push_back(tag);
	}
}


