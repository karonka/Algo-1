#include <iostream>
#include <cstring>
#define N 15

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

class MergeSort {
public:
  void sort(int* seq, int sz){
	if (sz == 2){
		if (seq[0] > seq[1]){
			swap(seq[0],seq[1]);
		}
	}
	else if (sz > 2){
		int mid = sz/2;
		sort(seq, mid);
		sort(seq + mid,sz - mid);
		int* tmp = new int[sz];
		int k = 0;
		for(int i = 0,j = mid; k < sz;){
			if(i >= mid){
				memcpy(tmp+k,seq+j,(sz-j)*sizeof(int));
				break;
			}
			else if(j >= sz){
				memcpy(tmp+k,seq+i,(mid-i)*sizeof(int));
				break;
			}
			else if(seq[i] > seq[j]) {
				tmp[k] = seq[j];
				k++;
				j++;
			}
			else{ //seq[i] <= seq[j]
				tmp[k] = seq[i];
				k++;
				i++;
			}
		}
		memcpy(seq,tmp,sz*sizeof(int));
		delete [] tmp;	
	}
  }
};

int main(){
	MergeSort s;
	int arr[N] = {5,6,3,6,8,3,1,2,0,4,1,1,1,1,1};// {10,9,8,7,6,5,4,3,2,1};//{1,2,3,4,5,6,7,8,9,10};//{5,8,-6,9,7,3,4,-1,0,2};
	s.sort(arr,N);
	for(int i = 0; i < N; i++) cout<<arr[i]<<" ";
	return 0;
}
