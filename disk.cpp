//disk.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "disk.h"
using namespace std;



class diskIO {
	FILE * disk;
	int currentBlock;
	int * blockIOQueue;
   public:
	diskIO() {
		currentBlock = 0;
		blockIOQueue = NULL;
		disk = NULL;
	};
	~diskIO() {};
   	void formatDisk(int sizeMB);
   	void writeBlock(char * data, int blockNumber);
   	void readBlock(char * data, int blockNumber);
   	void setFile(string fileName);
   	void closeFile();

};

void diskIO::formatDisk(int sizeMB)
{
	int i;
	char by = 0;
	for(i = 0; i <= (((BLOCK_SIZE * 2) * 1024) * sizeMB); i++)
	{
		fputc(by, disk);
	}
}

void diskIO::writeBlock(char * data, int blockNumber)
{
	fseek(disk, (BLOCK_SIZE * blockNumber), SEEK_SET);
	fwrite(data, sizeof(char), sizeof(data), disk);
}	

void diskIO::readBlock(char * data, int blockNumber)
{
	fseek(disk, (BLOCK_SIZE * blockNumber), SEEK_SET);
	fread(data, sizeof(char), sizeof(data), disk);
}

void diskIO::setFile(string fileName)
{

	char * cstr = new char [fileName.length()+1];
	strcpy(cstr, fileName.c_str());
	disk = fopen(cstr, "w+");
	delete cstr;
}

void diskIO::closeFile()
{
	fclose(disk);
}

int main()
{
	diskIO dsk;
	string fileName("disk.bin");
	dsk.setFile(fileName);
	dsk.formatDisk(36);
	dsk.closeFile();
	return 0;
}
