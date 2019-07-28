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
	// ��׼ֵ�� array[right]

	while (begin < end) {
		// ���������
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// һ������߿�ס��

		// �����ұ�
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// һ�����ұ�Ҳ��ס��

		Swap(array + begin, array + end);
	}

	// ���䱻�ֳ� С���󣬻�׼
	Swap(array + begin, array + right);

	// ���ص�ǰ��׼ֵ����λ��
	return begin;
}
//�ڿӷ�
int Parition_2(int array[], int left, int right){
	int pivot = array[right];   //��׼ֵ
	int begin = left;
	int end = left;
	while (begin<end){
		//��begin������
		while (array[left] <= pivot&&begin < end){
			begin++;
		}
		//��arrayy[left]�����׼ֵ��ʱ������ѭ��������ڿӽ�array[left]�����Ҳ�Ŀ���
		array[end] = array[begin];
		//��end������
		while (array[end] >= pivot&&begin < end){
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}
//���±귨
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


// Ҫ����������� array[left, right]
void __QuickSort(int array[], int left, int right) {
	// ��ֹ���� size == 0 || size == 1
	// left == right	�����ڻ�ʣһ����
	// left > right		������û����
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int div; // �Ȼ�׼ֵС�ķŻ�׼ֵ��ߣ���ķ��ұߺ󣬻�׼ֵ���ڵ��±�
	div = Parition_3(array, left, right);	// ���� array[left, right]����С�ķ��󣬴�ķ���
	__QuickSort(array, left, div - 1);	// ���ν����ߵ�С����
	__QuickSort(array, div + 1, right);	// ���ν���ұߵ�С����
}



//�ǵݹ��������
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
//	//��ֹ���� 
//	//size==1  left = right
//	//size==0  left > left
//	if (left == right)
//		return;
//	if (left > right)
//		return;
//	int div;
//	//�ҳ�������Ԫ��Ϊ��׼ֵ�����������ų���������
//	//�����ػ�׼ֵ�±�λ��
//	div = Parition(array, left,right);
//	_QuickSort(array, left, div - 1);
//	_QuickSort(array, div + 1, right);
//}
//
//
//void QuickSort(int array[], int size){
//	_QuickSort(array, 0, size);
//}