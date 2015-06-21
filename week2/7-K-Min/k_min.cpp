#include <iostream>
#include <vector>
#define INF 2147483647

using namespace std;
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

class KMin {
public:
	void make_heap(vector<int>& seq){
		int size = seq.size();
		for(int i = size/2 - 1; i >= 0; i--){
			heapify(seq, size, i);
		}
	}
	void heapify(vector<int>& seq, int size, int i){
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
	int kthMinimum(vector<int> numbers, int k) {
		make_heap(numbers);
		int size = numbers.size();
		int curr = numbers[0];
		int c = 1;
 		for (int i = 0; i < size && c < k; i++){
			if(numbers[0] != curr){
				curr = numbers[0];
				c++;
			}
			swap(numbers[0], numbers[size - i - 1]);
			heapify(numbers, size - i - 1, 0);
		}
		if(c == k) return curr;
		return -1;
	}
};

int main(){
	vector<int> arr = {0,5,3,6,4,8,1};
	vector<int> arr2 = {10,15,3,6,4,6,15,15,4,8,1};
	KMin km;
	cout << km.kthMinimum(arr,1) << endl;
	cout << km.kthMinimum(arr,2) << endl;
	cout << km.kthMinimum(arr,5) << endl;
	cout << km.kthMinimum(arr,7) << endl;
	cout << km.kthMinimum(arr2,7) << endl;
	cout << km.kthMinimum(arr2,4) << endl;
	return 0;
}
