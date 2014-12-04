//disk.cpp

#include <iostream>
#include <stdio.h>
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
   	void formatDisk(int sizeMB, FILE * file);
   	void writeBlock(char * data, int blockNumber);
   	void readBlock(char * data, int blockNumber);
   	void setFile(char * fileName);
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

void diskIO::setFile(char * fileName)
{
	disk = fopen(fileName, "w+");
}

void diskIO::closeFile()
{
	fclose(disk);
}

int main()
{
	diskIO dsk;
	setFile("disk.bin")
	dsk.formatDisk(36);
	closeFile();
	return 0;
}
