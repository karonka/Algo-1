#include <iostream>
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
		int sz = size - 1;
		for(int i = 1; i < size; i++){
			heapify(seq + i, sz--, 0);
		}
	}
};

int main(){
	int arr[] = {5,10,3,20,16,8,12};
	HeapSort hs;
	hs.make_heap(arr,7);
	for(int i = 0; i < 7; i++) cout<<arr[i]<<" ";cout<<endl;
	hs.sort(arr,7);
	for(int i = 0; i < 7; i++) cout<<arr[i]<<" ";cout<<endl;
	return 0;
}
