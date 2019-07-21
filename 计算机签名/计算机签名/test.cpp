#include <iostream>
#include "Md5.h"

int main(int argc, char *argv[]){
	if (argc != 3){
		std::cout << "eg:" << std::endl;
		std::cout << argv[0] << "\t0\tfilename" << std::endl;
		std::cout << argv[0] << "\t1\tString" << std::endl;
		return 0;
	}

	MD5 md5;
	char option = *argv[1];
	switch(option)
	{
	case '0':
		std::cout << md5.getFileMd5(argv[2]) << std::endl;
	case '1':
		std::cout << md5.getStrMd5(argv[2]) << std::endl;
	}
	return 0;
}

//void menu(){
//	std::cout << "************************************" << std::endl;
//	std::cout << "*******      MD5加密工具     *******" << std::endl;
//	std::cout << "************************************" << std::endl;
//	std::cout << "请选择你要进行的操作:" << std::endl;
//	std::cout << "             1.文件加密             " << std::endl;
//	std::cout << "             2.密码加密             " << std::endl;
//	std::cout << "             0.退出                 " << std::endl;
//}


//int main(){
//	while (1){
//		menu();
//		int option;
//		bool tab = 0;
//		std::cin >> option;
//		char input;
//		MD5 md5;
//		switch (option){
//		case 0:
//			std::cout << "感谢使用，再见！" << std::endl;
//			tab = 1;
//			break;
//		case 1:
//			std::cout << "\t0\tfilename" << std::endl;
//			std::cin >> input;
//			std::cout << md5.getFileMd5(input) << std::endl;
//			break;
//		case 2:
//			std::cout << "\t1\tString" << std::endl;
//		}
//		if (tab)
//			break;
//	}
//	return 0;
//}