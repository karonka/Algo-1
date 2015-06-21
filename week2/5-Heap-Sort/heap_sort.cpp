#include <iostream>
#include <cstring>
#define INF 2147483647
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

class HeapSort {
public:
	void make_heap(int* seq, int size){
		for(int i = size/2 - 1; i >= 0; i--){
			heapify(seq, size, i);
		}
	}
	void heapify(int* seq, int size, int i){
		int a,b;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size) a = seq[i*2 + 1];
			if (i*2 + 2 < size) b = seq[i*2 + 2];
			else b = INF;
			int min = a < b? i*2+1 : i*2+2;
			if (seq[min] < seq[i]){
				swap(seq[min],seq[i]);
				i = min;
			}
			else return;
		}
	}
	void sort(int* seq, int size) {
		int arr[size];
		for(int i = 0; i < size; i++){
			arr[i] = seq[0];
			swap(seq[0], seq[size - i - 1]);
			heapify(seq, size - i - 1, 0);
		}
		memcpy(seq,arr,size*sizeof(int));
	}
};

int main(){
	//int arr[] = {5,10,3,20,16,8,12};
	int arr[] = {0,5,3,6,4,8,4};
	HeapSort hs;
	hs.make_heap(arr,7);
	for(int i = 0; i < 7; i++) cout<<arr[i]<<" ";cout<<endl;
	hs.sort(arr,7);
	for(int i = 0; i < 7; i++) cout<<arr[i]<<" ";cout<<endl;
	return 0;
}
