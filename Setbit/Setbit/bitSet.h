
#include <vector>


using namespace std;
class bitSet{
public:
	//����
	bitSet(size_t range){
		_bits.resize((range >> 5) + 1);
		_count=range;
	}
	//��1����ʾ����
	void Set(size_t x){
		if (x > _count)
			return;
		size_t index = x >> 5;  //   /32
		size_t bitNum = x % 32;
		_bits[index] |= (1 << bitNum);
	}
	//��0����ʾ������
	void ReSet(size_t x){
		if (x > _count)
			return;
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		_bits[index] &= ~(1 << bitNum);
	}
	//�ж�x��Ӧ��λ�Ƿ����
	bool Test(size_t x){
		if (x > _count)
			return false;
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		return _bits[index] & (1 << bitNum);
	}
private:
	vector<int> _bits;
	size_t _count;
};