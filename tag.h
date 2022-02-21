#ifndef TAG_H
#define TAG_H
#include <vector>

namespace NKRBLE001 {
	struct TagStruct{
		std::string tagName;
		int totalNum;	
		std::string tagText;
	};


	void readFile(std::string filename);
	void processLine(std::string line);
	void printVector(std::vector<TagStruct> tagvec);
	
}
#endif
