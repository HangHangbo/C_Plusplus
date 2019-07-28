#include <iostream>

void Swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void Print(int* arr, int size){
	for (int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



int Parition_1(int array[], int left, int right) {
	int begin = left;
	int end = right;
	// 基准值是 array[right]

	while (begin < end) {
		// 优先走左边
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// 一定是左边卡住了

		// 再走右边
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// 一定是右边也卡住了

		Swap(array + begin, array + end);
	}

	// 区间被分成 小，大，基准
	Swap(array + begin, array + right);

	// 返回当前基准值所在位置
	return begin;
}
//挖坑法
int Parition_2(int array[], int left, int right){
	int pivot = array[right];   //基准值
	int begin = left;
	int end = left;
	while (begin<end){
		//走begin向右走
		while (array[left] <= pivot&&begin < end){
			begin++;
		}
		//当arrayy[left]大与基准值的时候跳出循环在左侧挖坑将array[left]填入右侧的坑中
		array[end] = array[begin];
		//走end向左走
		while (array[end] >= pivot&&begin < end){
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}
//上下标法
int Parition_3(int array[], int left, int right){
	int d = left;

	for (int i = left; i < right; i++){
		if (array[i] < array[right]){
			Swap(array + d, array + i);
			d++;
		}
	}
	Swap(array + d, array + right);
	return array[d];
}


// 要排序的区间是 array[left, right]
void __QuickSort(int array[], int left, int right) {
	// 终止条件 size == 0 || size == 1
	// left == right	区间内还剩一个数
	// left > right		区间内没有数
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int div; // 比基准值小的放基准值左边，大的放右边后，基准值所在的下标
	div = Parition_3(array, left, right);	// 遍历 array[left, right]，把小的放左，大的放右
	__QuickSort(array, left, div - 1);	// 分治解决左边的小区间
	__QuickSort(array, div + 1, right);	// 分治解决右边的小区间
}



//非递归快速排序
#include<stack>
#include<iostream>
void _QuickSortNor(int array[], int left, int right){
	std::stack<int>s;
	s.push(right);
	s.push(left);

	int _left;
	int _right;

	while (!s.empty()){
		_left = s.top(); s.pop();
		_right = s.top(); s.pop();

		if (_left >= _right){
			continue;
		}

		int d = Parition_1(array, _left, _right);

		//d+1,right
		s.push(_right);
		s.push(d + 1);

		//_left,d-1
		s.push(d - 1);
		s.push(_left);

	}
}
void QuickSort(int array[], int size) {
	_QuickSortNor(array, 0, size - 1);
}



//int Parition(int arr[], int left, int right){
//
//}
//void _QuickSort(int array[], int left, int right){
//	//终止条件 
//	//size==1  left = right
//	//size==0  left > left
//	if (left == right)
//		return;
//	if (left > right)
//		return;
//	int div;
//	//找出以最左元素为基准值将待排序列排成左右两列
//	//并返回基准值下标位置
//	div = Parition(array, left,right);
//	_QuickSort(array, left, div - 1);
//	_QuickSort(array, div + 1, right);
//}
//
//
//void QuickSort(int array[], int size){
//	_QuickSort(array, 0, size);
//}