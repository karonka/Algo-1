#include <iostream>
#include <cstring>

using namespace std;
class InsertionSort {
public:
  void sort(int* seq, int sz){
	for(int i = 1; i < sz; i++){
		int j;
		for (j = i - 1; j >= 0; j--){
			if (seq[j] < seq[i]){
				break;
			}
		}
		int tmp = seq[i];
		memmove(seq+j+2, seq+j+1, (i-j-1)*sizeof(int));
		seq[j+1] = tmp;
	}
  }
};

int main(){
	InsertionSort s;
	int arr[10] = {5,8,-6,9,7,3,4,-1,0,2};//{1,2,3,4,5,6,7,8,9,10};
	s.sort(arr,10);
	for(int i = 0; i < 10; i++) cout<<arr[i]<<" ";
	return 0;
}
