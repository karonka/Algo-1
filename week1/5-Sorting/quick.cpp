#include <iostream>
#define N 10

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
class Quick {
public:
  void sort(int* seq, int sz){
	if (sz < 2) return;
	int c = seq[0];
	int pos = 0;
	int i = 0, j = sz - 1;
	while( i < j){
		while (seq[i] < c && i < sz - 1) i++;
		while (seq[j] > c && j > 0) j--;
		if (i < j) {
			swap(seq[i],seq[j]);
			if(seq[i] == c) {pos = i;}
			else if(seq[j] == c) {pos = j;}
			if (seq[i] == seq[j]){j--;} 
		}
	}
	if (pos == 0) pos = 1;
	sort(seq, pos);
	sort(seq+pos, sz-pos);
  }
};
int main(){
	Quick s;
	int arr[N] = {5,8,-6,9,7,3,4,-1,0,2};//{1,2,3,4,5,6,7,8,9,10};//{10,9,8,7,6,5,4,3,2,1};//{5,6,3,6,8,3,1};//,2,0,4,1,1,1,1,1};//
	s.sort(arr,N);
	for(int i = 0; i < N; i++) cout<<arr[i]<<" ";
	return 0;
}
