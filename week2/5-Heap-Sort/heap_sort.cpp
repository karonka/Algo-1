#include <cstdio>
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
		for(int i = 0; i < size; i++) printf("%d ", arr[i]);
	}
};

int main(){
	HeapSort hs;
	int n;
	int* arr;
	scanf("%d", &n);
	arr = new int[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	hs.make_heap(arr,n);
	hs.sort(arr,n);
	delete [] arr;
	return 0;
}
