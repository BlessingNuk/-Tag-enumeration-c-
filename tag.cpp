#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include "tag.h"

using namespace NKRBLE001;
std::vector<TagStruct> tagsVector;
std::stack<TagStruct> S;

/**
 * Converts text in a given file into one long string
 * if file is nested call processNested() else processline()
 * 
 * @param filename, contains the name of the file to be processed
 */
void NKRBLE001::readFile(std::string filename){
	tagsVector.clear();
	std::string s, longstr;
	std::ifstream infile;
	infile.open(filename);
	
	if (!infile) {
		std::cout << "Incorrect file entered";
	}
	
	while (getline(infile, s)) {
		longstr = longstr + s; //Convert all the lines in the file into one long string
	}
	
	infile.close();
	std::cout << filename << " is being processed\n";
	
	if (filename.find("nested") == -1) //check if file is nested
		processLine(longstr);
	else
		processNested(longstr);

}

/**
 * Takes string and itentifies tags and creats a TagStruct object for each tag
 * adds the TagStruct objects in a vector tagsVector
 * 
 * @param line, string to be processed
 * */
void NKRBLE001::processLine(std::string line) {
	
	if (line.length() != 0) {
		TagStruct newTag;
		std::string tName, tText;
		int pos, closetag, index, pindex; 
	
		pos = line.find('>');
		tName = line.substr(1, pos - 1);
		closetag = line.find("</"+tName+">"); //find index of the closing tag, assuming that all tags have closing tags and not nested
		tText = trim(line.substr(pos+1, closetag - (pos+1)));
		
		index = searchTag(tName); //search for tag in vector
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
	
		processLine(line);
	}
	
}

/**
 * Prints all the tags to the console 
 */
void NKRBLE001::printTags() {
	for (int i = 0; i < tagsVector.size(); i++) {
		std::cout << '<' << tagsVector[i].tagName << '>' << std::endl;
	}
	
}

/**
 * Writes the tags' information into a file
 * 
 * @param filename, file to write to
 */
void NKRBLE001::writeFile(std::string filename){
	std::ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < tagsVector.size(); i++) {
		outfile << '\"'<< tagsVector[i].tagName << "\"," << tagsVector[i].totalNum << ",\"" << tagsVector[i].tagText<<"\"\n";
	}
	outfile.close();
}

/**
 * Prints the name of the tag, tag count and tag text to the console
 * 
 * @param tagName, the name of the tag to print
 */
void NKRBLE001::printTagInfo(std::string tagName){
	int index = searchTag(tagName);
	if (index >= 0) {
		std::cout <<"Tag name: \""<< tagsVector[index].tagName;
		std::cout << "\", Tag count: " << tagsVector[index].totalNum;
		std::cout << ", Tag text: \"" << tagsVector[index].tagText<<"\"\n";
	}else{
		std::cout << "Tag not found\n";
	}
}

/**
 * Search the tag in the vector tagsVector
 * 
 * @param tagName, name of tag to search
 * @return `i`, index of the tag if found in the vector, -1 if tag not found
 */
int NKRBLE001::searchTag(std::string tagName){
	for (int i = 0; i < tagsVector.size(); i++) {
		if (tagsVector[i].tagName == tagName) { 
			return i;
		}
	}
	return -1;
}

/**
 * Called when the file has nested tags
 * Takes string and itentifies tags and creats a TagStruct object for each tag
 * Adds the TagStruct objects in a vector tagsVector
 * 
 * @param s, string to be processed
 * @return 0 when end of string s is reached i.e s=="\0"
 * */
int NKRBLE001::processNested(std::string s){
	if (s == "\0"){ return 0;}
	TagStruct tagData;
	int start, end, index;
	std::string tagName, tagText;

	if(s[0] != '<') {
		start = s.find('<');
		S.top().tagText = S.top().tagText + ' ' + s.substr(0, start);
		s = s.substr(start);
	}
	
	if (s[1] != '/') { //If not a closing tag
			end = s.find('>');
			tagData.tagName = s.substr(1, end - 1);
			s = s.substr(end+1);
			start = s.find('<');
			tagData.tagText = trim(s.substr(0, start));
			S.push(tagData);
			s = s.substr(start);
	} 
	else { //it is a closing tag
		index = searchTag(S.top().tagName);
		if (index >= 0) {
			tagsVector[index].tagText = tagsVector[index].tagText + ':' + S.top().tagText;
			tagsVector[index].totalNum++;
		}else{
			tagData.totalNum = 1;
			tagData.tagName = S.top().tagName;
			tagData.tagText = S.top().tagText;
			tagsVector.push_back(tagData);
		}
		
		S.pop();
		start = s.find('>');
		s = s.substr(start+1);
	}

	processNested(s);

}

/**
 * Removes tabs and newline characters from a string
 * 
 * @param line, string to trim
 * @return newline, a new string with no '\t' and '\n'
 */
std::string NKRBLE001::trim(std::string line) {
	char unwanted = '\t';
	std::string newline;
	//std::cout << "helloo\n";
	for(int i=0; i<line.size(); i++) {
		if(line[i]!='\t' and line[i]!='\n'){
			newline = newline+line[i];
		}
	}
	return newline;
}










