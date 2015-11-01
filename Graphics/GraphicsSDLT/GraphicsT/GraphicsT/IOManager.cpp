#include "IOManager.h"

#include <fstream>

bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer)
{
	std::ifstream file(filePath, std::ios::binary);
	if (file.fail()){
		perror(filePath.c_str());
		return false;
	}

	// seek to the end
	file.seekg(0, std::ios::end);

	// Get the file size
	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// Reduce the file size by any header files present
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read((char*)&(buffer[0]), fileSize);
	
	return true;

}