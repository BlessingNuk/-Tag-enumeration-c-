#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "tag.h"

using namespace NKRBLE001;
std::vector<TagStruct> tagsVector; //tagsVector.push_back(x); 

void NKRBLE001::readFile(std::string filename){
	std::string s, longstr;
	std::ifstream infile;
	infile.open(filename);
	
	if (!infile) {
		std::cout << "Incorrect file entered";
		}
	while (getline(infile, s)) {
		longstr = longstr + s;
	}
	
	infile.close();
	std::cout << filename << " is being processed\n";
	processLine(longstr);
	//std::cout << longstr;

}


void NKRBLE001::processLine(std::string line) {
	
	if (line.length() != 0) {
		TagStruct newTag;
		std::string tName, tText;
		int pos, closetag, index, pindex; 
	
		pos = line.find('>');
		tName = line.substr(1, pos - 1);
		closetag = line.find("</"+tName+">");
		tText = line.substr(pos+1, closetag - (pos+1));
		//std::cout << tText;
		//tText = line.substr(pos+1, line.rfind('<') - (pos+1));
		
		index = searchTag(tName);
		if (index >= 0) {
			tagsVector[index].tagText = tagsVector[index].tagText + ':' + tText;
			tagsVector[index].totalNum++;
		}else{
			newTag.totalNum = 1;
			newTag.tagName = tName;
			newTag.tagText = tText;
			tagsVector.push_back(newTag);
		}
		
		pindex = closetag+tName.length()+3;
		line = line.substr(pindex);
	//	std::cout << pindex << std::endl;
	
		processLine(line);
	}
	
}

/*
void NKRBLE001::printTags() {
	bool file = false;
	for (int i = 0; i < tagsVector.size(); i++) {
		std::cout << tagsVector[i].tagName << std::endl;
	}
	
}


void NKRBLE001::writeFile(std::string filename){
	std::ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < tagsVector.size(); i++) {
		outfile << '\"'<< tagsVector[i].tagName << "\"," << tagsVector[i].totalNum << ",\"" << tagsVector[i].tagText<<"\"\n";
	}
	outfile.close();
}

void NKRBLE001::printTagInfo(std::string tagName){
	int index = searchTag(tagName);
	if (index >= 0) {
		std::cout << "Tag Name: " << tagsVector[index].tagName;
		std::cout << "\nNumber of \"" << tagsVector[index].tagName << "\" tags: " << tagsVector[index].totalNum;
		std::cout << "\nTag text: \"" << tagsVector[index].tagText << "\"\n";
	}else{
		std::cout << "Tag not found\n";
	}
}*/

int NKRBLE001::searchTag(std::string tagName){
	for (int i = 0; i < tagsVector.size(); i++) {
		if (tagsVector[i].tagName == tagName) { //if tag is already in vector, then increment the total number of that tag, and concatinate text
			return i;
		}
	}
	return -1;
}



