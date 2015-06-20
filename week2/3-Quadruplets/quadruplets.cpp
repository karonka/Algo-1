#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> first;
vector<long long> second;

int binary(int num){
	int l = 0; 
	int r = second.size();
	int mid;
	while(l < r) {
		mid = l + (r - l)/2;
		if (second[mid] == num) break;
		if (second[mid] > num){
			r = l + (r - l)/2 - 1;
		}
		else{
			l = l + (r - l)/2 + 1;
		}
	}
	mid = l + (r - l)/2;
	int cnt = 0;
	while(mid >= 0 && second[mid] == num) {
		cnt++;
		mid--;
	}
	mid = l + (r - l)/2 + 1;
	while(mid < second.size() && second[mid] == num) {
		cnt++;
		mid++;
	}
	return cnt;
}


class Quadruplets {
public:
	int zero_quadruplets_count(int* a, int* b, int* c, int* d, int size) {
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				first.push_back(a[i] + b[j]);
				second.push_back(c[i] + d[j]);
			}
		}
		int count = 0;
		sort(second.begin(),second.end());
		for(int i = 0; i < first.size(); i++){
				count += binary(-first[i]);
		}
		return count;
	}
};

int main(){
	Quadruplets q;
	int a[] = {5, 3, 4, 9};
	int b[] = {-2, -1, 6, 0};
	int c[] = {-1, -2, 4, 0};
	int d[] = {-1, -2, 7, -9};
	
	cout << q.zero_quadruplets_count(a,b,c,d,4) << endl;
}
