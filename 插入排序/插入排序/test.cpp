#include <iostream>
//直接插入排序

void Print(int array[], int size){
	for (int i = 0; i < size; i++)
		std::cout << array[i]<<" ";
	std::cout << std::endl;
}

void InsertSort(int array[], int size){
	for (int i = 1; i < size; i++){
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0; --j){
			if (array[j] <= k)
				break;
			else
				array[j + 1] = array[j];
		}
		array[j + 1] = k;
	}
	Print(array, size);
}

void InsertSortGap(int array[], int size, int gap){
	for (int i = gap; i < size; i++){
		int k = array[i];
		int j;
		for ( j = i - gap; j >= 0; j -= gap){
			if (array[j] <= k)
				break;
			else
				array[j + gap] = array[j];
		}
		array[j + gap] = k;
	}
}
void ShellSort(int array[], int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		//gap 比较大的数 --> 小 --->1 结束
		InsertSortGap(array, size, gap);
		if (gap == 1)
			break;
	}
	Print(array, size);
}




int main(){
	int array[] = { 2, 5, 8, 7, 9, 1, 2, 4 };
	int size = sizeof(array) / sizeof(array[0]);
	//InsertSort(array, size);
	ShellSort(array, size);
	system("pause");
	return 0;
}