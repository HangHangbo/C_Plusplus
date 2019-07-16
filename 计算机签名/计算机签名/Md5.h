#pragma once
#include <cmath>
#include <cstring>
#include <fstream>
#define N 64

class MD5{
	
private:
	MD5();
	void init();
	void calculateMD5(size_t* chunk);
	void calculateMD5Final();
	std::string getFileMd5(const char * filename);
	std::string getStrMd5(const std::string &str);
		//每个chunk 占64个byte 每四个字节处理 便将chunk转位size_t 
	size_t F(size_t x, size_t y, size_t z){
		return (x & y) | ((~x) & z);
	}
	size_t G(size_t x, size_t y, size_t z){
		return (x & z) | (y & (~z));
	}
	size_t H(size_t x, size_t y, size_t z){
		return  x ^ y ^ z;
	}
	size_t I(size_t x, size_t y, size_t z){
		return	y ^ (x | (~z));
	}
	size_t shiftLeftRotate(size_t num, size_t n){
		return (num << n) | (num >> (32 - n));

	}
private:

	//因为在算k_[N]的时候要计算2^32 int存不下
	size_t a_ ;
	size_t b_ ;
	size_t c_ ;
	size_t d_ ;
	/*
	word A: 01 23 45 67
	word B: 89 ab cd ef
	word C: fe dc ba 98
	word D: 76 54 32 10
	低字节子前
	a= 0x67452301;
	b = 0xefcdab89;
	c = 0x98badcfe;
	d= 0x10325476;
	*/

	size_t k_[N];
	//循环左移偏移量
	size_t sft_[N];

	const size_t chunkByte_;
	unsigned char chunk_[N];	//每次要处理的大小

	size_t lastByte_;

	unsigned long long totalByte_;
};