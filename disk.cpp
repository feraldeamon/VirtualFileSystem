//disk.cpp

#include <iostream>
#include <stdio.h>
using namespace std;

#define BLOCK_SIZE 512

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


};

void diskIO::formatDisk(int sizeMB, FILE * file)
{
	int i;
	char by = 0;
	for(i = 0; i <= (((BLOCK_SIZE * 2) * 1024) * sizeMB); i++)
	{
		fputc(by, file);
	}
}

int main()
{
	diskIO dsk;
	FILE * fin = fopen("disk.bin", "w+");
	dsk.formatDisk(36, fin);
	fclose(fin);
	return 0;
}
