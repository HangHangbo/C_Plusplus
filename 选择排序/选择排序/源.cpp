#include <iostream>


void Print(int array[], int size){
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}


void SelectSort(int array[], int size){
	int min;//��¼��СԪ�ص��±�
	for (int i = 0; i < size - 1; i++){
		min = i;
		for (int j = i + 1; j < size; j++){
			if (array[j] < array[min]){
				min = j;
			}
		}
		if (i != min){
			int k = array[i];
			array[i] = array[min];
			array[min] = k;
		}
	}
	Print(array, size);
}



//void HeapSort(){
//	//��һ�����
//
//
//	for (int i = 0; i < size - 1; i++){
//		swap(array, array + size - i - 1);
//		//���µ������Ѷѽṹ����Ϊ��ȷ״̬
//	}
//}

void Swap(int *left, int *right){
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

//�����򣨴�ѣ�
//���µ���
void AdjustDown(int array[], int size, int root){

	int i = 2 * root + 1;
	int j = 2 * root + 2;

	if (i >= size){
		return;
	}

	int m = i;
	if ( j<size && array[j]>array[i])
		m = j;

	if (array[m] > array[root]){
		Swap(array + m, array + root);
		AdjustDown(array, size, m);
	}
}

//����
void GreateHeap(int array[], int size){
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}
}

//������
void HeapSort(int array[], int size){
	GreateHeap(array, size);
	for (int i = 0; i < size; i++){
		Swap(array, array + size - i - 1);
		AdjustDown(array, size-1 - i, 0);
	}
	
}


void BubbleSort(int array[], int size){
	for (int i = 0; i < size-1; i++){
		for (int j = i+1; j < size; j++){
			if (array[i] < array[j]){
				Swap(array+i, array+j);
			}
		}
	}
}
int main(){
	int array[] = { 3,4,9,8,7,11,12,4,5,1,0,2,6 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	//SelectSort(array, size);
	//BubbleSort(array, size);
	HeapSort(array, size);
	Print(array, size);
	system("pause");
	return 0;
}
