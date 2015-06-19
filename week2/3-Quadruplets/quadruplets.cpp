#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<long long> first;
map<long long,int> second;

class Quadruplets {
public:
	int zero_quadruplets_count(int* a, int* b, int* c, int* d, int size) {
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				first.push_back(a[i] + b[j]);
				second[c[i] + d[j]]++;
			}
		}
		int count = 0;
		
		map<long long, int> :: iterator it;
		for(int i = 0; i < first.size(); i++){
			it = second.find(-first[i]);
			if(it != second.end()){
				count += it->second;
			}
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
