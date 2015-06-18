#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<long long> first;
map<long long,int> second;

int zero_quadruplets_count(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			first.push_back(a[i] + b[j]);
		}
	}
	for(int i = 0; i < c.size(); i++){
		for(int j = 0; j < d.size(); j++){
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

int main(){
	vector<int> a = {5, 3, 4, 9};
	vector<int> b = {-2, -1, 6, 0};
	vector<int> c = {-1, -2, 4, 0};
	vector<int> d = {-1, -2, 7, -9};
	
	cout << zero_quadruplets_count(a,b,c,d) << endl;
}
