#ifndef TAG_H
#define TAG_H

struct TagStruct{
	std::string tagName;
	int totalNum;	
	std::string tagText;
};

//vector<TagStruct> tagsVector; //tagsVector.push_back(x);

void readFile(std::string filename);
void processLine(std::string line);
#endif
