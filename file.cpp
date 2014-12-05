//file.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "disk.h"

using namespace std;

class fileIO {

	string fileName;
	int inodeNumber;
	char currentblock[BLOCK_SIZE];
	vector<int> dataBlocks;
	bool writePermission;
	bool readPermission;
	bool executePermission;
  public:
  	void writeInode();

};
