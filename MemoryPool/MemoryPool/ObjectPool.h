#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_

template <class T>
class ObjectPool{
protected:
	struct Block
	{   
		//管理从系统申请的内存块
		char* _start=nullptr;
		
		//标识这个块已经使用了多少个字节
		size_t _bytesize=0;

		//剩余字节数
		size_t _byteleft = 0;

		//下一个块的指针，用来链接下一个块
		Block* _next = nullptr;
		Block(size_t bytesize){
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_next = nullptr;
		}
	};
public:
	ObjectPool(size_t initnum = 8){
		//将第一个块申请出来
		_head = _tail = new Block(ininum* sizeof(T));
	}
	T* New(){
		//先申请一个对象出来，现在自由链表里面找是否有足够大的空间
		if (_freelist != nullptr){

		}
		else{
			Block* tail = _tail;
			if (_tail->_byteleft == 0){
				//内存块已满，重写申请内存块，并更新指针
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
	//自由链表
	T* _freelist=nullptr;
	
	//块管理
	Block* _head=nullptr;

	//当前在用的一个块
	Block* _tail=nullptr;
};



#endif