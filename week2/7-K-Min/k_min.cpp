#include <cstdio>
#include <vector>
#define INF 2147483647

using namespace std;

class KMin {
public:
	void make_heap(vector<int>& seq){
		int size = seq.size();
		for(int i = size/2 - 1; i >= 0; i--){
			heapify(seq, size, i);
		}
	}
	void heapify(vector<int>& seq, int size, int i){
		int min = i;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size && seq[i*2 + 1] < seq[min]) min = i*2 + 1;
			if (i*2 + 2 < size && seq[i*2 + 2] < seq[min]) min = i*2 + 2;
			if (seq[min] < seq[i]){
				swap(seq[min],seq[i]);
				i = min;
			}
			else return;
		}
	}
	int kthMinimum(vector<int>& numbers, int k) {
		make_heap(numbers);
		int size = numbers.size();
		int curr = 0;
		int c = 0;
 		for (int i = 0; i < size && c < k; i++){
			curr = numbers[0];
			c++;
			swap(numbers[0], numbers[size - i - 1]);
			heapify(numbers, size - i - 1, 0);
		}
		if(c == k) return curr;
		return -1;
	}
};

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	KMin km;
	printf("%d", km.kthMinimum(arr,k));
	return 0;
}
