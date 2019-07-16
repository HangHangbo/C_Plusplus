
#include "Md5.h"

void MD5::calculateMD5(size_t *chunk){
	size_t a = a_;
	size_t b = b_;
	size_t c = c_;
	size_t d = d_;

	size_t f, g;   //f��ϣ��������ֵ   chunk[g]


	//64�α任��4�ֲ�����ÿһ�ֲ�����16���Ӳ���
	for (size_t i = 0; i < 64; i++){
		if (0 <= i&&i < 16){
			f = F(b, c, d);
			g = i;
		}
		else if (16 <= i&&i < 32){
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (32 <= i&&i < 48){
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		
		size_t dtmp = d;
		d = c;
		c = b;
		b = b + shiftLeftRotate(a + f + k_[i] + chunk[g], sft_[i]);
		a = dtmp;
	}


	//����buffer��ֵ
	a_ += a;
	b_ += b;
	c_ += c;
	d_ += d;
}
void MD5::calculateMD5Final(){
	//lastByte_:<64byte ���һ�����ݴ�С
	unsigned char *p=chunk_ + lastByte_;
	//���λ��ǰ��bitλ��1000 0000 0X80
	*p++ = 0x80;
	size_t remainFillByte = chunkByte_ - lastByte_ - 1;
	if (remainFillByte < 8){
		memset(p, 0, remainFillByte);
		calculateMD5((size_t*)chunk_);
		memset(chunk_, 0, chunkByte_);
	}
	//���һ��chunk_С��448bit
	else{
		memset(p, 0, remainFillByte);
	}
	//���˸��ֽڴ��ԭʼ�ĵ���bit����
	((unsigned long long*)chunk_)[7] = totalByte_ * 8;
	calculateMD5((size_t*)chunk_);
}
MD5::MD5()
:chunkByte_(N)
{
	init();
	memset(chunk_, 0, chunkByte_);
	lastByte_ = totalByte_ = 0;
}

void MD5::init(){
	size_t a_ = 0x67452301;
	size_t b_ = 0xefcdab89;
	size_t c_ = 0x98badcfe;
	size_t d_ = 0x10325476;

	size_t s[N] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
				       5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
					   4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
					   6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
	memcpy(sft_, s, sizeof(s));
	
	for (int i = 0; i < 64; i++){
		k_[i] = (size_t)(abs(sin(i + 1)) * pow(2, 32));
	}

}

std::string MD5::getFileMd5(const char * filename){
	std::ifstream fin(filename, std::ifstream::binary);
	if (fin.is_open()){
		while (!fin.eof()){
			fin.read((char*)chunk_, chunkByte_);
			if (chunkByte_ != fin.gcount())
				break;

			totalByte_ += chunkByte_;
			calculateMD5((size_t*)chunk_);
		}
		lastByte_ = fin.gcount();
		totalByte_ += lastByte_;
		calculateMD5Final();
	}
	return 0;
	//return chaneHex(a_)+
}

std::string MD5::getStrMd5(const std::string &str){
	if (str.empty()){
		return "";
	}
	else{
		unsigned char* pstr = (unsigned char*)str.c_str;
		size_t numChunk = str.size() / chunkByte_;
		for (size_t i = 0; i < numChunk; i++){
			totalByte_ += chunkByte_;
			calculateMD5((size_t*)pstr + i*chunkByte_);
		}
		lastByte_ = str.size() % chunkByte_;
		memcpy(chunk_, pstr + totalByte_, lastByte_ );
		calculateMD5Final();

	}
}