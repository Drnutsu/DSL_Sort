#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print(int *arr,int size){
	for(int i = 0;i < size;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


void bubbleSort(int *arr,int n){
	bool swaped = true;
	for(int i = n-1;i >=1;i--){
		swaped = false;
		for(int j = 0;j < i;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				swaped = true;
			}
		}
	}
}

void selectionSort(int *arr,int n){
	int pos;
	for(int i = n-1;i >= 1;i--){
		int max = 0;
		for(int j = 0;j <= i;j++){
			if(arr[j] > max){
				max  = arr[j];
				pos = j;
			}
		}
		int temp  = arr[i];
		arr[i] = max;
		arr[pos] = temp;
		print(arr,5);
	}
}

void insertionSort(int *arr,int n){
	for(int i = 1;i < n;i++){
		int num = arr[i];
		int j = i;
		/*while(i > 0 && num <= arr[j-1]){
		arr[j] = arr[j-1];
		j--;
		}*/
		for(;i>0 && num <= arr[j-1];j--){
			arr[j] = arr[j-1];
		}
		arr[j]  = num;
	}
}

void merge(int *a,int beginA,int endA,int beginB,int endB){
	int c = 0;
	int beginPrt = beginA; // เก็บค่า temp เอาไว้เพื่อกำหนดตำแหน่งเริ่ม ใส่ array ตอนสุดท้าย
	int temp[10];
	while(beginA <= endA && beginB <= endB){
		if(a[beginA] <= a[beginB]){
			temp[c] = a[beginA];
			beginA++;
		}else{
			temp[c] = a[beginB];
			beginB++;
		}
		c++;
	}
	while(beginA <= endA){
		temp[c] = a[beginA];
		c++;
		beginA++;
	}
	while(beginB <= endB){
		temp[c] = a[beginB];
		c++;
		beginB++;
	}
	int j = 0; // temp จะมีการใส่ค่าที่ถูกต้องเริ่มต้นที่ 0 เสมอในขณะที่ i ไม่ขำเป็นต้องเริ่มที่ 0
	for(int i = beginPrt;i <= endB;i++){ 
		a[i] = temp[j];
		j++;
	}
}

void mergeSort(int *a,int left,int right){
	if(left < right){
		int center = (right+left)/2;
		mergeSort(a,left,center);
		mergeSort(a,center+1,right);
		merge(a,left,center,center+1,right);
	}
}

//First Element Quicksort
void QuickSort(int *arr,int left,int right){
	if(right - left > 0) { //Base case recursive for check
		int pivot = left;
		int i  = pivot+1;
		int j = right;
		while(i < j){
			while(arr[i] < arr[pivot])i++;
			while(arr[j] > arr[pivot])j--;
			if(i < j){ //check ถ้าหากไม่มีการสลับเลยจะด้ข้ามไปเลย
				//swap
				swap(arr[i],arr[j]);
				//move
				i++;
				j--;
			}
		}
		if(arr[j] < arr[pivot]){
			swap(arr[j],arr[pivot]); //move pivot to right position
		}
		print(arr,10);
		QuickSort(arr,left,j-1);
		QuickSort(arr,j+1,right);
	}
}

void swap(int *a,int *b){
	int *temp = a;
	a = b;
	b = temp;
}

int main() {
	int a[5] = {8,3,9,4,5};
	cout << "---------------Bubble Sort------------------" << endl;
	bubbleSort(a,5);
	cout << "--------------------------------------------" << endl;
	cout << "---------------Selection Sort---------------" << endl;
	int b[5] = {6,9,8,5,4};
	selectionSort(b,5);
	cout << "--------------------------------------------" << endl;
	cout << "---------------Insertion Sort---------------" << endl;
	int c[5] = {8,6,7,5,9};
	insertionSort(c,5);
	print(c,5);
	cout << "--------------------------------------------" << endl;
	cout << "---------------Merge Sort-------------------" << endl;
	int d[8] = {5,3,6,1,2,7,8,4};
	mergeSort(d,0,7);
	print(d,8);
	cout << "--------------------------------------------" << endl;
	cout << "---------------Quick Sort-------------------" << endl;
	int e[10] = {5,1,4,9,6,3,8,2,7,0};
	QuickSort(e,0,9);
	print(e,10);
	cout << "--------------------------------------------" << endl;

	//Reading files
	ifstream myReadFile;
	myReadFile.open("500.txt");
	int output;
	int i = 0;
	int arr[510];
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> output;
			arr[i] = output;
			i++;
		}
	}
	myReadFile.close();
	bubbleSort(arr,500);
	print(arr,500);
	
	return 0;

}