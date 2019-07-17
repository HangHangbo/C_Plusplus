#include <iostream>
#include "Md5.h"

int main(int argc, char *argv[]){
	if (argc != 2){
		std::cout << argv[0] << "\tfilename" << std::endl;
		return 0;
	}

	MD5 md5;
	std::cout << md5.getFileMd5(argv[1]) << std::endl;
	return 0;
}