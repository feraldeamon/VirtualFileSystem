//file.cpp

#include <iostream>
#include <stdio.h>
#include <vector.h>
#include "disk.h"

class fileIO {
	string fileName;
	char currentblock[BLOCK_SIZE];
	vector<int> dataBlocks;
	bool writePermission;
	bool readPermission;
	bool executePermission;
  public:
  	writeInode();

}