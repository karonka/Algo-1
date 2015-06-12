#include <iostream>
#include <iostream>
#include <cstdlib>
#define N 10

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int* sort(int* seq, int sz){
	for(int i = 0; i < sz - 1; i++){
		int min = i;
		for(int j = i + 1; j < sz; j++){
			if (seq[j] < seq[min]){
				min = j;
			}
		}
		swap(seq[i], seq[min]);
	}
	return seq;
}

int main(){
	int arr[N] = {5,8,6,9,7,3,4,1,0,2};
	sort(arr,N);
	for(int i = 0; i < N; i++) cout<<arr[i]<<" ";
	return 0;
}


