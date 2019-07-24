#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_

template <class T>
class ObjectPool{
protected:
	struct Block
	{   
		//�����ϵͳ������ڴ��
		char* _start=nullptr;
		
		//��ʶ������Ѿ�ʹ���˶��ٸ��ֽ�
		size_t _bytesize=0;

		//ʣ���ֽ���
		size_t _byteleft = 0;

		//��һ�����ָ�룬����������һ����
		Block* _next = nullptr;
		Block(size_t bytesize){
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_next = nullptr;
		}
	};
public:
	ObjectPool(size_t initnum = 8){
		//����һ�����������
		_head = _tail = new Block(ininum* sizeof(T));
	}
	T* New(){
		//������һ������������������������������Ƿ����㹻��Ŀռ�
		if (_freelist != nullptr){

		}
		else{
			Block* tail = _tail;
			if (_tail->_byteleft == 0){
				//�ڴ����������д�����ڴ�飬������ָ��
				Block newblock = new Block(_tail->_bytesize*2);
				_tail->next = newblock;
				_tail = newblock;
			}
			char *obj = _tail->_strat + (_tail->_bytesize - _tail->_byteleft);
			_tail->_byteleft -= sizeof(T);

			return obj;
		}
	}
	void Delete(T *ptr)
	{}
protected:
	//��������
	T* _freelist=nullptr;
	
	//�����
	Block* _head=nullptr;

	//��ǰ���õ�һ����
	Block* _tail=nullptr;
};



#endif