#include <iostream>
#include <map>
#define N 12
using namespace std;

class Count {
public:
 // за голям range
	void sort(int* seq,int sz){
		map<int,int> mp;
		for(int i = 0; i < sz; i++){
			mp[seq[i]]++;
		}
		int k = 0;
		for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
			while((it->second)--){
				seq[k++] = it->first;
			}
		}
  	}
//а малък range
	/*void sort(int* seq,int sz){
		//определяме range на елементите
		int min = seq[0],max = seq[0];
		for(int i = 1; i < sz; i++){
			if(seq[i] < min) min = seq[i];
			else if(seq[i] > max) max = seq[i];
		}
		int range = max - min + 1;
		int* tmp = new int[range];
		for(int i = 0; i < sz; i++){
			tmp[seq[i] - min]++;
		}
		int k = 0;
		for(int i = 0; i < range; i++){
			while(tmp[i]--){
				seq[k++] = i + min;
			}
		}
		delete [] tmp;
	}*/
};


int main(){
	Count s;
	int arr[N] = {1,1,1,0,-50909,0,1,43534,1,1,1,1};//{5,8,-6,7,7,3,4,-1,0,2,0,-1};//{1,2,3,4,5,6,7,8,9,10};
	s.sort(arr,N);
	for(int i = 0; i < N; i++) cout<<arr[i]<<" ";
	return 0;
}
