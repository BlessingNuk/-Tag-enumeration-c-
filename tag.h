#ifndef TAG_H
#define TAG_H


namespace NKRBLE001 {
	struct TagStruct{
		std::string tagName;
		int totalNum = 0;	
		std::string tagText;
	};


	void readFile(std::string filename);
	void processLine(std::string line);
	int processNested(std::string nestedFile);
	void printTags();
	void writeFile(std::string filename);
	void printTagInfo(std::string tagName);
	int searchTag(std::string tagName);
	std::string trim(std::string line);
	
}
#endif
